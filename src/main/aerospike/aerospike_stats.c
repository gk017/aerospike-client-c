/*
 * Copyright 2008-2018 Aerospike, Inc.
 *
 * Portions may be licensed to Aerospike, Inc. under one or more contributor
 * license agreements.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#include <aerospike/aerospike_stats.h>
#include <aerospike/as_cluster.h>
#include <aerospike/as_node.h>

/******************************************************************************
 * GLOBALS
 *****************************************************************************/

extern uint32_t as_event_loop_capacity;
extern uint32_t as_event_loop_size;

/******************************************************************************
 * STATIC FUNCTIONS
 *****************************************************************************/

static inline void
as_sum_init(as_conn_stats* stats)
{
	stats->in_pool = 0;
	stats->in_use = 0;
}

static inline void
as_sum_no_lock(as_conn_pool* pool, as_conn_stats* stats)
{
	// Warning: cross-thread reference without a lock.
	int tmp = as_queue_size(&pool->queue);

	// Timing issues may cause values to go negative. Adjust.
	if (tmp < 0) {
		tmp = 0;
	}
	stats->in_pool += tmp;
	tmp = pool->total - tmp;

	if (tmp < 0) {
		tmp = 0;
	}
	stats->in_use += tmp;
}

/******************************************************************************
 * FUNCTIONS
 *****************************************************************************/

void
aerospike_cluster_stats(as_cluster* cluster, as_cluster_stats* stats)
{
	as_nodes* nodes = as_nodes_reserve(cluster);
	stats->nodes = cf_malloc(sizeof(as_node_stats) * nodes->size);
	stats->nodes_size = nodes->size;

	for (uint32_t i = 0; i < nodes->size; i++) {
		aerospike_node_stats(nodes->array[i], &stats->nodes[i]);
	}

	// cf_queue applies locks, so we are safe here.
	stats->thread_pool_queued_tasks = cf_queue_sz(cluster->thread_pool.dispatch_queue);
	as_nodes_release(nodes);
}

void
aerospike_stats_destroy(as_cluster_stats* stats)
{
	uint32_t max = stats->nodes_size;

	// Release individual nodes.
	for (uint32_t i = 0; i < max; i++) {
		aerospike_node_stats_destroy(&stats->nodes[i]);
	}
	cf_free(stats->nodes);
}

void
aerospike_node_stats(as_node* node, as_node_stats* stats)
{
	as_node_reserve(node); // Released in aerospike_node_stats_destroy()
	stats->node = node;

	as_sum_init(&stats->sync);
	as_sum_init(&stats->async);
	as_sum_init(&stats->pipeline);

	uint32_t max = node->cluster->conn_pools_per_node;

	// Sync connection summary.
	for (uint32_t i = 0; i < max; i++) {
		as_conn_pool_lock* pool_lock = &node->conn_pool_locks[i];

		pthread_mutex_lock(&pool_lock->lock);
		uint32_t in_pool = as_queue_size(&pool_lock->pool.queue);
		uint32_t total = pool_lock->pool.total;
		pthread_mutex_unlock(&pool_lock->lock);

		stats->sync.in_pool += in_pool;
		stats->sync.in_use += total - in_pool;
	}

	// Async connection summary.
	if (as_event_loop_capacity > 0) {
		for (uint32_t i = 0; i < as_event_loop_size; i++) {
			// Regular async.
			as_sum_no_lock(&node->async_conn_pools[i], &stats->async);

			// Pipeline async.
			as_sum_no_lock(&node->pipe_conn_pools[i], &stats->pipeline);
		}
	}
}


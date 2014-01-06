# Client Class

<<<<<<< HEAD
The `Client` class provides operations which can be performed on an Aerospike
database cluster. In order to get an instance of the Client class, you need
to call `aerospike.client()`:

```js
var aerospike = require('aerospike')

var client = aerospike.client(config)
```

The `config` variable is an instance of the client [Configuration](configuration.md),
which needs to be populated and passed to `aerospike.client()`.

With a new client, you can then use any of the methods specified below.

=======
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
- [Methods](#methods)
	- [batch_get()](#batch_get)
	- [close()](#close)
	- [connect()](#connect)
	- [get()](#get)
	- [info()](#info)
	- [operate()](#operate)
	- [put()](#put)
	- [remove()](#remove)
	- [select()](#select)


<a name="methods"></a>
## Methods


<<<<<<< HEAD
<!--
################################################################################
batch_get()
################################################################################
-->
<a name="batch_get"></a>

### batch_get(keys, policy=null, callback)
=======

<a name="batch_get"></a>
### batch_get(keys, [policy,] callback)
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Read a batch of records from the database cluster.

Parameters:

<<<<<<< HEAD
- `keys`      – An array of [Key objects](datamodel.md#key), used to locate the records in the cluster.
- `policy`    – (optional) The [ReadKey object](policy.md#read) to use for this operation.
- `callback`  – The function to call when the operation completes, with the results of the batch operation. 

The parameters for the `callback` argument:

- `error`   – The [Error object](datamodel.md#error) representing the status of 
              the operation.
- `records` – An array of objects containing a `record` field  and a `metadata` 
              field. The `records` is a [Record object](metadata.md#record). The 
              `metadata` field is a [Metadata object](metadata.md#metadata).

=======
- `keys` – An array of key objects.
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.

The `callback` should be a function like:

```js
function (error, records)
```
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Example:
```js
var key = aerospike.key

var keys = [
  key('test', 'demo', 'key1'),
  key('test', 'demo', 'key2'),
  key('test', 'demo', 'key3')
]

<<<<<<< HEAD
client.batch_get(keys, function(err, recs) {
=======
client.batch_get(keys, function(err, records) {
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
close()
################################################################################
-->
<a name="close"></a>

=======
<a name="close"></a>
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
### close()

Close the client connection to the cluster.

Example:
```js
client.close()
```

<<<<<<< HEAD
<!--
################################################################################
connect()
################################################################################
-->
<a name="connect"></a>

=======

<a name="connect"></a>
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
### connect()

Establish the client connection to the cluster.

<<<<<<< HEAD
Parameters:

- `callback`  – The function to call when the operation completes.

Returns the client object which was used to connect to the cluster.

The parameters for the `callback` argument:

- `error` – An [Error object](datamodel.md#error), which contains the status of the connect call. 

Example:
```js
client.connect(function (error){
  if ( error.status == aerospike.Status.AEROSPIKE_OK ) {
    // handle success
  }
  else {
    // handle failure
  }
})
```

<!--
################################################################################
get()
################################################################################
-->
<a name="get"></a>

=======
Example:
```js
client.connect()
```


<a name="get"></a>
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
### get(key, [policy,] callback)

Read a record from the database cluster using the key provided.

Parameters:

<<<<<<< HEAD
- `key`         – A [Key objects](datamodel.md#key), used to locate the record in the cluster.
- `policy`      – (optional) The [ReadPolicy object](policy.md#read) to use for this operation.
- `callback`    – The function to call when the operation completes with the results of the operation.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
- `record`      – The [Record object](metadata.md#record), containing the fields of the record.
- `metadata`    – The [Metadata object](metadata.md#record) for the `record`.
### info(request, [host,] [port,] callback)


Example:

=======
- `key` – A key object.
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.

The `callback` should be a function like:

```js
function (error, record, metadata)
```

Example:
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
```js
var key = aerospike.key

client.gey(key('test','demo','key1'), function(err, record, metadata) {
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
info()
################################################################################
-->
<a name="info"></a>

### info(request, host=null, port=null, policy=null, callback)
=======

<a name="info"></a>
### info(request, [host,] [port,] callback)
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Perform an info request against the database cluster or specific host.

Parameters:

<<<<<<< HEAD
- `request`     – The info request to send.
- `host`        – (optional) The address of a specific host to send the request to.
- `port`        – (optional) The port of a specific host to send the request to.
- `callback`    – The function to call when the operation completes with the results of the operation.

The `request` argument is a string representing an info request. The `host` and `port` arguments are optional, and allow the request to be sent to a specific host, rather than the entire cluster. With the `host` and `port` defined, then client is not required to be connected to a cluster.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
- `response`    – ???

Example:

=======
- `request` – The info request to send.
- `host` – (optional) The address of a specific host to send the request to.
- `port` – (optional) The port of a specific host to send the request to.
- `callback` – The function to call when the operation completes.

The `request` argument is a string representing an info request. The `host` and `port` arguments are optional, and allow the request to be sent to a specific host, rather than the entire cluster. With the `host` and `port` defined, then client is not required to be connected to a cluster.

The `callback` argument should be function:

```js
function(error, response)
```

The `error` argument represents any error that may have occurred. 

Example:
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
```js
client.operate(key, "statistics", function(err, response) {
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
operate()
################################################################################
-->
<a name="operate"></a>

### operate(key, operations, policy=null, callback)
=======

<a name="operate"></a>
### operate(key, operations, [policy,] callback)
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Perform multiple operations on a single record. 

Parameters:

<<<<<<< HEAD
- `key`         – A [Key object](datamodel.md#key), used to locate the record in the cluster.
- `operations`  – An array of operations.
- `policy`      – (optional) A [WritePolicy object](policy.md#writepolicy) to use for this operation.
- `callback`    – The function to call when the operation completes with the results of the operation.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
- `record`      – The [Record object](metadata.md#record), containing the fields of the record.
- `metadata`    – The [Metadata object](metadata.md#record) for the `record`.

=======
- `key` – a key object
- `operations` – an array of operation objects.
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.

The `operations` argument is an array of operations, which are populated via the [Operators object](operators.md). 

The `callback` should be a function like:

```js
function (error, record, metadata)
```
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Example:

```js
var op = aerospike.Operators

var ops = [
  op.append('a', 'xyz'),
  op.incr('b', 10),
  op.read('b')
]

client.operate(key, ops, function(err, rec, meta) {
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
put()
################################################################################
-->
<a name="put"></a>

### put(key, record, metadata=null, policy=null, callback)

Write a record to the database cluster. If the record exists, it will modify the record with bins provided. 
To remove a bin, set its value to `null`.

Parameters:

- `key`         – A [Key object](datamodel.md#key), used to locate the record in the cluster.
- `record`      – A [Record object](datamodel.md#record) used for specifying the fields to store.
- `metadata`    – (optional) A [Metadata object](datamodel.md#metadata).
- `policy`      – (optional) A [WritePolicy object](policy.md#writepolicy) to use for this operation.
- `callback`    – The function to call when the operation completes with the results of the operation.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
=======

<a name="put"></a>
### put(key, record, [metadata,] [policy,] callback)

Writing a record to the database cluster.

Parameters:

- `key` – a key object
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.

The `callback` should be a function like:

```js
function (error)
```
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Example:
```js
var key = aerospike.key

var rec = {
  a: 'xyz',
  b: 123
}

client.put(key('test','demo','key1'), rec, function(err) {
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
remove()
################################################################################
-->
<a name="remove"></a>

### remove(key, policy=null, callback)

Remove a record with the specified key from the database cluster.

Parameters:

- `key`         – A [Key object](datamodel.md#key) used for locating the record to be removed.
- `policy`      – (optional) The [RemovePolicy object](policy.md#writepolicy) to use for this operation.
- `callback`    – The function to call when the operation completes wit the results of the operation.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
=======
<a name="remove"></a>
### remove(key, [policy,] callback)

Parameters:

- `key` – a key object
- `operations` – an array of operation objects.
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

Example:
```js
var key = aerospike.key

client.remove(key('test','demo','key1'), function(err) {
  // do something
});
```

<<<<<<< HEAD
<!--
################################################################################
select()
################################################################################
-->
<a name="select"></a>

### select(key, bins, policy=null, callback)

Retrieve a specified bins for a record of given key from the database cluster.

Parameters:

- `key`         – A [Key objects](datamodel.md#key), used to locate the record in the cluster.
- `bins`        – An array of bin names for the bins to be returned for the given key.
- `policy`      – (optional) The [ReadPolicy object](policy.md#read) to use for this operation.
- `callback`    – The function to call when the operation completes with the results of the operation.

The parameters for the `callback` argument:

- `error`       – The [Error object](datamodel.md#error) representing the status of 
                  the operation.
- `record`      – The [Record object](metadata.md#record), containing the fields of the record.
- `metadata`    – The [Metadata object](metadata.md#record) for the `record`.

Example:
```js
var key = aerospike.key

client.select(key('test','demo','key1'), ["name","age"] function(err, rec, meta) {
  // do something
});
```
=======

<a name="select"></a>
### select(key, bins, [policy,] callback)

Retrieve a specified bins for a record of given key.

Parameters:

- `key` – The key of the record to select bins from.
- `policy` – (optional) The policy to use for this operation.
- `callback` – The function to call when the operation completes.

>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656
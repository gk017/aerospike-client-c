// Writing n records to database.

var env = require('./env')
var aerospike = require('aerospike')

var status = aerospike.Status
var policy = aerospike.Policy
var client = aerospike.connect(env.config)

// No of put of operation to be performed
var n = env.nops
var m = 0

console.time(n + " put")

for (var i = 0; i < n; i++ ) {

  var str = "This is abnormally lengthy string. This is to test batch_get functioning for more than 8 bytes";

  var o = {
    a: 1,
    b: 2,
    c: [1, 2, 3],
    d: str
  }

  // pack the object o using msgpack
  // var pbuf = msgpack.pack(o)

  // Key of the record.
  var k1 = {
    ns: env.namespace,
    set: env.set,
    key: "value" + i
  }

  // bins to be written 
  var binlist = {
    s: i.toString(),
    i: i
  }

  //metadata of the record. 
  var meta = {
    ttl: 10000,
    gen: 0
  }

  // Record to be written
  var rec = {
    metadata: meta,
    bins: binlist
  }

  // Policy to be followed while writing.
  var write_policy = {
    timeout: 10,
    Retry: policy.Retry.ONCE,       // If a write fails, retry the operation once
    Key: policy.Key.SEND,           // Send the key 
    Gen: policy.Generation.IGNORE,  // Ignore the generation of the record while writing
    Exists: policy.Exists.IGNORE    // Write the record regardless of the existence
  }

  // write the record to database
  client.put(k1, rec, write_policy, function(err) {
    if ( err.code != status.AEROSPIKE_OK ) {
        // Error code AEROSPIKE_OK specifies the success of write operation.
        console.log("error: %s", err.message)
    }
    if ( (++m) == n ) {
        console.timeEnd(n + " put")
    }
  })

}

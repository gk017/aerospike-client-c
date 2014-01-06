# Policies

<<<<<<< HEAD
Policies provide the ability to modify the behavior of operations.

This document provides information on structure of policy objects for certain 
operation and allowed values for some of the policies.

- [`Policy Objects`](#Objects)
- [`Policy Values`](#Values)


<a name="Objects"></a>
## Objects

Policy objects are objects which define the behavior of associated operations.

When invoking an operation, you can choose to provide a policy:

```js
client.get(key, {timeout: 1000}, callback);
```

<!--
################################################################################
BatchPolicy
################################################################################
-->
<a name="BatchPolicy"></a>

### BatchPolicy 

Attributes:

- `timeout`         – Maximum time in milliseconds to wait for the operation to
                      complete. If 0 (zero), then the value will default to 
                      global default timeout value.

<!--
################################################################################
InfoPolicy
################################################################################
-->
<a name="InfoPolicy"></a>

### InfoPolicy 

Attributes:

- `check_bounds`    – Ensure the request is within allowable size limits
- `send_as_is`      – Send request without any further processing
- `timeout`         – Maximum time in milliseconds to wait for the operation to 
                      complete. If 0 (zero), then the value will default to 
                      global default timeout value


<!--
################################################################################
OperatePolicy
################################################################################
-->
<a name="OperatePolicy"></a>

### OperatePolicy 

Attributes:

- `key`             – Specifies the behavior for the key. 
                       For values, see [Key Policy Values](policy_values.md#key).
- `gen`             – Specifies the behavior for the generation value.
                      For values, see [Generation Policy Values](policy_values.md#gen).
- `retry`           – An instance of :data:`RetryPolicy`. Specifies the behavior
                      for failed operations.

<!--
################################################################################
ReadPolicy
################################################################################
-->
<a name="ReadPolicy"></a>

### ReadPolicy 

Attributes:

- `key`             – Specifies the behavior for the key. 
                      For values, see [Key Policy Values](policy_values.md#key).
- `timeout`         – Integer datatype. Maximum time in milliseconds to wait for
                      the operation to complete. If 0 (zero), then the value 
                      will default to global default timeout value.


<!--
################################################################################
RemovePolicy
################################################################################
-->
<a name="RemovePolicy"></a>

### RemovePolicy 

Attributes:

- `gen`             – Specifies the behavior for the generation value.
                      For values, see [Generation Policy Values](policy_values.md#gen).
- `generation`      – The generation of the record to be removed.
- `key`             – Specifies the behavior for the key. 
                      For values, see [Key Policy Values](policy_values.md#key).
- `retry`           – Specifies the retry behavior of failed operations.
                      For values, see [Retry Policy Values](policy_values.md#retry).

<!--
################################################################################
WritePolicy
################################################################################
-->
<a name="WritePolicy"></a>

### WritePolicy 

Attributes:

- `gen`             – Specifies the behavior for the generation value.
                      For values, see [Generation Policy Values](policy_values.md#gen).
- `exists`          – Specifies the behavior for the existence of the record.
                      For values, see [Exists Policy Values](policy_values.md#exists).
- `key`             – Specifies the behavior for the key. 
                      For values, see [Key Policy Values](policy_values.md#key).
- `retry`           – Specifies the retry behavior of failed operations.
                      For values, see [Retry Policy Values](policy_values.md#retry).
- `timeout`         – Maximum time in milliseconds to wait for the operation to
                      complete. If 0 (zero), then the value will default to 
                      global default values.


<a name="Values"></a>
## Values

The following are values allowed for various policies.

<!--
################################################################################
key
################################################################################
-->
<a name="key"></a>

### Key Policy Values
=======
The Policies object contains an enumeration of values for policies. modify the behavior of database operations. The policies object provides values that are available for each policy.

Example:

```js
var policies = aerospike.Policies

client.get(key, {key=policies.Key.SEND}, callback)
```



## Key Policy Values
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

#### DIGEST

Send the digest value of the key. This is the recommended mode of operation. This calculates the digest and send the digest to the server. The digest is only calculated on the client, and not on the server. 

```js
policies.Key.DIGEST
```

#### SEND

Send the key. This policy is ideal if you want to reduce the number of bytes sent over the network. This will only work if the combination the set and key value are less than 20 bytes, which is the size of the digest. This will also cause the digest to be computer once on the client and once on the server. If your values are not less than 20 bytes, then you should just use Policy.Key.DIGEST

```js
policies.Key.SEND
```

<<<<<<< HEAD
<!--
################################################################################
retry
################################################################################
-->
<a name="retry"></a>

### Retry Policy Values
=======

## Retry Policy Values
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

#### NONE

Only attempt an operation once

```js
policies.Retry.NONE
```

#### ONCE

If an operation fails, attempt the operation one more time

```js
policies.Retry.ONCE
```

<<<<<<< HEAD
<!--
################################################################################
gen
################################################################################
-->
<a name="gen"></a>

### Generation Policy Values
=======

## Generation Policy Values
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

#### IGNORE

Write a record, regardless of generation.

```js
policies.Generation.IGNORE
```

#### EQ

Write a record, ONLY if generations are equal.

```js
policies.Generation.EQ
```

#### GT

Write a record, ONLY if local generation is greater-than remote generation.

```js
policies.Generation.GT
```

#### DUP

Write a record creating a duplicate, ONLY if the generation collides.

```js
policies.Generation.DUP
```

<<<<<<< HEAD
<!--
################################################################################
exists
################################################################################
-->
<a name="exists"></a>

### Exists Policy Values
=======

## Exists Policy Values
>>>>>>> d39fa88f028e87f1b5585798cd9f3a01d71ee656

#### IGNORE

Write the record, regardless of existence

```js
policies.Exists.IGNORE
```

#### CREATE

Create a record, ONLY if it doesn't exist

```js
policies.Exists.CREATE
```
Dictionary - Level 3
==========================

This data structure implementation aims to implement a simple fixed size HashMap (i.e. a HashTable) that maps an integer key to a string value. It properly hashes keys to store values as they are added by the user. The overall runtime of the dictionary is O(1).

Functions are provided to declare a new HashMap, set key/value pairs, update values, delete key/value pairs, and get the current load of the HashMap.

Below is an example of this functionality:
```java
// declare a new HashMap of max size 5
FixedSizeHashMap map = new FixedSizeHashMap(5)
```

```java
// set the integer 7 to map to the string "Tanishq"
map.set(7, "Tanishq");
```

```java
// get the value associated with the key '7' and print it out
System.out.println(map.get(7));
```

```java
// get the current map's overall load
Sytem.out.println(map.load());
```

```java
// delete the value associated with key '7'
map.delete(7)
```

## Features of this implementation:
* Properly hashes the integer to stay within array bounds
* Provides a load function to easily double, copy, and rehash when load goes above a certain value
* Utilizes chaining to store colliding keys if they are different

So, in a sense, its somewhere between Level 3 and 4 in terms of functionality :)
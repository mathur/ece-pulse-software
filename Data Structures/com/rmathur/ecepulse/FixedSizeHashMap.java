package com.rmathur.ecepulse;

public class FixedSizeHashMap {

    private static int currSize;
    private static int maxSize;
    private static Record data[];

    class Record {
        final int key;
        String value;
        Record next;

        Record(int k, String v) {
            key = k;
            value = v;
        }

        public int getKey() {
            return key;
        }

        public String getValue() {
            return value;
        }

        public void setValue(String value) {
            this.value = value;
        }
    }

    public FixedSizeHashMap(int s) {
        // create a new data record
        data = new Record[s];

        // set size variables correctly
        currSize = 0;
        maxSize = s;
    }

    public boolean set(int key, String value) {
        // hash the key to fit within the bounds of the array
        int hash = key % maxSize;

        // check to see if a record already exists at that location
        Record e = data[hash];
        if(e != null) {
            if(e.key == key) {
                // if its the same key too, update the value to the new value
                if(e.value != value)
                    e.value = value;
                return true;
            } else {
                if(currSize == maxSize) {
                    // map is full
                    return false;
                } else {
                    // find the next open spot
                    while(e.next != null) {
                        e = e.next;
                    }

                    // create a new record and insert it
                    Record createdRecord = new Record(key, value);
                    e.next = createdRecord;

                    // bump the size of the map
                    currSize++;
                    return true;
                }
            }
        } else {
            // create a new record and insert it
            Record createdRecord = new Record(key, value);
            data[hash] = createdRecord;

            // bump the size of the map
            currSize++;
            return true;
        }
    }

    public String get(int k) {
        // hash the entry to fit within the bounds of the array
        int hash = k % maxSize;

        // get the current entry
        Record e = data[hash];
        while(e != null) {
            // try to find the key at that location or in its chain
            if(e.key == k) {
                // once found, return the value
                return e.value;
            }
            // if not the current element, go down the chain to find it
            e = e.next;
        }

        // key was not found in the map, so return null
        return null;
    }

    public String delete(int k) {
        // hash the entry to fit within the bounds of the array
        int hash = k % maxSize;

        // get the current entry and set it to null
        Record e = data[hash];
        data[hash] = null;

        if(e != null) {
            // if there was an entry before, decrement the size of the map
            currSize--;
            return e.value;
        } else {
            // the record was empty before so don't do anything
            return null;
        }
    }

    public float load() {
        // return the current extent to which it is filled
        return (float) currSize / maxSize;
    }

    public static void main(String[] args) {
        // create a new map
        FixedSizeHashMap map = new FixedSizeHashMap(5);

        // set some data
        map.set(3, "Steven");
        map.set(27, "Tanishq");

        // print that data from the map
        System.out.println(map.get(27));
        System.out.println(map.get(3));

        // get the current map's load
        System.out.println(map.load());
    }
}
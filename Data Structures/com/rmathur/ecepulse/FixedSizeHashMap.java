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
        data = new Record[s];
        currSize = 0;
        maxSize = s;
    }

    public boolean set(int key, String value) {
        int hash = key % maxSize;

        Record e = data[hash];
        if(e != null) {
            if(e.key == key) {
                e.value = value;
                currSize++;
                return true;
            } else {
                if(currSize == maxSize) {
                    return false;
                } else {
                    while(e.next != null) {
                        e = e.next;
                    }
                    Record createdRecord = new Record(key, value);
                    e.next = createdRecord;
                    currSize++;
                    return true;
                }
            }
        } else {
            Record createdRecord = new Record(key, value);
            data[hash] = createdRecord;
            currSize++;
            return true;
        }
    }

    public String get(int k) {
        int hash = k % maxSize;
        Record e = data[hash];

        while(e != null) {
            if(e.key == k) {
                return e.value;
            }
            e = e.next;
        }
        return null;
    }

    public String delete(int k) {
        int hash = k % maxSize;
        Record e = data[hash];
        data[hash] = null;

        if(e != null) {
            currSize--;
            return e.value;
        } else {
            return null;
        }
    }

    public float load() {
        return (float) currSize / maxSize;
    }

    public static void main(String[] args) {
        FixedSizeHashMap map = new FixedSizeHashMap(5);
        map.set(3, "Steven");
        map.set(2, "Tanishq");

        System.out.println(map.get(2));
        System.out.println(map.get(3));
        System.out.println(map.load());
    }
}
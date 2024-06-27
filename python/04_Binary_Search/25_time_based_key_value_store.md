Binary Search 5
# Time Based Key Value Store
## Company: Google
### Level: Medium

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:
- `TimeMap()` Initializes the object of the data structure.
- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value` at the given time `timestamp`.
- String `get(String key, int timestamp)` Returns a value such that `set` was called previously, with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the largest `timestamp_prev`. If there are no values, it returns `""`.

***Break It Down For Me...***
*We need to create a data structure that can store key-value pairs where each value is associated with a timestamp.*
*We can set values for keys at different timestamps and retrieve the value set for the same key; we will need to return the value associated with the largest timestamp that is less that or equal to the given timestamp.*
*If there are no values for the key or the given timestamp is earlier than any stored timestamp, then we return an empty string.*

### Example 1
```
Output: 
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Input: 
[null, null, "bar", "bar", null, "bar2", "bar2"]
```
## Python
```
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # Dictionary to store the mapping of keys to lists of [value, timestamp] pairs
        self.keyStore = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If the key is not already in the keyStore, initialize it with an empty list
        if key not in self.keyStore:
            self.keyStore[key] = []
        # Append the [value, timestamp] pair to the list associated with the key
        self.keyStore[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        # Initialize result variable to store the final value to be returned
        res = ""
        # Get the list of [value, timestamp] pairs associated with the key, or an empty list if the key is not present
        values = self.keyStore.get(key, [])
        
        # Initialize pointers for binary search
        l, r = 0, len(values) - 1
        
        # Perform binary search on the list of [value, timestamp] pairs
        while l <= r:
            m = (l + r) // 2
            # If the timestamp at the middle index is less than or equal to the target timestamp,
            # update the result and move the left pointer to search for larger timestamps
            if values[m][1] <= timestamp:
                res = values[m][0]
                l = m + 1
            # If the timestamp at the middle index is greater than the target timestamp,
            # move the right pointer to search for smaller timestamps
            else:
                r = m - 1
        
        # Return the final result (the value associated with the latest timestamp not greater than the target timestamp)
        return res
```

## JavaScript
```
class TimeMap {
    constructor() {
        // Initialize an empty map to store key-value pairs with timestamps
        this.map = {};
    }

    /**
     * Set a key-value pair with the given timestamp
     * @param {string} key
     * @param {string} value
     * @param {number} timestamp
     * Time complexity: O(1)
     * Space complexity: O(1)
     * @return {void}
     */
    set(key, value, timestamp) {
        // Get the bucket associated with the key or initialize an empty array if it doesn't exist
        const bucket = this.map[key] || [];

        // Update the map with the bucket
        this.map[key] = bucket;

        // Push the [value, timestamp] pair into the bucket
        bucket.push([value, timestamp]);
    }

    /**
     * Get the value associated with the given key at the specified timestamp
     * @param {string} key
     * @param {number} timestamp
     * Time complexity: O(log(N)) where N is the size of the bucket
     * Space complexity: O(1)
     * @return {string}
     */
    get(key, timestamp, value = '', bucket = this.map[key] || []) {
        // Initialize pointers for binary search
        let [left, right] = [0, bucket.length - 1];

        // Perform binary search on the bucket
        while (left <= right) {
            const mid = (left + right) >> 1;
            const [guessValue, guessTimestamp] = bucket[mid];

            // Check if the timestamp at the middle index is less than or equal to the target timestamp
            const isTargetGreater = guessTimestamp <= timestamp;
            if (isTargetGreater) {
                // Update the value and move the left pointer to search for larger timestamps
                value = guessValue;
                left = mid + 1;
            }

            // Check if the timestamp at the middle index is greater than the target timestamp
            const isTargetLess = timestamp < guessTimestamp;
            if (isTargetLess) right = mid - 1;
        }

        // Return the final value (the value associated with the latest timestamp not greater than the target timestamp)
        return value;
    }
}
```

## Go
```
// TimeMap is a data structure to store key-value pairs with timestamps
type TimeMap struct {
	store map[string][]ValStamp // key : list of [val, timestamp]
}

// ValStamp represents a value with its associated timestamp
type ValStamp struct {
	Val  string // value
	Time int    // timestamp
}

// Constructor initializes a new TimeMap object
func Constructor() TimeMap {
	return TimeMap{store: make(map[string][]ValStamp)}
}

// Set stores the key with the value and timestamp
func (this *TimeMap) Set(key string, value string, timestamp int) {
	// If key doesn't exist, initialize an empty slice
	if _, ok := this.store[key]; !ok {
		this.store[key] = make([]ValStamp, 0)
	}
	// Append the new value and its timestamp to the list of values for the key
	this.store[key] = append(this.store[key], ValStamp{value, timestamp})
}

// Get retrieves the value of a key at a certain timestamp
func (this *TimeMap) Get(key string, timestamp int) string {
	var res string
	var values []ValStamp
	// Check if the key exists in the store
	if _, ok := this.store[key]; ok {
		values = this.store[key]
	}
	// Binary search to find the value associated with the largest timestamp <= given timestamp
	l, r := 0, len(values)-1
	for l <= r {
		mid := l + (r-l)/2
		if values[mid].Time <= timestamp {
			res = values[mid].Val
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return res
}
```
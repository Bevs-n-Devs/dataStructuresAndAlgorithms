Linked List 9
# LRU Cache
## Company: Twitch
### Level: Medium

Design a data structure that follows the constraints of a [Least Recently Used (LRU)](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU) cache.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` Initialize the LRU cache with positive size capacity.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, evict the least recently used key.

The functions `get` and `put` must each run in `O(1)` average time complexity.

***Break It Down For Me***
*We need to create a data structure called `LRUCache` that keeps track of the most recently used items and has a fixed capacity.*
*When the cache reaches its capacity, it should remove the least recently used item to make space for new items.*
*We have to have the following:*
- *Initialization: You need to initialize the cache with a given capacity.*
- *Get Operation: Retrieve the value of a given key if it exists in the cache. If the key does not exist, return `-1.`*
- *Put Operation: Add a new key-value pair to the cache. If the key already exists, update its value. If adding this new pair exceeds the cache's capacity, remove the least recently used item.*

Click [here](https://leetcode.com/problems/lru-cache/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=7ABFKPK2hD4) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input:
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output:
[null, null, null, 1, null, -1, null, -1, 3, 4]
```

## Python
```
class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}  # map key to node

        # Create dummy nodes for the left (least recently used) and right (most recently used) ends
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    # Remove a node from the doubly linked list
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    # Insert a node at the right (most recently used) end
    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.cache:
            # If key exists, move the node to the most recently used position
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # If key already exists, remove the old node
            self.remove(self.cache[key])
        # Create a new node and insert it to the most recently used position
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            # If the cache exceeds its capacity, remove the least recently used node
            lru = self.left.next  # LRU node is next to the dummy left node
            self.remove(lru)
            del self.cache[lru.key]
```

## JavaScript
```
class LRUCache {
    constructor(capacity) {
        this.capacity = capacity; // Maximum capacity of the cache
        this.map = new Map(); // To store the key-value pairs

        this.head = {}; // Dummy head node for the doubly linked list
        this.tail = {}; // Dummy tail node for the doubly linked list

        this.head.next = this.tail; // Initially, head is connected to tail
        this.tail.prev = this.head; // Initially, tail is connected to head
    }

    // Helper method to remove the least recently used node
    removeLastUsed() {
        const [ key, next, prev ] = [ this.head.next.key, this.head.next.next, this.head ];

        this.map.delete(key); // Remove key from map
        this.head.next = next; // Remove the first real node from the list
        this.head.next.prev = prev; // Update the previous pointer of the new first node
    }

    // Method to add a key-value pair to the cache
    put(key, value) {
        const hasKey = this.get(key) !== -1; // Check if the key already exists
        const isAtCapacity = this.map.size === this.capacity; // Check if the cache is at capacity
        
        if (hasKey) return (this.tail.prev.value = value); // If key exists, update its value and return
        if (isAtCapacity) this.removeLastUsed(); // If at capacity, remove the least recently used node

        const node = { key, value }; // Create a new node
        this.map.set(key, node); // Add the new node to the map
        this.moveToFront(node); // Move the new node to the front (most recently used position)
    }

    // Helper method to move a node to the front (most recently used position)
    moveToFront(node) {
        const [ prev, next ] = [ this.tail.prev, this.tail ]; // Get the previous and next nodes

        this.tail.prev.next = node; // Update the previous last node to point to the new node
        this.connectNode(node, { prev, next }); // Connect the new node to the previous and next nodes
        this.tail.prev = node; // Update the tail's previous pointer to the new node
    }

    // Helper method to connect a node between two nodes
    connectNode(node, top) {
        node.prev = top.prev; // Set the previous pointer of the node
        node.next = top.next; // Set the next pointer of the node
    }

    // Method to get the value of a key from the cache
    get(key) {
        const hasKey = this.map.has(key); // Check if the key exists in the map
        if (!hasKey) return -1; // If not, return -1

        const node = this.map.get(key); // Get the node from the map
        
        this.disconnectNode(node); // Disconnect the node from its current position
        this.moveToFront(node); // Move the node to the front (most recently used position)

        return node.value; // Return the value of the node
    }

    // Helper method to disconnect a node from the doubly linked list
    disconnectNode(node) {
        node.next.prev = node.prev; // Update the next node's previous pointer
        node.prev.next = node.next; // Update the previous node's next pointer
    }
}
```

## Go
```
// Node represents a node in the doubly linked list
type Node struct {
    key  int
    val  int
    prev *Node
    next *Node
}

// LRUCache represents the LRU Cache
type LRUCache struct {
    capacity int            // Maximum capacity of the cache
    cache    map[int]*Node  // Map to store the key-node pairs
    left     *Node          // Dummy head node
    right    *Node          // Dummy tail node
}

// Constructor initializes the LRUCache with the given capacity
func Constructor(capacity int) LRUCache {
    ret := LRUCache{
        capacity: capacity,
        cache:    make(map[int]*Node),
        left:     &Node{key: 0, val: 0},
        right:    &Node{key: 0, val: 0},
    }
    ret.left.next, ret.right.prev = ret.right, ret.left // Initialize the doubly linked list with dummy head and tail
    return ret
}

// Remove removes a node from the doubly linked list
func (this *LRUCache) Remove(node *Node) {
    prev, nxt := node.prev, node.next
    prev.next, nxt.prev = nxt, prev // Update the pointers of the adjacent nodes
}

// Insert inserts a node at the right end (most recently used position) of the doubly linked list
func (this *LRUCache) Insert(node *Node) {
    prev, nxt := this.right.prev, this.right
    nxt.prev = node
    prev.next = nxt.prev
    node.next, node.prev = nxt, prev // Connect the new node between the previous last node and the tail
}

// Get retrieves the value of the key from the cache
func (this *LRUCache) Get(key int) int {
    if _, ok := this.cache[key]; ok { // Check if the key exists in the cache
        this.Remove(this.cache[key])  // Remove the node from its current position
        this.Insert(this.cache[key])  // Move the node to the front (most recently used position)
        return this.cache[key].val    // Return the value of the node
    }
    return -1 // If the key does not exist, return -1
}

// Put adds a key-value pair to the cache
func (this *LRUCache) Put(key int, value int) {
    if _, ok := this.cache[key]; ok { // If the key already exists
        this.Remove(this.cache[key])  // Remove the existing node
    }
    this.cache[key] = &Node{key: key, val: value} // Create a new node and add it to the cache
    this.Insert(this.cache[key])                  // Move the new node to the front (most recently used position)

    if len(this.cache) > this.capacity { // If the cache is at capacity
        lru := this.left.next            // Get the least recently used node (next node of dummy head)
        this.Remove(lru)                 // Remove the LRU node from the list
        delete(this.cache, lru.key)      // Delete the LRU node from the map
    }
}
```
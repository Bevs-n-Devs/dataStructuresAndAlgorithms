Tries 1
# Implement Trie Prefix Tree
## Company: Microsoft
### Level: Medium

A [trie](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

***Break It Down For Me...***
*A trie (pronounced "try") is a special type of tree used to store and find strings quickly. It's useful for things like autocomplete and spellcheck.*
*You need to create a Trie class with the following features:*

- **Initialize the trie:** *Create an empty trie.*
- **Insert a word:** *Add a word to the trie.*
- **Search for a word:** *Check if a word is in the trie. Return true if it is, and false if it isn't.*
- **Check for a prefix:** *See if there is any word in the trie that starts with a given prefix. Return true if there is, and false if there isn't.*

Click [here](https://leetcode.com/problems/implement-trie-prefix-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=oobqoCJlHA0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Trie](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/#:~:text=A%20Trie%20is%20a%20special,parent%20node%20to%20its%20children.) data structure in Python, JavaScript and Go.


### Example 1
```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
```

**Explanation**
```
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

## Python
```
class TrieNode:
    def __init__(self):
        # Initialize a node with 26 children (one for each letter) and a boolean to mark the end of a word
        self.children = [None] * 26
        self.end = False

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # Initialize the trie with a root node
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        # Start from the root node
        curr = self.root
        # Traverse each character in the word
        for c in word:
            # Calculate the index of the character (0-25 for 'a'-'z')
            i = ord(c) - ord("a")
            # If the child node for this character doesn't exist, create it
            if curr.children[i] == None:
                curr.children[i] = TrieNode()
            # Move to the child node
            curr = curr.children[i]
        # Mark the end of the word
        curr.end = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        # Start from the root node
        curr = self.root
        # Traverse each character in the word
        for c in word:
            # Calculate the index of the character
            i = ord(c) - ord("a")
            # If the child node for this character doesn't exist, the word is not in the trie
            if curr.children[i] == None:
                return False
            # Move to the child node
            curr = curr.children[i]
        # Return True if we are at the end of a word, otherwise False
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        # Start from the root node
        curr = self.root
        # Traverse each character in the prefix
        for c in prefix:
            # Calculate the index of the character
            i = ord(c) - ord("a")
            # If the child node for this character doesn't exist, there is no word with this prefix
            if curr.children[i] == None:
                return False
            # Move to the child node
            curr = curr.children[i]
        # If we've successfully traversed the prefix, return True
        return True
```

## JavaScript
```
class TrieNode {
    constructor() {
        // Each node has a children object to store child nodes and a boolean to mark the end of a word
        this.children = {};
        this.isWord = false;
    }
}

class Trie {
    constructor() {
        // Initialize the trie with a root node
        this.root = new TrieNode();
    }

    /* Time O(N) | Space O(N) */
    insert(word, node = this.root) {
        // Traverse each character in the word
        for (const char of word) {
            // Get the child node for the character, or create a new one if it doesn't exist
            const child = node.children[char] || new TrieNode();

            // Set the child node in the children object
            node.children[char] = child;

            // Move to the child node
            node = child;
        }

        // Mark the end of the word
        node.isWord = true;
    }

    /* Time O(N) | Space O(1) */
    search(word, node = this.root) {
        // Traverse each character in the word
        for (const char of word) {
            // Get the child node for the character, or null if it doesn't exist
            const child = node.children[char] || null;

            // If the child node doesn't exist, the word is not in the trie
            if (!child) return false;

            // Move to the child node
            node = child;
        }

        // Return true if we are at the end of a word, otherwise false
        return node.isWord;
    }

    /* Time O(N) | Space O(1) */
    startsWith(prefix, node = this.root) {
        // Traverse each character in the prefix
        for (const char of prefix) {
            // Get the child node for the character, or null if it doesn't exist
            const child = node.children[char] || null;

            // If the child node doesn't exist, there is no word with this prefix
            if (!child) return false;

            // Move to the child node
            node = child;
        }

        // If we've successfully traversed the prefix, return true
        return true;
    }
}
```

## Go
```
type Trie struct {
	children  [26]*Trie // Array to store references to child nodes for each letter a-z
	endOfWord bool      // Boolean to mark the end of a word
	root      *Trie     // Pointer to the root node of the Trie
}

// Constructor initializes the Trie with an empty root node
func Constructor() Trie {
	return Trie{
		children:  [26]*Trie{},
		endOfWord: false,
		root:      &Trie{}}
}

// Insert adds a word to the Trie
func (this *Trie) Insert(word string) {
	cur := this.root // Start from the root node

	for i := 0; i < len(word); i++ {
		index := word[i] - 'a' // Calculate the index for the current character
		if cur.children[index] == nil {
			cur.children[index] = &Trie{} // Create a new node if it doesn't exist
		}
		cur = cur.children[index] // Move to the child node
	}

	cur.endOfWord = true // Mark the end of the word
}

// Search checks if a word is in the Trie
func (this *Trie) Search(word string) bool {
	cur := this.root // Start from the root node

	for i := 0; i < len(word); i++ {
		index := word[i] - 'a' // Calculate the index for the current character
		if cur.children[index] == nil {
			return false // Return false if the child node doesn't exist
		}
		cur = cur.children[index] // Move to the child node
	}

	return cur.endOfWord // Return true if it's the end of a word, otherwise false
}

// StartsWith checks if there is any word in the Trie that starts with the given prefix
func (this *Trie) StartsWith(prefix string) bool {
	cur := this.root // Start from the root node

	for i := 0; i < len(prefix); i++ {
		index := prefix[i] - 'a' // Calculate the index for the current character
		if cur.children[index] == nil {
			return false // Return false if the child node doesn't exist
		}
		cur = cur.children[index] // Move to the child node
	}

	return true // Return true if we've successfully traversed the prefix
}
```
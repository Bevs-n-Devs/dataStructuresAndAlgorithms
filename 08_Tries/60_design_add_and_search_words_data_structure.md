Tries 2
# Design Add and Search Data Structure
## Company: Google
### Level: Medium

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

- `WordDictionary()` Initializes the object.
- `void addWord(word)` Adds `word` to the data structure, it can be matched later.
- `bool search(word)` Returns `true` if there is any string in the data structure that matches `word` or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.*

***Break It Down For Me...***
*We need to create a system where you can add words and later check if any of the added words match a given word. The given word can have dots ('.') which can be any letter.*
- *`WordDictionary()`: This is a special function to set up the system.*
- *`addWord(word)`: This function adds a word to the system so you can search for it later.*
- *`search(word)`: This function checks if a word is in the system. The word can have dots ('.') which can stand for any letter. It returns true if the word is found and false if it isn't.*

Click [here](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=BTf05gs_8iU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Trie](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/#:~:text=A%20Trie%20is%20a%20special,parent%20node%20to%20its%20children.) data structure in Python, JavaScript and Go.

### Example 1
```
Input
["WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"]
[[], ["bad"], ["dad"], ["mad"], ["pad"], ["bad"], [".ad"], ["b.."]]

Output
[null, null, null, null, false, true, true, true]
```

## Python
```
class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to hold child nodes (e.g., 'a': TrieNode)
        self.word = False  # Boolean to indicate if a word ends at this node


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()  # Initialize the root of the Trie

    def addWord(self, word: str) -> None:
        """
        Adds a word to the trie.
        """
        cur = self.root  # Start from the root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()  # Create a new TrieNode if it doesn't exist
            cur = cur.children[c]  # Move to the child node
        cur.word = True  # Mark the end of the word

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie. 
        A word can contain '.' which can match any letter.
        """
        def dfs(j, root):
            """
            Depth-first search helper function.
            """
            cur = root  # Start from the given root node

            for i in range(j, len(word)):
                c = word[i]
                if c == ".":  # If the current character is '.', it can match any letter
                    for child in cur.children.values():  # Check all possible children
                        if dfs(i + 1, child):  # Continue DFS from the next character
                            return True
                    return False  # If no paths match, return False
                else:
                    if c not in cur.children:  # If the character is not found, return False
                        return False
                    cur = cur.children[c]  # Move to the child node
            return cur.word  # Return True if it's the end of a word

        return dfs(0, self.root)  # Start DFS from the root and the first character
```

## JavaScript
```
/**
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = new WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */

class TrieNode {
    constructor() {
        this.children = {};  // Dictionary to hold child nodes
        this.isWord = false;  // Boolean to indicate if a word ends at this node
    }
}

class WordDictionary {
    constructor() {
        this.root = new TrieNode();  // Initialize the root of the Trie
    }

    /* Time O(N) | Space O(N) */
    addWord(word, node = this.root) {
        // Iterate through each character in the word
        for (const char of word) {
            // Get the child node corresponding to the current character
            const child = node.children[char] || new TrieNode();

            // If the child node doesn't exist, create it
            node.children[char] = child;

            // Move to the child node
            node = child;
        }

        // Mark the end of the word
        node.isWord = true;
    }

    /* Time O(N) | Space O(N) */
    search(word) {
        // Start DFS search from the root and the first character
        return this.dfs(word, this.root, 0);
    }

    dfs(word, node, level) {
        // Base case: If the current node is null, return false
        if (!node) return false;

        // If we have reached the end of the word, check if it's a valid word
        const isWord = level === word.length;
        if (isWord) return node.isWord;

        // If the current character is a wildcard '.', check all possible children
        const isWildCard = word[level] === '.';
        if (isWildCard) return this.hasWildCard(word, node, level);

        // Move to the next character in the word and the corresponding child node
        return this.dfs(word, node.children[word[level]], level + 1);
    }

    hasWildCard(word, node, level) {
        // Iterate through all children of the current node
        for (const char of Object.keys(node.children)) {
            const child = node.children[char];

            // Continue DFS from the next character
            const hasWord = this.dfs(word, child, level + 1);
            if (hasWord) return true;
        }

        // If no paths match, return false
        return false;
    }
}
```

## Go
```
type TrieNode struct {
    children map[byte]*TrieNode // Map to hold child nodes
    word     bool               // Boolean to indicate if a word ends at this node
}

type WordDictionary struct {
    root *TrieNode // Root node of the Trie
}

// Constructor initializes the WordDictionary with an empty root node
func Constructor() WordDictionary {
    return WordDictionary{root: &TrieNode{children: make(map[byte]*TrieNode)}}
}

// AddWord inserts a word into the Trie
func (this *WordDictionary) AddWord(word string) {
    cur := this.root
    for c := 0; c < len(word); c++ {
        // If the current character is not a child, create a new TrieNode
        if _, ok := cur.children[word[c]]; !ok {
            cur.children[word[c]] = &TrieNode{children: make(map[byte]*TrieNode)}
        }
        // Move to the child node
        cur = cur.children[word[c]]
    }
    // Mark the end of the word
    cur.word = true
}

// Search looks for a word in the Trie, supporting '.' as a wildcard character
func (this *WordDictionary) Search(word string) bool {
    // Define a DFS function to handle the search
    var dfs func(int, *TrieNode) bool
    dfs = func(j int, root *TrieNode) bool {
        cur := root
        
        // Iterate through each character starting from position j
        for i := j; i < len(word); i++ {
            c := word[i]
            if c == '.' { // If the character is a wildcard
                // Recursively search all possible paths
                for _, child := range cur.children {
                    if dfs(i + 1, child) {
                        return true
                    }
                }
                return false
            } else { // If the character is not a wildcard
                // Check if the character exists in the current node's children
                if _, ok := cur.children[c]; !ok {
                    return false
                }
                // Move to the child node
                cur = cur.children[c]
            }
        }
        // Return true if the end of the word is reached
        return cur.word
    }
    
    // Start the DFS search from the root and the first character
    return dfs(0, this.root)
}
```
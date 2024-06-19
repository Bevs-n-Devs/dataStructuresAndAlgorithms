Tries 3
# Word Search 2
## Company: Meta
### Level: Hard

Given an `m x n` `board` of characters and a list of strings `words`, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

***Break It Down For Me...***
**

Click [here](https://leetcode.com/problems/word-search-ii/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=asbcE9mZz_U) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Trie](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/#:~:text=A%20Trie%20is%20a%20special,parent%20node%20to%20its%20children.) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)
```
Input: board = [["o","a","a","n"], ["e","t","a","e"], ["i","h","k","r"], ["i","f","l","v"]], words = ["oath", "pea", "eat", "rain"]
Output: ["eat", "oath"]
```

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)
```
Input: board = [["a","b"], ["c","d"]], words = ["abcb"]
Output: []
```

## Python
```
class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to hold child nodes
        self.isWord = False  # Boolean to indicate if a word ends at this node
        self.refs = 0  # Reference count to track how many words pass through this node

    def addWord(self, word):
        cur = self
        cur.refs += 1  # Increase reference count for the root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()  # Create a new TrieNode if character not present
            cur = cur.children[c]
            cur.refs += 1  # Increase reference count for each character in the word
        cur.isWord = True  # Mark the end of the word

    def removeWord(self, word):
        cur = self
        cur.refs -= 1  # Decrease reference count for the root
        for c in word:
            if c in cur.children:
                cur = cur.children[c]
                cur.refs -= 1  # Decrease reference count for each character in the word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for w in words:
            root.addWord(w)  # Add each word to the Trie

        ROWS, COLS = len(board), len(board[0])  # Dimensions of the board
        res, visit = set(), set()  # Set for results and visited positions

        def dfs(r, c, node, word):
            # Base case for DFS: check if position is out of bounds, character not in Trie, no refs, or already visited
            if (
                r not in range(ROWS) 
                or c not in range(COLS)
                or board[r][c] not in node.children
                or node.children[board[r][c]].refs < 1
                or (r, c) in visit
            ):
                return

            visit.add((r, c))  # Mark the cell as visited
            node = node.children[board[r][c]]  # Move to the next node in the Trie
            word += board[r][c]  # Add character to current word
            if node.isWord:
                node.isWord = False  # Avoid duplicate entries
                res.add(word)  # Add the word to the result set
                root.removeWord(word)  # Remove the word from the Trie

            # Explore all four directions
            dfs(r + 1, c, node, word)
            dfs(r - 1, c, node, word)
            dfs(r, c + 1, node, word)
            dfs(r, c - 1, node, word)
            visit.remove((r, c))  # Unmark the cell as visited

        # Start DFS from each cell in the board
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root, "")

        return list(res)  # Convert the result set to a list

```

## JavaScript
```
/**
 * @param {character[][]} board
 * @param {string[]} words
 * Time O((ROWS * COLS) * (4 * (3 ^ (WORDS - 1)))) | Space O(N)
 * @return {string[]}
 */
var findWords = function (board, words) {
    // Create a Trie with the given words and search the board
    return new Trie(words).searchBoard(board);
};

class TrieNode {
    constructor() {
        this.children = {};  // Dictionary to hold child nodes
        this.word = '';  // To store the complete word if a word ends at this node
    }
}

class Trie {
    constructor(words) {
        this.root = new TrieNode();  // Root node of the Trie
        words.forEach((word) => this.insert(word));  // Insert each word into the Trie
    }

    /* Time O(N) | Space O(N) */
    insert(word, node = this.root) {
        // Insert a word into the Trie
        for (const char of word) {
            const child = node.children[char] || new TrieNode();

            node.children[char] = child;  // Link the child node

            node = child;  // Move to the child node
        }

        node.word = word;  // Mark the end of the word
    }

    /* Time O((ROWS * COLS) * (4 * (3 ^ (WORDS - 1)))) | Space O(N) */
    searchBoard(board, node = this.root, words = []) {
        const [rows, cols] = [board.length, board[0].length];  // Get the number of rows and columns in the board

        // Traverse each cell in the board
        for (let row = 0; row < rows; row++) {
            for (let col = 0; col < cols; col++) {
                this.dfs(board, row, rows, col, cols, node, words);  // Perform DFS starting from the cell
            }
        }

        return words;  // Return the found words
    }

    dfs(board, row, rows, col, cols, node, words) {
        const char = board[row][col];
        const child = node.children[char] || null;

        if (this.canSkip(char, child)) return;  // Skip if the cell is already visited or no child node

        node = child;
        this.checkWord(node, words);  // Check if the current node marks the end of a word
        this.backTrack(board, row, rows, col, cols, node, words);  // Continue the DFS search
    }

    canSkip(char, child) {
        const hasSeen = char === '#';  // Check if the cell is already visited
        const isMissingChild = !child;  // Check if there is no child node

        return hasSeen || isMissingChild;
    }

    checkWord(node, words) {
        if (!node.word.length) return;  // If the node doesn't mark the end of a word, return

        words.push(node.word);  // Add the word to the result
        node.word = '';  // Clear the word to avoid duplicate entries
    }

    backTrack(board, row, rows, col, cols, node, words) {
        const char = board[row][col];

        board[row][col] = '#';  // Mark the cell as visited

        // Explore the neighbors (up, down, left, right)
        for (const [_row, _col] of this.getNeighbors(row, rows, col, cols)) {
            this.dfs(board, _row, rows, _col, cols, node, words);
        }

        board[row][col] = char;  // Unmark the cell as visited
    }

    getNeighbors(row, rows, col, cols) {
        // Get the neighboring cells
        return [
            [row - 1, col],  // Up
            [row + 1, col],  // Down
            [row, col - 1],  // Left
            [row, col + 1],  // Right
        ].filter(([_row, _col]) => !this.isOutOfBounds(_row, rows, _col, cols));
    }

    isOutOfBounds(row, rows, col, cols) {
        // Check if the row or column is out of bounds
        const isRowOut = row < 0 || rows <= row;
        const isColOut = col < 0 || cols <= col;

        return isRowOut || isColOut;
    }
}
```

## Go
```
type TrieNode struct {
    children map[byte]*TrieNode  // Maps each character to the corresponding child TrieNode
    isWord bool  // Indicates if the node represents the end of a word
    refs int  // Keeps track of references to help with removing words
}

// Adds a word to the Trie
func (this *TrieNode) addWord(word string) {
    cur := this
    cur.refs += 1  // Increment reference count
    for c := 0; c < len(word); c++ {
        if _, ok := cur.children[word[c]]; !ok {
            cur.children[word[c]] = &TrieNode{children: make(map[byte]*TrieNode)}
        }
        cur = cur.children[word[c]]
        cur.refs += 1  // Increment reference count for each character
    }
    cur.isWord = true  // Mark the end of the word
}

// Removes a word from the Trie
func (this *TrieNode) removeWord(word string) {
    cur := this
    cur.refs -= 1  // Decrement reference count
    for c := 0; c < len(word); c++ {
        if _, ok := cur.children[word[c]]; ok {
            cur = cur.children[word[c]]
            cur.refs -= 1  // Decrement reference count for each character
        }
    }
}

// Finds all words from the list that are present in the board
func findWords(board [][]byte, words []string) []string {
    root := &TrieNode{children: make(map[byte]*TrieNode)}
    for _, w := range words {
        root.addWord(w)  // Add each word to the Trie
    }

    ROWS, COLS := len(board), len(board[0])
    res := make(map[string]bool)  // Store the result words
    visit := make(map[int]bool)  // Track visited cells

    // Depth-first search function
    var dfs func(int, int, *TrieNode, string)
    dfs = func(r, c int, node *TrieNode, word string) {
        // Boundary and condition checks
        if r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            node.children[board[r][c]] == nil || node.children[board[r][c]].refs < 1 ||
            visit[r*COLS + c] {
            return
        }

        visit[r*COLS + c] = true  // Mark the cell as visited
        node = node.children[board[r][c]]
        word += string(board[r][c])
        if node.isWord {
            node.isWord = false  // Avoid duplicate entries
            res[word] = true  // Add word to result
            root.removeWord(word)  // Remove word from Trie to avoid reuse
        }

        // Explore neighboring cells
        dfs(r + 1, c, node, word)  // Down
        dfs(r - 1, c, node, word)  // Up
        dfs(r, c + 1, node, word)  // Right
        dfs(r, c - 1, node, word)  // Left
        visit[r*COLS + c] = false  // Unmark the cell
    }

    // Start DFS from each cell
    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            dfs(r, c, root, "")
        }
    }
    return list(res)  // Convert result map to list
}

// Helper function to convert map keys to a list
func list(mapping map[string]bool) []string {
    res := make([]string, 0, len(mapping))
    for key := range mapping {
        res = append(res, key)
    }
    return res
}
```
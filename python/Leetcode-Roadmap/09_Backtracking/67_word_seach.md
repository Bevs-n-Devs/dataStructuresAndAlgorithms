Backtracking 6
# Word Search
## Company: Meta
### Level: Medium

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

***Break It Down For Me...***
*We have a grid of letters (like a table with rows and columns) called board, and also a word that we need to find in the grid.*
*The task is to check if we can find the word in the grid by moving through letters that are next to each other.*
*We can move up, down, left, or right, but we can't use the same letter cell more than once.*
*If we can find the word in the grid, return true. If you can't, return false.*

Click [here](https://leetcode.com/problems/word-search/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=pfiQ_PS1g8E) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)
```
Input: board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "ABCCED"
Output: true
```

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)
```
Input: board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "SEE"
Output: true
```

### Example 3
![Example 3 Image](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)
```
Input: board = [["A", "B", "C", "E"],["S", "F", "C", "S"],["A", "D", "E", "E"]], word = "ABCB"
Output: false
```


## Python
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # Get the number of rows and columns in the board
        ROWS, COLS = len(board), len(board[0])
        path = set()  # To keep track of the visited cells

        def dfs(r, c, i):
            # If the whole word is found, return True
            if i == len(word):
                return True
            # Check boundaries, current character match, and if the cell is already visited
            if (
                min(r, c) < 0
                or r >= ROWS
                or c >= COLS
                or word[i] != board[r][c]
                or (r, c) in path
            ):
                return False
            # Mark the cell as visited
            path.add((r, c))
            # Move to the next cell in all four possible directions
            res = (
                dfs(r + 1, c, i + 1)
                or dfs(r - 1, c, i + 1)
                or dfs(r, c + 1, i + 1)
                or dfs(r, c - 1, i + 1)
            )
            # Unmark the cell as visited
            path.remove((r, c))
            return res

        # To improve performance, reverse the word if the first letter is more frequent than the last
        count = defaultdict(int, sum(map(Counter, board), Counter()))
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]
            
        # Start the search from every cell in the board
        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
        return False
```

## JavaScript
```
var exist = function(board, word) {
    // Start the search from every cell in the board
    for(let row = 0; row < board.length; row++) {
        for(let col = 0; col < board[0].length; col++){
            // If the word is found, return true
            if (dfs(board, row, col, word, 0)) return true;
        }
    }
    // If the word is not found, return false
    return false;
}

const dfs = (board, row, col, word, index) => {
    // If the whole word is found, return true
    if (index === word.length) return true;
    // Check boundaries and current character match
    if (isOutOfBound(board, row, col) || board[row][col] !== word[index]) return false;
        
    board[row][col] = '*';  // Mark the cell as visited
    
    // Move to the next cell in all four possible directions
    const hasWord = Object
        .values(directions(row, col))
        .filter(([r, c]) => dfs(board, r, c, word, index + 1))
        .length;
    
    board[row][col] = word[index];  // Unmark the cell as visited
    return hasWord;
}

const isOutOfBound = (board, row, col) => {
    const isRowOutOfBound = row < 0 || board.length - 1 < row;
    const isColOutOfBound = col < 0 || board[0].length - 1 < col;
    return isRowOutOfBound || isColOutOfBound;
}

const directions = (row, col) => ({
    up: [row - 1, col],
    down: [row + 1, col],
    left: [row, col - 1],
    right: [row, col + 1]
});
```

## Go
```
package main

func exist(board [][]byte, word string) bool {
	n := len(board)    // Number of rows
	m := len(board[0]) // Number of columns

	// Depth-First Search function
	var dfs func(i int, j int, curr int) bool
	dfs = func(i int, j int, curr int) bool {
		// If out of bounds or current character doesn't match, return false
		if i < 0 || j < 0 || i >= n || j >= m || curr == len(word) {
			return false
		}
		if board[i][j] != word[curr] || board[i][j] == '*' {
			return false
		}
		// If all characters are found, return true
		if curr == len(word)-1 {
			return true
		}

		tmp := board[i][j]  // Temporarily mark the cell as visited
		board[i][j] = '*'   // Mark the cell as visited

		// Move to the next cell in all four possible directions
		res := dfs(i+1, j, curr+1) || dfs(i-1, j, curr+1) || dfs(i, j-1, curr+1) || dfs(i, j+1, curr+1)

		board[i][j] = tmp  // Unmark the cell as visited

		return res
	}

	// Start the search from every cell in the board
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if dfs(i, j, 0) {
				return true
			}
		}
	}

	return false
}
```
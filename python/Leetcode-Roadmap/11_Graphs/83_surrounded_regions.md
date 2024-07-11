Graphs 7
# Surrounded Regions
## Company: Medium

You are given an `m x n` matrix `board` containing letters '`X`' and '`O`', capture regions that are surrounded:

- **Connect**: A cell is connected to adjacent cells horizontally or vertically.
- **Region**: To form a region connect every '`O`' cell.
- **Surround**: The region is surrounded with '`X`' cells if you can connect the region with '`X`' cells and none of the region cells are on the edge of the `board`.
A surrounded region is captured by replacing all '`O`'s with '`X`'s in the input matrix `board`.


***Braek It Down For Me...***
*We have a grid (a rectangle made up of rows and columns) with '`X`' and '`O`' letters.

- `X` *is like a wall.*
- `O` *is like an open space.*
*We want to change all '`O`'s that are completely surrounded by '`X`'s into '`X`'s.*

- *A cell (square) is connected to other cells directly up, down, left, or right.*
- *A region is a group of '`O`' cells connected together.*
- *A region is surrounded if you can draw a line of '`X`' cells all around it, and none of the 'O' cells in this region touch the edge of the grid.*
*If an '`O`' region is surrounded, change all '`O`'s in that region to '`X`'s in the grid.*


Click [here](https://leetcode.com/problems/surrounded-regions/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=9z2BunfoZ5Y) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python & JavaScript.

### Example 1
```
Input: board = [["X","X","X","X"], ["X","O","O","X"], ["X","X","O","X"], ["X","O","X","X"]]

Output: [["X","X","X","X"], ["X","X","X","X"], ["X","X","X","X"], ["X","O","X","X"]]
```
**Explanation:** 
![Example 1 Image](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)
In the diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

### Example 2
```
Input: board = [["X"]]

Output: [["X"]]
```

## Python
```
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        ROWS, COLS = len(board), len(board[0])

        # Helper function to perform DFS and mark connected 'O's
        def capture(r, c):
            # Base case: if out of bounds or the cell is not 'O', return
            if r < 0 or c < 0 or r == ROWS or c == COLS or board[r][c] != "O":
                return
            board[r][c] = "T"  # Mark the cell as temporarily captured
            # Recursively capture all connected 'O's in all four directions
            capture(r + 1, c)
            capture(r - 1, c)
            capture(r, c + 1)
            capture(r, c - 1)

        # 1. (DFS) Capture unsurrounded regions (O -> T)
        for r in range(ROWS):
            for c in range(COLS):
                # Start DFS from 'O's on the border to mark all connected 'O's
                if board[r][c] == "O" and (r in [0, ROWS - 1] or c in [0, COLS - 1]):
                    capture(r, c)

        # 2. Capture surrounded regions (O -> X)
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"  # Change all remaining 'O's to 'X'

        # 3. Uncapture unsurrounded regions (T -> O)
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "T":
                    board[r][c] = "O"  # Change all 'T's back to 'O'
```

## JavaScript
```
var solve = function solve(board) {
    // Search the rows for 'O's that are connected to the borders
    searchRows(board);  /* Time O(ROWS * COLS) | Space O(ROWS * COLS) */
    // Search the columns for 'O's that are connected to the borders
    searchCols(board);  /* Time O(ROWS * COLS) | Space O(ROWS * COLS) */
    // Search the entire grid to capture surrounded regions
    searchGrid(board);  /* Time O(ROWS * COLS) | Space O(ROWS * COLS) */
}

// Function to search rows for 'O's connected to the borders
var searchRows = (board) => {
    const [ rows, cols ] = [ board.length, board[0].length ];

    // Traverse each row
    for (let row = 0; row < rows; row++) {       /* Time O(ROWS) */
        // Perform DFS from the first and last columns of each row
        dfs(board, row, rows, 0, cols);          /* Space O(ROWS) */
        dfs(board, row, rows, (cols - 1), cols); /* Space O(ROWS) */
    }
}

// Function to search columns for 'O's connected to the borders
var searchCols = (board) => {
    const [ rows, cols ] = [ board.length, board[0].length ];

    // Traverse each column except the first and last columns
    for (let col = 1; col < (cols - 1); col++) { /* Time O(COLS) */
        // Perform DFS from the first and last rows of each column
        dfs(board, 0, rows, col, cols);          /* Space O(COLS) */
        dfs(board, (rows - 1), rows, col, cols); /* Space O(COLS) */
    }
}

// Function to search the entire grid and capture surrounded regions
var searchGrid = (board) => {
    const [ rows, cols ] = [ board.length, board[0].length ];

    // Traverse the entire grid
    for (let row = 0; row < rows; row++) {       /* Time O(ROWS) */
        for (let col = 0; col < cols; col++) {   /* Time O(COLS) */
            const isO = board[row][col] === 'O';
            if (isO) board[row][col] = 'X';  // Capture surrounded 'O' regions

            const isStar = board[row][col] === '*';
            if (isStar) board[row][col] = 'O'; // Restore 'O's that are connected to the border
        }
    }
}

// Depth-First Search (DFS) to mark 'O's connected to the border
const dfs = (board, row, rows, col, cols) => {
    const isBaseCase = board[row][col] !== 'O';
    if (isBaseCase) return; // Return if the cell is not 'O'

    board[row][col] = '*'; // Mark the cell as visited

    // Recursively visit all neighboring cells (up, down, left, right)
    for (const [ _row, _col ] of getNeighbors(row, rows, col, cols)) {
        dfs(board, _row, rows, _col, cols); /* Time O(HEIGHT) | Space O(HEIGHT) */
    }
}

// Function to get all valid neighboring cells
var getNeighbors = (row, rows, col, cols) => [ [0, 1], [0, -1], [1, 0], [-1, 0] ]
    .map(([ _row, _col ]) => [ (row + _row), (col + _col)])
    .filter(([ _row, _col ]) => (0 <= _row) && (_row < rows) && (0 <= _col) && (_col < cols));
```

## Go
```
func solve(board [][]byte) {
	m := len(board)    // Number of rows
	n := len(board[0]) // Number of columns

	// Perform DFS from the edges to find 'O's connected to the border
	for i := 0; i < n; i++ {
		dfs(board, 0, i)     // Top row
		dfs(board, m-1, i)   // Bottom row
	}

	for i := 0; i < m; i++ {
		dfs(board, i, 0)     // Left column
		dfs(board, i, n-1)   // Right column
	}

	// Process the board to capture surrounded regions
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X' // Capture surrounded 'O' regions
			}
			if board[i][j] == '*' {
				board[i][j] = 'O' // Restore 'O's that are connected to the border
			}
		}
	}
}

// Depth-First Search (DFS) to mark 'O's connected to the border
func dfs(board [][]byte, m int, n int) {
	// Check if the current cell is out of bounds or already processed
	if m < 0 || m >= len(board) || n < 0 || n >= len(board[0]) || board[m][n] == 'X' || board[m][n] == '*' {
		return
	}

	board[m][n] = '*' // Mark the cell as visited and part of the border-connected region

	// Recursively visit all neighboring cells (up, down, left, right)
	dfs(board, m+1, n) // Down
	dfs(board, m-1, n) // Up
	dfs(board, m, n+1) // Right
	dfs(board, m, n-1) // Left
}
```
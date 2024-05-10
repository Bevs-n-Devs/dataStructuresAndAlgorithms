// Function to check the validity of a Sudoku board
var isValidSudoku = (board) => {
    const [boards, cells] = [3, 9];
    const [boxes, rows, cols] = getBoards(boards, cells); /* Time O(ROWS * COLS) | Space O(CELLS) */

    return searchGrid(board, boxes, rows, cols); /* Time O(ROWS * COLS) | Space O(CELLS) */
}

// Helper function to initialize arrays for tracking numbers in each box, row, and column
var getBoards = (boards, cells) => new Array(boards).fill()
    .map(() => new Array(cells).fill(0));

// Helper function to search through the Sudoku grid and check for valid numbers
var searchGrid = (board, boxes, rows, cols) => {
    const [_rows, _cols] = [9, 9];

    for (let row = 0; row < _rows; row++) { /* Time O(ROWS)*/
        for (let col = 0; col < _cols; col++) { /* Time O(COLS)*/
            const char = board[row][col];
            const position = 1 << (char - 1);
            const index = (Math.floor(row / 3) * 3) + Math.floor(col / 3);

            const isEmpty = char === '.';
            if (isEmpty) continue;

            const hasMoved = (boxes[index] & position) || (cols[col] & position) || (rows[row] & position);
            if (hasMoved) return false;

            // Mark the position of the current number in the corresponding box, row, and column
            rows[row] |= position; /* Space O(CELLS)*/
            cols[col] |= position; /* Space O(CELLS)*/
            boxes[index] |= position; /* Space O(CELLS)*/
        }
    }

    // If the loop completes without finding conflicts, the Sudoku board is valid
    return true;
}

// implementation
console.log("Leetcode 36: Valid Sudoku\n");

// Example 1
example1 = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]];

console.log(`Example 1: board = [${example1}]`);
console.log("Output:", isValidSudoku(example1));

// Example 2
example2 = [["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]];

console.log(`Example 2: board = [${example2}]`);
console.log("Output:", isValidSudoku(example2));
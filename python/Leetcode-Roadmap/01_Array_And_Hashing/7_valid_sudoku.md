Arrays And Hashing 7
# Valid Sudoku
## Company: Amazon
### Level: Medium

Determine id a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules:**

1. Each row must contain the digits `1 -9` without repetition.
2. Each column must contain the digits `1 - 9` without repitition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits without repitition.

**Note:**
- A Soduko board (partially filled) could be valid but is not necessarily solvable.
- Only the cells need to be validated to the mentioned rules.


***Break It Down For Me...***
*We have a Sudoku game and we have to check if the numbers on the board stick to Sudoku rules.*
*Each Sudoku cell must be 3 x 3 and the numbers have to be between 1 - 9, but we can't repeat the numbers.*


Click [here](https://leetcode.com/problems/valid-sudoku/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=TjFXEUCMqI8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challange we will use a **[Hash Map](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used)** in the Python, JavaScript and Go solution.


# Example 1
Input:
```
board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```
Input: `true`

# Example 2
Input:
```
board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```
Output: `false`

Explanation: Same as Example 1, except with the `5` in the top left corner being modiefied to `8`. 
Since there two 8's in the top left 3x3 sub-box, it is invalid.

# Python
```
cols = collections.defaultdict(set)
rows = collections.defaultdict(set)
squares = collections.defaultdict(set)  # key = (r // 3, c // 3)

for r in range(9):
    for c in range(9):

        if board[r][c] == ".":
            continue

        if (
            board[r][c] in rows[r]
            or board[r][c] in cols[c]
            or board[r][c] in squares[(r // 3, c // 3)]
        ):
            return False

        cols[c].add(board[r][c])
        rows[r].add(board[r][c])
        squares[(r // 3, c // 3)].add(board[r][c])

return True

# Code comments can be found in valid_sudoku.py
```
# JavaScript
```
var isValidSudoku = (board) => {
    const [boards, cells] = [3, 9];
    const [boxes, rows, cols] = getBoards(boards, cells); 

    return searchGrid(board, boxes, rows, cols);
}

var getBoards = (boards, cells) => new Array(boards).fill()
    .map(() => new Array(cells).fill(0));

var searchGrid = (board, boxes, rows, cols) => {
    const [_rows, _cols] = [9, 9];

    for (let row = 0; row < _rows; row++) { 
        for (let col = 0; col < _cols; col++) {
            const char = board[row][col];
            const position = 1 << (char - 1);
            const index = (Math.floor(row / 3) * 3) + Math.floor(col / 3);

            const isEmpty = char === '.';
            if (isEmpty) continue;

            const hasMoved = (boxes[index] & position) || (cols[col] & position) || (rows[row] & position);
            if (hasMoved) return false;

            rows[row] |= position;
            cols[col] |= position;
            boxes[index] |= position;
        }
    }

    return true;
}

// Code comments can be found in valid_sudoku.js
```

# Go
```
hashMap := make(map[string]bool)

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {

			row := i
			column := j

			current_val := string(board[i][j])

			if current_val == "." {
				continue
			}
			_, ok1 := hashMap[current_val+"found in row"+string(row)]
			_, ok2 := hashMap[current_val+"found in column"+string(column)]
			_, ok3 := hashMap[current_val+"found in grid"+string(i/3)+"-"+string(j/3)]

			if ok1 || ok2 || ok3 {

				return false
			} else {
				hashMap[current_val+"found in row"+string(row)] = true
				hashMap[current_val+"found in column"+string(column)] = true
				hashMap[current_val+"found in grid"+string(i/3)+"-"+string(j/3)] = true
			}
		}

	}
	return true
```
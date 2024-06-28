Backtracking 9
# N Queens
## Company: Meta
### Level: Hard

The n-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return all distinct solutions to the **n-queens puzzle.** You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

***Break It Down For Me...***
*You have a puzzle called the n-queens puzzle. The goal is to place n queens on a chessboard that is n rows by n columns. You need to place the queens in such a way that no two queens can attack each other. Queens can attack other pieces that are in the same row, column, or diagonal.

Given a number n, find all the possible ways to place the queens on the board. Return the solutions in any order.

Each solution should show the board with 'Q' for a queen and '.' for an empty space.*

Click [here](https://leetcode.com/problems/n-queens/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Ph95IHmRp5M) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

## Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)
```
Input: n = 4
Output: [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
```
**Explanation:** There exist two distinct solutions to the 4-queens puzzle above.

## Example 2
```
Input: n = 1
Output: [["Q"]]
```

### Python
```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = set()  # Columns where queens are placed
        posDiag = set()  # Positive diagonals (r + c)
        negDiag = set()  # Negative diagonals (r - c)

        res = []  # List to store the result boards
        board = [["."] * n for i in range(n)]  # Initialize an empty n x n board

        def backtrack(r):
            if r == n:  # If all rows are filled, add the board to results
                copy = ["".join(row) for row in board]
                res.append(copy)
                return

            for c in range(n):
                # Skip if a queen can attack on the column, positive diagonal, or negative diagonal
                if c in col or (r + c) in posDiag or (r - c) in negDiag:
                    continue

                # Place the queen
                col.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"

                # Move to the next row
                backtrack(r + 1)

                # Remove the queen (backtrack)
                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backtrack(0)  # Start from the first row
        return res
```

### JavaScript
```
function solveNQueens(n, colSet = new Set(), posDiagSet = new Set(), negDiagSet = new Set()) {
    const board = new Array(n).fill().map(() => new Array(n).fill('.'));  // Initialize an empty n x n board

    return dfs(board, n, colSet, posDiagSet, negDiagSet);
}

const dfs = (board, n, colSet, posDiagSet, negDiagSet, row = 0, moves = []) => {
    const isBaseCase = row === n;
    if (isBaseCase) {
        const rows = board.map((_row) => _row.join(''))  // Convert board to strings
        moves.push(rows);
        return moves;
    }

    for (let col = 0; col < n; col++) {
        const hasQueen = colSet.has(col) || posDiagSet.has(row + col) || negDiagSet.has(row - col)
        if (hasQueen) continue;  // Skip if a queen can attack

        backTrack(board, n, row, col, colSet, posDiagSet, negDiagSet, moves);
    }

    return moves
}

const backTrack = (board, n, row, col, colSet, posDiagSet, negDiagSet, moves) => {
    // Place the queen
    colSet.add(col);
    posDiagSet.add(row + col);
    negDiagSet.add(row - col);
    board[row][col] = "Q";

    // Move to the next row
    dfs(board, n, colSet, posDiagSet, negDiagSet, (row + 1), moves);

    // Remove the queen (backtrack)
    colSet.delete(col);
    posDiagSet.delete(row + col);
    negDiagSet.delete(row - col);
    board[row][col] = ".";
}
```

### Go
```
package main

func solveNQueens(n int) [][]string {
    ans, curr := make([][]string, 0), make([]string, 0)
    column, diag1, diag2 := make(map[int]int), make(map[int]int), make(map[int]int)
    
    var backtrack func(y int)
    backtrack = func(y int) {
        if y == n {  // If all rows are filled, add the board to results
            ans = append(ans, append([]string{}, curr...))
        }
        for x := 0; x < n; x++ {
            // Skip if a queen can attack on the column, positive diagonal, or negative diagonal
            if column[x] > 0 || diag1[x+y] > 0 || diag2[n+x-y-1] > 0 {
                continue
            }
            // Place the queen
            column[x], diag1[x+y], diag2[n+x-y-1] = 1, 1, 1
            s := ""
            for i := 0; i < n; i++ {
                if i == x {
                    s += "Q"
                } else {
                    s += "."
                }
            }
            curr = append(curr, s)
            backtrack(y + 1)
            // Remove the queen (backtrack)
            column[x], diag1[x+y], diag2[n+x-y-1] = 0, 0, 0
            curr = curr[:len(curr)-1]
        }
    }
    backtrack(0)  // Start from the first row
    return ans
}
```
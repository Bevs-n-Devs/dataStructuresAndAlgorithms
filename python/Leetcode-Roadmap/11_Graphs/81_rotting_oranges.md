Graphs 5
# Rotting Oranges
## Company: 
### Level:

You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

***Break It Down DFor Me...***
*We are given a grid (a 2D array) with m rows and n columns. Each cell in the grid can be one of three things:*

- `0` *- an empty cell*
- `1` *- a fresh orange*
- `2` *- a rotten orange*
*Every minute, any fresh orange that is directly next to (up, down, left, or right) a rotten orange will become rotten.*

*Our task is to find the minimum number of minutes it will take for all the fresh oranges to become rotten. If it is not possible for all fresh oranges to become rotten, return `-1`.*

Click [here](https://leetcode.com/problems/rotting-oranges/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=y704fEOx0s0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python & JavaScript.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)
```
Input: grid = [[2,1,1], [1,1,0], [0,1,1]]
Output: 4
```

### Example 2
```
Input: grid = [[2,1,1], [0,1,1], [1,0,1]]
Output: -1
```
**Explanation:** The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

### Example 3
```
Input: grid = [[0, 2]]
Output: 0
```
**Explanation:** Since there are already no fresh oranges at minute 0, the answer is just `0`.

### Python
```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = collections.deque()  # Queue to perform BFS
        fresh = 0  # Counter for fresh oranges
        time = 0  # Timer to track minutes elapsed

        # Loop through the grid to count fresh oranges and add rotten oranges to the queue
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:  # Count fresh oranges
                    fresh += 1
                if grid[r][c] == 2:  # Add rotten oranges to the queue
                    q.append((r, c))

        # Possible directions for adjacent cells (right, left, down, up)
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        # BFS to rot adjacent fresh oranges
        while fresh > 0 and q:  # Continue while there are fresh oranges and the queue is not empty
            length = len(q)  # Number of rotten oranges to process in this minute
            for i in range(length):
                r, c = q.popleft()  # Get the position of the current rotten orange

                # Check all four possible directions
                for dr, dc in directions:
                    row, col = r + dr, c + dc
                    # If the adjacent cell is within bounds and is a fresh orange, rot it
                    if (
                        row in range(len(grid))
                        and col in range(len(grid[0]))
                        and grid[row][col] == 1
                    ):
                        grid[row][col] = 2  # Rot the fresh orange
                        q.append((row, col))  # Add the newly rotten orange to the queue
                        fresh -= 1  # Decrease the count of fresh oranges
            time += 1  # Increment the time after processing all current rotten oranges

        # If there are no fresh oranges left, return the time elapsed; otherwise, return -1
        return time if fresh == 0 else -1
```

### JavaScript
```
var orangesRotting = function(grid, minutes = 2) {
    // Continue rotting fresh oranges until no more can be rotted in one iteration
    while (expireFresh(grid, minutes)) minutes++;  /* Time O((ROWS * COLS)^2) */

    // If there are no fresh oranges left, return the minutes passed minus 2 (initial value adjustment)
    // Otherwise, return -1 indicating not all fresh oranges can rot
    return !hasFresh(grid)                         /* Time O(ROWS * COLS) */
        ? (minutes - 2)
        : -1;
}

// Function to rot adjacent fresh oranges
var expireFresh = (grid, minutes, toBeContinued = false) => {
    const [ rows, cols ] = [ grid.length, grid[0].length ];

    // Loop through the entire grid
    for (let row = 0; row < rows; row++) {  /* Time O(ROWS) */
        for (let col = 0; col < cols; col++) {  /* Time O(COLS) */
            const isEqual = grid[row][col] === minutes;
            if (!isEqual) continue;

            // Check each neighbor of the current cell
            for (const [ _row, _col ] of getNeighbors(row, rows, col, cols)) {
                const isFresh = grid[_row][_col] === 1;
                if (!isFresh) continue;

                // Rot the fresh orange by setting it to the next minute value
                grid[_row][_col] = (minutes + 1);
                toBeContinued = true;
            }
        }
    }

    // Return true if at least one fresh orange was rotted in this iteration
    return toBeContinued;
}

// Function to get valid neighbors (up, down, left, right) of a cell
var getNeighbors = (row, rows, col, cols) => [ [ 0, 1 ], [ 0, -1 ], [ 1, 0 ], [ -1, 0 ] ]
    .map(([ _row, _col ]) => [ (row + _row), (col + _col) ])
    .filter(([ _row, _col ]) => (0 <= _row) && (_row < rows) && (0 <= _col) && (_col < cols));

// Function to check if there are any fresh oranges left in the grid
const hasFresh = (grid) => {
    for (const row of grid) {  /* Time O(ROWS) */
        for (const cell of row) {  /* Time O(COLS) */
            const isFresh = cell === 1;
            if (isFresh) return true;
        }
    }

    // Return false if no fresh oranges are found
    return false;
}
```

### Go
```
const ROW = 0
const COL = 1

func orangesRotting(grid [][]int) int {
    q := make([][]int, 0) // Queue to perform BFS
    fresh := 0            // Counter for fresh oranges
    time := 0             // Timer to track minutes elapsed
    
    // Loop through the grid to count fresh oranges and add rotten oranges to the queue
    for r := 0; r < len(grid); r++ {
        for c := 0; c < len(grid[0]); c++ {
            if grid[r][c] == 1 { // Count fresh oranges
                fresh += 1
            }
            if grid[r][c] == 2 { // Add rotten oranges to the queue
                q = append(q, []int{r, c})
            }
        }
    }
    
    // Possible directions for adjacent cells (right, left, down, up)
    directions := [4][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
    
    // BFS to rot adjacent fresh oranges
    for fresh > 0 && len(q) != 0 { // Continue while there are fresh oranges and the queue is not empty
        length := len(q) // Number of rotten oranges to process in this minute
        for i := 0; i < length; i++ {
            cell := q[0] // Get the position of the current rotten orange
            q = q[1:]
            
            // Check all four possible directions
            for _, d := range directions {
                row, col := cell[ROW] + d[ROW], cell[COL] + d[COL]

                // If the adjacent cell is within bounds and is a fresh orange, rot it
                if (
                    row >= 0 && row < len(grid) &&
                    col >= 0 && col < len(grid[0]) &&
                    grid[row][col] == 1) {
                    grid[row][col] = 2 // Rot the fresh orange
                    q = append(q, []int{row, col}) // Add the newly rotten orange to the queue
                    fresh -= 1 // Decrease the count of fresh oranges
                }
            }
        }
        time += 1 // Increment the time after processing all current rotten oranges
    }
    
    // If there are no fresh oranges left, return the time elapsed; otherwise, return -1
    if fresh == 0 {
        return time
    }
    return -1
}
```
Graphs 2
# Max Area Of Islands
## Company: Meta
### Level: Medium

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return the maximum area of an island in `grid`. If there is no island, return `0`.

***Break It Down For Me...***
*We have a grid (a 2D array) of size `m x n` filled with 0s (water) and 1s (land).*
*An island is a group of connected 1s.*
*The connections can be up, down, left, or right.*

*We need to find the size of the biggest island.*
*The size of an island is the number of 1s in that island.*
*If there are no islands, the answer should be 0.*

*The size of the biggest island is the answer.*

Click [here](https://leetcode.com/problems/max-area-of-island/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=iJGr1OtmH0c) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg)
```
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0], [0,0,0,0,0,0,0,1,1,1,0,0,0], [0,1,1,0,1,0,0,0,0,0,0,0,0], [0,1,0,0,1,1,0,0,1,0,1,0,0], [0,1,0,0,1,1,0,0,1,1,1,0,0], [0,0,0,0,0,0,0,0,0,0,1,0,0], [0,0,0,0,0,0,0,1,1,1,0,0,0], [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
```
**Explanation:** The answer is not `11`, because the island must be connected **4-directionally**.

### Example 2
```
Input: grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
Output: 0
```

## Python
```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # Get the number of rows and columns in the grid
        ROWS, COLS = len(grid), len(grid[0])
        # Initialize a set to keep track of visited cells
        visit = set()

        def dfs(r, c):
            # Check for base cases to stop recursion:
            # - if the current cell is out of grid bounds
            # - if the current cell is water (0)
            # - if the current cell has already been visited
            if (
                r < 0
                or r == ROWS
                or c < 0
                or c == COLS
                or grid[r][c] == 0
                or (r, c) in visit
            ):
                return 0
            # Mark the current cell as visited
            visit.add((r, c))
            # Recursively calculate the area of the island by exploring all four directions
            return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1)

        # Initialize a variable to keep track of the maximum area found
        area = 0
        # Iterate over each cell in the grid
        for r in range(ROWS):
            for c in range(COLS):
                # Update the maximum area by comparing with the area of the current island
                area = max(area, dfs(r, c))
        # Return the maximum area found
        return area
```

## JavaScript
```
var maxAreaOfIsland = function(grid, maxArea = 0) {
    // Get the number of rows and columns in the grid
    const [ rows, cols ] = [ grid.length, grid[0].length ];
    // Initialize a 2D array to keep track of visited cells
    const seen = new Array(rows).fill().map(() => new Array(cols));

    // Iterate over each cell in the grid
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            // Calculate the area of the island starting from the current cell
            const area = getArea(grid, row, rows, col, cols, seen);

            // Update the maximum area if the current island's area is larger
            maxArea = Math.max(maxArea, area);
        }
    }

    // Return the maximum area found
    return maxArea;
};

var getArea = (grid, row, rows, col, cols, seen) => {
    // Base case: if the current cell is water (0), return 0
    const isBaseCase = grid[row][col] === 0;
    if (isBaseCase) return 0;

    // If the current cell has already been visited, return 0
    if (seen[row][col]) return 0;
    // Mark the current cell as visited
    seen[row][col] = true;

    // Calculate the total area of the island by performing DFS and adding 1 for the current cell
    return dfs(grid, row, rows, col, cols, seen) + 1;
}

const dfs = (grid, row, rows, col, cols, seen, area = 0) => {
    // Get the neighbors (up, down, left, right) of the current cell
    for (const [ _row, _col ] of getNeighbors(row, rows, col, cols)) {
        // Recursively calculate the area for each neighbor
        area += getArea(grid, _row, rows, _col, cols, seen);
    }

    // Return the total area calculated
    return area;
} 

var getNeighbors = (row, rows, col, cols) => 
    // Define the directions for the neighbors (right, left, down, up)
    [[ 0, 1 ], [ 0, -1 ], [ 1, 0 ], [ -1, 0 ]]
    // Map the directions to actual row and column indices
    .map(([ _row, _col]) => [ (row + _row), (col + _col) ])
    // Filter out the neighbors that are out of grid bounds
    .filter(([ _row, _col ]) => (0 <= _row) && (_row < rows) && (0 <= _col) && (_col < cols));
```

## Go
```
func maxAreaOfIsland(grid [][]int) int {
    // Get the number of rows and columns in the grid
    row, col := len(grid), len(grid[0])
    res := 0 // Initialize the result to keep track of the maximum area

    // Iterate over each cell in the grid
    for i := 0; i < row; i++ {
        for j := 0; j < col; j++ {
            // If the current cell is land (1)
            if grid[i][j] == 1 {
                // Calculate the area of the island starting from the current cell
                curr := dfs(grid, i, j)
                // Update the maximum area if the current island's area is larger
                if curr > res {
                    res = curr
                }
            }
        }
    }

    return res // Return the maximum area found
}

func dfs(grid [][]int, row, col int) int {
    // Check if the current cell is out of grid bounds
    if row < 0 || row >= len(grid) || col < 0 || col >= len(grid[0]) {
        return 0 // Return 0 if it is out of bounds
    }

    // Check if the current cell is water (0)
    if grid[row][col] == 0 {
        return 0 // Return 0 if it is water
    }

    // Mark the current cell as visited by setting it to 0
    grid[row][col] = 0

    // Recursively calculate the area of the island by exploring all four directions
    return dfs(grid, row+1, col) + dfs(grid, row-1, col) + dfs(grid, row, col+1) + dfs(grid, row, col-1) + 1
}
```
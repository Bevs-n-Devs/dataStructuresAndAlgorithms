Graphs 1
# Number Of Islands
## Company: Google
### Level: Medium

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


***Break It Down For Me...***
*Imagine we have a map that is like a grid made up of small squares.*
*Each square can either be land (`'1'`) or water (`'0'`).*

*We need to find out how many islands there are on the map.*

- *An island is a group of land squares (`'1'`s) that are connected either horizontally or vertically.*
- *Islands are completely surrounded by water (`'0'`s).*
- *The edges of the map are also surrounded by water.*
*We need to write a program to count the number of islands on the map.*


Click [here](https://leetcode.com/problems/number-of-islands/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=pV2kpPD66nE) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

### Example 2
```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

## Python
```
class SolutionBFS:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0  # If the grid is empty, there are no islands

        rows, cols = len(grid), len(grid[0])  # Get the number of rows and columns in the grid
        visited = set()  # A set to keep track of visited cells
        islands = 0  # Counter for the number of islands

        def bfs(r, c):
            q = deque()  # Initialize a queue for BFS
            visited.add((r, c))  # Mark the starting cell as visited
            q.append((r, c))  # Add the starting cell to the queue

            while q:
                row, col = q.popleft()  # Get the current cell from the queue
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]  # Define the directions for movement

                for dr, dc in directions:
                    r, c = row + dr, col + dc  # Calculate the new cell coordinates
                    # Check if the new cell is within the grid, is land, and has not been visited
                    if (r) in range(rows) and (c) in range(cols) and grid[r][c] == '1' and (r, c) not in visited:
                        q.append((r, c))  # Add the new cell to the queue
                        visited.add((r, c))  # Mark the new cell as visited

        for r in range(rows):  # Iterate over each row
            for c in range(cols):  # Iterate over each column
                # If the current cell is land and has not been visited, it's a new island
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)  # Perform BFS to visit all connected land cells
                    islands += 1  # Increment the island counter

        return islands  # Return the total number of islands
```

## JavaScript
```
var numIslands = function(grid, connectedComponents = 0) {
    const [ rows, cols ] = [ grid.length, grid[0].length ]; // Get the number of rows and columns in the grid

    // Loop through each cell in the grid
    for (let row = 0; row < rows; row++) { // Iterate over each row
        for (let col = 0; col < cols; col++) { // Iterate over each column
            const isIsland = grid[row][col] === '1'; // Check if the current cell is land ('1')
            if (isIsland) connectedComponents++; // If it's land, it's part of an island, so increase the count

            // Perform Depth-First Search to mark the entire island as visited
            dfs(grid, row, rows, col, cols); // Visit all connected land cells
        }
    }

    return connectedComponents; // Return the total number of islands found
};

const dfs = (grid, row, rows, col, cols) => {
    const isBaseCase = grid[row][col] === '0'; // Check if the current cell is water ('0')
    if (isBaseCase) return; // If it's water, stop the DFS

    grid[row][col] = '0'; // Mark the current cell as visited by setting it to '0'

    // Get all neighboring cells (up, down, left, right) and perform DFS on them
    for (const [ _row, _col ] of getNeighbors(row, rows, col, cols)) {
        dfs(grid, _row, rows, _col, cols); // Recursively visit each neighbor
    }
}

// Get the valid neighboring cells (up, down, left, right) of the current cell
var getNeighbors = (row, rows, col, cols) => [ [ 0, 1 ], [ 0, -1 ], [ 1, 0 ], [ -1, 0 ] ] // Define the directions to move
    .map(([ _row, _col ]) => [ (row + _row), (col + _col) ]) // Calculate the new row and column indices for each direction
    .filter(([ _row, _col ]) => (0 <= _row) && (_row < rows) && (0 <= _col) && (_col < cols)); // Filter out invalid indices
```

## Go
```
func numIslands(grid [][]byte) int {
    // Get the number of rows (m) and columns (n) in the grid
    m, n := len(grid), len(grid[0])
    // Initialize a counter for the number of islands
    num_islands := 0

    // Define the DFS function to traverse the grid
    var dfs func(i int, j int)
    dfs = func(i int, j int) {
        // Base cases for recursion
        // If the current cell is out of grid bounds, return
        if i < 0 || i >= m { return }
        if j < 0 || j >= n { return }
        // If the current cell is water ('0'), return
        if grid[i][j] == '0' { return }

        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0'

        // Recursively call DFS for all adjacent cells (up, down, left, right)
        dfs(i - 1, j) // Up
        dfs(i + 1, j) // Down
        dfs(i, j - 1) // Left
        dfs(i, j + 1) // Right
    }

    // Iterate over each cell in the grid
    for i, row := range grid {
        for j, point := range row {
            // If the current cell is land ('1'), it's a part of an island
            if point == '1' {
                // Increment the island counter
                num_islands++
                // Perform DFS to visit all connected land cells
                dfs(i, j)
            }
        }
    }
    // Return the total number of islands found
    return num_islands
}
```
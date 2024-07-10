Graphs 6
# Pacific Atlantic Water Flow
## Company: Meta
### Level: Medium 

There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the height above sea level of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates `result` where `result[i] = [ri, ci]` denotes that rain water can flow from cell `(ri, ci)` to both the Pacific and Atlantic oceans.

***Break It Down For Me...***
*We have an m x n grid that represents an island. This grid has rows (`m`) and columns (`n`). Each cell in the grid has a number that tells you how high it is above sea level.*

- *The Pacific Ocean touches the left and top edges of the island.*
- *The Atlantic Ocean touches the right and bottom edges of the island.*
*When it rains, water can flow from one cell to another cell that is directly north, south, east, or west of it, but only if the other cell is the same height or lower.*

*Our task is to find all the cells in the grid where water can flow to both the Pacific and Atlantic Oceans.*

*We have to return a list of these cells' coordinates.*

Click [here](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=s-VkcjHqkGI) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python & JavaScript.


### Example 1
![Example 1](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)
```
Input: heights = [[1,2,2,3,5], [3,2,3,4,4], [2,4,5,3,1], [6,7,1,4,5], [5,1,1,2,4]]
Output: [[0,4], [1,3], [1,4], [2,2], [3,0], [3,1], [4,0]]
```
**Explanation**: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
`[0,4]`: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
`[1,3]`: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
`[1,4]`: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
`[2,2]`: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
`[3,0]`: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
`[3,1]`: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
`[4,0]`: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

### Example 2
```
Input: heights = [[1]]
Output: [[0,0]]
```
**Explanation:** The water can flow from the only cell to the Pacific and Atlantic oceans.

## Python
```
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # Get the number of rows and columns in the heights grid
        ROWS, COLS = len(heights), len(heights[0])
        # Create sets to keep track of cells that can flow to the Pacific and Atlantic oceans
        pac, atl = set(), set()

        # Define the depth-first search (DFS) function
        def dfs(r, c, visit, prevHeight):
            # If the cell is already visited or out of bounds or its height is less than the previous cell, return
            if (
                (r, c) in visit
                or r < 0
                or c < 0
                or r == ROWS
                or c == COLS
                or heights[r][c] < prevHeight
            ):
                return
            # Add the cell to the visited set
            visit.add((r, c))
            # Perform DFS for the neighboring cells (down, up, right, left)
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])

        # Perform DFS from the Pacific Ocean (left and top edges)
        for c in range(COLS):
            dfs(0, c, pac, heights[0][c])          # Top edge (Pacific)
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c]) # Bottom edge (Atlantic)

        # Perform DFS from the Atlantic Ocean (right and bottom edges)
        for r in range(ROWS):
            dfs(r, 0, pac, heights[r][0])          # Left edge (Pacific)
            dfs(r, COLS - 1, atl, heights[r][COLS - 1]) # Right edge (Atlantic)

        # Collect cells that can flow to both the Pacific and Atlantic oceans
        res = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r, c) in pac and (r, c) in atl:
                    res.append([r, c])
        return res
```

## JavaScript
```
var pacificAtlantic = function(heights) {
    // Perform BFS to find cells reachable from the Pacific and Atlantic Oceans
    const [pacificQueue, atlanticQueue] = search(heights);  // Time O(ROWS + COLS) | Space O(ROWS + COLS)
    const [pacificReachable, atlanticReachable] = [bfs(heights, pacificQueue), bfs(heights, atlanticQueue)];  // Time O(ROWS * COLS) | Space O(ROWS * COLS)

    // Find the intersection of cells that can reach both oceans
    return getIntersection(heights, pacificReachable, atlanticReachable);  // Time O(ROWS * COLS) | Space O(ROWS * COLS)
}

var search = (heights, pacificQueue = new Queue([]), atlanticQueue = new Queue([])) => {
    // Initialize the search from the rows
    searchRows(heights, pacificQueue, atlanticQueue);
    // Initialize the search from the columns
    searchCols(heights, pacificQueue, atlanticQueue);

    // Return the initialized queues for Pacific and Atlantic
    return [pacificQueue, atlanticQueue];
}

var searchRows = (heights, pacificQueue, atlanticQueue) => {
    const [rows, cols] = [heights.length, heights[0].length];

    // Enqueue cells on the left (Pacific) and right (Atlantic) edges
    for (let row = 0; row < rows; row++) {  // Time O(ROWS)
        pacificQueue.enqueue([row, 0]);          // Space O(ROWS)
        atlanticQueue.enqueue([row, (cols - 1)]);  // Space O(ROWS)
    }
}

var searchCols = (heights, pacificQueue, atlanticQueue) => {
    const [rows, cols] = [heights.length, heights[0].length];

    // Enqueue cells on the top (Pacific) and bottom (Atlantic) edges
    for (let col = 0; col < cols; col++) {  // Time O(COLS)
        pacificQueue.enqueue([0, col]);          // Space O(COLS)
        atlanticQueue.enqueue([(rows - 1), col]);  // Space O(COLS)
    }
}

const bfs = (heights, queue) => {
    const [rows, cols] = [heights.length, heights[0].length];
    const isReachable = getMatrix(rows, cols);  // Time O(ROWS * COLS) | Space O(ROWS * COLS)

    // Perform BFS to find all reachable cells
    while (!queue.isEmpty()) {
        for (let i = (queue.size() - 1); 0 <= i; i--) {  // Space O(WIDTH)
            const [row, col] = queue.dequeue();

            checkNeighbor(heights, row, rows, col, cols, isReachable, queue);
        }
    }

    return isReachable;
}

var getMatrix = (rows, cols) => new Array(rows).fill()  // Time O(ROWS * COLS) | Space O(ROWS * COLS)
    .map(() => new Array(cols).fill(false));

var checkNeighbor = (heights, row, rows, col, cols, isReachable, queue) => {
    // Mark the current cell as reachable
    isReachable[row][col] = true;

    // Check all neighboring cells
    for (const [_row, _col] of getNeighbors(row, rows, col, cols)) {
        if (isReachable[_row][_col]) continue;

        const isLower = heights[_row][_col] < heights[row][col];
        if (isLower) continue;

        // Enqueue the cell if it can flow water to the ocean
        queue.enqueue([_row, _col]);
    }
}

var getNeighbors = (row, rows, col, cols) => [ [0, 1], [0, -1], [1, 0], [-1, 0] ]
    .map(([_row, _col]) => [(row + _row), (col + _col)])
    .filter(([_row, _col]) => (0 <= _row) && (_row < rows) && (0 <= _col) && (_col < cols));

const getIntersection = (heights, pacificReachable, atlanticReachable, intersection = []) => {
    const [rows, cols] = [heights.length, heights[0].length];

    // Find cells that are reachable by both oceans
    for (let row = 0; row < rows; row++) {  // Time O(ROWS)
        for (let col = 0; col < cols; col++) {  // Time O(COLS)
            const isReachable = pacificReachable[row][col] && atlanticReachable[row][col];
            if (!isReachable) continue;

            intersection.push([row, col]);  //
```

## Go
```
func pacificAtlantic(heights [][]int) [][]int {
    ROWS, COLS := len(heights), len(heights[0])
    pac, atl := make(map[int]bool), make(map[int]bool)

    // Depth-first search function to mark cells reachable from an ocean
    var dfs func(int, int, map[int]bool, int)
    dfs = func(r, c int, visit map[int]bool, prevHeight int) {
        // Base cases to stop recursion
        if (
            visit[r*COLS+c] ||  // Cell already visited
            r < 0 || c < 0 || r == ROWS || c == COLS ||  // Out of bounds
            heights[r][c] < prevHeight) {  // Cell height is less than the previous cell height
            return
        }
        visit[r*COLS+c] = true  // Mark the cell as visited
        // Recursively visit all four adjacent cells
        dfs(r+1, c, visit, heights[r][c])
        dfs(r-1, c, visit, heights[r][c])
        dfs(r, c+1, visit, heights[r][c])
        dfs(r, c-1, visit, heights[r][c])
    }

    // Perform DFS from all cells adjacent to the Pacific Ocean
    for c := 0; c < COLS; c++ {
        dfs(0, c, pac, heights[0][c])  // Top row
        dfs(ROWS-1, c, atl, heights[ROWS-1][c])  // Bottom row
    }

    // Perform DFS from all cells adjacent to the Atlantic Ocean
    for r := 0; r < ROWS; r++ {
        dfs(r, 0, pac, heights[r][0])  // Left column
        dfs(r, COLS-1, atl, heights[r][COLS-1])  // Right column
    }

    // Find cells that can reach both the Pacific and Atlantic Oceans
    res := make([][]int, 0)
    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            if pac[r*COLS+c] && atl[r*COLS+c] {
                res = append(res, []int{r, c})  // Add the cell to the result
            }
        }
    }
    return res
}
```
Graphs 4
# Walls And Gates
## Company: Amazon
### Level: Medium

You are given a 𝑚 × 𝑛 m×n 2D `grid` initialized with these three possible values:

1. `-1` - A water cell that can not be traversed.
2. `0` - A treasure chest.
3. `INF` - A land cell that can be traversed. We use the integer `2^31 - 1 = 2147483647 `to represent `INF`.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain `INF`.

Assume the grid can only be traversed up, down, left, or right.

***Break It Down For Me...***
*We have a grid (like a map) that has `m` rows and `n` columns.*
*Each spot on the grid can have one of three values:*

1. `-1`: *This spot is water and you can't walk on it.*
2. `0`: *This spot has a treasure chest.*
3. `INF`: *This spot is land, and you can walk on it. `INF` is a very large number, which is `2147483647`.*
*Our task is to fill each land spot (`INF`) with the number of steps it takes to get to the nearest treasure chest (`0`).*
*You can only move up, down, left, or right.*

*If a land spot can't reach any treasure chest, it should stay `INF`.*


Click [here](https://neetcode.io/problems/islands-and-treasure)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=e69C6xhiSQE) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python & JavaScript.

### Example 1
```
Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]

```

### Example 2
```
Input: [
  [0,-1],
  [2147483647,2147483647]
]

Output: [
  [0,-1],
  [1,2]
]
```

## Python
```
class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    
    def walls_and_gates(self, rooms: List[List[int]]):
        ROWS, COLS = len(rooms), len(rooms[0])  # Get the number of rows and columns in the grid
        visit = set()  # Set to keep track of visited cells
        q = deque()  # Queue to perform breadth-first search (BFS)

        # Function to add neighboring rooms to the queue
        def addRooms(r, c):
            # Check if the room is out of bounds, already visited, or is a wall (-1)
            if (
                min(r, c) < 0  # If r or c is less than 0 (out of bounds)
                or r == ROWS  # If r is equal to the number of rows (out of bounds)
                or c == COLS  # If c is equal to the number of columns (out of bounds)
                or (r, c) in visit  # If the room is already visited
                or rooms[r][c] == -1  # If the room is a wall
            ):
                return
            visit.add((r, c))  # Mark the room as visited
            q.append([r, c])  # Add the room to the queue

        # Initialize the queue with all gates (0) and mark them as visited
        for r in range(ROWS):
            for c in range(COLS):
                if rooms[r][c] == 0:  # If the room is a gate
                    q.append([r, c])  # Add the gate to the queue
                    visit.add((r, c))  # Mark the gate as visited

        dist = 0  # Distance from the gate
        while q:
            for i in range(len(q)):  # Process all rooms at the current distance
                r, c = q.popleft()  # Get the current room
                rooms[r][c] = dist  # Update the room with the distance from the gate
                addRooms(r + 1, c)  # Add the room below the current room
                addRooms(r - 1, c)  # Add the room above the current room
                addRooms(r, c + 1)  # Add the room to the right of the current room
                addRooms(r, c - 1)  # Add the room to the left of the current room
            dist += 1  # Increment the distance for the next level of rooms
```

## JavaScript
```
var wallsAndGates = function(rooms) {
    const [rows, cols] = [rooms.length, rooms[0].length]; // Get the number of rows and columns in the grid

    // Loop through each cell in the grid
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            const isGate = rooms[row][col] === 0; // Check if the current cell is a gate (value is 0)
            if (!isGate) continue; // If it's not a gate, skip to the next cell

            // Perform depth-first search (DFS) from the gate to update distances
            dfs(rooms, row, col);
        }
    }
}

const dfs = (rooms, row, col) => {
    const [rows, cols] = [rooms.length, rooms[0].length]; // Get the number of rows and columns in the grid

    // Loop through each neighbor (up, down, left, right) of the current cell
    for (const [_row, _col] of getNeighbors(row, rows, col, cols)) {
        const isPreviousDistanceGreater = rooms[_row][_col] <= (rooms[row][col] + 1); // Check if the neighbor already has a smaller distance
        if (isPreviousDistanceGreater) continue; // If it does, skip this neighbor

        rooms[_row][_col] = (rooms[row][col] + 1); // Update the neighbor's distance from the gate

        // Recursively perform DFS from the neighbor to update distances
        dfs(rooms, _row, _col);
    }
}

// Function to get valid neighbors of a cell (up, down, left, right)
var getNeighbors = (row, rows, col, cols) => [ [0, 1], [0, -1], [1, 0], [-1, 0] ] // Relative positions of neighbors
    .map(([ _row, _col ]) => [ (row + _row), (col + _col) ]) // Calculate the absolute positions of neighbors
    .filter(([ _row, _col ]) => (0 <= _row) && (0 <= _col) && (_row < rows) && (_col < cols)); // Keep only valid neighbors within the grid boundaries
```
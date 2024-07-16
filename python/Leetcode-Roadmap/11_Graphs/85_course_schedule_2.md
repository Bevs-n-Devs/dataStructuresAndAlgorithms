Graphs 9
# Course Schedule 2
## Company: Google
### Level: Medium

There are a total of `numCourses` courses you have to take, labeled from 0 to `numCourses` - 1. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

***Break It Down To Me...***
*You have to take `numCourses` courses.*
*The courses are numbered from 0 to `numCourses - 1`.*
*Some courses need you to take other courses first.*
*This is given in a list called prerequisites.*
*Each item in this list is a pair `[a, b]` which means you need to take course `b` before you can take course `a`.*

- *For example, `[0, 1]` means you need to take course 1 before you can take course `0`.*

*The job is to find an order in which you can take all the courses. If there are multiple correct orders, any one of them is fine. If it's impossible to take all courses, return an empty list.*

Click [here](https://leetcode.com/problems/course-schedule-ii/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Akt3glAwyfY) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.
 

### Example 1:
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
```
**Explanation:** There are a total of `2` courses to take. To take course `1` you should have finished course `0`. So the correct course order is [0,1].

### Example 2:
```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
```
**Explanation:** There are a total of 4 courses to take. To take course 3 you should have finished both courses `1` and `2`. Both courses `1` and `2` should be taken after you finished course `0`.
So one correct course order is `[0,1,2,3]`. Another correct ordering is `[0,2,1,3]`.

### Example 3:
```
Input: numCourses = 1, prerequisites = []
Output: [0]
```

## Python
```
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Create a dictionary to keep track of each course's prerequisites
        prereq = {c: [] for c in range(numCourses)}
        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        output = []  # This will store the order of courses to take
        visit, cycle = set(), set()  # Sets to keep track of visited courses and current path

        def dfs(crs):
            if crs in cycle:  # If we encounter a course in the current path, there's a cycle
                return False
            if crs in visit:  # If the course has already been visited, no need to process again
                return True

            cycle.add(crs)  # Add course to current path
            for pre in prereq[crs]:  # Visit all prerequisites for the current course
                if dfs(pre) == False:  # If any prerequisite leads to a cycle, return False
                    return False
            cycle.remove(crs)  # Remove course from current path
            visit.add(crs)  # Mark course as visited
            output.append(crs)  # Add course to the output order
            return True

        # Apply DFS to each course
        for c in range(numCourses):
            if dfs(c) == False:  # If any course leads to a cycle, return an empty list
                return []
        return output  # Return the order of courses to take
```

## JavaScript
```
var findOrder = function(numCourses, prerequisites) {
    // Build the graph and initialize necessary variables
    const { graph, color, isDirectedAcyclicGraph, topologicalOrder } = buildGraph(numCourses, prerequisites);

    // Perform the search to detect cycles and build the topological order
    search(numCourses, graph, color, topologicalOrder, isDirectedAcyclicGraph);

    // If the graph is a Directed Acyclic Graph (DAG), return the topological order reversed
    // Otherwise, return an empty array as it's impossible to finish all courses
    return isDirectedAcyclicGraph[0]
        ? topologicalOrder.reverse()
        : [];
}

// Initialize the graph and other structures
var initGraph = (numCourses) => ({
    graph: new Array(numCourses).fill().map(() => []), // Adjacency list representation of the graph
    color: new Array(numCourses).fill(1), // 1 represents White (unvisited)
    isDirectedAcyclicGraph: [true], // Flag to indicate if the graph is a DAG
    topologicalOrder: [] // List to store the topological order
});

// Build the graph from the prerequisites
var buildGraph = (numCourses, prerequisites) => {
    const { graph, color, isDirectedAcyclicGraph, topologicalOrder } = initGraph(numCourses);

    for (const [src, dst] of prerequisites) {
        const neighbors = (graph[dst] || []);
        neighbors.push(src); // Add an edge from dst to src
        graph[dst] = neighbors;
    }

    return { graph, color, isDirectedAcyclicGraph, topologicalOrder };
}

// Perform a search on the graph to detect cycles and build the topological order
var search = (numCourses, graph, color, topologicalOrder, isDirectedAcyclicGraph) => {
    for (let i = 0; i < numCourses; i++) {
        const isNew = color[i] === 1; // Check if the node is unvisited (White)
        if (isNew) dfs(i, graph, color, topologicalOrder, isDirectedAcyclicGraph);
    }
}

// Depth-First Search (DFS) to detect cycles and build the topological order
var dfs = (node, graph, color, topologicalOrder, isDirectedAcyclicGraph) => {
    const hasCycle = !isDirectedAcyclicGraph[0];
    if (hasCycle) return; // If a cycle is already detected, stop further processing

    // Perform DFS and color backtracking
    colorBackTrack(node, graph, color, topologicalOrder, isDirectedAcyclicGraph);

    topologicalOrder.push(node); // Add the node to the topological order
}

// Perform color backtracking during DFS
const colorBackTrack = (node, graph, color, topologicalOrder, isDirectedAcyclicGraph) => {
    color[node] = 2; // Mark the node as being visited (Grey)
    checkNeighbors(node, graph, color, topologicalOrder, isDirectedAcyclicGraph);
    color[node] = 3; // Mark the node as fully processed (Black)
}

// Check all neighbors of a node during DFS
var checkNeighbors = (node, graph, color, topologicalOrder, isDirectedAcyclicGraph) => {
    for (const neighbor of graph[node]) {
        const isNew = color[neighbor] === 1; // Check if the neighbor is unvisited (White)
        if (isNew) dfs(neighbor, graph, color, topologicalOrder, isDirectedAcyclicGraph);

        const isCycle = color[neighbor] === 2; // Check if the neighbor is being visited (Grey), indicating a cycle
        if (isCycle) isDirectedAcyclicGraph[0] = false;
    }
}
```

## Go
```
const CRS = 0
const PRE = 1

func findOrder(numCourses int, prerequisites [][]int) []int {
    // Initialize the adjacency list for prerequisites€
    prereq := make([][]int, 0)
    for i := 0; i < numCourses; i++ {
        prereq = append(prereq, make([]int, 0))
    }

    // Fill the adjacency list with prerequisites
    for _, edge := range prerequisites {
        prereq[edge[CRS]] = append(prereq[edge[CRS]], edge[PRE])
    }

    // Output list to store the order of courses
    output := make([]int, 0)
    // Arrays to track visited nodes and nodes in the current path (cycle detection)
    visit, cycle := make([]bool, numCourses), make([]bool, numCourses)

    // Depth-First Search (DFS) function
    var dfs func(int) bool
    dfs = func(crs int) bool {
        if cycle[crs] {
            // If the course is in the current path, a cycle is detected
            return false
        } else if visit[crs] {
            // If the course is already visited, no need to visit again
            return true
        }

        // Mark the course as being in the current path
        cycle[crs] = true
        // Visit all prerequisite courses
        for _, pre := range prereq[crs] {
            if !dfs(pre) {
                // If any prerequisite leads to a cycle, return false
                return false
            }
        }
        // Mark the course as not in the current path anymore
        cycle[crs] = false
        // Mark the course as visited
        visit[crs] = true
        // Append the course to the output list
        output = append(output, crs)
        return true
    }

    // Perform DFS for each course
    for c := 0; c < numCourses; c++ {
        if dfs(c) == false {
            // If a cycle is detected, return an empty array
            return []int{}
        }
    }

    // Return the topological order of courses
    return output
}
```
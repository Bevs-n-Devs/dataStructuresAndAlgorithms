Graphs 11
# Number of Connected Components in Undirected Graph
## Company: Google
### Level: Medium

There is an undirected graph with `n` nodes. 
There is also an `edges` array, where `edges[i] = [a, b]` means that there is an edge between node `a` and node `b` in the graph.

Return the total number of connected components in that graph.


***Break It Down For Me...***
*Imagine we have a set of `n` dots.*
*Some of these dots are connected by lines.*
*The connections are given as pairs in an edges array, where `edges[i] = [a, b]` means dot `a` is connected to dot `b`.

*The task is to find out how many separate groups of connected dots there are in total*

Click [here](https://neetcode.io/problems/count-connected-components)for the question on Neetcode.

Click [here](https://www.youtube.com/watch?v=8f1XPm4WOUc) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.

### Example 1
```
Input:
n=3
edges=[[0,1], [0,2]]

Output:
1
```

### Example 2
```
Input:
n=6
edges=[[0,1], [1,2], [2,3], [4,5]]

Output:
2
```

## Python
```
class UnionFind:
    def __init__(self):
        # Initialize a dictionary to store the parent of each node
        self.f = {}

    def findParent(self, x):
        # Find the root parent of node x
        y = self.f.get(x, x)  # If x is not in the dictionary, its parent is itself
        if x != y:
            # Recursively find the root parent and perform path compression
            y = self.f[x] = self.findParent(y)
        return y

    def union(self, x, y):
        # Connect the root parent of x to the root parent of y
        self.f[self.findParent(x)] = self.findParent(y)

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # Create an instance of the UnionFind class
        dsu = UnionFind()
        # Perform union operation for each edge
        for a, b in edges:
            dsu.union(a, b)
        # Find the number of unique root parents to determine the number of connected components
        return len(set(dsu.findParent(x) for x in range(n)))
```

## JavaScript
```
var countComponents = function (n, edges, count = 0) {
    // Build the graph and initialize the visited array
    const { graph, visited } = buildGraph(n, edges);

    // Check each node to see if it has been visited
    for (const node in graph) {
        if (hasPath(graph, node, visited)) count++;
    }

    return count;
};

const initGraph = (n) => ({
    // Initialize graph with empty arrays for each node
    graph: new Array(n).fill().map(() => []),
    // Initialize visited array with false for each node
    visited: new Array(n).fill(false),
});

const buildGraph = (n, edges) => {
    const { graph, visited } = initGraph(n);

    // Add edges to the graph
    for (const [src, dst] of edges) {
        graph[src].push(dst);
        graph[dst].push(src);
    }

    return { graph, visited };
}

const hasPath = (graph, current, visited) => {
    // If the node is already visited, return false
    if (visited[current]) return false;
    // Mark the node as visited
    visited[current] = current;

    // Recursively visit all neighbors
    for (const neighbor of graph[current]) {
        hasPath(graph, neighbor, visited);
    }

    return true;
}
```

## Go
```
func countComponents(n int, edges [][]int) int {
    if n == 1 {
        // If there's only one node, there's only one component
        return 1
    }

    var components int
    visited := make([]bool, n)
    graph := make(map[int][]int)

    // Build the graph
    for _, edge := range edges {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }

    var dfs func(i int)
    dfs = func(i int) {
        // Mark the node as visited
        visited[i] = true
        // Visit all the neighbors
        for _, j := range graph[i] {
            if !visited[j] {
                dfs(j)
            }
        }
    }

    // Perform DFS for each node
    for i := 0; i < n; i++ {
        if !visited[i] {
            components++
            dfs(i)
        }
    }

    return components
}
```
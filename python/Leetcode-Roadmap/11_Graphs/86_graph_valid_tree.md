Graphs 10
# Graph Valid Tree
## Company:  Meta
### Level: Medium

Given n nodes labeled from `0` to `n - 1` and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

***Break It Down For Me...***
*You have n points labeled from `0` to `n - 1`. We are also given a list of connections (edges) where each connection is a pair of points.*

*Our task is to write a function to check if these connections form a valid tree.*

What is a Valid Tree?
- **No Loops:** *There should be no cycles. A cycle means you can start at a point, follow the connections, and return to the same point without retracing your steps.*
- **All Points Connected:** *All points should be connected. This means you can get from any point to any other point by following the connections.*

Click [here](https://neetcode.io/problems/valid-tree)for the question on Neetcode.

Click [here](https://www.youtube.com/watch?v=bXsUuownnoQ) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.

### Example 1
```
Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

Output:
true
```

### Example 2
```
Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

Output:
false
```

## Python
```
class Solution:
    """
    @param n: An integer representing the number of nodes
    @param edges: a list of undirected edges (each edge is a pair of nodes)
    @return: true if it's a valid tree, or false
    """

    def validTree(self, n, edges):
        # If there are no nodes, it's considered a valid tree
        if not n:
            return True

        # Create an adjacency list to represent the graph
        adj = {i: [] for i in range(n)}
        for n1, n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)

        # This set will keep track of all visited nodes
        visit = set()

        def dfs(i, prev):
            # If the node is already visited, then there is a cycle
            if i in visit:
                return False

            # Mark the node as visited
            visit.add(i)
            
            # Visit all the neighbors of the current node
            for j in adj[i]:
                # Skip the previous node to avoid false cycle detection
                if j == prev:
                    continue
                # Recursively visit the neighbors, if any returns False, then there is a cycle
                if not dfs(j, i):
                    return False
            return True

        # Start DFS from node 0, with no previous node (-1)
        # Check if the graph is connected and has no cycles
        return dfs(0, -1) and n == len(visit)

        # Explanation:
        # - dfs(0, -1) ensures there are no cycles and all nodes connected starting from node 0.
        # - n == len(visit) ensures all nodes are connected (visited).
```

## JavaScript
```
var validTree = function(n, edges, root = 0) {
    // Check if the number of edges is exactly one less than the number of nodes
    const isEqual = edges.length === (n - 1);
    if (!isEqual) return false; // If not, it cannot be a valid tree

    // Build the graph and initialize visited set
    const { graph, visited } = buildGraph(n, edges);

    // Perform Depth-First Search (DFS) starting from the root node (0)
    dfs(root, graph, visited);

    // Check if all nodes are visited
    return visited.size === n;
}

var initGraph = (n) => ({
    // Initialize the graph as an array of empty arrays
    graph: new Array(n).fill().map(() => []),
    // Initialize an empty set to keep track of visited nodes
    visited: new Set()
})

var buildGraph = (n, edges) => {
    const { graph, visited } = initGraph(n);

    // Populate the graph with edges (undirected)
    for (const [src, dst] of edges) {
        graph[src].push(dst);
        graph[dst].push(src);
    }

    return { graph, visited };
}

const dfs = (node, graph, visited) => {
    // If the node is already visited, return to avoid cycles
    if (visited.has(node)) return;
    // Mark the node as visited
    visited.add(node);

    // Visit all neighbors of the current node
    for (const neighbor of graph[node]) {
        dfs(neighbor, graph, visited);
    }
}
```
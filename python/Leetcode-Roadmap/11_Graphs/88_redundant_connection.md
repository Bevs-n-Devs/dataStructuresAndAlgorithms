Graphs 12
# Redundant Connection 
## Company: SnapChat
### Level: Medium

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. 
The added edge has two different vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length n where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

Return an edge that can be removed so that the resulting graph is a tree of `n` nodes. If there are multiple answers, return the answer that occurs last in the input.

 ***Break It Down For Me...***
 *We are given a graph that used to be a tree.*
 *A tree is a special kind of graph that is connected (you can get from any node to any other node) and has no cycles (no loops).*

*The graph has `n` nodes labeled from `1` to `n`.*
*One extra edge (connection) was added to this tree, which created a cycle.*

*We are given an array `edges` where each element `edges[i] = [a, b]` means there is an edge between node `a` and node `b`.

*The task is to find and return the edge that was added last and can be removed to make the graph a tree again. If there are multiple edges that can be removed, return the one that appears last in the input list.*

Click [here](https://leetcode.com/problems/redundant-connection/description/)for the question on Neetcode.

Click [here](https://www.youtube.com/watch?v=FXWRE67PLL0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg)
```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg)
```
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

## Python
```
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Initialize parent and rank arrays
        par = [i for i in range(len(edges) + 1)]
        rank = [1] * (len(edges) + 1)

        # Find the root parent of a node with path compression
        def find(n):
            p = par[n]
            while p != par[p]:
                par[p] = par[par[p]]  # Path compression
                p = par[p]
            return p

        # Union two nodes and return False if they are already unioned
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return False  # They are already connected
            if rank[p1] > rank[p2]:
                par[p2] = p1
                rank[p1] += rank[p2]
            else:
                par[p1] = p2
                rank[p2] += rank[p1]
            return True

        # Iterate through each edge
        for n1, n2 in edges:
            if not union(n1, n2):
                return [n1, n2]  # Return the redundant edge
```

## JavaScript
```
var findRedundantConnection = function (edges) {
    // Initialize the graph with empty adjacency lists
    const graph = new Array((1000 + 1)).fill().map(() => []);

    // Iterate through each edge
    for (const [ src, dst ] of edges) {
        // Check if both nodes are already in the graph and if there's a redundant connection
        const hasNodes = (src in graph) && (dst in graph)
        if (hasNodes && hasRedundantConnection(graph, src, dst)) return [ src, dst ];

        // Add the edge to the graph
        graph[src].push(dst);
        graph[dst].push(src);
    }
}

// Check if there is a path from source to target using DFS
const hasRedundantConnection = (graph, source, target, seen = new Set()) => {
    if (seen.has(source)) return false;  // Node already seen
    seen.add(source);

    if (source === target) return true;  // Found a path to the target

    // Recursively check all neighbors
    return dfs(graph, source, target, seen);
}

// DFS helper function to find a path
const dfs = (graph, source, target, seen) => {
    for (const neighbor of graph[source]) {
        if (hasRedundantConnection(graph, neighbor, target, seen)) return true;
    }

    return false;
}
```

## Go
```
func findRedundantConnection(edges [][]int) []int {
    // Initialize the parent array
    parent := make([]int, len(edges)+1)

    // Set each node to be its own parent
    for i := 0; i < len(parent); i++ {
        parent[i] = i
    }

    // Iterate through each edge
    for _, edge := range edges {
        // If both nodes of the edge have the same root parent, this edge is redundant
        if find(parent, edge[0]) == find(parent, edge[1]) {
            return edge
        }
        // Union the two nodes of the edge
        unify(parent, edge[0], edge[1])
    }

    return []int{}
}

// Find the root parent of a node with path compression
func find(parent []int, num int) int {
    if parent[num] == num {
        return num
    }
    // Recursively find the root parent and compress the path
    return find(parent, parent[num])
}

// Union two nodes by making the root of one node point to the root of the other
func unify(parent []int, x, y int) {
    parent[find(parent, y)] = find(parent, x)
}
```
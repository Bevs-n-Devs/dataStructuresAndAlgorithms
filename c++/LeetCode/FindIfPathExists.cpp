#include "../Utils/utils.h"
#include <unordered_map>
#include <math.h>
#include <algorithm>

/**
 * Find if Path Exists in Graph
 * 
 * There is a bi-directional graph with n vertices, where each vertex is labeled 
 * from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D 
 * integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional 
 * edge between vertex ui and vertex vi. Every vertex pair is connected by at most 
 * one edge, and no vertex has an edge to itself.
 * 
 * You want to determine if there is a valid path that exists from vertex source 
 * to vertex destination.
 * 
 * Given edges and the integers n, source, and destination, return true if there 
 * is a valid path from source to destination, or false otherwise.
 * 
 * Constraints:
 *      1 <= n <= 2 * 10^5
 *      0 <= edges.length <= 2 * 10^5
 *      edges[i].length == 2
 *      0 <= ui, vi <= n - 1
 *      ui != vi    
 *      0 <= source, destination <= n - 1
 *      There are no duplicate edges.
 *      There are no self edges.
 * 
 */


/**
 * Test Object
 */
typedef struct {
    int n;
    std::vector<std::vector<int>> edges;
    int source;
    int destination;
    bool expectedResult;
} Test;

/**
 * Test Cases
 */
Test TestCases[] = {
    Test{
        6,
        {{0,1},{0,2},{3,5},{5,4},{4,3}},
        0,
        9,
        false
    },
    Test{
        50,
        {{41,40},{9,32},{48,14},{6,44},{18,41},{41,1},{7,41},{38,41},{19,4},{16,41},{41,43},{41,22},{41,21},{9,0},{41,48},{32,36},{24,44},{39,41},{48,17},{49,15},{47,41},{19,31},{11,41},{41,23},{41,49},{45,44},{2,49},{13,41},{35,41},{30,0},{5,44},{8,0},{41,20},{41,28},{12,11},{12,41},{49,10},{19,0},{0,37},{34,41},{42,48},{27,41},{0,41},{19,44},{41,26},{41,29},{33,41},{49,46},{41,25},{3,41}},
        40,
        3,
        true
    },
    Test{
        10,
        {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}},
        5,
        9,
        true
    }
};

/**
 * Sets visited vertices to 1 while searching for destination vertex
 *
 * @param src: started vertex
 * @param dst: destination vertex
 * @param visited: set of already visited vertices
 * @param adj_lst: unordered map adjacenvy list
 *
 * @return true if path is found, otherwise false
 *
 */
bool dfs(int src, int dst, std::vector<int> &visited, std::unordered_map <int, std::vector<int>> &adj_lst)     {
    // set vertex visited value to true
    visited[src] = 1;
    
    // check for destination find
    if (src == dst) return true;
    
    // loop through src neighbors
    for(auto v: adj_lst[src]){
        // cancel loop if dst found 
        if (visited[dst]) return true;
        // recursively check neighbors 
        if (!visited[v]) dfs(v, dst, visited,adj_lst);
    }
    
    return visited[dst];
}

/**
 * Finds valid path in bi-directional graph
 *
 * @param n : number of vertices
 * @param edges : 2D vector of vertices graph
 * @param source : started vertex  
 * @param destination : destination vertex
 *
 * @return boolean if path is valid, false otherwise
 *
 */
bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    // catch early condition
    if (source == destination) return true;
    // check constraints
    if (!n || !edges.size()) return false;
    if (edges.size() > 2*std::pow(10,5)) return false;
    if (n > 2*pow(10,5)) return false;
    if (source < 0 || source >= n) return false;
    if (destination < 0 || destination >= n) return false;
    
    // declaring & defining the adjacency list
    std::unordered_map <int, std::vector<int>> adj_lst;
    for (std::vector<int> e: edges){
        // check constraints
        if (e.size() != 2) return false;
        if (e.front() == e.back()) return false;
        if (e.front() < 0 || e.front() >= n) return false;
        if (e.back() < 0 || e.back() >= n) return false;
        
        // because the graph is bidirectional 
        // u can travel to v, so v can travel to u
        adj_lst[e.front()].push_back(e.back());
        adj_lst[e.back()].push_back(e.front());
    }
    
    // src neighbors
    std::vector<int> src_adj = adj_lst[source];
    
    // quick check source neighbors
    if (find(src_adj.begin(), src_adj.end(), destination) != src_adj.end()) return true;
    
    // create vector as visited tracker for each vertices
    std::vector<int> visited(n,0);
    return dfs(source, destination, visited, adj_lst);
}

int main(){
    std::cout << " --- Running Leetcode Problem FindIfPathExists --- " << std::endl;

    for (int i=0; i< sizeof(TestCases)/sizeof(TestCases[0]);i++){
        Test test = TestCases[i];
        std::cout << "Test Case: " << i+1 << std::endl;
        std::cout << " input: {n: " << test.n << ", edges: ";
        printMatrix_Vector_Int(test.edges);
        std::cout << "\n source: " << test.source << ", destination: " << test.destination << "}" << std::endl;
        std::cout <<"\texpectedResult: " << std::boolalpha << test.expectedResult << std::endl;
        bool ans = validPath(test.n, test.edges, test.source, test.destination);
        std::cout << "\tActual Result: " << std::boolalpha << ans << std::endl;
        std::cout << "\n========================================================\n" << std::endl;
    }
    return 0;
}
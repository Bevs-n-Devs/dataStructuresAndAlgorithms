Graphs 8
# Course Schedule
## Company: Google
### Level: Medium

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you must take course `bi` first if you want to take course `ai`.

For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.
Return `true` if you can finish all courses. Otherwise, return `false`.

***Break It Down For Me...***
*We have some courses to take, numbered from `0` to `numCourses - 1`. Some courses need you to take other courses first.*

*We get a list called `prerequisites`. Each item in the list is a pair `[a, b]`, meaning we must take course `b` before we can take course `a`.*

*For example, if we have `[0, 1]`, it means we must take course `1` before we can take course `0`.*

*Our task is to figure out if we can take all the courses.*

*We need to return `true` if we can take all the courses, and `false` if we can't.*

Click [here](https://leetcode.com/problems/course-schedule/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=EgI5nU9etnU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.

## Example 1
```
Input: numCourses = 2, prerequisites = [[1, 0]]
Output: true
```
**Explanation:** There are a total of `2` courses to take. To take course `1` you should have finished course `0`. So it is possible.

## Example 2
```
Input: numCourses = 2, prerequisites = [[1,0], [0,1]]
Output: false
```
**Explanation:** There are a total of `2` courses to take. To take course `1` you should have finished course `0`, and to take course `0` you should also have finished course `1`. So it is impossible.

### Python
```
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Create a map to store prerequisites for each course
        preMap = {i: [] for i in range(numCourses)}

        # Fill the map with the given prerequisites
        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        # Set to keep track of courses currently being visited in the DFS
        visiting = set()

        def dfs(crs):
            # If the course is already in the visiting set, it means there's a cycle
            if crs in visiting:
                return False
            # If the course has no prerequisites, it can be finished
            if preMap[crs] == []:
                return True

            # Add the course to the visiting set
            visiting.add(crs)
            # Perform DFS on all prerequisites of the course
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            # Remove the course from the visiting set after exploring all prerequisites
            visiting.remove(crs)
            # Mark the course as having no prerequisites (since we have checked it)
            preMap[crs] = []
            return True

        # Perform DFS for each course
        for c in range(numCourses):
            # If any course cannot be finished, return False
            if not dfs(c):
                return False
        # If all courses can be finished, return True
        return True
```

### JavaScript
```
var canFinish = function(numCourses, prerequisites) {
    // Build the graph and initialize the path array
    const { graph, path } = buildGraph(numCourses, prerequisites);

    // Check if there's a valid path to finish all courses
    return hasPath(numCourses, graph, path);
}

var initGraph = (numCourses) => ({
    // Initialize the graph as an array of empty arrays for each course
    graph: new Array(numCourses).fill().map(() => []),
    // Initialize the path array to keep track of the visit status of each course
    path: new Array(numCourses).fill(false)
})

var buildGraph = (numCourses, prerequisites) => {
    // Initialize the graph and path
    const { graph, path } = initGraph(numCourses);

    // Build the graph from the prerequisites array
    for (const [src, dst] of prerequisites) {
        // Get the current neighbors of the destination course
        const neighbors = (graph[dst] || []);

        // Add the source course as a neighbor
        neighbors.push(src);

        // Update the graph with the new neighbors
        graph[dst] = neighbors;
    }

    return { graph, path };
}

var hasPath = (numCourses, graph, path) => {
    // Check for each course if it has a cyclic path
    for (let course = 0; course < numCourses; course++) {
        if (isCyclic(course, graph, path)) return false;
    }

    return true;
}

var isCyclic = (currCourse, graph, path) => {
    // If the current course is already in the path, we have a cycle
    const hasSeen = path[currCourse]
    if (hasSeen) return true

    // If the current course has no neighbors, return false (no cycle)
    const isMissingNext = !(currCourse in graph)
    if (isMissingNext) return false;

    // Backtrack to check if there's a cycle
    return backTrack(currCourse, graph, path);
}

var backTrack = (currCourse, graph, path) => {
    // Mark the current course as visited
    path[currCourse] = true;

    // Check if there is a cycle starting from the current course
    const _hasCycle = hasCycle(currCourse, graph, path)

    // Unmark the current course after the check
    path[currCourse] = false;

    return _hasCycle
}

var hasCycle = (currCourse, graph, path) => {
    // For each neighbor of the current course, check for cycles
    for (const neighbor of graph[currCourse]) {
        if (isCyclic(neighbor, graph, path)) return true;
    }

    return false
}
```

### Go
```
func canFinish(numCourses int, prerequisites [][]int) bool {
	graph := make(map[int][]int)

	for _, prer := range prerequisites {
		graph[prer[1]] = append(graph[prer[1]], prer[0])
	}

	visitSet := make(map[int]struct{})

	var dfs func(course int) bool

	dfs = func(course int) bool {
		if _, ok := visitSet[course]; ok {
			return false
		}

		if len(graph[course]) == 0 {
			return true
		}

		visitSet[course] = struct{}{}

		for _, pre := range graph[course] {
			if !dfs(pre) {
				return false
			}
		}
		delete(visitSet, course)

		graph[course] = []int{}

		return true
	}

	for i := 0; i < numCourses; i++ {
		if !dfs(i) {
			return false
		}
	}

	return true
}
```
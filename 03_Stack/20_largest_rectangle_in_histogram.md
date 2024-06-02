Stack 7
# Largest Rectangle in Histogram
## Company: Google
### Level: Hard

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`,
return the *area of the largest rectangle in the histogram*.

***Break It Down For Me...***
*We're given an array of integers representing the heights of bars within histogram.*
*The width of each bar is assumed to be 1 unit.*
*We need to find the largest rectangle that can be formed within this histogram.*

Click [here](https://leetcode.com/problems/largest-rectangle-in-histogram/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=zx5Sw9130L0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) in Python, JavaScript and Go.

### Example 1
```
Input: heights = [2, 1, 5, 6, 2, 3]
Output: 10
```

### Example 2
```
Input: [2, 4]
Output: 4
```

## Python
```
maxArea = 0

stack = []  # Stack elements: (index, height)

for i, h in enumerate(heights):
    start = i
    while stack and stack[-1][1] > h:
        index, height = stack.pop()
        maxArea = max(maxArea, height * (i - index))
        start = index
    stack.append((start, h))

for i, h in stack:
    maxArea = max(maxArea, h * (len(heights) - i))

return maxArea

# Code comments can be found in largest_rectangle_in_histogram.py
```

## JavaScript
```
var largestRectangleArea = function(heights, left = 0, right = (heights.length - 1)) {
    const isBaseCase = right < left;
    if (isBaseCase) return 0;

    return divideAndConquer(heights, left, right);
}

const divideAndConquer = (heights, left, right, min = left) => {
    for (let i = left; i <= right; i++) {
        const isMinGreater = heights[i] < heights[min];
        if (!isMinGreater) continue;

        min = i;
    }

    const window = (right - left) + 1;

    const area = heights[min] * window;

    const leftArea = largestRectangleArea(heights, (min + 1), right);
    const rightArea = largestRectangleArea(heights, left, (min - 1));

    return Math.max(area, leftArea, rightArea);
}

// Code comments can be found in largestRectangleInHistogram.js
```

## Go
```
type StackValue struct {
	index  int
	height int
}

func largestRectangleArea(heights []int) int {
	stack := []StackValue{}
	maxArea := 0
	var start int

	for i, h := range heights {
		start = i
		for len(stack) != 0 && stack[len(stack)-1].height > h {
			index, height := stack[len(stack)-1].index, stack[len(stack)-1].height
			stack = stack[0 : len(stack)-1] 
			maxArea = max(maxArea, height*(i-index))
			start = index
		}
		stack = append(stack, StackValue{start, h})
	}

	for _, h := range stack {
		maxArea = max(maxArea, h.height*(len(heights)-h.index))
	}
	return maxArea
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Code comments can be found in largestRectangleInHistogram.go
```
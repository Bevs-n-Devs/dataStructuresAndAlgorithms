Two Pointers 4
# Container With Most Water 
## Company: Meta & Google
### Level: Medium

You are given an integer array `height` of length `n`.
There are `n` verticle lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

*Return the maximum amount of water a container can store.*

**Notice that you cannot slant the container.**

***Break It Down For Me...***
*Imagine you have a bunch of lines on a piece of paper, each line has a different height.*
*We need to figure out the following:*
- *Find two lines that along with the bottom of the paper, makes a container. This container should hold as much water as possible.*
- *The lines cannot be diagonal; they must be straight up and down.*
- *We need to figure out how much water the container can hold.*

Click [here](https://leetcode.com/problems/container-with-most-water/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=UuiTKBwPgAo) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use the [Pointer method](https://www.studysmarter.co.uk/explanations/computer-science/computer-programming/pointers-and-arrays/#:~:text=C%20programming%20language%3F-,A%20pointer%20is%20a%20variable%20that%20stores%20the%20memory%20address,the%20efficiency%20of%20certain%20algorithms.) in Python, JavaScript and Go.

### Example 1
```
Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49
```
**Explanation:** The above vertical lines are represented by array `[1, 8, 6, 2, 5, 4, 8, 3, 7]`.
In this case, the max area of water the container can contain is 49.

### Example 2
```
Input: height = [1, 1]
Output: 1
```

## Python
```
left, right = 0, len(height) - 1
result = 0

while left < right:
    result = max(result, min(height[left], height[right]) * (right - left))
    
    if height[left] < height[right]:
        left += 1
    elif height[right] <= height[left]:
        right -= 1
    
return result

# Code comments can be found in container_with_most_water.py
```

## JavaScript
```
let [left, right, max] = [0, height.length - 1, 0];

while (left < right) {
    let containerHeight, area;

    let containerWidth = right - left;

    if (height[left] < height[right]) {
        containerHeight = height[left];
        left++;
    } else {
        containerHeight = height[right];
        right--;
    }

    area = containerWidth * containerHeight;

    if (area > max) {
        max = area;
    }
}

return max;

// Code comments can be found in containerWithMostWater.js
```

## Go
```
func maxArea(height []int) int {
	left := 0
	right := len(height) - 1
	res := 0

	for left < right {
		area := min(height[left], height[right]) * (right - left)

		if area > res {
			res = area
		}

		if height[left] > height[right] {
			right--
		} else {
			left++
		}
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Code comments can be found in containerWithMostWater.go
```
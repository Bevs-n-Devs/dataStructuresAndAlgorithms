Binary Search 1
# Binary Search
## Company: Microsoft
### Level: Easy

Given an array of integers `nums` which is sorted in an ascending order, and an integer `target`, write a function to search `target` in `nums`.
If target exists, then return its index.
Otherwise return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

***Break This Down For Me...***
*Lets say we have a list of numbers and we want to find a specific number in the list.*
*If the list is sorted we can use a [Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm) to find the answer.*
*A binary search is like flipping through a book; you start at the middle, checking if the page number you're looking for is higher or lower than the middle pages.*
*You then repeat the process in the half where your page number might be until you find it.*

Click [here](https://leetcode.com/problems/binary-search/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=s4DPM8ct1pI) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Binary Search](https://www.geeksforgeeks.org/what-is-binary-search-algorithm/) in Python, JavaScript and Go.

### Example 1
```
Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
```
**Explanation:** `9` exists in nums and its index is `4`.

### Example 2
```
Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1
```
**Explanation:** `2` does not exist in nums so return `-1`.

## Python
```
l, r = 0, len(nums) - 1

while l <= r:
    m = l + ((r - l) // 2)  # (l + r) // 2 can lead to overflow

    if nums[m] > target:
        # the right pointer now updated
        r = m - 1
    
    elif nums[m] < target:
        l = m + 1

    else:
        return m    # return index

return -1

# Code comments can be found in binary_search.py
``

## JavaScript
```
let left = 0, right = nums.length - 1;

while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    
    if (nums[mid] > target) {
        right = mid - 1;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        return mid;
    }
}
return -1;

// Code comments can be found in binarySearch.js
```

## Go
```
package main

func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1

	for left <= right {
		middle := (left + right) / 2

		if nums[middle] == target {
			return middle
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			right = middle - 1
		}
	}
	return -1

}

// Code comments can be found in binarySearch.go
``` 
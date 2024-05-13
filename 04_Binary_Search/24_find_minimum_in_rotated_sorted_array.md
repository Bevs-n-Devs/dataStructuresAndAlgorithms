Binary Search 4
# Find Minimum in Rotated Sorted Array
## Company: Meta
### Level: Medium

Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times.
For example, the array `nums = [0,1,2,4,5,6,7]` might become:
- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, *return the minimum element of this array.*

*You must write an algorithim that runss `O(log n)` time.*

***Break It Down For Me...***
*We are given an array that has already been sorted in ascending order, but has been rotated between `1` and `n` times.*
*The goal is to find out the smallest element in this array.*
*The algorithm needs to be `O(log n)` which means as the array gets bigger, the time it takes for the algorithm to run should increase at a slow rate.*

### Example 1
```
Input: nums = [3, 4, 5, 1, 2]
Output: 1
```
**Explanation:** The original array was `[1, 2, 3, 4, 5]` rotated 3 times.

### Example 2
```
Input: nums = [4, 5, 6, 7, 0, 1, 2]
Output: 0
```
**Explanation:** The orginal array was `[0, 1, 2, 3, 4, 5, 6, 7]` was rotated 4 times.

### Example 3
```
Input: nums = [11, 13, 15, 17]
Output: 11
```
**Explanation:** The original array was `[11, 13, 15, 17]` and was rotated 4 times.

## Python
```
start, end = 0, len(nums) - 1 

curr_min = float("inf")

while start < end:
    mid = (start + end) // 2
    
    curr_min = min(curr_min, nums[mid])
    
    if nums[mid] > nums[end]:
        start = mid + 1
        
    else:
        end = mid - 1 

return min(curr_min, nums[start])

# Code comments can be found in find_minimum_in_rotated_array.py
```

## JavaScript
```

while (left < right) {
    const mid = (left + right) >> 1;
    const guess = nums[mid];
    const [leftNum, rightNum] = [nums[left], nums[right]];

    const isTarget = leftNum < rightNum;
    if (isTarget) return leftNum;

    const isTargetGreater = leftNum <= guess;
    if (isTargetGreater) left = mid + 1;

    const isTargetLess = guess < leftNum;
    if (isTargetLess) right = mid;
}

return nums[left];

// Code comments can be found in findMinimumInRotatedSortedArray.js
```

## Go
```
func findMin(nums []int) int {
    res := nums[0]
    l, r := 0, len(nums)-1
    
    for l <= r {
        p := (l+r) / 2
        if nums[p] >= nums[0] {
            l = p+1
        } else {
            if nums[p] < res {
                res = nums[p]
            }
            r = p-1
        }
    }
    
    return res
}

// Code comments can be found in findMinimumInSortedArray.go
```
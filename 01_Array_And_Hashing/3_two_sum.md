Array And Hashing 3
# Two Sum
## Company: N/A
### Level: Easy

Given an arrat of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to* `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

***Break It Down For Me...***
*We are given two variables; `nums` is a list and `target` is an integer.*
*What we need to do is create a function that will check if any of the numbers inside of the `nums` list can form the `target` number.*
*If it does, then we need to return the the number's list index as the answer.*

Click [here](https://leetcode.com/problems/two-sum/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=KLlXCFG5TnA) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challange we will use a **[Hash Map](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used)** in the Python, JavaScript and Go solution.

### Example 1
Input: `nums = [2, 7, 11, 15], target = 9`

Output: `[0, 1]`

*Explanation: Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.*

### Example 2
Input: `nums = [3, 2, 4], target = 6`

Output: `[1, 2]`

### Example 3
Input: `nums = [3, 3], target = 6`

Output: `[0, 1]`


## Python Solution
```
prevMap = {}  # val -> index

for i, n in enumerate(nums):
    diff = target - n

    if diff in prevMap:
        return [prevMap[diff], i]

    prevMap[n] = i

# Code comments can be found in two_sum.py
```

## JavaScript Solution
```
var twoSum = function(nums, target) {
    const prevMap = {};

    for (let i = 0; i < nums.length; i++) {
        const diff = target - n;
        
        if (prevMap.hasOwnProperty(diff)) {
            return [prevMap[diff], i];
        }
        
        prevMap[n] = i;
    }
    return null
};


// Code comments can be found in two_sum.js
```

## Go Solution
```
hashmap := make(map[int]int)
    
for listIndex := 0; listIndex < len(nums); listIndex++ {

    num := nums[listIndex]
    diff := target - num
    
    if _, found := hashmap[diff]; found {
        return []int{hashmap[diff], listIndex}
    }
    
    hashmap[num] = listIndex
}

return nil

// Code comments can be found in two_sum.go
```
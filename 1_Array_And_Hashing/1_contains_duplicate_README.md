Arrays And Hashing 1
# Contains Duplicate
## Company: Amazon
### Level: Easy


Given an integer array `nums`, return `true` if any value appears at least **twice** in the array, 
and return `false` if every element is distinct.

***Break It Down For Me...***

*Imagine you have a list of numbers.*
*If any number appears in the list more than once, then you should return `true`.*
*However, if there are no duplicates return `false`.*

To solve this challenge we will use a **Hash Set** in the Python solution, and a **Pointer** solution for JavaScript and Go.

Click [here](https://leetcode.com/problems/contains-duplicate/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=3OamzN90kPg) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**


### Example 3:
Input: `nums = [1,1,1,3,3,4,3,2,4,2]`

Output: `true`

### Example 1:
Input: `nums = [1,2,3,1]`

Output: `true`

### Example 2:
Input: `nums = [1,2,3,4]`

Output: `false`
 

## Python Solution
```
hashset = set()

for num in nums:
    if num in hashset:
        return True
    hashset.add(num)
return False

# Code comments can be found in contains_duplicate.py
```

## JavaScript Solution
```
for (let right = 0; right < nums.length; right++) {
    for (let left = 0; left < right; left++) { 
        const isDuplicate = nums[left] === nums[right];
        if (isDuplicate) return true;
    }
}
return false;

// Code comments can be found in contains_duplicate.js
```

## Go Solution
```
var isDuplicate bool

for right := 0; right < len(nums); right++ {
    for left := 0; left < right; left++ {
        if nums[left] == nums[right] {
            isDuplicate = true
            break
        }
    }
    if isDuplicate {
        break
    }
}
return isDuplicate

// Code comments can be found in contains_duplicate.go
```
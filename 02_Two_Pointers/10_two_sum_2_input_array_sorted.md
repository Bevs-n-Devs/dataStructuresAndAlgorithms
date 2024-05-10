Two Pointers 2
# Two Sum 2: Input Array Sorted
## Company: Amazon
## Level: Medium

Given a **1-indexed** array of integers `numbers` that is alraedy **sorted in non-decreaing order**, find two numbers such that they add up to a specific `target` number.
Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers, `index1` and `index2`, **added by one** as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**.
You **may not** use the same element twice.

Your solution must use only constant extra space.

***Break It Down For Me...***
*You need to find two numbers in a sorted list of integers that add up to a specific number stored as a variable called `target`.*
*You have to return the index of the two numbers that sum to the `target` value.*
**We need to remember that when returning the list indexes, the list index starts from `1` and not `0`.**

Click [here](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=cQ1Oz4ckceM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use the [Pointer method](https://www.studysmarter.co.uk/explanations/computer-science/computer-programming/pointers-and-arrays/#:~:text=C%20programming%20language%3F-,A%20pointer%20is%20a%20variable%20that%20stores%20the%20memory%20address,the%20efficiency%20of%20certain%20algorithms.) in Pythopn, JavaScript and Go.


### Eaxmple 1
Input: `numbers = [2, 7, 11, 15], target = 9`

Output: [1, 2]

### Example 2
Input: `numbners = [2, 3, 4], target = 6`

Output: `[1, 3]`

### Example 3
Input: `numbers = [-1, 0], target = -1`

Output: `[1, 2]`


## Python
```
left, right = 0, len(numbers) - 1

while left < right:
    curSum = numbers[left] + numbers[right]

    if curSum > target:
        right -= 1
    elif curSum < target:
        l += 1
    else:
        return [left + 1, right + 1]

# Code comments can be found in two_sum_2_input_array_sorted.py
```

## JavaScript
```
var twoSum = function(numbers, target) {
    let pLeft = 0, pRight = (numbers.length) - 1;
    
    while (pLeft < pRight) {
        let currentSum = numbers[pLeft] + numbers[pRight];
        
        if (currentSum > target) {
            pRight -= 1;
        } else if (currentSum < target) {
            pLeft += 1;
        } else {
            return [pLeft + 1, pRight + 1];
        }
    }
};

// Code comments can be found in two_sum_2_input_array_sorted.md

```

## Go
```
p1 := 0
p2 := len(numbers) - 1
for p1 < p2 {
    n := numbers[p1] + numbers[p2]

    if n == target {
        return []int{p1 + 1, p2 + 1}
    }

    if n > target {
        p2--
    } else { 
        p1++
    }
}

return []int{0, 0}

// Code comments can be found in two_sum_2_input_array_sorted.go
```
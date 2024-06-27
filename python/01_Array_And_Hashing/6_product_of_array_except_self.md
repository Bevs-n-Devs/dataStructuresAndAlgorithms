Arrays And Hashing 6
# Product of Array Except Self
## Company: Amazon
### Level: Medium

Given an array of `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

***Break It Down For Me***
*You are given a list of integers, what you need to do is find the product of all the numbers within the list.*
*While looping through the list, for each number, calculate the product of all the other numbers excluding the current one.*
*This means multiplying all the numbers together except for the one you're currently on.*

Click [here](https://leetcode.com/problems/product-of-array-except-self/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=bNvIQI2wAjk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this solution we will use a **[Two-Pass Algorithm](https://uo-cis211.github.io/chapters/08_1_Twopass.html#:~:text=We%20often%20use%20multi%2Dpass,%E2%80%9Cpass%E2%80%9D%20to%20use%20it.)** (which is essentially an efficient nested loop).

### Example 1
Input: `nums = [1, 2, 3, 4]`

Output: `[24, 12, 8, 6]`

###  Example 2
Input: `nums = [-1, 1, 0, -3, 3]`

Output: `[0, 0, 9, 0, 0]`


## Python Solution#
```
result = [1] * (len(nums))

for index in range(1, len(nums)):
    result[index] = result[index-1] * nums[index-1]

postfix = 1

for index in range(len(nums) - 1, -1, -1):
    result[index] *= postfix
    postfix *= nums[index]

return result

# Code comments can be found in product_of_arrary_except_self.py
```

## JavaScript Solution
```
const result = [];

let prefix = 1;

for (let index = 0; index < nums.length; index++) {
    result[index] = prefix;
    prefix *= nums[index];
}

let postfix = 1;

for (let index = nums.length - 2; index >= 0; index--) {
    postfix *= nums[index + 1];
    result[index] *= postfix;
}

return result;

// Code comments can be found in product_of_arrary_except_self.js
```

## Go Solution
```
result := make([]int, len(nums))

for index := range result {
    result[index] = 1
}

for index := 1; index < len(nums); index++ {
    result[index] = result[index-1] * nums[index-1]
}

postfix := 1

for index := len(nums) - 1; index >= 0; index-- {
    result[index] *= postfix
    postfix *= nums[index]
}

return result

// Code comments can be found in product_of_arrary_except_self.go
```
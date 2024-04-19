19/04/2024
# Jump Game 
## Company: Amazon

You are given an integer array `nums`. You are initially positioned at the array's **first index**,
and each element in the array represents your maximum jump length at that position.

Retun `true` only *if you can reach the last index, or `false` otherwise*.

***Break It Down For Me...***
*You have a list of numbers and what you need to do is jump from the first index `0` to the last*
*index of the array. Each index value will represent how many indexes you can jump to. So if the index*
*you are on has a value of `2`, this means you can jump 2 indexes forward.*  
***Remember when counting list indexes, the frist index is always 0.***

To solve this challenge we will use a **Greedy Algorithm**.


Click [here](https://leetcode.com/problems/jump-game/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Yan0cv2cLy8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**


### Example 1:
Input: `nums = [2, 3, 1, 1, 4]`

Output: `true`

Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Example 2:
Input: `nums = [3, 2, 1, 0, 4]`

Output: `false`


## Python Solution
```
class Solution:
    def canJump(self, nums: list[int]) -> bool:
        goal = len(nums) - 1

        for index in range(len(nums) -2, -1, -1):
            if index + nums[index] >= goal:
                goal = index
        
        return goal == 0

# Code comments can be found in jump_game.py file
```

## JavaScript Solution
```
var canJump = (nums, right = nums.length - 1) {
    for (let index = right; 0 <=index; index--) {
        const isJumpable = right <= (index + nums[index]);
        if (isJumpable) right = i;
    }

    return right === 0;
}

// Code comments can be found in jump_game.js
```
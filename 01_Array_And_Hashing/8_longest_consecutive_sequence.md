Arrays And Hashing 8
# Longest Consecutive Sequence
## Company: Google
### Level: Medium

Given an unsorted array of integers `num`, return the *return the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in [`O(n)`](https://neetcode.io/courses/lessons/big-o-notation) time.


***Break It Down For Me...***
*You have a bunch of numbers in a list.*
*What you need to do is find the longest sequence of consecutive numbers in that list, then display those numbers as the answer.*
*So if we have `[100, 4, 200, 3, 1, 2]`, the longest sequence would be `[1, 2, 3, 4]`.*
*The key thing to do is to return the results as quick as possible.*

Click [here](https://leetcode.com/problems/longest-consecutive-sequence/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=P6RZZMu_maU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**


### Example 1
Input: `nums = [100, 4, 200, 1, 3, 2]`

Output: `4`

**Explanation:**
*The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

### Example 2
Input: `nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`

Output: `9`

# Python
```
numSet = set(nums)
longest = 0

for n in numSet:
    if (n - 1) not in numSet:
        length = 1
        while (n + length) in numSet:
            length += 1
        longest = max(length, longest)

return longest

# Code comments can be found in longest_consecutive_sequence.py
```

# JavaScript
```
const numSet = new Set(nums); /* Time O(N) | Space O(N) */

for (const num of [...numSet]) { /* Time O(N) */
    const prevNum = num - 1;

    if (numSet.has(prevNum)) continue; /* Time O(N) */

    let [currNum, score] = [num, 1];

    const isStreak = () => numSet.has(currNum + 1);

    while (isStreak()) { /* Time O(N) */
        currNum++;
        score++;
    }

    maxScore = Math.max(maxScore, score);
}

return maxScore;

// Code comments can be found in longest_consecutive_sequence.js
```

# Go
```
set := map[int]bool{}

for _, num := range nums {
    set[num] = true
}

result := 0

for _, num := range nums {
    if set[num-1] {
        continue
    }

    sequence := 1
    temp := num + 1

    for set[temp] {
        sequence++
        temp++
    }

    if sequence > result {
        result = sequence
    }
}

return result

// Code comments can be found in longest_consecutive_sequence.go
```
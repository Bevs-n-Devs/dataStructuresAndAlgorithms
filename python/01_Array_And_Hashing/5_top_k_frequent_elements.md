Arrays And Hashing 5
# Top K Frequent Elements
## Company: Amazon
### Level: Medium

Given an integer array `num` and an integer `k`, return the `k` most frequent elements. You may return the answer in any answer.

***Break It Down For Me...***
*You are given two variables; one is a list of integers and the other is a number.*
*What we need to do is find the integer(s) that appear in the list the most.*
*The variable that is a number indicates how many of the most frequent integers we need to find.*

Click [here](https://leetcode.com/problems/top-k-frequent-elements/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=XEmy13g1Qxc) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challange we will use a **[Hash Map](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used)** in the Python, JavaScript and Go solution.

### Example 1
Input: `nums = [1, 1, 1, 2, 2, 3], k = 2`

Output: `[1, 2]`

### Example 2
Input: `nums = [1], k = 1`

Output: `[1]`


## Python Solution
```
count = {}

freq = [[] for i in range(len(nums) + 1)]

for n in nums:
    count[n] = 1 + count.get(n, 0)

for n, c in count.items():
    freq[c].append(n)

res = []

for i in range(len(freq) - 1, 0, -1):

    for n in freq[i]:
        res.append(n)

        if len(res) == k:
            return res

return res

# Code comments can be found in top_k_frequent_elements.py
```

## JavaScript Solution
```
var topKFrequent = function(nums, k) {
    const mp = new Map();

    const arr = new Array(nums.length + 1).fill(0);

    const ans = [];

    nums.forEach(el => {
        const val = mp.get(el) || 0;
        mp.set(el, val + 1);
    });

    for (let [key, value] of mp) {
        const prev = arr[value] || [];
        prev.push(key);
        arr[value] = prev;
    }

    arr.reverse();

    for (let el of arr) {
        if (k < 1) break;
        if (el) {
            for (let el2 of el) {
                ans.push(el2);
                k--;
            }
        }
    }

    return ans;
};

// Code comments can be found in top_k_frequent_elements.js
```

## Go Solution
```
count := make(map[int]int)

freq := make([][]int, len(nums)+1)

for _, num := range nums {
    count[num]++
}

for index, num := range count {
    freq[num] = append(freq[num], index)
}

result := make([]int, 0, k)

for index := len(freq) - 1; index > 0; index-- {
    for _, num := range freq[index] {
        result = append(result, num)
        if len(result) == k {
            return result
        }
    }
}

return result

// Code comments can be found in top_k_frequent_elements.go
```

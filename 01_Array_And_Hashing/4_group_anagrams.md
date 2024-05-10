Arrays And Hashing 4
# Group Anagram
## Company: Amazon
### Level: Medium

Given the array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

*An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*

***Break It Down For Me...***
*You are given an array of strrings and what we need to do is group together all the words that have the same set of letters.*

Click [here](https://leetcode.com/problems/group-anagrams/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=vzdNOK2oB2E) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challange we will use a **[Hash Map](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used)** in the Python, JavaScript and Go solution.  With the Python solution we will use Python's built-in **[collections](https://docs.python.org/3/library/collections.html)** library.

### Example 1
Input: `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]`

Output: `[["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]`

### Example 2
Input: `strs = [""]`

Output: `[[""]]`

### Example 3
Input: `strs = ["a"]`

Output: `[["a"]]`


## Python Saolution
```
ans = collections.defaultdict(list)

for s in strs:
    count = [0] * 26

    for c in s:
        count[ord(c) - ord("a")] += 1

    ans[tuple(count)].append(s)

return ans.values()

# Code comments can be found in group_anagram.py
```

## JavaScript Solution
```
 const groupedAnagrams = new Map();

for (const str of strs) {
    const key = str.split('').sort().join('');
    if (!groupedAnagrams.has(key)) {
        groupedAnagrams.set(key, []);
    }
    groupedAnagrams.get(key).push(str);
}

return Array.from(groupedAnagrams.values());

// Code comments can be found in group_anagarams.js
```

## Go Solution
```
groupedAnagrams := make(map[string][]string)

for _, str := range strs {
    slice := []byte(str)

    sort.Slice(slice, func(i, j int) bool {
        return slice[i] < slice[j]
    })
    sortedStr := string(slice)

    if _, ok := groupedAnagrams[sortedStr]; !ok {
        groupedAnagrams[sortedStr] = []string{}
    }

    groupedAnagrams[sortedStr] = append(groupedAnagrams[sortedStr], str)
}

result := make([][]string, 0, len(groupedAnagrams))
for _, v := range groupedAnagrams {
    result = append(result, v)
}

return result

// Code comments can be found in group_anagrams.go
```

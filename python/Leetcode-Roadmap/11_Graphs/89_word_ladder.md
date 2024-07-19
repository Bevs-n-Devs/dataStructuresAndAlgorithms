Graphs 13
# Word Ladder
## Company: Google
### Level: Hard

 A transformation sequence from word `beginWord` to word `endWord` using a dictionary ``wordList`` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`
Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words in the shortest transformation sequence** from `beginWord` to `endWord`, or `0` if no such sequence exists.

***Break It Down Down FOR mE...***
*We have two words: a starting word (called `beginWord`) and an ending word (called `endWord`). You also have a list of words (called `wordList`).*

*We need to change `beginWord` to `endWord` by changing only one letter at a time. Each new word you form must be in the `wordList`.*

*Our task is to find the shortest path of these changes to get from `beginWord` to `endWord`. If it's not possible to get from `beginWord` to `endWord`, return `0`.*

Click [here](https://leetcode.com/problems/word-ladder/description/)for the question on Neetcode.

Click [here](https://www.youtube.com/watch?v=h9iTnkgv05E) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Graphs](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=Graphs%20in%20data%20structures%20are,circuit%20networks%2C%20and%20social%20networks.) as a data structure in Python, JavaScript & Go.

### Example 1
```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5

# Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

### Example 2
```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0

# Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

## Python
```
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # If endWord is not in wordList, return 0
        if endWord not in wordList:
            return 0

        # Initialize a defaultdict to store patterns
        nei = collections.defaultdict(list)
        wordList.append(beginWord)
        # Create a pattern map
        for word in wordList:
            for j in range(len(word)):
                pattern = word[:j] + "*" + word[j + 1:]
                nei[pattern].append(word)

        # Initialize a set to keep track of visited words
        visit = set([beginWord])
        # Initialize a queue for BFS
        q = deque([beginWord])
        # Initialize the result as 1
        res = 1
        # Perform BFS
        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for j in range(len(word)):
                    pattern = word[:j] + "*" + word[j + 1:]
                    for neiWord in nei[pattern]:
                        if neiWord not in visit:
                            visit.add(neiWord)
                            q.append(neiWord)
            res += 1
        return 0
```

## JavaScript
```
var ladderLength = function(beginWord, endWord, wordList) {
    // Initialize the queue, wordSet, and seen set
    const [ queue, wordSet, seen ] = [ new Queue([[ beginWord, 1 ]]), new Set(wordList), new Set([ beginWord ]) ];

    return bfs(queue, wordSet, seen, endWord); // Call BFS function
};

// BFS function to find the shortest path
const bfs = (queue, wordSet, seen, endWord) => {
    while (!queue.isEmpty()) {
        for (let i = (queue.size() - 1); 0 <= i; i--) {
            const [ word, depth ] = queue.dequeue();

            const isTarget = word === endWord;
            if (isTarget) return depth;

            transform(queue, wordSet, seen, word, depth); // Transform the word and add neighbors to the queue
        }
    }

    return 0;
};

// Transform the word by changing one character at a time
const transform = (queue, wordSet, seen, word, depth) => {
    for (const index in word) {
        for (const char of 'abcdefghijklmnopqrstuvwxyz') {
            const neighbor = getNeighbor(word, index, char);

            const hasSeen = !wordSet.has(neighbor) || seen.has(neighbor);
            if (hasSeen) continue;

            queue.enqueue([ neighbor, (depth + 1) ]);
            seen.add(neighbor);
        }
    }
};

// Helper function to get the neighbor word by changing one character
const getNeighbor = (word, index, char) => {
    const neighbor = word.split('');

    neighbor[index] = char;

    return neighbor.join('');
};
```

## Go
```
func ladderLength(beginWord string, endWord string, wordList []string) int {
    // Check if the endWord is in the wordList
    if !contains(wordList, endWord) {
        return 0
    }

    // Initialize a map to store patterns
    nei := make(map[string][]string)
    // Add beginWord to the wordList
    wordList = append(wordList, beginWord)
    // Create a pattern map
    for _, word := range wordList {
        for j := 0; j < len(word); j++ {
            pattern := word[:j] + "*" + word[j+1:]
            nei[pattern] = append(nei[pattern], word)
        }
    }

    // Initialize a visit map to keep track of visited words
    visit := map[string]bool{beginWord: true}
    // Initialize a queue for BFS
    q := []string{beginWord}
    // Initialize the result as 1
    res := 1
    // Perform BFS
    for len(q) != 0 {
        for tmp := len(q); tmp > 0; tmp-- {
            word := q[0]
            q = q[1:]
            if word == endWord {
                return res
            }
            for j := 0; j < len(word); j++ {
                pattern := word[:j] + "*" + word[j+1:]
                for _, neiWord := range nei[pattern] {
                    if !visit[neiWord] {
                        visit[neiWord] = true
                        q = append(q, neiWord)
                    }
                }
            }
        }
        res += 1
    }
    return 0
}

// Helper function to check if the wordList contains the endWord
func contains(s []string, word string) bool {
    for _, element := range s {
        if element == word {
            return true
        }
    }
    return false
}
```
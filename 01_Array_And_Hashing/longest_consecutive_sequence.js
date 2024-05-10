var longestConsecutive = (nums, maxScore = 0) => {
    // Create a set to efficiently check existence of numbers
    const numSet = new Set(nums); /* Time O(N) | Space O(N) */

    // Iterate through each unique number in the set
    for (const num of [...numSet]) { /* Time O(N) */
        const prevNum = num - 1;

        // Skip if the current number is not the start of a sequence
        if (numSet.has(prevNum)) continue; /* Time O(N) */

        // Initialize variables for the current number and the current score
        let [currNum, score] = [num, 1];

        // Helper function to check if there is a streak of consecutive numbers
        const isStreak = () => numSet.has(currNum + 1);

        // Iterate through the consecutive streak and update the score
        while (isStreak()) { /* Time O(N) */
            currNum++;
            score++;
        }

        // Update the maximum score if the current streak is longer
        maxScore = Math.max(maxScore, score);
    }

    // Return the maximum consecutive sequence length
    return maxScore;
}

// implementation
console.log("Leetcode 128: Longest Consecutive Sequence\n");

// Example 1
example1 = [100, 4, 200, 1, 3, 2];
console.log(`Example 1: nums = [${example1}]`);
console.log("Output:", longestConsecutive(example1));

// Example 2
example2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1];
console.log(`Example 2: nums = [${example2}]`);
console.log("Output:", longestConsecutive(example2));
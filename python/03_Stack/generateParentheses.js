// Function to generate all valid combinations of parentheses for a given value of n
var generateParenthesis = (n, combos = []) => {
    // Check if the base case is reached (no remaining parentheses to add)
    const isBaseCase = (n === 0);

    // If it is the base case, add an empty string to the combinations and return
    if (isBaseCase) {
        combos.push('');
        return combos;
    }

    // Iterate through possible values of c, where c represents the number of parentheses on the left
    for (let c = 0; c < n; c++) {
        // Recursively generate combinations for the left and right parts
        for (const left of generateParenthesis(c)) {
            for (const right of generateParenthesis((n - 1) - c)) {
                // Combine the left and right parts and add to the combinations
                combos.push(`(${left})${right}`);
            }
        }
    }

    // Return the list of valid combinations
    return combos;
};

// implementation
console.log("Leetcode 22: Generate Parentheses\n");

// Example 1
var example1 = 3;
console.log(`Example 1: n = ${example1}`);
console.log("Output:", generateParenthesis(example1));

// Example 2
var example2 = 1;
console.log(`Example 2: n = ${example2}`);
console.log("Output:", generateParenthesis(example2));
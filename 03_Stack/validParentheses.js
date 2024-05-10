var isValid = function(s) {
    // create hashmap
    const hashmap = {'}':'{', ']':'[', ')':'('};
    // create stack
    let stack = [];
    
    // check if char is in hashmap
    for (let index = 0; index < s.length; index++) {
        let char = s[index];
        
        // check if NOT closing paretheses
        if (!(char in hashmap)) {
            stack.push(char);
            continue;
        }
        
        // if NOT in stack OR NOT closing parethesis
        if (stack.length === 0 || stack[stack.length- 1] !== hashmap[char]) {
            return false;
        }
        
        // if the above positions are not met then we have a match!
        stack.pop();
    }
    // returns true is the stack is empty
    return stack.length === 0;
};

// implementation

console.log("Leetcode 20: Valid Parentheses\n");

// Example 1
const example1 = "()";
console.log(`Example 1: s = ${example1}`);
console.log("Output", isValid(example1));

// Example 2
const example2 = "()[]{}";
console.log(`Example 2: s = ${example2}`);
console.log("Output:", isValid(example2));

// Example 3
const example3 = "(]";
console.log(`Example 3: s = ${example3}`);
console.log("Output:", isValid(example3));
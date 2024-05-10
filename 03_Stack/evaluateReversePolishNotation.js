var evalRPN = function (tokens, stack = []) {
    for (const char of tokens) {
        const isOperation = char in OPERATORS;
        if (isOperation) {
            const value = performOperation(char, stack);

            stack.push(value);    

            continue;
        }

        stack.push(Number(char)); 
    }

    return stack.pop();
}

var OPERATORS = {
    '+': (a, b) => a + b,
    '-': (a, b) => a - b,
    '*': (a, b) => a * b,
    '/': (a, b) => Math.trunc(a / b)
};

var performOperation = (char, stack) => {
    const [ rightNum, leftNum ] = [ stack.pop(), stack.pop() ];
    const operation = OPERATORS[char];

    return operation(leftNum, rightNum);
}

// implementation
console.log("Leetcode 150: Evaluate Reverse Polish Notation");

// Example 1
example1 = ["2", "1", "+", "3", "*"];
console.log(`Example 1: tokens = [${example1}]`);
console.log("Output:", evalRPN(example1));

// Example 2
exapmle2 = ["4", "13", "5", "/", "+"];
console.log(`Example 2: tokens = [${exapmle2}]`);
console.log("Output", evalRPN(exapmle2));

// Example 3
example3 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"];
console.log(`Example 3: tokens = [${example3}]`);
console.log("Output:", evalRPN(example3));
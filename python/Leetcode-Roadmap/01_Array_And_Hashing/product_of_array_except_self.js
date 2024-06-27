function productExceptSelf(nums) {
    // Initialize an array to store the final result
    const result = [];
    
    // Initialize a variable to store the prefix product
    let prefix = 1;
    
    // Calculate the prefix products and update the result array
    for (let i = 0; i < nums.length; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Initialize a variable to store the postfix product
    let postfix = 1;

    // Calculate the postfix products and update the result array in reverse order
    for (let i = nums.length - 2; i 
        >= 0; i--) {
        postfix *= nums[i + 1];
        result[i] *= postfix;
    }

    // Return the final result array
    return result;
};


// implementation
console.log("Leetcode 238: Product of Array Except Self\n");

// Example 1
example1 = [1, 2, 3, 4];
console.log(`Example 1: nums = [${example1}]`);
console.log("Output:", productExceptSelf(example1));

// Example 2
example2 = [-1, 1, 0, -3, 3];
console.log(`Example 2: nums = [${example2}]`);
console.log("Output:", productExceptSelf(example2));
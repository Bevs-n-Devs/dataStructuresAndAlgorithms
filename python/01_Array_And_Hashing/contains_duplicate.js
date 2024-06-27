/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    // loop through nums list
    for (let right = 0; right < nums.length; right++) {
        // loop through each right pointer
        for (let left = 0; left < right; left++) { 
            // check if both pointers are duplicate
            const isDuplicate = nums[left] === nums[right];
            // return true if match is found
            if (isDuplicate) return true;
        }
    }
    // return false if no match 
    return false;
};


// implementation
console.log("Leetcode 217: Contains Duplicate\n");

// Example 1
const example1 = [1, 2, 3, 1];
console.log(`Example 1: num = [${example1}]`);
console.log("Output:", containsDuplicate(example1));

// Example 2
const example2 = [1, 2, 3, 4];
console.log(`Example 2: num = [${example2}]`);
console.log("Output:", containsDuplicate(example2));

// Example 3
const example3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
console.log(`Example 3: num = [${example3}]`);
console.log("Output:", containsDuplicate(example3));
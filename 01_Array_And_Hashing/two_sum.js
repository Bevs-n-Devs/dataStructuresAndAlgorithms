/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    // create empty hashmap
    const hashmap = {};

    // loop list via its length
    for (let index = 0; index < nums.length; index++) {
        const num = nums[index];          // get each number from list
        const diff = target - num;    // target minus the value in each list
        
        // check if diff is in hashmap
        if (hashmap.hasOwnProperty(diff)) {
            return [hashmap[diff], index];
        }
        
        // update hashmap -> list value: list index
        hashmap[num] = index;
    }
    return null
};


// implementation
console.log("Leetcode 1: Two Sum\n")
// Example 1
const example1 = [2, 7, 11, 15];
const target1 = 9;
console.log(`Example 1: nums = [${example1}], target = ${target1}`)
console.log("Output:", twoSum(example1, target1))

// Example 2
const example2 = [3, 2, 4];
const target2 = 6;
console.log(`Example 2: nums = [${example2}], target = ${target2}`)
console.log("Output:", twoSum(example2, target2))

// Example 3
const example3 = [3, 3];
const target3 = 6;
console.log(`Example 3: nums = [${example3}], target = ${target3}`)
console.log("Output:", twoSum(example3, target3))
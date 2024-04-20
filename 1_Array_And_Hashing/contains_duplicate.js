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
const example_1 = [1, 2, 3, 1];
console.log(containsDuplicate(example_1));

const example_2 = [1, 2, 3, 4];
console.log(containsDuplicate(example_2));

const example_3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
console.log(containsDuplicate(example_3));
var search = function(nums, target) {
    // create left and right pointers
    let left = 0, right = nums.length - 1;
    
    // search through the array using the pointers
    while (left <= right) {
        // calculate the midpoint
        const mid = left + Math.floor((right - left) / 2);
        
        // if nums higher than the midpoint, update the right pointer
        // if nums lower than midpoint, update left pointer
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
};

// implementation
console.log("Leetcode 704: Binary Search\n");

const nums = [-1, 0, 3, 5, 9, 12];

// Example 1
const target1 = 9;
console.log(`Example 1: nums = [${nums}], target = ${target1}`);
console.log("Output:", search(nums, target1));

// Example 2
const target2 = 2;
console.log(`Example 2: nums = [${nums}], target = ${target2}`);
console.log("Output:", search(nums, target2));
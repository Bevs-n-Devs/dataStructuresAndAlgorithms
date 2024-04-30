var threeSum = function(nums) {
    // create empty list
    let results = [];
    nums.sort((a, b) => a - b);  // Proper sorting function to sort in ascending order

    for (let index = 0; index < nums.length - 2; index++) {
        const a = nums[index];

        if (a > 0) {
            break;
        }

        if (index > 0 && a === nums[index - 1]) {
            continue;
        }

        // create pointers
        let left = index + 1, right = nums.length - 1;

        while (left < right) {
            // the 3 sum caluclation
            const sum = a + nums[left] + nums[right];

            if (sum === 0) {
                results.push([a, nums[left], nums[right]]);
                while (nums[left] === nums[left + 1]) left++;  // Skip duplicates
                while (nums[right] === nums[right - 1]) right--;  // Skip duplicates
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return results;
};

// implementation

console.log("Leetcode 15: 3 Sum\n");

// Example 1
example1 = [-1, 0, 1, 2, -1, -4];
console.log(`Example 1: nums = [${example1}]`);
console.log("Output:", threeSum(example1));

// Example 2
example2 = [0, 1, 1];
console.log(`Example 2: nums = [${example2}]`);
console.log("Output:", threeSum(example2));

// Example 3
example3 = [0, 0, 0];
console.log(`Example 3: nums = [${example3}]`);
console.log("Output:", threeSum(example3));
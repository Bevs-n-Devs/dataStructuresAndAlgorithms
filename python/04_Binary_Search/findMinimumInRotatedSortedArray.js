var findMin = function (nums) {
    let [left, right] = [0, nums.length - 1];

    while (left < right) {
        const mid = (left + right) >> 1;
        const guess = nums[mid];
        const [leftNum, rightNum] = [nums[left], nums[right]];

        const isTarget = leftNum < rightNum;
        if (isTarget) return leftNum;

        const isTargetGreater = leftNum <= guess;
        if (isTargetGreater) left = mid + 1;

        const isTargetLess = guess < leftNum;
        if (isTargetLess) right = mid;
    }

    return nums[left];
};

// implementation
console.log("Leetcode 153: Find Minimum In Rotated Sorted Array\n");

// Example 1
const example1 = [3, 4, 5, 1, 2];
console.log(`Example 1: nums = [${example1}]`);
console.log("Output:", findMin(example1));

// Example 2
const example2 = [4, 5, 6, 7, 0, 1, 2];
console.log(`Example 2: nums = [${example2}]`);
console.log("Output:", findMin(example2));

// Example 3
const example3 = [11, 13, 15, 17];
console.log(`Example 3: nums = [${example3}]`);
console.log("Output:", findMin(example3));

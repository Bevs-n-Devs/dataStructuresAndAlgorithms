var maxArea = function (height) {
    // Initialize left, right pointers, and max area.
    let [left, right, max] = [0, height.length - 1, 0];

    // Continue the loop until the left pointer is less than the right pointer.
    while (left < right) {
        // Variables to store container height and area.
        let containerHeight, area;

        // Calculate the width of the container between left and right pointers.
        let containerWidth = right - left;

        // Determine the smaller height of the two walls.
        if (height[left] < height[right]) {
            containerHeight = height[left];
            // Move the left pointer to the right.
            left++;
        } else {
            containerHeight = height[right];
            // Move the right pointer to the left.
            right--;
        }

        // Calculate the area of the current container.
        area = containerWidth * containerHeight;

        // Update the maximum area if the current area is greater.
        if (area > max) {
            max = area;
        }
    }

    // Return the maximum area found.
    return max;
};

// implementation

console.log("Leetcode 15: Container With Most Water\n");

// Eaxmple 1
example1 = [1, 8, 6, 2, 5, 4, 8, 3, 7];
console.log(`Example 1: height = [${example1}]`);
console.log("Output:", maxArea(example1));

// Example 2
example2 = [1, 1];
console.log(`Example 2: height = [${example2}]`);
console.log("Output:", maxArea(example2));
// Function to calculate the trapped water given an array of heights
var trap = function (height) {
    // Initialize left and right pointers at the beginning and end of the array
    let [left, right] = [0, height.length - 1];

    // Initialize variables to keep track of the maximum heights on the left and right, and the total trapped water
    let [maxLeft, maxRight, area] = [0, 0, 0];

    // Continue the loop until the left and right pointers meet
    while (left < right) {
        // Get the heights at the left and right pointers
        const [leftHeight, rightHeight] = getHeights(height, left, right);

        // Get the trapped water in the left and right windows
        const [leftWindow, rightWindow] = getWindows(
            height,
            left,
            maxLeft,
            right,
            maxRight
        );

        // Check if the height on the right is greater than or equal to the height on the left
        const isRightGreater = leftHeight <= rightHeight;

        // If the height on the right is greater, update maxLeft and add the trapped water in the left window
        if (isRightGreater) {
            if (hasNewMax(maxLeft, leftHeight)) maxLeft = leftHeight;
            else area += leftWindow;

            left++;
        }

        // Check if the height on the right is less than the height on the left
        const isRightLess = rightHeight < leftHeight;

        // If the height on the right is less, update maxRight and add the trapped water in the right window
        if (isRightLess) {
            if (hasNewMax(maxRight, rightHeight)) maxRight = rightHeight;
            else area += rightWindow;

            right--;
        }
    }

    // Return the total trapped water
    return area;
};

// Function to check if a new maximum height is encountered
const hasNewMax = (max, height) => max < height;

// Function to get the heights at the left and right pointers
const getHeights = (height, left, right) => [height[left], height[right]];

// Function to get the trapped water in the left and right windows
const getWindows = (height, left, maxLeft, right, maxRight) => {
    const [leftHeight, rightHeight] = getHeights(height, left, right);

    // Calculate the heights of the left and right windows
    const [leftWindow, rightWindow] = [
        maxLeft - leftHeight,
        maxRight - rightHeight,
    ];

    // Return the trapped water in the left and right windows
    return [leftWindow, rightWindow];
};


// implementation

console.log("Leetcode 42: Trapping Rain Water\n");

// Example 1
example1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
console.log(`Example 1: height = [${example1}]`);
console.log("Output:", trap(example1));

// Example 2
example2 = [4, 2, 0, 3, 2, 5];
console.log(`Example 2: height = [${example2}]`);
console.log("Output:", trap(example2));
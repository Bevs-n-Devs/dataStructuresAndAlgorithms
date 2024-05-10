// Function to find the largest rectangle area in a histogram using divide-and-conquer
var largestRectangleArea = function(heights, left = 0, right = (heights.length - 1)) {
    // Check if the current range is a base case (empty or single element)
    const isBaseCase = right < left;
    if (isBaseCase) return 0;

    // Call the divide-and-conquer helper function
    return divideAndConquer(heights, left, right);
}

// Helper function for divide-and-conquer approach
const divideAndConquer = (heights, left, right, min = left) => {
    // Iterate through the current range to find the index of the minimum height
    for (let i = left; i <= right; i++) {
        // Check if the current height is less than the height at the current minimum index
        const isMinGreater = heights[i] < heights[min];
        if (!isMinGreater) continue;

        // Update the index of the minimum height
        min = i;
    }

    // Calculate the width of the current range
    const window = (right - left) + 1;

    // Calculate the area of the rectangle formed by the minimum height in the current range
    const area = heights[min] * window;

    // Recursively calculate the area for the left and right subranges
    const leftArea = largestRectangleArea(heights, (min + 1), right);
    const rightArea = largestRectangleArea(heights, left, (min - 1));

    // Return the maximum of the area in the current range and the areas from the left and right subranges
    return Math.max(area, leftArea, rightArea);
}

// implementation
console.log("Leetcode 84: Largest Rectangle in Histogram\n");

// Example 1
const example1 = [2, 1, 5, 6, 2, 3];
console.log(`Example 1: heights = [${example1}]`);
console.log("Output:", largestRectangleArea(example1));

// Example 2
const example2 = [2, 4];
console.log(`Example 2: heights = [${example2}]`);
console.log("Output:", largestRectangleArea(example2));
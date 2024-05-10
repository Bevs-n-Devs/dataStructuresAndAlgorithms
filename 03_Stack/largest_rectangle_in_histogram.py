class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        # Initialize the variable to store the maximum area
        maxArea = 0

        # Initialize a stack to keep track of indices and heights
        stack = []  # Stack elements: (index, height)

        # Iterate through each bar in the histogram
        for i, h in enumerate(heights):
            start = i
            # While the stack is not empty and the current height is less than the height at the top of the stack
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                # Calculate the area of the rectangle formed by the popped bar
                maxArea = max(maxArea, height * (i - index))
                start = index
            # Push the current index and height onto the stack
            stack.append((start, h))

        # Process the remaining bars in the stack
        for i, h in stack:
            # Calculate the area of the rectangle formed by the remaining bars
            maxArea = max(maxArea, h * (len(heights) - i))

        # Return the maximum area
        return maxArea

# implementation
answer = Solution()

print("Leetcode 84: Largest Rectangle in Histogram\n")

# Example 1
example_1 = [2, 1, 5, 6, 2, 3]
print(f"Example 1: heights = {example_1}")
print("Output:", answer.largestRectangleArea(example_1))

# Example 2
example_2 = [2, 4]
print(f"Example 2: heights = {example_2}")
print("Output:", answer.largestRectangleArea(example_2))
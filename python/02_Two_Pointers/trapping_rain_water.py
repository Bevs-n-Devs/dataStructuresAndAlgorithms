class Solution:
    def trap(self, height: list[int]) -> int:
        # Check if the input list is empty
        if not height:
            return 0

        # Initialize left and right pointers at the beginning and end of the list
        left, right = 0, len(height) - 1

        # Initialize variables to keep track of the maximum height on the left and right
        leftMax, rightMax = height[left], height[right]

        # Initialize a variable to store the total trapped water
        result = 0

        # Continue the loop until the left and right pointers meet
        while left < right:
            # If the height at the left pointer is smaller, move the left pointer to the right
            if leftMax < rightMax:
                left += 1
                # Update the leftMax if the current height is greater
                leftMax = max(leftMax, height[left])
                # Add the trapped water between leftMax and the current height to the result
                result += leftMax - height[left]
            else:
                # If the height at the right pointer is smaller, move the right pointer to the left
                right -= 1
                # Update the rightMax if the current height is greater
                rightMax = max(rightMax, height[right])
                # Add the trapped water between rightMax and the current height to the result
                result += rightMax - height[right]

        # Return the total trapped water
        return result

# implementation
answer = Solution()

print("Leetcode 42: Trapping Rain Water\n")

# Example 1
example_1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(f"Example 1: height = {example_1}")
print("Output:", answer.trap(example_1))

# Example 2
example_2 = [4, 2, 0, 3, 2, 5]
print(f"Example 2: height = {example_2}")
print("Output:", answer.trap(example_2))
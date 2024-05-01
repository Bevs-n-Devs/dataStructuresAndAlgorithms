class Solution:
    def maxArea(self, height: list[int]) -> int:
        # Initialize left and right pointers at the two ends of the height list.
        left, right = 0, len(height) - 1
        # Initialize the variable to store the maximum area.
        result = 0

        # Continue the loop until the left pointer is less than the right pointer.
        while left < right:
            # Calculate the current area between the two pointers and update the result.
            result = max(result, min(height[left], height[right]) * (right - left))
            
            # Move the pointers towards each other based on the height of the walls.
            if height[left] < height[right]:
                left += 1
            elif height[right] <= height[left]:
                right -= 1
            
        # Return the maximum area found.
        return result

# implementation 
answer = Solution()

print("Leetcode 15: Container With Most Water\n")

# Example 1
example_1 = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(f"Example 1: height = {example_1}")
print(f"Output:", answer.maxArea(example_1))

# Example 2
example_2 = [1, 1]
print(f"Example 2: height = {example_2}")
print("Output:", answer.maxArea(example_2))
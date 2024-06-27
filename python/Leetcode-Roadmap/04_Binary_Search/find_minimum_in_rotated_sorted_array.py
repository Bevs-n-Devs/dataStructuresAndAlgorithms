class Solution:
    def findMin(self, nums: list[int]) -> int:
        # Initialize the start and end indices for binary search
        start, end = 0, len(nums) - 1 
        
        # Initialize a variable to store the current minimum value
        curr_min = float("inf")
        
        # Perform binary search until start index is less than end index
        while start < end:
            # Calculate the middle index
            mid = (start + end) // 2
            
            # Update the current minimum value with the minimum of the current minimum and the value at the middle index
            curr_min = min(curr_min, nums[mid])
            
            # If the value at the middle index is greater than the value at the end index, the minimum is on the right
            if nums[mid] > nums[end]:
                start = mid + 1
                
            # If the value at the middle index is less than or equal to the value at the end index, the minimum is on the left
            else:
                end = mid - 1 
        
        # Return the minimum value between the current minimum and the value at the start index
        return min(curr_min, nums[start])
    
# implementation
answer = Solution()

print("Leetcode 153: Find Minimum in Rotated Sorted Array\n")

# Example 1
example_1 = [3, 4, 5, 1, 2]
print(f"Example 1: nums = {example_1}")
print("Output:", answer.findMin(example_1))

# Example 2
example_2 = [4, 5, 6, 7, 0, 1, 2]
print(f"Example 2: nums = {example_2}")
print("Output:", answer.findMin(example_2))

# Example 3
example_3 = [11, 13, 15, 17]
print(f"Example 3: nums = {example_3}")
print("Output:", answer.findMin(example_3))
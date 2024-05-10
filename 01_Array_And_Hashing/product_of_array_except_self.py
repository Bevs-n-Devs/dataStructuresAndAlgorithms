class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        # Initialize a result array with all elements set to 1
        result = [1] * (len(nums))

        # Calculate the prefix products and update the result array
        for index in range(1, len(nums)):
            result[index] = result[index-1] * nums[index-1]

        # Initialize a variable to store the postfix product
        postfix = 1

        # Update the result array with the postfix products
        for index in range(len(nums) - 1, -1, -1):
            result[index] *= postfix
            postfix *= nums[index]

        # Return the final result array
        return result 


# implementation
print("Leetcode 238: Product of Array Except Self\n")    
answer = Solution()

# Example 1
example_1 = [1, 2, 3, 4]
print(f"Example 1: nums = {example_1}")
print("Output:", answer.productExceptSelf(example_1))

# Example 2
example_2 = [-1, 1, 0, -3, 3]
print(f"Example 2: nums = {example_2}")
print("Output:", answer.productExceptSelf(example_2))
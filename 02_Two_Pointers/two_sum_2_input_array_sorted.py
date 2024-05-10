class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        # create your left & right pointers
        left, right = 0, len(numbers) - 1

        # loop through the pointers to add values
        while left < right:
            # add the two pointers together
            currentSum = numbers[left] + numbers[right]

            # move right pointer if higher than target
            if currentSum > target:
                right -= 1
            # move left pointer if lower than target
            elif currentSum < target:
                left += 1
            else:
                return [left + 1, right + 1]

# implementation
answer = Solution()
print("Leetcode 167: Two Sum 2 - Input Array Sorted\n")

# Example 1
example_1 = [2, 7, 11, 15]
target_1 = 9
print(f"Example 1: numbers = {example_1}, target = {target_1}")
print("Output:", answer.twoSum(example_1, target_1))

# Example 2
example_2 = [2, 3, 4]
target_2 = 6
print(f"Example 2: numbers = {example_2}, target = {target_2}")
print("Output:", answer.twoSum(example_2, target_2))

# Example 3
example_3 = [-1, 0]
target_3 = -1
print(f"Example 3: numbers = {example_3}, target = {target_3}")
print("Output:", answer.twoSum(example_3, target_3))
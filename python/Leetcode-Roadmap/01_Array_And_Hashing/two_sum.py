class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # create hashmap to add number & index 
        prevMap = {}  # val -> index

        # iterate through list using enumerate -> returns index,value
        for i, n in enumerate(nums):
            # calculate difference (tarsget minus index value)
            diff = target - n
            # check if difference is already in hashmap
            if diff in prevMap:
                return [prevMap[diff], i]     # return pair of indecies
            # update hashmap
            prevMap[n] = i


# implementation
answer = Solution()
print("Leetcode 1: Two Sum\n")

# Example 1
example_1 = [2, 7, 11, 15]
target_1 = 9
print(f"Example 1: nums = {example_1}, target = {target_1}")
print("Output:", answer.twoSum(example_1, target_1))

# Example 2
example_2 = [3, 2, 4]
target_2 = 6
print(f"Example 1: nums = {example_2}, target = {target_2}")
print("Output:", answer.twoSum(example_2, target_2))

# Example 3
example_3 = [3, 3]
target_3 = 6
print(f"Example 1: nums = {example_3}, target = {target_1}")
print("Output:", answer.twoSum(example_3, target_3))
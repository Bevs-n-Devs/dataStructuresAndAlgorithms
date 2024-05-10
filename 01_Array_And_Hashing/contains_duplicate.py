class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        # create a hashset to store the looped numbers
        hashset = set()

        # loop through list to check duplicates
        for num in nums:
            # check if num already exists in hashset
            if num in hashset:
                return True
            # add num to hashset
            hashset.add(num)
        return False


# implementaion
print("Leetcode 217: Contains Duplicate\n")
answer = Solution()

# Example 1
example_1 = [1, 2, 3, 1]
print(f"Example 1: nums = {example_1}")
print("Output:", answer.containsDuplicate(example_1))

# Example 2
example_2 = [1, 2, 3, 4]
print(f"Example 2: nums = {example_2}")
print("Output:", answer.containsDuplicate(example_2))

# Example 3
example_3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
print(f"Example 3: nums = {example_3}")
print("Output:", answer.containsDuplicate(example_3))
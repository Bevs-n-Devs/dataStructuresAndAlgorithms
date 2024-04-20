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
example_1 = [1, 2, 3, 1]
answer = Solution()
print(answer.containsDuplicate(nums=example_1))

example_2 = [1, 2, 3, 4]
print(answer.containsDuplicate(example_2))

example_3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
print(answer.containsDuplicate(example_3))
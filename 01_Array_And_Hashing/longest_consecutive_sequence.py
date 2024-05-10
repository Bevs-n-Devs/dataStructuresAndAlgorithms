class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        # Create a set to efficiently check existence of numbers
        numSet = set(nums)
        longest = 0

        # Iterate through each number in the set
        for n in numSet:
            # Check if it's the start of a sequence
            if (n - 1) not in numSet:
                length = 1
                # Check consecutive numbers in the sequence
                while (n + length) in numSet:
                    length += 1
                # Update the longest consecutive sequence length
                longest = max(length, longest)

        # Return the length of the longest consecutive sequence
        return longest
    

# implementation

print("Leecode 128: Longest Consecutive Sequence\n")
answer = Solution()

# Example 1
example_1 = [100, 4, 200, 1, 3, 2]
print(f"Example 1: nums = {example_1}")
print("Output:", answer.longestConsecutive(example_1))

# Example 2
example_2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
print(f"Example 2: nums = {example_2}")
print("Output:", answer.longestConsecutive(example_2))
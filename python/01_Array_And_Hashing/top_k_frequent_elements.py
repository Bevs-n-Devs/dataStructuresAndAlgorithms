class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        # Dictionary to store the count of each number
        count = {}

        # List to store numbers grouped by frequency
        freq = [[] for i in range(len(nums) + 1)]

        # Count the occurrences of each number in the input list
        for n in nums:
            count[n] = 1 + count.get(n, 0)

        # Group numbers by frequency in the 'freq' list
        for n, c in count.items():
            freq[c].append(n)

        # Result list to store the top k frequent numbers
        res = []

        # Iterate through the 'freq' list in reverse order
        for i in range(len(freq) - 1, 0, -1):
            # Iterate through the numbers in the current frequency group
            for n in freq[i]:
                # Append the number to the result list
                res.append(n)
                # Check if the result list has reached the desired length k
                if len(res) == k:
                    return res

        # The function will only reach this point if k is greater than the number of unique elements in the input list
        return res
    

# implementation
answer = Solution()
print("Leetcode 347: Top K Frequent Elements\n")

# Example 1
example_1 = [1, 1, 1, 2, 2, 3]
k1 = 2
print(f"Example 1: nums = {example_1}, k = {k1}")
print("Output:", answer.topKFrequent(example_1, k1))

# Example 2
example_2 = [1]
k2 = 1
print(f"Example 2: nums = {example_2}, k = {k2}")
print("Output:", answer.topKFrequent(example_2, k2))
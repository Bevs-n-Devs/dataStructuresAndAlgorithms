import collections

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        # Initialize a defaultdict to store anagrams grouped by their character counts
        answer = collections.defaultdict(list)

        # Iterate through each string in the input list
        for char in strs:
            # Initialize a list to count the occurrences of each character in the string
            count = [0] * 26

            # Count the occurrences of each character in the string
            for letter in char:
                # using ASCII to map lowercase letter to a number between 97 - 122 (a - z)
                count[ord(letter) - ord("a")] += 1

            # Convert the count list to a tuple to use it as a key in the defaultdict
            answer[tuple(count)].append(char)

        # Return the grouped anagrams as a list of lists
        return answer.values()
    

# implementation
print("Leetcode 49: Group Anagrams\n")
answer = Solution()

# Example 1
example_1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(f"Example 1: strs = {example_1}")
print("Outcome:", answer.groupAnagrams(example_1))

# Example 1
example_2 = [""]
print(f"Example 2: strs = {example_2}")
print("Outcome:", answer.groupAnagrams(example_2))

# Example 3
example_3 = ["a"]
print(f"Example 3: strs = {example_3}")
print("Outcome:", answer.groupAnagrams(example_3))
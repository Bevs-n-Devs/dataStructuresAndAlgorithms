class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # check if length of both strings match in length
        if len(s) != len(t):
            return False

        # create empty hashmap 
        # this will count how many times each letter has in a string
        countS, countT = {}, {}

        # loop through both strings, add them to hashmaps
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)

        # check if hashmaps are equal
        for c in countS:
            if countS[c] != countT.get(c, 0):
                return False

        return True


# implementation
print("Leetcode 242: Valid Anagram \n")
answer = Solution()

# Eample 1
s1 = "anagram"
t1 = "nagaram"
print(f"Example 1: s = {s1}, t = {t1}")
print("Output:", answer.isAnagram(s1, t1))

# Example 2
s2 = "rat"
t2 = "car"
print(f"Example 1: s = {s2}, t = {t2}")
print("Output:", answer.isAnagram(s2, t2))
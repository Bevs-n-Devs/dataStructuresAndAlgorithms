class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        # create a new empty string to add letters from given word
        newStr = ""

        # loop through each letter to check if alphanumeric then add to newStr object
        for letter in s:
            if letter.isalnum():
                newStr += letter.lower()

        # reverse the letters to see if they are the same backwards
        return newStr == newStr[::-1]
    
# implementation
answer = Solution()
print("Leetcode 125: Valid Palindrome\n")

# Example 1
example_1 = "A man, a plan, a canal: Panama"
print(f"Example 1: s = '{example_1}'")
print("Output:", answer.isPalindrome(example_1))

# Example 2
example_2 = "race a car"
print(f"Example 2: s = '{example_2}'")
print("Output:", answer.isPalindrome(example_2))

# Example 3
example_3 = " "
print(f"Example 3: s = '{example_3}'")
print("Output:", answer.isPalindrome(example_3))
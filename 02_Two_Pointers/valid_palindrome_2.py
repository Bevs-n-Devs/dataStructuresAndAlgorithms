class Solution:
    # Could write own alpha-numeric function
    def alphanum(self, c):
            return (
                ord("A") <= ord(c) <= ord("Z")
                or ord("a") <= ord(c) <= ord("z")
                or ord("0") <= ord(c) <= ord("9")
            )

    def isPalindrome(self, s: str) -> bool:
        # create pointers 
        left, right = 0, len(s) - 1

        # create a loop by iterating the pointers 
        while left < right:
            # move left pointer if no number or letter found
            while left < right and not self.alphanum(s[left]):
                left += 1
            # move right pointer if no number or letter found
            while left < right and not self.alphanum(s[right]):
                right -= 1
            
            # compare the letters in L & R pointers
            if s[left].lower() != s[right].lower():
                return False
            
            # move the pointers by 1 to compare next letters
            left += 1
            right -= 1
        return True

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
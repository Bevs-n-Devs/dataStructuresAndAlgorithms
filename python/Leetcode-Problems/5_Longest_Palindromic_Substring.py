import pytest

"""
5. Longest Palindromic Substring (Medium)
Given a string s, return the longest palindromic substring in s

Constraints:
    * 1 <= s.length <= 1000
    * s consist of only digits and English letters.
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, s: str, expectedResult: str):
        self.s = s
        self.expectedResult = expectedResult

TestCases = [
    Test(s="babad", expectedResult="bab"),
    Test(s="cbbd", expectedResult="bb"),
    Test(s="babaddtattarrattatddetartrateedredividerb", expectedResult="ddtattarrattatdd"),
    Test(s="aaaa", expectedResult="aaaa"),
    Test(s="ca", expectedResult="c"),
    Test(s="a", expectedResult="a"),
    Test(s="adam", expectedResult="ada"),
    Test(s="aab", expectedResult="aa"),
    Test(s="abb", expectedResult="bb"),
    Test(s="aba", expectedResult="aba"),
]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        Scans a string for the longest palindromic substring
        NOTE: Palindrome is a word that spells the same word
        if all the letters are reversed
        
        @param s: string to scan
        @type s: string
        
        @return longest found palindrome string
        """
        # constraints check
        if len(s) < 2:
            return s
        if len(s) > 1000:
            return ""
        
        # catch small conditions to speed up results
        if len(s) == 2:
            if s[0] == s[1]:
                return s
            
            return s[0]
        
        # store found palindromes
        self.memo = {}
        # store previously checked index pairs
        self.rngs = []
        # store the longest palindrome, start with empty string
        self.longest = ""
        
        def is_palindrome(s: str, l: int, r: int):
            """
            Nested method to check if a palindromic substring is 
            found about a given index; expanding outward as matching
            characters are found.
            
            @param s: full string to scan
            @type s: str
            @param l: left index to start scan
            @type l: int
            @param r: right index to start scan
            @type r: int
            """
            
            # checks if the search index pair has already been
            # checked, this can be removed with the new iteration
            # approach
            if (l,r) in self.rngs:
                return
            else:
                self.rngs.append((l,r))
            
            # boundary check, if the index pair is outside of the bounds
            # of the string s, immediately exit this method
            if l < 0 or r > len(s)-1:
                return
            
            # print(f"l: {l}, r: {r}")
            # declaring palindrome bool to track if any palindrome was found
            # or not
            p = False
            # declaring a variable to hold a palindromic substring
            ss = ""
            
            # right expansion -> while characters match
            if l == 0 and r-l == 1:
                while r < len(s) and s[l] == s[r]:
                    r+=1
                    p = True
                
                # if a palindromic substring was found account
                # for final index expansions that included 
                # non-matching conditions
                if p:
                    r-=1
            
            # left expansion <- while characters match
            elif r == len(s)-1 and r -l == 1:
                while l > -1 and s[l] == s[r]:
                    l-=1
                    p = True
                
                # if a palindromic substring was found account
                # for final index expansions that included 
                # non-matching conditions
                if p:
                    l+=1
            # expand outward    
            else:
                # print("expand outward") <-> expanding both directions
                while l > -1 and r < len(s) and s[l] == s[r]:
                    l-=1
                    r+=1
                    p = True
                
                # if a palindromic substring was found account
                # for final index expansions that included 
                # non-matching conditions
                if p == True:
                    l+=1
                    r-=1
            
            # False condition, if no palindromic substring was found, exit the method 
            if not p:
                return 
            
            # updating the substring found, but this also is no longer necessary
            # for new approach
            self.memo[s[l:r+1]] = True
            ss = s[l:r+1]
            self.memo[ss] = True
            
            # if the new palindromic substring is longer than the current longest
            # update it to be the new longest value
            if len(ss) > len(self.longest):
                self.longest = ss
            
        # loop through all characters of the string
        # checking for odd and even potential substrings
        for i in range(0,len(s)-1):
            # constraints check
            if ord(s[i].lower()) < ord('a') | ord(s[i].lower()) > ord('z'):
                return "" 
            
            # odd expansion check
            is_palindrome(s,i,i)
            # even expansion check
            is_palindrome(s,i,i+1)
        
        return self.longest
    
def test_solution():
    for test in TestCases:
        S = Solution()
        assert test.expectedResult == S.longestPalindrome(s=test.s), "solution did not match result"
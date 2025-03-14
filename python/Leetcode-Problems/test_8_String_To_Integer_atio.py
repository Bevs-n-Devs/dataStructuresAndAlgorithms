import pytest

"""
8. String to Integer [atoi] (Medium)
Implement the myAtoi(string s) function, which converts a string to 
a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

Example 1:

    Input: s = "42"

    Output: 42

    Explanation:

    The underlined characters are what is read in and the caret is the current reader position.
    Step 1: "42" (no characters read because there is no leading whitespace)
            ^
    Step 2: "42" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "42" ("42" is read in)
            ^
Example 2:

    Input: s = " -042"

    Output: -42

    Explanation:

    Step 1: "   -042" (leading whitespace is read and ignored)
                ^
    Step 2: "   -042" ('-' is read, so the result should be negative)
                ^
    Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

    Input: s = "1337c0d3"

    Output: 1337

    Explanation:

    Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
            ^
    Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

    Input: s = "0-1"

    Output: 0

    Explanation:

    Step 1: "0-1" (no characters read because there is no leading whitespace)
            ^
    Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
            ^
Example 5:

    Input: s = "words and 987"

    Output: 0

    Explanation:

    Reading stops at the first non-digit character 'w'.

Constraints:

    * 0 <= s.length <= 200
    * s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, s: str, expectedResult: int):
        self.s = s
        self.expectedResult = expectedResult

TestCases = [
    Test(s="42", expectedResult=42),
    Test(s="   -042", expectedResult=-42),
    Test(s="1337c0d3", expectedResult=1337),
    Test(s="0-1", expectedResult=0),
    Test(s="  +b12102370352", expectedResult=0),
    Test(s="-91283472332", expectedResult=-2147483648),
    Test(s="21474836460", expectedResult=2147483647),
    Test(s="-5-", expectedResult=-5),
    Test(s="", expectedResult=0)
]

class Solution:
    def myAtoi(self, s: str) -> int:
        """
        Converts string into signed 32 bit integer

        @param s: string to convert
        @ptype s: str

        @return converted integer
        """
        
        def removeSpaces() -> tuple:
            """
            Ignores trailing and/or leading spaces by
            moving left and/or right index pointers

            @return tuple of int's
            """
            l = 0
            r = len(s)-1
            while s[l] == ' ' and l < r: l+=1
            while s[r] == ' ' and l < r: r-=1

            return l, r

        l,r = 0,len(s)-1
        # constraints check
        if r-l+1 < 1 or r-l+1 > 200:
            return 0

        if s[0] == ' ' or s[-1] == ' ':
            # ignore trailing and/or leading spaces
            l,r = removeSpaces()
            # constraints check
            if r-l+1 < 1 or r-l+1 > 200:
                return 0
        
        nil = ord('0')      # storing base int value for char '0'
        res = 0             # tracking result
        mul = 1             # tracking multiplier
        neg = s[l] == '-'   # storing if negative value
        lmt = False         # tracking 32bit value limit

        # looping through each character
        for i in range(r,l-1,-1):
            c = s[i]

            # Constraints check
            if c.upper() < 'A' and c.upper() > 'Z' \
                and c.upper() < '0' and c.upper() > '9' and c != ' ' \
                and c != '+' and c != '-' and c != '.': return 0 
            
            # Check for intermediate non-numeric characters
            if (c < '0' or c > '9') :
                if i == l: 
                    if c == '-': return -(res)
                    if c == '+': return res
                mul = 1
                res = 0
                lmt = False
                continue 

            if not lmt:
                # update result value & shift based on multiplier
                res+=mul*(ord(c)-nil)
                mul*=10

                # 32 bit limit check (overflow)
                if res > 2**31 -1: 
                    lmt = True
                    res = (2**31)-1
                    if neg: res+=1
        
        # adjust for negative value
        if neg: return -(res)
        return res

def test_solution():
    for test in TestCases:
        S = Solution()
        assert test.expectedResult == S.myAtoi(s=test.s), "solution did not match result"
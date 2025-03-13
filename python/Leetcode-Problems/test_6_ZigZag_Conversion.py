import pytest

"""
6. Zigzag Conversion (Medium)
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this: (you may want to display 
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this 
conversion given a number of rows:

    string convert(string s, int numRows);
 

Example 1:

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

Example 2:

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

Example 3:

    Input: s = "A", numRows = 1
    Output: "A"
 

Constraints:

    * 1 <= s.length <= 1000
    * s consists of English letters (lower-case and upper-case), ',' and '.'.
    * 1 <= numRows <= 1000
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, s: str, numRows: int, expectedResult: str):
        self.s = s
        self.numRows = numRows
        self.expectedResult = expectedResult


TestCases = [
    Test(s="A",numRows=1,expectedResult="A"),
    Test(s="AB",numRows=1,expectedResult="AB"),
    Test(s="PAYPALISHIRING",numRows=3,expectedResult="PAHNAPLSIIGYIR"),
    Test(s="PAYPALISHIRING",numRows=4,expectedResult="PINALSIGYAHRPI"),
    Test(s="PAYPALISHIRING",numRows=5,expectedResult="PHASIYIRPLIGAN"),
    Test(s="PAYPALISHIRING",numRows=6,expectedResult="PRAIIYHNPSGAIL"),
    Test(s="Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.",numRows=2,expectedResult="Aaidoeswr,haenme,rtesqecouishtabrateaeaietedrcinwtgnrlloacsoajsmnsoucutoadodiiesplnrmiaodprs,ubroohreunefnttacneedhsmwynihrieto,iheeaalwnefrdutettpntainnwrdvdr.")
]

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """
        Converts string based on ZigZag pattern following
        number of rows.

        @param s: string to convert
        @ptype s: str
        @param numRows: rows count for zigzag pattern
        @ptype numRows: int

        @rtype: converted string 
        """

        # Constraints check
        if len(s) < 1 or len(s) > 1000: return ""
        if numRows < 1 or numRows > 1000: return ""
        
        # Catch base condition that doesn't require
        # any conversion
        if numRows == 1 or len(s) <= numRows: return s
        
        S = "" # string variable to store result
        r = 0  # int variable to track current row
        i = 0  # int to track char index

        col_gap = numRows-2         # expected gap between columns
        offset = numRows+col_gap    # offset from main row to next full row

        # loop through rows
        while r < numRows:
            # secondary index tracker
            j = i
            # loop followning pattern
            while j < len(s):
                # Constraints check
                if s[j].isalpha() == False and s[j] != ',' and s[j] != '.' : return ""

                S+=s[j]
                k = (j+offset-(r*2))
                j += offset
                # check gap columns
                if r > 0 and r < numRows-1 and k > 0 and k < len(s) and k < j: S+=s[k]
            
            r+=1
            i+=1
        
        return S
    
def test_solutions():
    S = Solution()
    for test in TestCases:
        assert test.expectedResult == S.convert(test.s, test.numRows), "Solution did not match expected result!"
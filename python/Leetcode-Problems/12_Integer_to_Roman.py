import pytest

"""
12. Integer to Roman (Medium)
Seven different symbols represent Roman numerals with the following values:
________________
Symbol	Value
    I	  1
    V	  5
    X	  10
    L	  50
    C	  100
    D	  500
    M	  1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

Constraints:
    * 1 <= num <= 3999
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, num: int, expectedResult: str):
        self.num = num
        self.expectedResult = expectedResult

# list of test cases
TestCases = [
    Test(num=3749, expectedResult="MMMDCCXLIX"),
    Test(num=58, expectedResult="LVIII"),
    Test(num=1994, expectedResult="MCMXCIV"),
]

class Solution:
    def intToRoman(num: int) -> str:
        # declear results variable
        res = ""
        
        # Constraints Check
        if num < 1 or num > 3999:
            return res
        
        # Using dict to store all Roman Numeral characters
        # and their respective values, for O(1) retrieval
        rmn = {
            'M': 1000,
            'CM': 900,
            'D': 500,
            'CD': 400,
            'C': 100,
            'XC': 90,
            'L': 50,
            'XL': 40,
            'X': 10,
            'IX': 9,
            'V': 5,
            'IV': 4,
            'I': 1,          
        }
        
        # loop through all key/value pairs matching the 
        # respective roman numeral characters. Each time
        # a character has been found, the number provided 
        # is reduced until it is zero
        for k,v in rmn.items():
            # catch condition when the number is 
            # depleted
            if num < 1:
                break
            
            # for cases where the num is exact, no
            # additional math is required
            if num == v:
                res+=k
                num-=v
            # if the num is greater than the dict value
            # the character string can be produced
            elif num > v:
                # floor division will get the highest digits
                # place's value
                tmp = num//v
                # if there is an exacte match, we reduce
                # by that exact value and append the roman
                # numeral to the result string
                if tmp == v:
                    res+=k
                    num-=v
                # if there is no exact match in value, the 
                # roman numeral is multiplied by the tmp value
                # which is the highest digit's value
                # e.g. 30 would be X 3 times: XXX
                else:
                    res+=tmp*k
                    num-=tmp*v

        return res
    
def test_solution():
    for test in TestCases:
        assert test.expectedResult == Solution.intToRoman(num=test.num), "solution did not match expected result"
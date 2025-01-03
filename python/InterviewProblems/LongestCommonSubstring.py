

def longestCommonSubstr(strs: list[str]) -> str:
    """
    Attempts to find the longest common substring in a list 
    of strings

    @param strs: list of strings

    @return substring
    @rtype str
    """
    if len(substrs) == 0:
        return ""
    
    l = 0
    r = 1
    S = strs[0][l:r]
    commonStr = ""
    while l < len(strs[0]) and r < len(strs[0])+2:
        for s in strs[1:]:
            if s.find(S) > -1:
                if len(S) > len(commonStr):
                    commonStr = S
                r+=1
            else:
                l+=1
                break
        if l >= r:
            S = strs[0][l:l+1]
        else:
            S = strs[0][l:r]


    return commonStr

## Tests
substrs = [
    ["flower", "flow", "floor"],
    ["dog", "racecar", "car"],
    ["tonkatruck", "dumptrucker", "garbagetruck"],
]

for s in substrs:
    print(f"The longest commons substring for {s}: \"{longestCommonSubstr(s)}\"")
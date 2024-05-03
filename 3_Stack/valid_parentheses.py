class Solution:
    def isValid(self, s: str) -> bool:
        # create hashmap to open parentheses
        Map = {")": "(", "]": "[", "}": "{"}
        stack = []

        # check if char is in hashmap
        for c in s:
            # if NOT a closing parentheses
            if c not in Map:
                stack.append(c)    # add to stack
                continue
            
            # if NOT in stack OR NOT closing parentheses 
            if not stack or stack[-1] != Map[c]:
                return False
            
            # if above conditions are not met then parentheses must match
            stack.pop()

        # returns true if the stack is empty 
        return not stack

# implementation
answer = Solution()

print("Leetcode 20: Valid Parentheses\n")

# Example 1
example_1 = "()"
print(f"Example 1: s = {example_1}")
print("Output:", answer.isValid(example_1))

# Example 2
example_2 = "()[]{}"
print(""f"Example 3: s = {example_2}")
print("Output:", answer.isValid(example_2))

# Example 3 
example_3 = "(]"
print(f"Example 3: s = {example_3}")
print("Output:", answer.isValid(example_3))
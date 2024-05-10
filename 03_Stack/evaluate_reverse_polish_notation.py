class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        # loop through list
        for c in tokens:
            if c == "+":
                # pop last values add result to stack
                stack.append(stack.pop() + stack.pop())
            elif c == "-":
                # pop last values in list
                a, b = stack.pop(), stack.pop()
                # add calculation to stack
                stack.append(b - a)
            elif c == "*":
                stack.append(stack.pop() * stack.pop())
            elif c == "/":
                a, b = stack.pop(), stack.pop()
                stack.append(int(b / a))
            else:
                # if not an operator its a number so 
                # convert str to int
                stack.append(int(c))
        return stack[0]
    
# implementation
answer = Solution()

print("Leetcode 150: Evaluate Reverse Polish Notation\n")

# Example 1
eaxmple_1 = ["2", "1", "+", "3", "*"]
print(f"Example 1: tokens = {eaxmple_1}")
print("Output:", answer.evalRPN(eaxmple_1))

# Example 2
example_2 = ["4", "13", "5", "/", "+"]
print(f"Example 2: tokens = {example_2}")
print("Output:", answer.evalRPN(example_2))

# Example 3
example_3 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
print(f"Example 3: tokens = {example_3}")
print("Output:", answer.evalRPN(example_3))
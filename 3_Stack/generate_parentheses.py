class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        # Initialize an empty stack to keep track of the current combination
        stack = []

        # Initialize an empty list to store the valid combinations
        res = []

        # Recursive function to generate valid combinations
        def backtrack(openN, closedN):
            # If the number of open and closed parentheses is equal to n, add the current combination to the result
            if openN == closedN == n:
                res.append("".join(stack))
                return

            # If the number of open parentheses is less than n, add an open parenthesis and recurse
            if openN < n:
                stack.append("(")
                backtrack(openN + 1, closedN)
                stack.pop()

            # If the number of closed parentheses is less than the number of open parentheses, add a closed parenthesis and recurse
            if closedN < openN:
                stack.append(")")
                backtrack(openN, closedN + 1)
                stack.pop()

        # Start the recursive function with initial counts of open and closed parentheses set to 0
        backtrack(0, 0)

        # Return the list of valid combinations
        return res
    
# implementation
answer = Solution()
print("Leetcode 22: Generate Parentheses\n")

# Example 1
example_1 = 3
print(f"Example 1: n = {example_1}")
print("Output:", answer.generateParenthesis(example_1))

# Example 2
example_2 = 1
print(f"Example 2: n = {example_2}")
print("Output:", answer.generateParenthesis(example_2))
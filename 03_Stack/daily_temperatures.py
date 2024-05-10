from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # Initialize a list to store the result with default values of 0
        res = [0] * len(temperatures)

        # Initialize a stack to keep track of temperatures and their indices
        stack = []  # Stack elements: [temperature, index]

        # Iterate through each temperature and its index
        for i, t in enumerate(temperatures):
            # Check if the current temperature is greater than the temperature at the top of the stack
            while stack and t > stack[-1][0]:
                # If it is greater, pop the stack and update the result for the popped index
                stackTemp, stackInd = stack.pop()
                res[stackInd] = i - stackInd

            # Push the current temperature and its index onto the stack
            stack.append((t, i))

        # Return the list of results representing the number of days until warmer temperatures
        return res
    
# implementation
answer = Solution()

print("Leetcode 739: Daily Temperatures\n")

# Example 1
example_1 = [73, 74, 75, 71, 69, 72, 76, 73]
print(f"Example 1: temperatures = {example_1}")
print("Output:", answer.dailyTemperatures(example_1))

# Example 2
example_2 = [30, 40, 50, 60]
print(f"Example 2: temperatures = {example_2}")
print("Output:", answer.dailyTemperatures(example_2))

# Example 3
example_3 = [30, 60, 90]
print(f"Example 3: temperatures = {example_3}")
print("Output:", answer.dailyTemperatures(example_3))
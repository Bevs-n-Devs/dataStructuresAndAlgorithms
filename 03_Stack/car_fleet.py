class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        # Create pairs of position and speed and sort them in reverse order based on position
        pair = [(p, s) for p, s in zip(position, speed)]
        pair.sort(reverse=True)

        # Initialize a stack to keep track of time to reach the target for each car
        stack = []

        # Iterate through the sorted pairs in reverse order
        for p, s in pair:
            # Calculate the time to reach the target for the current car
            stack.append((target - p) / s)

            # Check if there are at least two cars in the stack and the current car is slower than the previous car
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()  # Remove the previous car from the stack as it is fleet with the current car

        # The length of the stack represents the number of car fleets
        return len(stack)
    

# implementation 
answer = Solution()

print("Leetdcode 853: Car Fleet\n")

# Example 1
target_1 = 12
position_1 = [10, 8, 0, 5, 3]
speed_1 = [2, 4, 1, 1, 3]
print(f"Example 1: target = {target_1}, position = {position_1}, speed = {speed_1}")
print("Output:", answer.carFleet(target_1, position_1, speed_1))

# Example 2
target_2 = 10
position_2 = [3]
speed_2 = [3]
print(f"Example 2: target = {target_2}, position = {position_2}, speed = {speed_2}")
print("Output:", answer.carFleet(target_2, position_2, speed_2))


# Example 3
target_3 = 100
position_3 = [0, 2, 4]
speed_3 = [4, 2, 1]
print(f"Example 3: target = {target_3}, position = {position_3}, speed = {speed_3}")
print("Output:", answer.carFleet(target_3, position_3, speed_3))

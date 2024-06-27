class Solution:
    def canJump(self, nums: list[int]) -> bool:
        # the goal is to reach the last index of the list
        goal = len(nums) - 1

        # iterate backwards through the list from 2nd-last to 1st list item
        for index in range(len(nums) -2, -1, -1):
            # check if index + maximum jump from index can reach or surpass our goal
            if index + nums[index] >= goal:
                # if so, update the goal to this index
                goal = index

        # Now check if the goal is eqaul to 0.
        # If so you have reached your goal.
        return goal == 0


# implementation:
example_1 = [2, 3, 1, 1, 4]

answer1 = Solution()
print(answer1.canJump(example_1))


example_2 = [3, 2, 1, 0, 4]

answer_2 = Solution()
print(answer_2.canJump(example_2))
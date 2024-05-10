class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []                                                # create empty list to store results
        nums.sort()                                             # sort list to accending order

        # use enumerate to get index-value from list
        # i=index a=number
        for i, a in enumerate(nums):
            # Skip positive integers
            if a > 0:
                break
            
            # skip number if duplicate
            if i > 0 and a == nums[i - 1]:
                continue
            
            # create left & right pointers 
            l, r = i + 1, len(nums) - 1
            while l < r:
                threeSum = a + nums[l] + nums[r]                # calculate the 3 sum
                if threeSum > 0:
                    r -= 1                                      # move pointer left if lower than 0
                elif threeSum < 0:
                    l += 1                                      # mover pointer right if higher than 0
                else:
                    res.append([a, nums[l], nums[r]])           # add correct numbers to empty list 
                    
                    # move pointers after each iteration
                    l += 1
                    r -= 1

                    # if a duplicate is found, but only want to move 1 pointer (edge case)
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                        
        return res

# implementation
answer = Solution()

print("Leetcode 15: 3 Sum\n")

# Example 1
example_1 = [-1, 0, 1, 2, -1, -4]
print(f"Example 1: nums = {example_1}")
print("Output", answer.threeSum(example_1))

# Example 2
example_2 = [0, 1, 1]
print(f"Example 2: nums = {example_2}")
print("Output", answer.threeSum(example_2))

# Example 3
example_3 = [0, 0, 0]
print(f"Example 3: nums = {example_3}")
print("Output", answer.threeSum(example_3))
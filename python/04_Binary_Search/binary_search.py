class Solution:
    def search(self, nums: list[int], target: int) -> int:
            # create left and right pointers
        l, r = 0, len(nums) - 1

        # iterate through the pointers
        while l <= r:
            # calculate the midpoint using floor division
            m = l + ((r - l) // 2)  # (l + r) // 2 can lead to overflow

            # if num higher than midpoint change right pointer
            if nums[m] > target:
                # the right pointer now updated
                r = m - 1
            
            # if num lower than midpoint update left pointer 
            elif nums[m] < target:
                l = m + 1

            # otherwise the num is found in mid point
            else:
                return m    # return index
        
        # return -1 if all fails 
        return -1

# implementation
answer = Solution()
nums = [-1, 0, 3, 5, 9, 12]

print("Leetcode 704: Binary Search\n")

# Example 1
target_1 = 9
print(f"Example 1: nums = {nums}, target = {target_1}")
print("Output:", answer.search(nums, target_1))

# Example 2
tasrget_2 = 2
print(f"Example 2: nums = {nums}, target = {tasrget_2}")
print("Output:", answer.search(nums, tasrget_2))
import math

class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        # set left & right pointers
        l, r = 1, max(piles)

        # initialise result to max number in list
        res = r

        while l <= r:
            # get the value of k (middle value in list)
            k = (l + r) // 2

            totalTime = 0
            # loop through each item in list
            for p in piles:
                # divide list item by k
                totalTime += math.ceil(float(p) / k)

            # update result if hours less or equal to input
            if totalTime <= h:
                res = k
                # update right pointer to find left portion of list
                r = k - 1
            else:
                # update left pointer to find right side of list
                l = k + 1
        
        # return the result
        return res
    
# implementation
answer = Solution()

print("Leetcode 875: Koko Eating Bananas\n")

# Example 1
piles_1 = [3, 6, 7, 11]
hours_1 = 8
print(f"Example 1: piles = {piles_1}, h = {hours_1}")
print("Output:", answer.minEatingSpeed(piles_1, hours_1))

# Example 2
piles_2 = [30, 11, 23, 4, 20]
hours_2 = 5
print(f"Example 2: piles = {piles_2}, h = {hours_2}")
print("Output:", answer.minEatingSpeed(piles_2, hours_2))

# Example 3
hours_3 = 6
print(f"Example 2: piles = {piles_2}, h = {hours_3}")
print("Output:", answer.minEatingSpeed(piles_2, hours_3))
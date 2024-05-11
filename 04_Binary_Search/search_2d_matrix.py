class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # get dimensions of the matrix by setting columns & rows
        ROWS, COLS = len(matrix), len(matrix[0])

        # create top & bottom pointers for rows in the matrix
        top, bot = 0, ROWS - 1
        
        # loop through the pointers to find the target row
        while top <= bot:
            # calculate middle row
            row = (top + bot) // 2

            # move top row down if target higher than last middle value
            if target > matrix[row][-1]:
                top = row + 1
            # move bottom row up if target lower than first middle value
            elif target < matrix[row][0]:
                bot = row - 1
            else:
                break

        # conduct binary search on the row

        # return false if target is not in row
        if not (top <= bot):
            return False

        # calculate the middle row for binary search
        row = (top + bot) // 2

        # create left and right pointers for the row
        l, r = 0, COLS - 1

        # repeat binary search on row
        while l <= r:
            # middle value for row
            m = (l + r) // 2

            # move left pointer if target higher than middle value
            if target > matrix[row][m]:
                l = m + 1

            # move right pointer if target lower than middle value
            elif target < matrix[row][m]:
                r = m - 1

            # return true if match found
            else:
                return True
        
        # return false if target never found
        return False
    
# implementation
answer = Solution()

print("Leetcode 74: Search A 2D Matrix\n")

matrix = [
    [1, 3, 5, 7], 
    [10, 11, 16, 20], 
    [23, 30, 34, 60],
]

# Example 1
target_1 = 3
print(f"Example 1: matrix = {matrix}, target = {target_1}")
print("Output:", answer.searchMatrix(matrix, target_1))

# Example 2
target_2 = 13
print(f"Example 2: matrix = {matrix}, target = {target_2}")
print("Output:", answer.searchMatrix(matrix, target_2))

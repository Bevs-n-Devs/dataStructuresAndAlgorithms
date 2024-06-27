Binary Search 2
# Seach A 2D Matrix
## Company: Microsoft
### Level: Medium

You are given an `m x n` integer `maix` with t following two properties:
- Each row is sorted in non-deceasng order.
- The first integer of the previous row.

Gven an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in `O(log(m * n))` time complexity.

***Break It Down For Me...***
*We have a grid of numbers where each row is sorted in ascending order and the first number of each row is greater than the last number of the previous row.*
*To find a specific number in this grid efficiently, we can use a modified binary search approach.*
*Start searching from the top-right corner of the grid and compare the target with this number.*
*Based on the comparison, move left or down in the grid, eliminating either a row or a column at each step until we find the target or exhaust the grid. This method ensures `O(log(m * n))` time complexity.*

Click [here](https://leetcode.com/problems/search-a-2d-matrix/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Ber2pi2C0j0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Binary Search](https://www.geeksforgeeks.org/what-is-binary-search-algorithm/) in Python, JavaScript and Go.

### Example 1
```
Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 3
Output: true
```

### Example 2
```
Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 13
Output: fasle
```

## Python
```
ROWS, COLS = len(matrix), len(matrix[0])

top, bot = 0, ROWS - 1

while top <= bot:
    # calculate middle row
    row = (top + bot) // 2

    if target > matrix[row][-1]:
        top = row + 1
    elif target < matrix[row][0]:
        bot = row - 1
    else:
        break

if not (top <= bot):
    return False

row = (top + bot) // 2

l, r = 0, COLS - 1

while l <= r:
    m = (l + r) // 2

    if target > matrix[row][m]:
        l = m + 1

    elif target < matrix[row][m]:
        r = m - 1

    else:
        return True

return False

# Code comments can be found in search_2d_matrix.py
```

## JavaScript
```
const ROWS = matrix.length, COLS = matrix[0].length;
let topRow = 0, bottomRow = ROWS - 1;

while (topRow <= bottomRow) {
    const middleRow = Math.floor(topRow + bottomRow);
    
    if (target > matrix[middleRow][-1]) {
        topRow = middleRow + 1;
    } else if (target < matrix[middleRow][0]) {
        bottomRow = middleRow - 1;
    } else {
        break; 
    }
}

if (!(topRow <= bottomRow)) {
    return false;
}

const currentMiddleRow = Math.floor(topRow + bottomRow);
let left = 0, right = COLS - 1;

while (left <= right) {
    let mid = Math.floor(left + right);
    if (target > matrix[currentMiddleRow][mid]) {
        left = mid + 1;
    } else if (target < matrix[currentMiddleRow][mid]) {
        right = mid - 1;
    } else {
        return true;
    }
}
return false;

// Code comments can be found in search2Dmatrix.js
```

## Go
```
ROWS := len(matrix)
COLUMNS := len(matrix[0])

top := 0
bot := ROWS - 1

for top <= bot {
    row := (top + bot) / 2
    if target > matrix[row][len(matrix[row])-1] {
        top = row + 1
    } else if target < matrix[row][0] {
        bot = row - 1
    } else {
        break
    }
}

if !(top <= bot) {
    return false
}

row := (top + bot) / 2
left := 0
right := COLUMNS - 1
for left <= right {
    middle := (left + right) / 2
    if target > matrix[row][middle] {
        left = middle + 1
    } else if target < matrix[row][middle] {
        right = middle - 1
    } else {
        return true
    }
}
return false


// Code comments can be found in search2Dmatrix.go
```
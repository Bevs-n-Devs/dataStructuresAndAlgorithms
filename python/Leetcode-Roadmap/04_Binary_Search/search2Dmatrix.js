var searchMatrix = function(matrix, target) {
    // get dimensions of the matrix
    const ROWS = matrix.length, COLS = matrix[0].length;
    // top & bottom pointers for matrix rows
    let topRow = 0, bottomRow = ROWS - 1;
    
    // loop pointers to find the target row
    while (topRow <= bottomRow) {
        // calculate middle row 
        const middleRow = Math.floor(topRow + bottomRow);
        
        // binary saerch on the rows to find target
        
        // update top row if target higher than last middle row value
        if (target > matrix[middleRow][-1]) {
            topRow = middleRow + 1;
        // update bottom row if target lower than first middle row value
        } else if (target < matrix[middleRow][0]) {
            bottomRow = middleRow - 1;
        } else {
           break; 
        }
    }
    // binary search on the last row
        
    // return false if target is not in any of the rows
    if (!(topRow <= bottomRow)) {
        return false;
    }
    
    // get middle row for binary search
    const currentMiddleRow = Math.floor(topRow + bottomRow);
    // create left and right pointers 
    let left = 0, right = COLS - 1;
    
    // repeat binary search on middle row
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
};

// implementation
console.log("Leetcode 74: Search A 2D Matrix\n");

const matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]];

// Example 1
const target1 = 3;
console.log(`Example 1: matrix = [[${matrix[0]}], [${matrix[1]}], [${matrix[2]}]] target = ${target1}`);
console.log("Output:", searchMatrix(matrix, target1));

// Example 2
const target2 = 13
console.log(`Example 2: matrix = [[${matrix[0]}], [${matrix[1]}], [${matrix[2]}]] target = ${target2}`);
console.log("Output:", searchMatrix(matrix, target2));
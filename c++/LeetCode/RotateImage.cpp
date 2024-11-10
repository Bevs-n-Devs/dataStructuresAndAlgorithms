#include "../Utils/utils.h"

/**
 * 48. Rotate Image
 * 
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
 * DO NOT allocate another 2D matrix and do the rotation.
 * 
 * Constraints:
 *      * n == matrix.length == matrix[i].length
 *      * 1 <= n <= 20
 *      * -1000 <= matrix[i][j] <= 1000
 * 
 */

/**
 * Test Object
 */
typedef struct{
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expectedResult;
}Test;

/**
 * Test Cases storing different tests to run
 */
Test TestCases[] = {
    Test{{{1,2,3},{4,5,6},{7,8,9}},{{7,4,1},{8,5,2},{9,6,3}}},
    Test{{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}},{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}},
    Test{{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}},{{21,16,11,6,1},{22,17,12,7,2},{23,18,13,8,3},{24,19,14,9,4},{25,20,15,10,5}}},
};

/**
 * Rotates image by 90 degrees
 *
 * @param matrix: 2D vector matrix
 *
 */
void rotate(std::vector<std::vector<int>>& matrix) {
    // constraints check
    int rows = matrix.size();
    if(!rows) return;
    int cols = matrix[0].size();
    if(rows != cols) return;
    if (rows > 20 | cols > 20) return;
        
    // transpose
    for (int r = 0; r <= rows-1; r++){
        for (int c = r; c <= cols-1; c++){
            if ( matrix[r][c] < -1000 || matrix[c][r] > 1000) return;
            std::swap(matrix[r][c], matrix[c][r]);
        }
    }
    
    // invert horizontally
    for (int row =0;row<rows;row++){
        int l = 0;
        int r = cols-1;
        while (l < r){
            if ( matrix[row][l] < -1000 || matrix[row][r] > 1000) return;
            std::swap(matrix[row][l], matrix[row][r]);
            l+=1;
            r-=1;
        }
    }
    
}

int main(){
    std::cout << " --- Running Rotate Image 48 LeetCode Problem --- " << std::endl;
    Test test;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Running Test " << i+1 << std::endl;
        std::cout << "Input: { matrix: " << std::endl;
        printMatrix_Vector_Int(test.matrix);
        std::cout << ",\texpectedResult: ";
        printMatrix_Vector_Int(test.expectedResult); 
        std::cout << "}" << std::endl;
        rotate(test.matrix);
        std::cout << "\t Actual Result: ";
        printMatrix_Vector_Int(test.matrix);
        std::cout << "\n======================================================================\n" << std::endl;
    }
    return 0;
}
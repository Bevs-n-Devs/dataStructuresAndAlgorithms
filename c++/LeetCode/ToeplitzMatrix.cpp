#include <iostream>
#include <set>
#include "../Utils/utils.h"

typedef struct{
    std::vector<std::vector<int>> matrix;
    bool expectedResult;
}Test;

std::vector<Test> TestCases = {
    Test{{{1,2,3,4},{5,1,2,3},{9,5,1,2}}, true},
    Test{{{1,2},{2,2}}, false},
    Test{{{0,9,52,22,65,69,13,0,93,17,27,77,99,15},{65,0,9,52,22,65,69,13,50,93,17,27,77,99}}, false},
};

/**
 * Helper function to check all diagonal neighbors 
 * from top left to bottom right
 * 
 * @param matrix 2D: matrix
 * @param r: vertical/row index of matrix element
 * @param c: horizontal/column index of matrix element
 * @param val: the integer value to consider
 * 
 * @return boolean value if the diagnoal neighbor 
 * holds the same value or not 
 * 
 */
bool check_diagonal(std::vector<std::vector<int>>& matrix, int r, int c, int val) {
    if (r < matrix.size()-1 && c < matrix[0].size()-1){
        if (matrix[r+1][c+1] == val) return check_diagonal(matrix, r+1, c+1, val);
        else return false;
    } else return true;
}

/**
 * Verifies if a matrix is a valid Toeplitz Matrix
 *
 * @param matrix: 2D vector matrix of integer values.
 *
 * @return boolean value of valid Toeplitz status
 */
bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    // catch contraints 
    if (!matrix.size() || !matrix[0].size()) return false;
    if (matrix[0].size() > 20) return false;
    
    // set to store previously found values to avoid duplicate iterations
    std::set<int*> vals; 
    
    // loop through each element in the matrix
    for (int r=0;r<matrix.size();r++){
        for(int c=0;c<matrix[0].size();c++){
            // catch constraints
            if (matrix[r][c] < 0 || matrix[r][c] > 99) return false;
            
            // if the current element's address is not in the set, 
            // store the value, and check diagonal neighbors
            if (vals.find(&matrix[r][c]) == vals.end()){
                vals.insert(&matrix[r][c]);
                if (!check_diagonal(matrix,r,c,matrix[r][c])) return false;
            }
        }
    }
    
    return true;
}

int main() {
    std::cout << " --- Running Toeplitz Matrix LeetCode Problem --- " << std::endl;
    for(int i=0; i<TestCases.size();i++){
        std::cout << "Test Case " << i+1 << std::endl;
        std::cout << "input: ";
        printMatrix_Vector_Int(TestCases[i].matrix);
        std::cout << "\n\tExpected Result: " << TestCases[i].expectedResult << std::endl;
        bool ans = isToeplitzMatrix(TestCases[i].matrix);
        std::cout << "\t Actual Result: " << ans << std::endl;
        std::cout << "===========================================================\n" << std::endl;
    }
    return 0;
}
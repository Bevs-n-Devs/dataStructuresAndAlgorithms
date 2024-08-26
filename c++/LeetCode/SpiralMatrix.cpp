#include "../Utils/utils.h"

/**
 * Test Object
 */
typedef struct{
    std::vector<std::vector<int>> matrix;
    std::vector<int> expectedResult;
}Test;

/**
 * Test Cases storing different tests to run
 */
Test TestCases[] = {
    Test{{{1,2,3},{4,5,6},{7,8,9}}, {1,2,3,6,9,8,7,4,5}},
    Test{{{1,2,3,4},{5,6,7,8},{9,10,11,12}},{1,2,3,4,8,12,11,10,9,5,6,7}},
};

/**
 * Gets all of the values in a matrix following 
 * a spiral pattern (starting at the top left)
 * 
 * @param matrix : 2D integer vector
 * 
 * @return vector of values found in spiral order
 * 
 */
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    
    // Get the number of rows
    int rows = matrix.size();
    // Get the number of columns
    int cols = matrix[0].size();
    
    // constraints check
    if(!rows) return res;
    if(cols>10) return res;
    
    // Get the matrix area, to know the number
    // of elements expected in the final 
    // vector
    int len = rows*cols;
    
    // track the boundaries of the matrix as they shrink
    int limits[]= {0,0,cols-1,rows-1};
    // use the idx of the array to track the next boundary
    int idx = 0;
    
    // loop through the matrix until the
    // vector matches the target length
    while (res.size() < len){
        // positive direction Right(increasing rows) & Down (increasing columns)
        if(idx < 2){
            for (int c = limits[idx];c<=limits[(idx+2)%4];c+=1){
                res.push_back(matrix[limits[(idx+1)%4]][c]);
                if (res.back() < -100 || res.back() > 100) return {};
            }
            // adjust the next index boundaries in the limits array
            idx = (idx+1)%4;
            limits[idx]+=1;
            for (int r = limits[idx];r<=limits[(idx+2)%4];r+=1){
                res.push_back(matrix[r][limits[(idx+1)%4]]);
                if (res.back() < -100 || res.back() > 100) return {};
            }
            // adjust the next index boundaries in the limits array
            limits[(idx+1)%4]-=1;
            idx = (idx+1)%4;
        } else {
            // negative direction Left (decreasing rows) & Up (decreasing columns) 
            for (int c = limits[idx];c>=limits[(idx+2)%4];c-=1){
                res.push_back(matrix[limits[(idx+1)%4]][c]);
                if (res.back() < -100 || res.back() > 100) return {};
            }
            // adjust the next index boundaries in the limits array
            limits[(idx+1)%4]-=1;
            idx = (idx+1)%4;
            for (int r = limits[idx];r>=limits[(idx+2)%4];r-=1){
                res.push_back(matrix[r][limits[(idx+1)%4]]);
                if (res.back() < -100 || res.back() > 100) return {};
            }
            // adjust the next index boundaries in the limits array
            limits[(idx+1)%4]+=1;
            idx = (idx+1)%4;
        }
        
        
    }
    
    return res;
}

int main(){
    std::cout << " --- Running Spiral Matrix LeetCode Problem --- " << std::endl;
    Test test;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Running Test " << i+1 << std::endl;
        std::cout << "Input: { matrix: " << std::endl;
        printMatrix_Vector_Int(test.matrix);
        std::cout << ",\texpectedResult: ";
        printVector_Int(test.expectedResult); 
        std::cout << "}" << std::endl;
        std::vector<int> ans = spiralOrder(test.matrix);
        std::cout << "\t Actual Result: ";
        printVector_Int(ans);
        std::cout << "\n======================================================================\n" << std::endl;
    }
    return 0;
}
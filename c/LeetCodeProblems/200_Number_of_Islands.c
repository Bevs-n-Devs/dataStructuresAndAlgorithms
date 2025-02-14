/**
 * 200 Number of Islands
 * (Medium)
 * 
 * Given an m x n 2D binary grid grid which represents a map of 
 * '1's (land) and '0's (water), return the number of islands.An 
 * island is surrounded by water and is formed by connecting adjacent 
 * lands horizontally or vertically. You may assume all four edges 
 * of the grid are all surrounded by water.
 * 
 * Example 1:
 * Input: grid = [
 *      ["1","1","1","1","0"],
 *      ["1","1","0","1","0"],
 *      ["1","1","0","0","0"],
 *      ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * Constraints:
 *  * m == grid.length
 *  * n == grid[i].length
 *  * 1 <= m, n <= 300
 *  * grid[i][j] is '0' or '1'.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* Test Case Structure to store Test Cases*/
typedef struct TestCase{
    char** grid;
    int gridSize;
    int* colGridSize;
    int expectedResult;
}TestCase;

/* Memory allocation alert */
void memAllocFailure(){
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
}

/**
 * Creates test case structures
 * 
 * @param gridStr : string representing the grid map
 * @param gridlength: the number of rows in the grid map
 * @param expectedResult: the correct answer for the test
 * 
 * @return new test case
 */
TestCase createTestCase(char* gridStr,int gridLength, int expectedResult){
    TestCase test;
    test.expectedResult = expectedResult;
    test.gridSize = gridLength;
    int cols = strlen(gridStr)/gridLength;
    int gridSz[gridLength];
    test.grid = (char**)malloc(sizeof(char*)*gridLength);
    if (!test.grid) memAllocFailure();
    
    for (int r=0; r< gridLength;r++) {
        test.grid[r] = (char*)malloc(cols*sizeof(char));
        if (!test.grid[r]){
            memAllocFailure();
        }
        for (int c=0;c<cols;c++) test.grid[r][c] = gridStr[(r*cols)+c];
    }
    test.colGridSize = (int*)calloc(gridLength, sizeof(int));
    if (!test.colGridSize) memAllocFailure();

    for (int c=0; c < gridLength;c++){
        test.colGridSize[c] = cols; 
    }

    return test;
}



void printGrid(char **grid,int gridSize, int* gridColSize){
    printf("gridSize: %d\n", gridSize);
    for (int r=0; r<gridSize;r++){
        int colSize = gridColSize[r];
        printf("[");
        for (int c=0; c < colSize;c++){
            if (!c) printf("'%c'",grid[r][c]);
            else printf(",'%c'",grid[r][c]);
        }
        printf("]\n");
    }  
}

/**
 * Removes 1's for full island to avoid recounting
 *
 * @param grid : matrix of map containing islands
 * @param gridSize : number of rows in grid
 * @param gridColSize : array of column sizes
 * @param col : column index of current cell
 * @param row : row index of current cell
 *
 * @return true if a bad character was found
 */
bool removeIsland(char** grid, int gridSize, int *gridColSize, int col, int row){
    // contraints check, this function is expected to be 
    // ran on cells containing an '1', but in the recursive 
    // call we only check for non '0' chars. This catches 
    // invalid characters
    if (grid[row][col] != '1') return true;
    // clears the current cell
    grid[row][col] = '0';
    int colSize = gridColSize[row];
    
    // setting row and col offsets to check neighboring cells
    // Southern and Eastern cells
    int r = row+1;
    int c = col+1;
    // Recursively calling removeIslands on each neighboring island cell
    if (r < gridSize && grid[r][col] != '0') removeIsland(grid, gridSize, gridColSize, col, r);
    if (c < colSize && grid[row][c] != '0') removeIsland(grid, gridSize, gridColSize, c, row);
    // Northern and Western cells
    r = row-1;
    c = col-1;
    if (r >-1 && grid[r][col] != '0') removeIsland(grid, gridSize, gridColSize, col, r);
    if (c >-1 && grid[row][c] != '0') removeIsland(grid, gridSize, gridColSize, c, row);

    return false;
}


/**
 * Counts number of islands in char grid representing a map
 *
 * @param grid : matrix of map containing islands
 * @param gridSize : number of rows in grid
 * @param gridColSize : array of column sizes
 *
 * @return the number of islands
 */
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (!gridSize || gridSize > 300) return 0;

    int cnt = 0;
    for (int r=0; r<gridSize;r++){
        int colSize = gridColSize[r];
        // contraints check
        if (colSize != gridColSize[0]) return 0;
        if (!colSize || colSize > 300) return 0;
        
        for (int c=0; c < colSize;c++){
            // checks for starting island cells
            // incrementing the count each time 
            // one is found;
            if (grid[r][c] == '1'){
                cnt+=1;
                if (removeIsland(grid, gridSize, gridColSize, c, r)) return 0;
            } else if(grid[r][c] != '0') return 0; // catch for invalid cell characters
        }
    }    
    
    return cnt;
}

int main(int argc, char** kwargs){
    TestCase test1 = createTestCase((char*)"11110110101100000000",4,1);
    TestCase test2 = createTestCase((char*)"11000110000010000011",4,3);
    TestCase TestCases[2] = {test1,test2};
    TestCase test;
    printf("--- 200 Number of Islands ---\n");
    printf("===================================================\n");
    for(int i=0; i< sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        printf("Test Case %d:\n",i+1);
        printf("input: { grid: \n");
        printGrid(test.grid, test.gridSize, test.colGridSize);
        printf(", expectedResult %d}\n", test.expectedResult);
        int ans = numIslands(test.grid, test.gridSize, test.colGridSize);
        printf("ActualResult: %d\n", ans);

        // cleaning up memory
        for (int r=0; r< test.gridSize;r++) free(test.grid[r]);
        free(test.grid);
        free(test.colGridSize);

        // compare result
        assert(test.expectedResult == ans);
        if(!i) printf("===================================================\n");
    }

    printf("======================FINISH=======================\n");
    return 0;
}
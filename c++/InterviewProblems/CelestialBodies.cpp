#include <iostream>
#include <set>
#include "../Utils/utils.h"

/**
 * You are given a black (1) & white (0) image of the night sky
 * and you are asked to count the number of celestial bodies
 * seen in the image.
 * 
 * A celestial body is any case where a pixel (element in the matrix)
 * has a value of 1, and can be a single 1 or a cluster of connected 
 * 1's. The matrix can be any size.
 * 
 * example:
 * 
 *  [   
 *      [0,0,0,1,1],
 *      [1,0,0,0,1],
 *      [1,0,1,1,0],
 *      [0,0,0,1,0],
 *      [1,0,0,1,0],
 *  ]
 * The Matrix above would report 4 celestial bodies.
 * 
 * 
 * > NOTE: The neighboring elements in any direction should be considered.
 * 
 * 
 * My Approach: I chose a recursive approach using the Flood Fill Algorithm 
 * explanation: https://www.geeksforgeeks.org/flood-fill-algorithm/
 */

/* Test Case object to store test matrices*/
struct TestCase {
    int **matrix;
    int expectedResult, width, height;
};

// Test Cases
TestCase TestCases[] = {
    TestCase{
        new int*[5]{
            new int[5]{0,0,0,0,0},
            new int[5]{0,0,0,0,0},
            new int[5]{0,0,0,0,0},
            new int[5]{0,0,0,0,0},
            new int[5]{0,0,0,0,0},
        },
        0,
        5,
        5
    },
    TestCase{
        new int*[5]{
            new int[5]{1,1,1,1,1},
            new int[5]{1,1,1,1,1},
            new int[5]{1,1,1,1,1},
            new int[5]{1,1,1,1,1},
            new int[5]{1,1,1,1,1},
        },
        1,
        5,
        5
    },
    TestCase{
        new int*[5]{
            new int[5]{0,1,0,0,0},
            new int[5]{1,1,0,0,1},
            new int[5]{0,1,1,0,0},
            new int[5]{0,0,0,0,1},
            new int[5]{0,0,0,0,0},
        },
        3,
        5,
        5
    }
};

/**
 * Erases the celestial body by clearing the pixels until
 * there are no more neighboring pixels found with 1's 
 * 
 * @param test: TestCase containing the matrix and its dimensions
 * @param r: the row position of the matrix element where a 1 was found
 * @param c: the column position of the matrix element where a 1 was found
 */
void eraseCelestialBody(TestCase test, int r, int c) {
    // If a zero is found, exit the function
    if (!test.matrix[r][c]) return;
    
    // clear the pixel
    test.matrix[r][c] = 0;

    // An array of all the neighboring elements
    // of the current matrix element
    //       NW N NE
    //        W - E
    //       SW S SE
    int nPixels[8][2] = {
        {r-1,c}, {r-1,c+1}, {r,c+1}, {r+1,c+1},
        {r+1,c}, {r+1,c-1}, {r,c-1}, {r-1,c-1},
    };

    // Loop through all of the valid neighbors
    for (auto coor: nPixels){
        // If the neighbor coordinates are valid (within the matrix)
        // recursively call the eraseCelestialBody function until
        // no more 1's are found. This represents the boundaries
        // of a celestial body
        if (coor[0] >= 0 && coor[0] < test.height &&
            coor[1] >= 0 && coor[1] < test.width && 
            test.matrix[coor[0]][coor[1]]) eraseCelestialBody(test,coor[0],coor[1]);
    }
}

/**
 * Counts any celestial bodies found in the image represented
 * by a matrix of pixels.
 * 
 * @param test: TestCase object with the matrix 
 * 
 * @return integer value of celestial found
 */
int countCelestialBodies(TestCase test){
    int count = 0;
    // using a set to store any matrix positions where a body was
    // previously found, to avoid duplicate counts
    std::set<int*> visited;

    // Returning 0 if an empty matrix is provided
    if (!test.height || !test.width) return count;

    // loop through all of the pixels in the matrix
    for (int row=0; row < test.height; row++){
        for(int col=0;col<test.width; col++){
            // If a 1 is found at a point in the matrix & it was not
            // previously visited, increase the count and erase the
            // body to avoid recounting it.
            if (test.matrix[row][col] && visited.find(&test.matrix[row][col]) == visited.end()) {
                visited.insert(&test.matrix[row][col]);
                count+=1;
                eraseCelestialBody(test, row, col);
            }
        }
    }

    return count;
}


int main() {
    std::cout << "--- Running Celestial Bodies Problem ---" << std::endl;
    TestCase test;
    for(int t=0; t<sizeof(TestCases)/sizeof(TestCases[0]);t++){
        test = TestCases[t];
        std::printf("Test %d:\ninput:", t+1);
        printMatrix_Int(test.matrix, test.width, test.height);
        std::printf(", Expected Result: %d\n\n", test.expectedResult);
        int ans = countCelestialBodies(test);
        std::printf("Number of celestial bodies in the image: %d\n", ans);
        std::printf("=====================================================\n");
    }
    return 0;
}
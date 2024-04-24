#include <iostream>

#define AREA1 16
#define AREA2 36

int MATRIX1[][4] = {
    { 1, 2, 3, 4},
    {12,13,14, 5},
    {11,16,15, 6},
    {10, 9, 8, 7},
};

int MATRIX2[][6] = {
    { 1,  2,  3,  4,  5,  6},
    {20, 21, 22, 23, 24,  7},
    {19, 32, 33, 34, 25,  8},
    {18, 31, 36, 35, 26,  9},
    {17, 30, 29, 28, 27, 10},
    {16, 15, 14, 13, 12, 11},
};

void printMatrix (int* matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = *((matrix + i * m) + j);
            if (val < 10) std::cout << "  " << val << " ";
            else std::cout << " " << val << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Generates an array of the matrix values found in a spiral pattern
 * 
 * @param matrix a 2D array/matrix
 * @param n number of rows in the matrix
 * @param m number of columns in the matrix
 * 
 * @return integer array of matrix spiral pattern values
*/
int* getSpiralSequence (int* matrix, int n, int m) {
    int A = m*n;
    int* spiralArr = new int[A];
    int idx = 0;
    int c_lower = 0;
    int c_upper = m-1;
    int r_lower = 0;
    int r_upper = m-1;
    int step = 1;
    int c,r;
    r = r_lower;

    while (idx < A) {
        
        if (step > 0) {
            // Column Walk positive
            for (c = c_lower; c <= c_upper;c+=step) {
                int val = *((matrix + r * m) + c);
                // std::cout << "(c)[" << r << "," << c << "] : " << val << std::endl;
                spiralArr[idx] = val;
                idx+=1;
            }
            c-=1;
        }
        else {
            // Column Walk negative
            for (c = c_upper; c >= c_lower;c+=step) {
                int val = *((matrix + r * m) + c);
                // std::cout << "(c)[" << r << "," << c << "] : " << val << std::endl;
                spiralArr[idx] = val;
                idx+=1;
            }
            c+=1;
        }
        
        // adjust column limits
        if (c == c_upper && r == r_lower) {
            c_upper-=1;
        } else if (c == c_lower && r == r_upper) {
            c_lower+=1;
            r_upper-=1;
        }
        
        if (step > 0) {
            r_lower+=1;
            // Row Walk
            for (r = r_lower; r <= r_upper;r+=step) {
                int val = *((matrix + r * m) + c);
                // std::cout << "(c)[" << r << "," << c << "] : " << val << std::endl;
                spiralArr[idx] = val;
                idx+=1;
            }
            r-=1;
        }
        else {
            // Row Walk
            for (r = r_upper; r >= r_lower;r+=step) {
                int val = *((matrix + r * m) + c);
                // std::cout << "(c)[" << r << "," << c << "] : " << val  << std::endl;
                spiralArr[idx] = val;
                idx+=1;
            }
            r+=1;
        }
        
        // Adjust row limits
        if (r == r_upper && c == c_lower) {
            r_upper-=1;
        }
        else if (r == r_lower && c == c_upper) {
            r_lower+=1;
            c_upper-=1;
        }

        // flip the for loop step
        step*=-1;
    }
    
    return spiralArr;
}

int main (int argc, char** argv) {
    int sel = -1;
    // Parse command line arguments
    if (argc == 0) return 1;
    else {
        if (argv[1][0] == '1') sel = 0;
        else if (argv[1][0] == '2') sel = 1;
    }

    int n, m, A;
    int* arr;
    std::cout << "Spiral Matrix Problem" << std::endl;
    std::cout << "\n===============================================================" << std::endl;
    switch (sel) {
        case 0:
            std::cout << "Original Matrix1:" << std::endl;
            m =  sizeof(MATRIX1[0])/sizeof(MATRIX1[0][0]);
            n =  sizeof(MATRIX1)/sizeof(MATRIX1[0]);
            A = m*n;
            std::cout << "rows: " << n << ", cols: " << m << std::endl;
            printMatrix((int*)MATRIX1,n,m);
            arr = getSpiralSequence((int*)MATRIX1,n,m);

            std::cout << "Spiral result: [ " ;
            for (int i = 0; i < A; i++) {
                if (i < A-1) std::cout << arr[i] << ", ";
                else std::cout << arr[i] << " ]" << std::endl;
            }
            break;

        case 1:
            std::cout << "Original Matrix2:" << std::endl;
            m =  sizeof(MATRIX2[0])/sizeof(MATRIX2[0][0]);
            n =  sizeof(MATRIX2)/sizeof(MATRIX2[0]);
            A = m*n;
            std::cout << "rows: " << n << ", cols: " << m << std::endl;
            printMatrix((int*)MATRIX2,n,m);
            arr = getSpiralSequence((int*)MATRIX2,n,m);

            std::cout << "Spiral result: [ " ;
            for (int i = 0; i < A; i++) {
                if (i < A-1) std::cout << arr[i] << ", ";
                else std::cout << arr[i] << " ]" << std::endl;
            }
            break;
        
        default:
            std::cout << "bad argument provded, please provide a 0 or 1" << std::endl;
            break;
    }
    

    

    // delete arr2;
    return 0;
}
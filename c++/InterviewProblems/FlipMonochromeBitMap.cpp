#include "../Utils/utils.h"
#include <bitset>
#include <cstdint>

/**
 * A flat monochrome (black & white) bitmap is given with a 
 * width in bits. The bitmap is provided as a Byte Array.
 * 
 * e.g.
 * input -> [0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf1]
 * width : 16
 * this bitmap would resemble the following:
 *      bitmap       <-     HEX
 * 00010010 00110100 <- 0x12 & 0x34
 * 01010110 01011000 <- 0x56 & 0x78
 * 10011010 10111100 <- 0x9a & 0xbc
 * 11011110 11110001 <- 0xde & 0xf1
 * 
 * Return the horizontally flipped bitmap
 * 
 */


/**
 * Test Object
 */
struct Test {
    uint8_t *bitmap, *expectedResult;
    int width;
    int height;
};

/**
 * Collection of Test Objects for the solution
 */
Test TestCases[]= {
    //0001 0010 start
    //1000 0100 reverse bits
    //0100 1000 reverse bytes
    Test{
            (uint8_t[]){0x12, 0x34},
            (uint8_t[]){0x48,0x2c},
            8,
            2
        },
    Test{
            (uint8_t[]){0x12, 0x34, 0x56, 0x78},
            (uint8_t[]){0x2c,0x48,0x1e,0x6a},
            (int)16,
            2
        },
        /* Test 3
        0x0f, 0xe0, 0xa0
        0x27, 0x90, 0x80
        0x4a, 0x9f, 0x00
        0x27, 0x90, 0x80
        0x0f, 0xe0, 0xa0
            *******     * *     
        *  ****  *    *
       *   * * *  *****
        *  ****  *    *
            *******     * *   
        */
    Test{
        (uint8_t[]){0x0f, 0xe0, 0xa0,
                    0x27, 0x90, 0x80,
                    0x4a, 0x9f, 0x00,
                    0x27, 0x90, 0x80,
                    0x0f, 0xe0, 0xa0},
        (uint8_t[]){0x5,0x7,0xf0,0x1,
                    0x9,0xe4,0x0,0xf9,
                    0x52,0x1,0x9,0xe4,
                    0x5,0x7,0xf0},
        (int)24,
        5
    }
};

/**
 * Reverses a byte
 * 
 * @param byte : byte to reverse
 * 
 */

void reverse_byte(uint8_t *byte){
    uint8_t t = 0x0;
    for (int i=0;i<8;i++){
        t |= (((*byte >> i) & 0x1)) << 7-i;
    }
    *byte = t;
}

/**
 * Swaps byte values and reverses the bits
 * 
 * @param a : 1st byte to swap
 * @param b : 2nd byte to swap
 * 
 */
void swap(uint8_t *a, uint8_t *b){
    reverse_byte(a);
    if (a==b) return;

    reverse_byte(b);
    uint8_t tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Draws a bitmap as a matrix
 * 
 * @param bitmap : flat array of bytes for a bitmap
 * @param width : width of the bitmap in bits
 * @param height : height of the bitmap (rows)
 * 
 */
void draw_bitmap(uint8_t* bitmap, int width, int height){
    std::cout << "====================================================" << std::endl;
    std::cout << "\t";
    // old method printing 1's and 0's
    int row_bound = width/8;
    // for (int i=0;i<width/8*height;i++){
    //     std::cout << (std::bitset<8>)bitmap[i];
    //     if (i==row_bound-1) {
    //         std::cout << "\n\t";
    //         row_bound+=width/8;
    //     }
    // }
    
    // new methods printing asterisks
    for (int i=0;i<width/8*height;i++){
        for (int j = 0;j<8;j++){
            if ((bitmap[i]>>(7-j))&0x1) std::cout << "*";
            else std::cout << " ";
        }
        
        if (i==row_bound-1) {
            row_bound+=width/8;
            std::cout << "\n\t";
        }
    }
    std::cout << "\n====================================================" << std::endl;
}

/**
 * Flips a Monochrome bitmap horizontally
 * 
 * @param bitmap : flat array of bytes for a bitmap
 * @param width : width of the bitmap in bits
 * @param height : height of the bitmap (rows)
 * 
 */
void flip_horizontal(uint8_t* bitmap, int width, int height){
    // draw bitmap to help with debug
    draw_bitmap(bitmap, width, height);
    
    // Because the width is in bits, it
    // is divided by the equivilant value in
    // bytes, this helps track the end of a row
    // based on the given width
    int end = width/8;

    // This gets the total amount of bytes 
    // expected in the final bitmap
    int sz = end*height;

    for(int i=0; i<sz;i+=end){
        int l = i;
        int r = i+end-1;
        while (l<=r){
            // if (l==r) bitmap[l]
            swap(&bitmap[l],&bitmap[r]);
            l++;
            r--;
        }
    }
    
    draw_bitmap(bitmap, width, height);
}


int main() {
    std::cout << " --- Running Horizontal Bitmap Problem --- " << std::endl;
    for (int i=0; i < sizeof(TestCases)/sizeof(TestCases[0]); i++){
        Test test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: { bitmap: ";
        printArray_Bytes(test.bitmap, test.width/8*test.height);
        std::cout << ", width: " << test.width << ", height: " << test.height;
        std::cout << ", expectedResult: ";
        printArray_Bytes(test.expectedResult, test.width/8*test.height);
        std::cout << " }" << std::endl;
        flip_horizontal(test.bitmap, test.width, test.height);
        printArray_Bytes(test.bitmap, test.width/8*test.height);
        std::cout << "\n=========================================================================\n" << std::endl;
    }
    return 0;
}

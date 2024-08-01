#include <iostream>

/**
 * In lower level programming like firmware, driver, or kernel code
 * many devices store system status in Control Status Registers (CSR)
 * that may be 8-64 bit long numbers. 
 * 
 * Because this is not large enough to hold readable text like strings, 
 * certain bits, or bit ranges, in each CSR are used to track system 
 * status like errors, enabled features, different modes, etc.
 * 
 * So with lower level programming it is essential to learn about bit 
 * operations & manipulations with "Bitwise Operators".
 * 
 *      >>  -   shifts bits to the right
 *      <<  -   shifts bits to the left 
 *       ~  -   boolean Compliment logic operator
 *       |  -   boolean OR logic operator
 *       &  -   boolean AND logic operator
 *       ^  -   boolean XOR logic operator
 * 
 * Terms:
 *      bit : a single digit that can be either 1 or 0
 *      nibble : 4 bits
 *      byte : 8 bits
 * 
 * Hexadecimal is represented as nibbles with 15 possible representations
 * that have decimal values.
 *      
 *     HEX |   Bin  |  DEC
 *    =====================
 *     0x0 | 0b0000 |   0   
 *     0x1 | 0b0001 |   1
 *     0x2 | 0b0010 |   2  
 *     0x3 | 0b0011 |   3
 *     0x4 | 0b0100 |   4
 *     0x5 | 0b0101 |   5
 *     0x6 | 0b0110 |   6
 *     0x7 | 0b0111 |   7
 *     0x8 | 0b1000 |   8
 *     0x9 | 0b1001 |   9
 *     0xA | 0b1010 |  10
 *     0xB | 0b1011 |  11
 *     0xC | 0b1100 |  12
 *     0xD | 0b1101 |  13
 *     0xE | 0b1110 |  14
 *     0xF | 0b1111 |  15
 */


/**
 * This sets a bit in a 32bit integer to a 1
 * 
 * @param data: 32bit integer to manipulate
 * @param bit: the bit position to set
 * 
 * @return 32bit adjusted integer 
 */
uint32_t set_bit(uint32_t data, uint8_t bit) {
    data |= 1 << bit;
    return data;
}

/**
 * This resets a bit in a 32bit integer to a 0
 * 
 * @param data: 32bit integer to manipulate
 * @param bit: the bit position to reset
 * 
 * @return 32bit adjusted integer 
 */
uint32_t rst_bit(uint32_t data, uint8_t bit) {
    data &= ~(1 << bit);
    return data;
}

/**
 * This toggle a bit in a 32bit integer to a 0
 * 
 * @param data: 32bit integer to manipulate
 * @param bit: the bit position to reset
 * 
 * @return 32bit adjusted integer 
 */
uint32_t tgl_bit(uint32_t data, uint8_t bit) {
    data ^= (1 << bit);
    return data;
}

/**
 * This gets a bit value from a 32bit integer
 * 
 * @param data: 32bit integer to manipulate
 * @param bit: the bit position to retrieve
 * 
 * @return single bit value 
 */
uint8_t get_bit(uint32_t data, uint8_t bit) {
    return (data >> bit) & 1;
}

/**
 * Reverses the bytes in a 32bit value
 * 
 * In Data Communications e.g. Bluetooth, TCP/IP, PCIe, etc, 
 * information is transmitted as byte arrays. When received, 
 * depending on the protocol used, it might be in "Little Endian"
 * format or "Big Endian" format.
 * 
 * If the value is 0x01020304 (bytes: 0x01, 0x02, 0x03, 0x04)
 * 
 * Big Endian is read with the Most Significant Byte on the left
 * left -> right 0x01, 0x02, 0x03, 0x04
 * 
 * Little Endian is read with the Most Significant byte on the right
 * right -> left 0x04, 0x03, 0x02, 0x01
 * 
 * Not reading this the right way can cause miscommunication
 * 
 * @param data: 32bit value to reverse bytes for
 * 
 * @return 32bit value with bbytes reversed
 */
uint32_t reverseBytes(uint32_t data) {
    uint32_t revr = 0;
    for (int i=0; i< 4; i++) {
        revr |= (data >> i*8) & 0xff;
        if (i < 3) revr <<= 8;
    }
    return revr;
}

int main() {
    std::cout << "--- Running Bit Manipulations ---" << std::endl;
    uint32_t val = 0xDEACBEFF;
    
    uint8_t bit = get_bit(val, 16);
    std::cout << "original value: 0x" << std::hex << val << std::endl;
    std::cout << "\nbit 16 is currently : " << bit+0 << std::endl;
    val = set_bit(val, 16);
    bit = get_bit(val, 16);
    std::cout << "bit 16 is now : " << bit+0 << std::endl;
    std::cout << "after setting bit 17: 0x" << std::hex << val << std::endl;
    
    bit = get_bit(val, 4);
    std::cout << "\nbit 4 is currently : " << bit+0 << std::endl;
    val = rst_bit(val, 4);
    bit = get_bit(val, 4);
    std::cout << "bit 4 is now : " << bit+0 << std::endl;
    std::cout << "after resetting bit 4: 0x" << std::hex << val << std::endl;
    
    bit = get_bit(val, 12);
    std::cout << "\nBit 12 toggle: " << bit+0 << ", data: 0x" << std::hex << val << std::endl;
    val = tgl_bit(val, 12);
    bit = get_bit(val, 12);
    std::cout << "Bit 12 toggle: " << bit+0 << ", data: 0x" << std::hex << val << std::endl;
    val = tgl_bit(val, 12);
    bit = get_bit(val, 12);
    std::cout << "Bit 12 toggle: " << bit+0 << ", data: 0x" << std::hex << val << std::endl;


    val = reverseBytes(val);
    std::cout << "\nAfter reversing the bytes : 0x" << std::hex << val << std::endl;
    return 0;
}
#include "../Utils/utils.h"
#include <math.h>

/**
 * Coin Change
 * 
 * You are given an integer array coins representing 
 * coins of different denominations and an integer amount 
 * representing a total amount of money. Return the 
 * fewest number of coins that you need to make up that 
 * amount. If that amount of money cannot be made up by 
 * any combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Constraints:
 *      * 1 <= coins.length <= 12
 *      * 1 <= coins[i] <= 231 - 1
 *      * 0 <= amount <= 104
 * 
 */

/**
 * Test Object
 */
typedef struct{
    std::vector<int> coins;
    int amount, expectedResult;
}Test;

/**
 * Test Cases for solution
 */
Test TestCases[] = {
    Test{{1,2,5}, 11, 3},
    Test{{2}, 3, -1},
    Test{{1}, 0, 0},
};

/**
 * Searches for the least number of coins
 * in a set, to equal a given amount.
 *
 * @param coins: vector of integers representing coin values
 * @param amount: target amount for coin combination sum
 *
 * @return integer value of total number of coins it takes to 
 * return the given amount
 *
 */
int coinChange(std::vector<int>& coins, int amount) {
    // constraints check
    if (coins.size() < 1 || coins.size() >= pow(2,31)) return -1;
    if (amount < 0 || amount > pow(10,4)) return -1;
    
    // create a dp to store coin combination sums
    // it will store the combinations for each potential
    // coin sum: 0 coins, 1 coin, 2 coins... n coins
    // where n is the amount given e.g. if 1 is a value 
    // and 10 is the amount, it would take 10 coins worth 1
    std::vector<int> dp(amount+1,amount+1);
    
    // we start with 0 as the base case
    dp[0] = 0;
    
    for (int amt=1; amt<amount+1;amt++){
            for (auto c: coins){
                // constraints check
                if (c < 1 || c > std::pow(2,31)) return -1;
                
                // loop as long as the diferrence is non-negative
                // a non-negative different would mean the sum is greater
                // than the desired amount
                if (amt-c >= 0){
                    // check for min combination, and store the value
                    dp[amt] = std::min(dp[amt], 1+dp[amt-c]);
                    
                }
            }
    }
    
    // if no result was found, return -1
    if (dp[amount] > amount) return -1;
    
    return dp[amount];
}

int main() {
    std::cout << " --- Running Coin Change LeetCode Problem --- " << std::endl;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Running Test " << i+1 << std::endl;
        Test test = TestCases[i];
        std::cout << "input: {coins: ";
        printVector_Int(test.coins);
        std::cout << ", amount: " << test.amount;
        std::cout << ", expectedResult: " << test.expectedResult << std::endl;
        int ans = coinChange(test.coins, test.amount);
        std::cout << "Actual Result: " << ans << std::endl; 
        std::cout << "\n============================================================\n" << std::endl;
    }
    return 0;
}
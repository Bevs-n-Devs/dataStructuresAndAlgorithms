#include <iostream>
#include <algorithm>
#include "../Utils/utils.h"

/**
 * A cafeteria table consists of a row of N seats, numbered from 1 to N from left to right. 
 * Social distancing guidelines require that every diner be seated such that K seats to their 
 * left and K seats to their right (or all the remaining seats to that side if there are 
 * fewer than K) remain empty.
 * 
 * There are currently M diners seated at the table, the ith of whom is in seat Si. No two 
 * diners are sitting in the same seat, and the social distancing guidelines are satisfied.
 * 
 * Determine the maximum number of additional diners who can potentially sit at the table 
 * without social distancing guidelines being violated for any new or existing diners, 
 * assuming that the existing diners cannot move and that the additional diners will cooperate 
 * to maximize how many of them can sit down.
 * 
 * Constraints
 *      * 1 ≤ N ≤ 10^15
 *      * 1 ≤ K ≤ N
 *      * 1 ≤ M ≤ 500,000
 *      * M ≤ N
 *      * 1 ≤ S ≤ N
 * 
 */
typedef struct {
    long long N, K;
    int M;
    std::vector<long long> S;
    long long expectedResult;
} Test;

Test TestCases[] {
    Test{10,1,2,{2,6}, 3},
    Test{15,2,3,{11,6,14}, 1}
};

long long getMaxAdditionalDinersCount(long long N, long long K, int M, std::vector<long long> S) {
    /**
     * Get the max number of additional diners given seat restrictions
     * 
     * @param N : number of seats
     * @type N : long long
     * @param K : number of seats between diners
     * @type K : long long 
     * @param M : currently seated diners
     * @type M : int
     * @param S : seated diners
     * @type S : vector<long long>
     * 
     * @return long long value for the number of available seats
     */

    // return value
    long long ret = 0;
    
    // check constraints
    if (N < 1 || N > std::pow(10, 15)){
        return ret;
    }
    if (K < 1 || K > N) {
        return ret;
    }
    if (M < 1 || M > 500000) {
        return ret;
    }
    if (M > N) {
        return ret;
    }
    
    // sort the seats so they are in order
    // to help with index tracking
    sort(S.begin(),S.end());

    // if the first value is greater than the distance
    // restriction seats, get the number of available seats 
    // before that occupied seat with division (this defaults to non-decimal division)
    if (S[0]-1 > K+1)
        ret += ((S[0]-1)/(K+1));
    
    // if the space after the last occupied seat is greater 
    // tha the distance restriction, division is used again to 
    // retrieve the number of availble seats after that occupied seat
    if (N - S[S.size()-1] > K+1)
        ret += ((N - S.back())/(K+1));
    
    // declare a variable to track the index position
    long long l = 1;

    // loop through the occupied seats adding available seats
    // when the spaces between occupied seats exceeds the 
    // seat restrictions
    while (l < S.size()){
        if (S[l]<1 | S[l]>N) return 0;
        if ((S[l]-S[l-1]) > K+1){
        ret += ((S[l] - S[l-1]) / (K+1))-1;  
        }
        l+=1;
    }
    
    return ret;
}

int main(){
    std::cout << " --- Running Solution for Meta Code Puzzle: Cafeteria  --- " << std::endl;
    Test test;
    long long ans;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Test " << i+1 << std::endl;
        test = TestCases[i];
        std::cout << "input: {N: " << test.N << ", K: " << test.K << ", M: " << test.M << "S: ";
        printVector_LngLng(test.S);
        std::cout << ", expected Result: " << test.expectedResult << "}" << std::endl;
        ans = getMaxAdditionalDinersCount(test.N, test.K, test.M, test.S);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n======================================================================\n" << std::endl;
    }
}
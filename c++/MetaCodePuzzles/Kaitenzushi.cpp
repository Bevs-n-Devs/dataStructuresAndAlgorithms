#include <iostream>
#include <map>
#include "../Utils/utils.h"

/**
 * There are N dishes in a row on a kaiten belt, with the ith dish being of type
 * D(i). Some dishes may be of the same type as one another.
 * 
 * You're very hungry, but you'd also like to keep things interesting. The N dishes 
 * will arrive in front of you, one after another in order, and for each one you'll 
 * eat it as long as it isn't the same type as any of the previous K dishes you've 
 * eaten. You eat very fast, so you can consume a dish before the next one gets to 
 * you. Any dishes you choose not to eat as they pass will be eaten by others. 
 * 
 * Determine how many dishes you'll end up eating.
 * 
 * Constraints
 *      * 1 ≤ N ≤ 500,000
 *      * 1 ≤ K ≤ N
 *      * 1 ≤ D(i) ≤ 1,000,000
 * 
 */

typedef struct {
    int N;
    std::vector<int> D;
    int K, expectedResult;
} Test;

Test TestCases[] {
    Test{6, {1, 2, 3, 3, 2, 1}, 1, 5},
    Test{6, {1, 2, 3, 3, 2, 1}, 2, 4},
    Test{7, {1, 2, 1, 2, 1, 2, 1}, 2, 2},
};

/**
 * Gets maximum number of eaten sushi dishes without repeating 
 * dishes within a certain range
 * 
 * @param N : number of dishes
 * @param D : series of dishes
 * @param K : range of previous dishes to consider not repeating
 * 
 * @return number of easten dishes
 * 
 */
int getMaximumEatenDishCount(int N, std::vector<int> D, int K) {
  // Constraints check
  if (N < 1 | N > 500000) return 0;
  if (K < 1 | K > N) return 0;
  
  // declare variable to store result
  int res = 0;
  
  // declaring map for O(1) search :: This helps resolve 
  // the final time exceeding issue
  std::map<int, bool> m;
  // declaring a vector for correct ordering of 
  // previously eaten dishes
  std::vector<int> v;

  // loop through dishes
  for (int i = 0; i < N; i++){
    int val = D[i];
    // Constraints check
    if (val < 1 | val > 1000000) return 0;
    
    // if this was not a previously eaten dish 
    // within the K range, eat the dish
    if (!m[val]){
      // increase eaten list
      res+=1;
      // store in eaten dish history vector
      v.push_back(val);
      // set that value to true in the map
      m[val] = true;

      // if the history vector exceeds the limit
      // remove the oldest value
      if (v.size() > K) {
        m[v.front()] = false;
        v.erase(v.begin());
      }
    }
    
   }
    
  return res;
}

int main() {
    std::cout << " --- Running Meta Code Puzzle: Kaitenzushi Solution --- " << std::endl;
    Test test;
    int ans;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {N: " << test.N << ", D: ";
        printVector_Int(test.D);
        std::cout << ", K: " << test.K << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getMaximumEatenDishCount(test.N, test.D, test.K);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n==================================================================\n" << std::endl;
    }
}
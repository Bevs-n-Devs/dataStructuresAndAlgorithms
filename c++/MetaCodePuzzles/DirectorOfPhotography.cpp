#include <iostream>
#include "../Utils/utils.h"

/**
 * 
 */


typedef struct {
    int N;
    std::string C;
    int X, Y, expectedResult;
} Test;

Test TestCases[] = {
    Test{5,"APABA",1,2,1},
    Test{5,"APABA",2,3,0},
    Test{8,".PBAAP.B",1,3,3},
};

/**
 * Gets the number of "Artistic Photos" within a given range, between
 * a backdrop and a photographer
 * 
 * @param N : number of characters in a string
 * @param C : The string representing the photo shoot elements
 * @param X : minimum distance from Photographer & Backdrop for Actor
 * @param Y : maximum distance from Photographer & Backdrop for Actor
 * 
 * @return number of valid artistic images
 * 
 */
int getArtisticPhotographCount(int N, std::string C, int X, int Y) {
  // Constraints check
  if (N < 1 | N > 200) return 0;
  if (X < 1 | X > Y | Y > N) return 0;
  
  int l, r, res;
  res = 0;
  l = 0;
  r = N-1;
  // This is a brute force approach
  // loop through every value
  while (l<N){
      // from the left, find the first matching Photographer or Backdrop
      if (C[l] == 'P' | C[l] == 'B') {
        // Because letters might repeat, the next loop will always
        // start from the furthest right character
        r=N-1;
        
        // now work from right to left
        while (r > l) {
          // loop through all right characters until the opposing character;
          // e.g. 'B' for the right if 'P' was found on the left, or the inverse
          if ( C[r] != C[l] & (C[r] == 'P' | C[r] == 'B')) {
            
            // Once the matching character is found, loop through the 
            // characters between the Backdrop & Photographer, searching
            // for actors
            for (int i = l+1; i<r; i++){
              // if an Actor is found and is within the X & Y distances (inclusively)
              // increment the artistic photo count
              if (C[i] == 'A' & 
                  i-l >= X & r-i >= X &
                  i-l <= Y & r-i <= Y) {
                res+=1;
              }
            }
          }

          r-=1;
        }
      }
      
      l+=1;
  }
  return res;
}

int main() {
    std::cout << " --- Running Meta Code Puzzle: Director of Photography Solution --- " << std::endl;
    Test test;
    int ans;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input : {N: " << test.N << ", C: "\
            << test.C << ", X: " << test.X << ", Y: " << test.Y\
            << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getArtisticPhotographCount(test.N, test.C, test.X, test.Y);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n===============================================================================\n" << std::endl;
    }
}
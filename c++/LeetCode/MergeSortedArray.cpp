#include <iostream>
#include <vector>
#include <math.h>


struct Test {
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    void printVectors(bool isResult=false) {
        if (isResult) std::cout << " - RESULT - \t" << " [";
        else std::cout << " - input - \tm:" << m << " [";
        for (auto i: nums1){
            if (i == nums1.front()) std::cout << i;
            else std::cout << "," << i ;
        }
        std::cout<< "]";
        if (isResult) std::cout << std::endl;
        else { 
            std::cout << ", n:" << n << " [";
            for (auto i: nums2){
                if (i == nums2.front()) std::cout << i;
                else std::cout << "," << i ;
            }
            std::cout<< "]" << std::endl;
        }
    }
    void printResult() {
        printVectors(true);
    }
};
Test TestCases[] = {
    Test{
        {1,2,3,0,0,0}, 
        3, 
        {2,5,6},
        3
    },
    Test{
        {1}, 
        1, 
        {},
        0
    },
    Test{
        {0}, 
        0, 
        {1},
        1
    },
};

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (nums1.size() != m+n) return;
    if (nums2.size() != n) return;
    if (m < 0 || n > 200) return;
    if (m+n < 1 || m+n > 200) return;
    int ulmt = pow(10, 9);
    int llmt = pow(-10, 9);
    
    int i = 0;
    while (nums2.size()) {
        if (nums2[0] > ulmt) return;
        if (i >= m) {
            nums1[i] = nums2[0];
            nums2.erase(nums2.begin());
        }
        else if (nums2[0] < nums1[i]) {
            if (nums1[i] < llmt) return;
            
            nums1.insert(nums1.begin()+i, nums2[0]);
            nums1.pop_back();
            nums2.erase(nums2.begin());
            m+=1;
        }
        i+=1;
    }
}

int main() {
    int i = 0;
    std::cout << "--- Merge Sorted Array Problem ---" << std::endl;
    for(auto test: TestCases) {
        std::cout << "Running test case : " << i+1 << std::endl;
        test.printVectors();
        merge(test.nums1, test.m, test.nums2, test.n);
        test.printResult();
        std::cout << "=====================================" << std::endl;
        i+=1;
    }
    return 0;
}
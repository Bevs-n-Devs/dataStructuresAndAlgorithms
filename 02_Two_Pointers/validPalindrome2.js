/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
     // Convert the string to lowercase and remove non-alphanumeric characters
     const cleanString = s.toLowerCase().replace(/[^a-z0-9]/g, '');
    
     // Create left and right pointers
     let leftPointer = 0;
     let rightPointer = cleanString.length - 1;
     
     // Check if each pointer has a valid alphanumeric
     // If not, move the pointer (forward or backwards) by 1
     while (leftPointer < rightPointer) {
         // Compare the alphanumeric values in each pointer
         if (cleanString[leftPointer] !== cleanString[rightPointer]) {
             return false;
         }
         
         // Move each pointer to the next character in the cleaned string
         leftPointer += 1;
         rightPointer -= 1;
     }
     return true;
};

// implementation
console.log("Leetcode 125: Valid Palindrome\n");

// example 1
example1 = "A man, a plan, a canal: Panama";
console.log(`Example 1: s = '${example1}'`);
console.log("Output:", isPalindrome(example1));
  
// example 2
example2 = "race a car";
console.log(`Example 2: s = '${example2}'`);
console.log("Output:", isPalindrome(example2));

// example 3
example3 = " ";
console.log(`Example 3: s = '${example3}'`);
console.log("Output:", isPalindrome(example3));
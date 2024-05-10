/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    // create empty string to store letters
    let newStr = '';

    // loop through each letter of string
    for (let i = 0; i < s.length; i++) {
        const char = s[i];    // this will loop each str character
        
        // check if letter is alphanumeric using regex
        if (/[a-zA-Z0-9]/.test(char)) {
            // add letter to empty string
            newStr += char.toLowerCase();
        }
    }

    // reverse the letters to see if palindrome
    return newStr === newStr.split('').reverse().join('');

    const palindromeString = isPalindrome('race a car');
    console.log(palindromeString);
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
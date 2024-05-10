/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    // first check if both strings match length
    if (s.length !== t.length) {
        return false;
    }

    /*
    Now we create the empy hashmaps, which will count
    how many times each letter appears in the string.
    */
    const countS = {};
    const countT = {};

    // loop through strings, adding them to their hashmap
    for (let i = 0; i < s.length; i++) {
        // this adds current letter of string to hashmap, with number of entries 
        countS[s[i]] = 1 + (countS[s[i]] || 0);
        countT[t[i]] = 1 + (countT[t[i]] || 0);
    }

    // check if both hashmaps are equal
    for (const char in countS) {
        // checks if pairs are NOT equal
        if (countS[char] !== countT[char]) {
            return false;
        }
    }
    return true;
};


// implementation

console.log("Leetcode 242: Valid Anagram \n")

// Example 1
const [s1, t1] = ["anagram", "nagaram"];  // this is a way of creating two variables in one line
console.log(`Example 1: s = "${s1}", t = "${t1}"`);
console.log("Output:", isAnagram(s1, t1));

// Exmaple 2
const s2 = "rat";
const t2 = "car";
console.log(`Example 2: s = "${s2}", t = "${t2}"`);
console.log("Output:", isAnagram(s2, t2));

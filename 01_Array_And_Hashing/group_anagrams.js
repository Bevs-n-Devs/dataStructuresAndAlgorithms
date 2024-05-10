/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const groupedAnagrams = new Map();

   for (const str of strs) {
       const key = str.split('').sort().join('');
       if (!groupedAnagrams.has(key)) {
           groupedAnagrams.set(key, []);
       }
       groupedAnagrams.get(key).push(str);
   }

   return Array.from(groupedAnagrams.values());
};


// implementation
console.log("Leetcode 49: Group Anagrams\n");

// Example 1
example1 = ["eat", "tea", "tan", "ate", "nat", "bat"];
console.log(`Example 1: strs = ${example1}`);
console.log("Output:", groupAnagrams(example1));

// Example 2
example2 = [""];
console.log(`Example 2: strs = ${example2}`);
console.log("Output:", groupAnagrams(example2));

// Example 3
example3 = ["a"];
console.log(`Example 3: strs = ${example3}`);
console.log("Output:", groupAnagrams(example3));
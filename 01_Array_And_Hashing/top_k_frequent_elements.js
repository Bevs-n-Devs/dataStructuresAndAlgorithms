/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

// Function to find the top k frequent elements in an array
var topKFrequent = function(nums, k) {
    // Map to store the frequency count of each element
    const mp = new Map();

    // Array to store elements grouped by their frequency
    const arr = new Array(nums.length + 1).fill(0);

    // Array to store the final result
    const ans = [];

    // Count the frequency of each element and store it in the map
    nums.forEach(el => {
        const val = mp.get(el) || 0;
        mp.set(el, val + 1);
    });

    // Group elements by frequency in the 'arr' array
    for (let [key, value] of mp) {
        const prev = arr[value] || [];
        prev.push(key);
        arr[value] = prev;
    }

    // Reverse the 'arr' array to iterate from highest to lowest frequency
    arr.reverse();

    // Iterate through the 'arr' array and add elements to the result list
    for (let el of arr) {
        if (k < 1) break;
        if (el) {
            for (let el2 of el) {
                ans.push(el2);
                k--;
            }
        }
    }

    // Return the final result
    return ans;
};


// implement

console.log("Leetcode 347: Top K Frequent Elements\n");

// Example 1
const example1 = [1, 1, 1, 2, 2, 3];
const k1 = 2;
console.log(`Example 1: nums = [${example1}], k = ${k1}`);
console.log("Output:", topKFrequent(example1, k1));

// Example 2
const example2 = [1];
const k2 = 1;
console.log(`Example 2: nums = [${example2}], k = ${k2}`);
console.log("Output:", topKFrequent(example2, k2));
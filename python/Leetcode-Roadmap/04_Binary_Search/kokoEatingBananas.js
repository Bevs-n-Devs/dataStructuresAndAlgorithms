/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    // set left & right pointers
    let left = 1, right = Math.max(...piles);
    // set result to highest number (this is only temporary)
    let result = right;
    
    while (left <= right) {
        // get the value of k 
        const k = Math.floor((left + right) / 2);
        let totalTime = 0;
        
        // loop through each item in list
        for (const pile of piles) {
            // update total time by dividing pile by k
            // use Math.ceil() to round up to nearest number
            totalTime += Math.ceil(pile / k);
        }
        
        // binary search
        
        // update the result if totalTime is less or equal to hours
        if (totalTime <= h) {
            result = k;
            // update right pointer to search the left side of list
            right = k - 1;
        } else {
            // update left pointer to search the right side of list
            left = k + 1;
        }
        
    }
    // return the result after the loop has finished
    return result;
    
};

// implementation
console.log("Leetcode 875: Koko Eating Bananas\n");

// Example 1
const piles1 = [3, 6, 7, 11];
var hours1 = 8;
console.log(`Example 1: piles = [${piles1}], h = ${hours1}`);
console.log("Output:", minEatingSpeed(piles1, hours1));

// Example 2
const piles2 = [30, 11, 23, 4, 20];
var hours2 = 5;
console.log(`Example 2: piles = [${piles2}], h = ${hours2}`);
console.log("Output:", minEatingSpeed(piles2, hours2));

// Example 3
var hours3 = 6;
console.log(`Example 3: piles = [${piles2}], h = ${hours3}`);
console.log("Output:", minEatingSpeed(piles2, hours3));
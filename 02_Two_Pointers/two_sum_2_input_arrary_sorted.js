var twoSum = function(numbers, target) {
    // create left and right pointers 
   let pLeft = 0, pRight = (numbers.length) - 1;
   
   // loop through the numbers array using pointers
   while (pLeft < pRight) {
       // add pointers together
       let currentSum = numbers[pLeft] + numbers[pRight];
       
       // move right pointer if current sum higher than target
       if (currentSum > target) {
           pRight -= 1;
       } else if (currentSum < target) {
           pLeft += 1;
       } else {
           return [pLeft + 1, pRight + 1];
       }
   }
};

// implementation

console.log("Leetcode 167: Two Sum 2 - Input Array Sorted\n");

// Example 1
const example1 = [2, 7, 11, 15];
let target1 = 9;
console.log(`Example 1: numbers = [${example1}], target = ${target1}`);
console.log("Output:", twoSum(example1, target1));

// Example 2
const example2 = [2, 3, 4];
let target2 = 6;
console.log(`Example 2: numbers = [${example2}], target = ${target2}`);
console.log("Output:", twoSum(example2, target2));

// Example 3
const example3 = [-1, 0];
let target3 = -1;
console.log(`Example 3: numbers = [${example3}], target = ${target3}`);
console.log("Output:", twoSum(example3, target3));
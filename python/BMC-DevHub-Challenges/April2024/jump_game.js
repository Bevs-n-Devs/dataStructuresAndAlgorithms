var canJump = (nums, right = nums.length - 1) => {
    // iterate backwards from the right to the beginning og the array
    for (let index = right; 0 <=index; index--) {
        // check if the current index allows you to jump to the right position
        const isJumpable = right <= (index + nums[index]);
        // if it can jump, then update the right position
        if (isJumpable) right = index;
    }

    // return true if the right position has reached the start (index 0)
    return right === 0;
}


// implementation:
const example1 = [2, 3, 1, 1, 4];
console.log(canJump(example1));

const example2 = [3, 2, 1, 0, 4];
console.log(canJump(example2));
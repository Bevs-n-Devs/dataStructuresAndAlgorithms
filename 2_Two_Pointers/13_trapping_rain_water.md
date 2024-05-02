Two Pointers 5
# Trapping Rain Water
## Company: Google
### Level: Hard

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

***Break It Down For Me...***
*You have a bunch of bars lined up next to each other, and each bar is a certain height.*
*It has been raining and water is trapped between the bars.*
*What we need to do is to find out how much water gets trapped between the bars.* 
*Basically return amount of water/blocks of water trapped.*
*To do this we must consider the following:*
- *Look at the height of each bar.*
- *Imagine water filling up the gaps between the bars.*
- *Calculate how much water is trapped between teh bars once the rain stops.*

Click [here](https://leetcode.com/problems/trapping-rain-water/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=ZI2z5pq0TqA) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use the [Pointer method](https://www.studysmarter.co.uk/explanations/computer-science/computer-programming/pointers-and-arrays/#:~:text=C%20programming%20language%3F-,A%20pointer%20is%20a%20variable%20that%20stores%20the%20memory%20address,the%20efficiency%20of%20certain%20algorithms.) in Pythopn, JavaScript and Go.

### Example 1
```
Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
```

### Example 2
```
Input: height = [4, 2, 0, 3, 2, 5]
Output: 9
```

## Python
```
if not height:
    return 0

left, right = 0, len(height) - 1

leftMax, rightMax = height[left], height[right]

result = 0

while left < right:
    if leftMax < rightMax:
        left += 1
        leftMax = max(leftMax, height[left])
        result += leftMax - height[left]
    else:
        right -= 1
        rightMax = max(rightMax, height[right])
        result += rightMax - height[right]

return result

# Code comments can be found in trapping_rain_water.go
```

## JavaScript
```
let [left, right] = [0, height.length - 1];

let [maxLeft, maxRight, area] = [0, 0, 0];

while (left < right) {
    const [leftHeight, rightHeight] = getHeights(height, left, right);

    const [leftWindow, rightWindow] = getWindows(
        height,
        left,
        maxLeft,
        right,
        maxRight
    );

    const isRightGreater = leftHeight <= rightHeight;

    if (isRightGreater) {
        if (hasNewMax(maxLeft, leftHeight)) maxLeft = leftHeight;
        else area += leftWindow;

        left++;
    }

    const isRightLess = rightHeight < leftHeight;

    if (isRightLess) {
        if (hasNewMax(maxRight, rightHeight)) maxRight = rightHeight;
        else area += rightWindow;

        right--;
    }
}

return area;

const hasNewMax = (max, height) => max < height;

const getHeights = (height, left, right) => [height[left], height[right]];

const getWindows = (height, left, maxLeft, right, maxRight) => {
    const [leftHeight, rightHeight] = getHeights(height, left, right);

    const [leftWindow, rightWindow] = [
        maxLeft - leftHeight,
        maxRight - rightHeight,
    ];

    return [leftWindow, rightWindow];
};

// Code comments can be found in trappingRainWater.js
```

## Go
```
if height == nil {
    return 0
}

left, right := 0, len(height) - 1
leftMax, rightMax := height[left], height[right]
res := 0

for left < right {
    if leftMax < rightMax {
        left += 1
        leftMax = max(leftMax, height[left])
        res += leftMax - height[left]
    } else {
        right -= 1
        rightMax = max(rightMax, height[right])
        res += rightMax - height[right]
    }
}
return res

func max(a int, b int) int {
    if a > b {
        return a;
    }
    return b;
}

// Code comments can be found in trappingRainWater.go
```
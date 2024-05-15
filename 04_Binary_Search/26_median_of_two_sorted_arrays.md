Binary Search 6
# Median of Two Sorted Arrays
## Company: Meta
### Level: Medium

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

***Break It Down For Me...***
*You have two lists of numbers, `nums1` and `nums2`. Both lists are sorted in order from smallest to largest. You need to find the median value when you combine these two lists into one larger list. The median is the middle number in a list of numbers.*

Click [here](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=q6IEA26hvXc) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Binary Search](https://www.geeksforgeeks.org/what-is-binary-search-algorithm/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: nums1= [1, 3], nums2 = [2]
Output: 2.00000
```
**Explanation:** the merged array is `[1, 2, 3]`, so the median is `2`.

### Example 2
```
Input: nums1 = [1, 2], nums2 = [3, 4]
Output: 2.50000
```
**Explanation:** the merged array is `[1, 2, 3, 4]`, so the median is `(2 + 3) / 2 = 2.5`.

### Python
```
A, B = nums1, nums2
total = len(nums1) + len(nums2)
half = total // 2

if len(B) < len(A):
    A, B = B, A

l, r = 0, len(A) - 1

while True:
    i = (l + r) // 2  # Pointer for array A
    j = half - i - 2  # Pointer for array B

    Aleft = A[i] if i >= 0 else float("-infinity")
    Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
    Bleft = B[j] if j >= 0 else float("-infinity")
    Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")

    if Aleft <= Bright and Bleft <= Aright:
        if total % 2:
            return min(Aright, Bright)
        return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
    elif Aleft > Bright:
        r = i - 1
    else:
        l = i + 1

# Code comments can be found in median_of_two_sorted_arrays.py
```

### JavaScript
```
var findMedianSortedArrays = function (nums1, nums2) {
    const canSwap = nums2.length < nums1.length;
    if (canSwap) [nums1, nums2] = [nums2, nums1];

    let [left, right] = [0, nums1.length - 1];
    const totalLength = nums1.length + nums2.length;
    const mid = totalLength >> 1;
    const isEven = totalLength % 2 === 0;

    while (true) {
        const mid1 = left + right;
        const mid2 = mid - mid1 - 2;
        const { aLeft, aRight, bLeft, bRight } = getPointers(
            nums1,
            mid1,
            nums2,
            mid2
        );

        const isTarget = aLeft <= bRight && bLeft <= aRight;
        if (isTarget)
            return isEven
                ? (Math.max(aLeft, bLeft) + Math.min(aRight, bRight)) / 2
                : Math.min(aRight, bRight);

        const isTargetGreater = aLeft <= bRight;
        if (isTargetGreater) left = mid1 + 1;

        const isTargetLess = bRight < aLeft;
        if (isTargetLess) right = mid1 - 1;
    }
};

const getPointers = (nums1, mid1, nums2, mid2) => {
    const getLeft = (nums, index) => (0 <= index ? nums[index] : -Infinity);

    const [aLeft, bLeft] = [getLeft(nums1, mid1), getLeft(nums2, mid2)];

    const getRight = (nums, index) =>
        index + 1 < nums.length ? nums[index + 1] : Infinity;

    const [aRight, bRight] = [getRight(nums1, mid1), getRight(nums2, mid2)];

    return { aLeft, aRight, bLeft, bRight };
};

// Code comments can be found in medianOfTwoSortedArrays.js
```

### Go
```
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	A, B := nums1, nums2
	total := len(nums1) + len(nums2)
	half := (total + 1) / 2

	var Aleft, Aright float64
	var Bleft, Bright float64

	if len(B) < len(A) {
		A, B = B, A
	}

	l, r := 0, len(A)-1
	for {
		i := (l + r) >> 1 // A
		j := half - i - 2 // B

		if i >= 0 {
			Aleft = float64(A[i])
		} else {
			Aleft = math.Inf(-1)
		}

		if (i + 1) < len(A) {
			Aright = float64(A[i+1])
		} else {
			Aright = math.Inf(1)
		}

		if j >= 0 {
			Bleft = float64(B[j])
		} else {
			Bleft = math.Inf(-1)
		}

		if (j + 1) < len(B) {
			Bright = float64(B[j+1])
		} else {
			Bright = math.Inf(1)
		}

		// partition is correct
		if Aleft <= Bright && Bleft <= Aright {
			// odd
			if total%2 == 1 {
				return max(Aleft, Bleft)
			}
			// even
			return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
		} else if Aleft > Bright {
			r = i - 1
		} else {
			l = i + 1
		}
	}
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

// Code comments can be found in medianOfTwoSortedArrays.go
```
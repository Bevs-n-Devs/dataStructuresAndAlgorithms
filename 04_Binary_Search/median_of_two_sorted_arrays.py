class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # Make sure nums1 is the smaller array
        A, B = nums1, nums2
        total = len(nums1) + len(nums2)
        half = total // 2

        if len(B) < len(A):
            A, B = B, A

        # Initialize pointers for binary search
        l, r = 0, len(A) - 1

        # Perform binary search
        while True:
            i = (l + r) // 2  # Pointer for array A
            j = half - i - 2  # Pointer for array B

            # Get values for partitioning
            Aleft = A[i] if i >= 0 else float("-infinity")
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
            Bleft = B[j] if j >= 0 else float("-infinity")
            Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")

            # Check if the partition is correct
            if Aleft <= Bright and Bleft <= Aright:
                # If the total number of elements is odd, return the smaller of Aright and Bright
                if total % 2:
                    return min(Aright, Bright)
                # If the total number of elements is even, return the average of the larger of Aleft and Bleft and the smaller of Aright and Bright
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            elif Aleft > Bright:
                # Adjust the pointers for binary search
                r = i - 1
            else:
                # Adjust the pointers for binary search
                l = i + 1

# implementation
answer = Solution()

print("Leetcode 4: Median of Two Dorted Arrays\n")

# Example 1
nums_1 = [1, 3]
nums_2 = [2]
print(f"Example 1: nums1 = {nums_1}, nums2 = {nums_2}")
print("Outcome:", answer.findMedianSortedArrays(nums_1, nums_2))

# Example 2
nums_1 = [1, 2]
nums_2 = [3, 4]
print(f"Example 2: nums1 = {nums_1}, nums2 = {nums_2}")
print("Outcome:", answer.findMedianSortedArrays(nums_1, nums_2))
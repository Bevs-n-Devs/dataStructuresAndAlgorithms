21/06/2024
# Code Wars: Biggest of the Smallest of the Biggest of the...

Your Task:

You are given an array arr of integers, and a string str that contains
steps to extract an array out of arr.

str contains a chained combination of "the biggest" and "the smallest"
inside it. An example would be "the biggest of the smallest of the
biggest of the biggest". At each step in str, extract either the
biggest or the smallest values from arr, and continue to the next step
with the extracted values.

Example:

Given the array [1,2,3,4,5,6,7,8,9] and the string "the biggest of the
smallest", you should return [3,4]. The first step in str is "the
smallest", and the smallest of the array is [1,2,3,4]. You then
proceed to the next step in str with this extracted array, [1,2,3,4].
The next step in str is "the biggest", and the biggest of [1,2,3,4] is
[3,4].


***Break It Down For Me...***

*What we need to do is take an array of numbers, and then follow a set of rules to pick out the rumbers in order to return the final group of numbers.*
*We first start with the whole array.*
*Then for each step:*
- If it's `the smallest` we keep the smallest half of the numbers
- if it's `the biggest` we keep the biggest half of the numbers
*We keep doing this with the new group of numbers until only the snmallest amount of possible numbers remain.*

### Example 1
```
Input: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Output:  [3, 4]
```

### Example 2
```
Input: [23, 567, 33, 13, 67, 43, 678, 9, 1, 56]
Output: [43, 56]
```

## Python
```
def extract_array(arr, instructions):
    if not arr:
        return []
    if not instructions:
        return arr
    
    # Split instructions into steps
    steps = instructions.split(' of ')
    
    # Create a list of tuples (value, original_index) to keep track of original positions
    indexed_arr = list(enumerate(arr))
    
    for step in steps:
        # Sort the array based on values
        indexed_arr.sort(key=lambda x: x[1])
        
        length = len(indexed_arr)
        if step == "the smallest":
            if length % 2 == 0:
                indexed_arr = indexed_arr[:length // 2]
            else:
                indexed_arr = indexed_arr[:length // 2]
        elif step == "the biggest":
            if length % 2 == 0:
                indexed_arr = indexed_arr[length // 2:]
            else:
                indexed_arr = indexed_arr[length // 2:]
                
        # If the length becomes one, return the current array
        if len(indexed_arr) == 1:
            break

    # Extract the values from the final indexed array and restore original order
    result = sorted(indexed_arr, key=lambda x: x[0])
    return [x[1] for x in result]

# Example usage:
arr = [23, 567, 33, 13, 67, 43, 678, 9, 1, 56]
instructions = "the smallest of the biggest"
print(extract_array(arr, instructions))  # Output: [43, 56]
```
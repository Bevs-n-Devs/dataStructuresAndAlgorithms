Stack 5
# Daily Temperatures
## Company: Meta
### Level: Medium

Given an array of integers `temperature` represents the daily temperatures, return an array `answer` such that `answer[i]` is in the number of days you have to wait after the `ith` day to get a warmer temperature.
If there is no future day for which this is possible, keep `answer[i] == 0` instead.

***Break It Down For Me...***
*We are given a list of temperatures for each day.* 
*For each day, we have to figure out how many days we have to wait until the temperature gets warmer.*
*If there is no warmer day in the future, we can put `0` for the day.*

Click [here](https://leetcode.com/problems/daily-temperatures/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=cTBiBSnjO3c) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]
```

### Example 2
```
Input: temperatures = [30, 40, 50, 60]
Output: [1, 1, 1, 0]
```

### Example 2
```
Input: temperatures = [30, 60, 90]
Output: [1, 1, 0]
```

## Python
```
result = [0] * len(temperatures)

stack = []  # Stack elements: [temperature, index]

for index, temp in enumerate(temperatures):
    while stack and temp > stack[-1][0]:
        stackTemp, stackInd = stack.pop()
        res[stackInd] = index - stackInd

    stack.append((temp, index))

return result

# Code comments can be found in daily_temperatures.py
```

## JavaScript
```
const days = new Array(temperatures.length).fill(0);

for (let day = (temperatures.length - 1); (0 <= day); day--) {
    const temperature = temperatures[day];

    const isHotter = hottest <= temperature;
    if (isHotter) {
        hottest = temperature;
        continue;
    }

    search(temperatures, day, temperature, days);
}

return days;

const search = (temperatures, day, temperature, days, dayCount = 1) => {
    const isHotter = () => temperatures[day + dayCount] <= temperature;

    while (isHotter()) {
        dayCount += days[day + dayCount];
    }

    days[day] = dayCount;
}

// Code comments can be found in dailyTemperatures.js
```

## Go
```
func dailyTemperatures(temperatures []int) []int {
    result := make([]int, len(temperatures))
    
    for i := len(temperatures) - 1; i >= 0; i-- {
        j := i + 1
        
        for j < len(temperatures) && temperatures[j] <= temperatures[i] {
            if result[j] <= 0 {
                break
            }
            j += result[j]
        } 
        
        if j < len(temperatures) && temperatures[j] > temperatures[i] {
            result[i] = j - i
        }
        
    }
    return result
}

// Code comemnts can be found in dailyTemperatures.go
```
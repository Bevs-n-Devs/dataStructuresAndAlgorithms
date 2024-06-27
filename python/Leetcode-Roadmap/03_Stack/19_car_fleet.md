Stack 6
# Car Fleet
## Company: Google
### Level: Medium

Threre are `n` cars going to the same direction along a one-lane road.
The destination is `target` miles away.

You are given two integer array `position` and `speed`, both of length `n`, where `position[i]` is the position of the `i`th car and `speed[i]` is the speed of the `i`th car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper **at the same speed**.
The faster car will **slow down** to match the slower car's speed.
The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A **car fleet** is some non-empty set of cars driving at the sam eposition and same speed.
Note that a single car is also a fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered ass one car fleet.

Return the **number of car fleets** that will arrive at the destination.

***Break It Down For Me...***
*Imagine there's a road where cars are driving in the same direction.*
*Each car has its own position on the road and its own speed.*
*We want to know how many groups of cars (or "fleets") will reach the same destination point.*

Click [here](https://leetcode.com/problems/car-fleet/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Pr6T-3yB9RM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) in Python, JavaScript and Go.

### Example 1
```
Input: target = 12, position = [10, 8, 0, 5, 3], speed = [2, 4, 1, 1, 3]
Output: 3
```
**Explanation:** The cars starting at 10 (`speed 2`) and 8 (`speed 4`) become a fleet, meeting each other at 12.
The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (`speed 1`) and 3 (`speed 3`) become a fleet, meeting each other at 6. The fleet moves at `speed 1` until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3.

### Example 2
```
Input: target = 10, position = [3], speed = [3]
Output: 1
```
**Explanation:** There is only one car, hence there is only one fleet.

### Example 3
```
Input: target = 100, position = [0, 2, 4], speed = [4, 2, 1]
Output: 1
```
**Explanation:** The cars starting at 0 (`speed 4`) and 2 (`speed 2`) become a fleet, meeting each other at 4. The fleet moves at `speed 2`.
Then, the fleet (`speed 2`) and the car starting at 4 (`speed 1`) become one fleet, meeting each other at 6. The fleet moves at `speed 1` until it reaches target.

## Python
```
pair = [(p, s) for p, s in zip(position, speed)]
pair.sort(reverse=True)

stack = []

for p, s in pair:
    stack.append((target - p) / s)

    if len(stack) >= 2 and stack[-1] <= stack[-2]:
        stack.pop()  # Remove the previous car from the stack as it is fleet with the current car

return len(stack)

# Code comments can be found in car_fleet.py
```

## JavaScript
```
var carFleet = function(target, position, speed) {
    const coordinates = getCoordinates(target, position, speed);

    return searchDescending(coordinates);
};

var getCoordinates = (target, position, speed) => position
    .map((_position, index) => [ _position, speed[index] ])
    .sort(([ aPosition ], [ bPosition ]) => bPosition - aPosition)
    .map(([ _position, _speed ]) => (target - _position) / _speed); 

var searchDescending = (coordinates, previous = 0, fleets = 0) => {
    for (const coordinate of coordinates) {
        const isPreviousLess = previous < coordinate;
        if (!isPreviousLess) continue;

        previous = coordinate;
        fleets++;
    }

    return fleets;
}

// Code comments can be found in carFleet.js
```

## Go
```
func carFleet(target int, position []int, speed []int) int {
	pair := []carInfo{}
	stack := []float32{}
	for i, _ := range position {
		pair = append(pair, carInfo{position[i], speed[i]})
	}

	sort.Slice(pair, func(i, j int) bool {
		return pair[i].pos < pair[j].pos
	})

	for i := len(pair) - 1; i >= 0; i-- {
		stack = append(stack, float32(target-pair[i].pos)/float32(pair[i].spd))
		if len(stack) >= 2 && stack[len(stack)-1] <= stack[len(stack)-2] {
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack)
}

type carInfo struct {
	pos int
	spd int
}

// Code comments can be found in carFleet.go
```
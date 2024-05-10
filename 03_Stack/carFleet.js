// Function to calculate the number of car fleets
var carFleet = function(target, position, speed) {
    // Get the coordinates representing time to reach the target for each car
    const coordinates = getCoordinates(target, position, speed);

    // Search for car fleets in descending order of time to reach the target
    return searchDescending(coordinates);
};

// Function to get coordinates representing time to reach the target for each car
var getCoordinates = (target, position, speed) => position
    .map((_position, index) => [ _position, speed[index] ])        // Create pairs of position and speed
    .sort(([ aPosition ], [ bPosition ]) => bPosition - aPosition) // Sort the pairs in descending order based on position
    .map(([ _position, _speed ]) => (target - _position) / _speed); // Calculate time to reach the target for each car

// Function to search for car fleets in descending order of time to reach the target
var searchDescending = (coordinates, previous = 0, fleets = 0) => {
    // Iterate through the coordinates in descending order
    for (const coordinate of coordinates) {
        // Check if the current coordinate is greater than the previous one
        const isPreviousLess = previous < coordinate;
        if (!isPreviousLess) continue; // Skip to the next iteration if the previous coordinate is greater or equal

        // Update the previous coordinate and increment the fleet count
        previous = coordinate;
        fleets++;
    }

    // Return the total number of car fleets
    return fleets;
}

// implementation
console.log("Leetcode 853: Car Fleet\n");

// Example 1
var target1 = 12;
var position1 = [10, 8, 0, 5, 3];
const speed1 = [2, 4, 1, 1, 3];
console.log(`Example 1: target = ${target1}, position = [${position1}], speed = [${speed1}]`);
console.log("Output:", carFleet(target1, position1, speed1));

// Example 2
var target2 = 10;
const position2 = [3];
const speed2 = [3];
console.log(`Example 1: target = ${target2}, position = [${position2}], speed = [${speed2}]`);
console.log("Output:", carFleet(target2, position2, speed2));

// Example 3
var target3 = 100;
const position3 = [0, 2, 4];
const speed3 = [4, 2, 1];
console.log(`Example 1: target = ${target3}, position = [${position3}], speed = [${speed3}]`);
console.log("Output:", carFleet(target3, position3, speed3));
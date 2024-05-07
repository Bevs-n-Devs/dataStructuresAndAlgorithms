// Function to calculate the number of days until warmer temperatures for each day
var dailyTemperatures = function(temperatures, hottest = 0) {
    // Initialize an array to store the result with default values of 0
    const days = new Array(temperatures.length).fill(0);

    // Iterate through each day in reverse order
    for (let day = (temperatures.length - 1); (0 <= day); day--) {
        // Get the temperature for the current day
        const temperature = temperatures[day];

        // Check if the current temperature is hotter than or equal to the hottest temperature
        const isHotter = hottest <= temperature;
        if (isHotter) {
            hottest = temperature;
            continue; // Move to the next iteration if the current temperature is hotter or equal
        }

        // If the current temperature is not hotter, perform a search for the next warmer day
        search(temperatures, day, temperature, days);
    }

    // Return the array representing the number of days until warmer temperatures for each day
    return days;
}

// Function to search for the next warmer day
const search = (temperatures, day, temperature, days, dayCount = 1) => {
    // Helper function to check if the temperature on the next day is hotter than the current temperature
    const isHotter = () => temperatures[day + dayCount] <= temperature;

    // Continue searching until a warmer day is found
    while (isHotter()) {
        // Increment the day count by the number of days until warmer temperatures from the next day
        dayCount += days[day + dayCount];
    }

    // Update the result array with the number of days until warmer temperatures for the current day
    days[day] = dayCount;
}


// implementation
console.log("Leetcode 739: Daily Temperatures\n");

// Example 1
const example1 = [73, 74, 75, 71, 69, 72, 76, 73];
console.log(`Example 1: temperatures = [${example1}]`);
console.log("Output:", dailyTemperatures(example1));

// Example 2
const example2 = [30, 40, 50, 60];
console.log(`Example 2: temperatures = [${example2}]`);
console.log("Output:", dailyTemperatures(example2));

// Example 3
const example3 = [30, 60, 90];
console.log(`Example 3: temperatures = [${example3}]`);
console.log("Output:", dailyTemperatures(example3));
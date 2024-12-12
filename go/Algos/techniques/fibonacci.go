package main

import "fmt"

/**
 * The fibonacci sequence is a very powerful example of recursion,
 * dynamic programming, and memoization.
 *
 * The fibonacci sequence takes the sum of the current number and the
 * previous number to produce the next value, starting at 0 then 1.
 * e.g. N is the position in the sequence, and V is the value
 *  N =[0] [1] [2] [3] [4] [5] [6] [ 7] [ 8] [ 9][10] ....
 *  V = 0   1   1   2   3   5   8   13   21   34  55  ....
 *
 *  N[3], where V=2, is the sum of N[2]+N[1]
 *  N[4], where V=3, is the sum of N[3]+n[2]
 *
 * Recursion: a function that calls itself, until a given point. It is
 * often compared to a while loop, in that it runs repeatedly but the you
 * MUST create a condition to stop it. It differs from a while loop in the
 * memory domain. When a function is called memory is allocated for everything
 * it needs to execute i.e. variables and datastructures. So this approach
 * can be heavy on memory if you're not careful.
 *
 * Memoization : a way of caching/remembering previous data; serving as a
 * "memo" to the next recursive call of information that may be valuable to
 * the next execution. In this example, it helps to avoid redundant work.
 *
 * Dynamic Programming : breaking a large problem into of smaller subproblems
 * and aggregating (combining) the results. For this exact example the 3rd value
 * in the fibonacci sequence it a the sum of the 1rst and 2nd value, then the 4th
 * value is a sum of the 2nd and 3rd value. This repeats for each next value.
 *
 *
 *
 */

/*
Function that returns the nth number in the Fibonacci sequence

@param n: the number in the fibonacci sequence desired
@param memo: a hashmap to store previously calculated values

@return the nth value in the fibonacci sequence
*/
func fib(n int32, memo map[int32]int32) int32 {

	// capture the base cases
	if n < 2 {
		return n
	}

	// use memoization to avoid duplicating work previously calculated
	val, inMemo := memo[n]
	if inMemo {
		return val
	}

	// storing the values recursively into the memo hashmap
	memo[n] = fib(n-2, memo) + fib(n-1, memo)

	// returning the final value
	return memo[n]
}

func main() {
	var n int32
	for n = 10; n < 35; n += 5 {
		var val int32 = fib(n, make(map[int32]int32))
		fmt.Printf(" The %vth value in the fibonacci sequence is: %v\n", n, val)
	}
}

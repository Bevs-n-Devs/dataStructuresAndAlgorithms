Binary Search 3
# Koko Eating Bananas
## Company: Google
### Level: Medium

Koko loves to eat bananas. There are `n` piles of bananas, the `i`th pile has `piles[i]` bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

*Return the minimum integer `k` such that she can eat all the bananas within `h` hours.*

***Break It Down For Me...***

*Koko has `n` piles of bananas, each with a different number of bananas.*
*She needs to eat all the bananas within `h` hours.*
*She can choose how many bananas to eat per hour (`k`),* 
*but if she starts eating from a pile, she must finish it within the hour.* 
*We need to find the smallest `k` that allows her to finish eating within `h` hours.*

Click [here](https://leetcode.com/problems/koko-eating-bananas/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=U2SozAs9RzA) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Binary Search](https://www.geeksforgeeks.org/what-is-binary-search-algorithm/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: piles = [3, 6, 7, 11], h = 8
Output: 4
```

### Example 2
```
Input: piles = [30, 11, 23, 4, 20], h = 5
Output: 30
```

### Example 3
```
Input: piles = [30, 11, 23, 4, 20], h = 6
Output: 23
```

## Python
```
l, r = 1, max(piles)

res = r

while l <= r:
    k = (l + r) // 2

    totalTime = 0
    for p in piles:
        totalTime += math.ceil(float(p) / k)

    if totalTime <= h:
        res = k
        r = k - 1
    else:
        l = k + 1

return res

# Code comments can be found in koko_eating_bananas.py
```

## JavaScript
```
let left = 1, right = Math.max(...piles);
let result = right;

while (left <= right) {
    const k = Math.floor((left + right) / 2);
    let totalTime = 0;
    
    for (const pile of piles) {
        totalTime += Math.ceil(pile / k);
    }
    
    if (totalTime <= h) {
        result = k;
        right = k - 1;
    } else {
        left = k + 1;
    }
    
}
return result;

// Code comments can be found in kokoEatingBananas.js
```

## Go
```
func canEat(piles []int, timeLimit, speed int) bool {
	timeNeed := 0
	for _, banana := range piles {
		timeNeed += (banana + speed - 1) / speed
		if timeNeed > timeLimit {
			return false
		}
	}

	return true
}

func minEatingSpeed(piles []int, h int) int {
	lo, hi, ans := 1, 1000000000, 1
	for lo <= hi {
		mid := (lo + hi) / 2
		if canEat(piles, h, mid) {
			ans = mid
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}

	return ans
}

// Code comments can be found in kokoEatingBananas.go
```
Heap / Priority Queue 5
# Design Twitter
## Company: X
### Level: Medium

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the `10` most recent tweets in the user's news feed.

Implement the `Twitter` class:

-`Twitter() `Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
- `List<Integer> getNewsFeed(int userId)` Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
- `void follow(int followerId, int followeeId)` The user with ID followerId started following the user with ID followeeId.
- `void unfollow(int followerId, int followeeId)` The user with ID followerId started unfollowing the user with ID followeeId.

***Break It Down For Me...***
*Imagine we want to create a small version of Twitter.Here's what it should do:*

1. *Post Tweets: Users can write tweets.*
2. *Follow Users: Users can follow other users.*
3. *Unfollow Users: Users can stop following other users.*
4. *See News Feed: Users can see the 10 most recent tweets from the people they follow and their own tweets.*

Click [here](https://leetcode.com/problems/design-twitter/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=pNichitDD2E) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.

### Example 1
```
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

# Explanation
# Twitter twitter = new Twitter();
# twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
# twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
# twitter.follow(1, 2);    // User 1 follows user 2.
# twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
# twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
# twitter.unfollow(1, 2);  // User 1 unfollows user 2.
# twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
```

## Python
```
from collections import defaultdict
import heapq

class Twitter:
    def __init__(self):
        self.count = 0  # Counter for tweet order
        self.tweetMap = defaultdict(list)  # Maps userId to a list of [count, tweetIds]
        self.followMap = defaultdict(set)  # Maps userId to a set of followeeIds

    def postTweet(self, userId: int, tweetId: int) -> None:
        # Append the tweet to the user's tweet list with a timestamp
        self.tweetMap[userId].append([self.count, tweetId])
        self.count -= 1  # Decrease count to ensure the most recent tweet has the smallest number

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []  # List to store the result
        minHeap = []  # Min heap to keep track of the most recent tweets

        self.followMap[userId].add(userId)  # User should also see their own tweets
        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                # Get the latest tweet of the followee
                index = len(self.tweetMap[followeeId]) - 1
                count, tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])

        while minHeap and len(res) < 10:
            count, tweetId, followeeId, index = heapq.heappop(minHeap)
            res.append(tweetId)  # Add the tweet to the result list
            if index >= 0:
                # Push the next tweet of the same followee into the heap
                count, tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        # Add followeeId to the followerId's follow set
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        # Remove followeeId from the followerId's follow set if it exists
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)
```

## JavaScript
```
class Twitter {
    constructor() {
        this.tweets = [];  // Array to store tweets
        this.following = new Map();  // Map to store user following relationships
    }
    
    postTweet(userId, tweetId) {
        // Add the tweet to the tweets array
        this.tweets.push({ authorId: userId, id: tweetId });
    }
    
    getNewsFeed(userId) {
        let newsIDs = [];  // Array to store the result
        
        // Iterate from the latest tweet to the earliest
        for (let i = this.tweets.length - 1; i >= 0 && newsIDs.length < 10; i--) {
            const tweet = this.tweets[i];

            const isAuthor = tweet.authorId === userId;
            const isFollowing = this.following.has(userId) && this.following.get(userId).has(tweet.authorId);
            if (isAuthor || isFollowing) {
                newsIDs.push(tweet.id);
            }
        }

        return newsIDs;
    }
    
    follow(followerId, followeeId) {
        // If the follower is not following anyone, initialize their follow set
        if (!this.following.has(followerId)) {
            this.following.set(followerId, new Set());
        }
        // Add the followee to the follower's follow set
        this.following.get(followerId).add(followeeId);
    }

    unfollow(followerId, followeeId) {
        // If the follower is following the followee, remove them from the follow set
        if (this.following.has(followerId)) {
            this.following.get(followerId).delete(followeeId);
        }
    }
}
```

## Go
```
import (
	"container/heap"
)

// Tweet structure to store tweet information
type Tweet struct {
	count      int  // Timestamp of the tweet
	tweetId    int  // ID of the tweet
	followeeId int  // ID of the user who posted the tweet
	index      int  // Index of the tweet in the user's tweet list
}

// TweetHeap is a priority queue for managing tweets
type TweetHeap []*Tweet

// Len returns the number of elements in the heap
func (h TweetHeap) Len() int { return len(h) }

// Less compares two elements to determine their order
func (h TweetHeap) Less(i, j int) bool { return h[i].count < h[j].count }

// Swap swaps two elements in the heap
func (h TweetHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

// Push adds an element to the heap
func (h *TweetHeap) Push(x interface{}) { *h = append(*h, x.(*Tweet)) }

// Pop removes and returns the smallest element from the heap
func (h *TweetHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Twitter structure to manage tweets and follow relationships
type Twitter struct {
	count     int                     // Counter for tweet order
	tweetMap  map[int][]*Tweet        // Maps userId to list of tweets
	followMap map[int]map[int]bool    // Maps userId to set of followeeIds
}

// Constructor initializes a new Twitter object
func Constructor() Twitter {
	return Twitter{
		tweetMap:  make(map[int][]*Tweet),
		followMap: make(map[int]map[int]bool),
	}
}

// PostTweet adds a new tweet for the given user
func (this *Twitter) PostTweet(userId int, tweetId int) {
	if _, ok := this.tweetMap[userId]; !ok {
		this.tweetMap[userId] = make([]*Tweet, 0)
	}
	this.tweetMap[userId] = append(this.tweetMap[userId], &Tweet{
		count: this.count,
		tweetId: tweetId,
	})
	this.count--  // Decrease count to ensure the most recent tweet has the smallest number
}

// GetNewsFeed retrieves the 10 most recent tweet IDs in the user's news feed
func (this *Twitter) GetNewsFeed(userId int) []int {
	res := make([]int, 0)  // List to store the result
	minHeap := TweetHeap{} // Min heap to keep track of the most recent tweets
	
	if _, ok := this.followMap[userId]; !ok {
		this.followMap[userId] = make(map[int]bool)
	}
	this.followMap[userId][userId] = true // User should also see their own tweets
	
	for followeeId := range this.followMap[userId] {
		if tweets, ok := this.tweetMap[followeeId]; ok {
			// Get the latest tweet of the followee
			index := len(tweets) - 1
			tweet := tweets[index]
			heap.Push(&minHeap, &Tweet{
				count: tweet.count,
				tweetId: tweet.tweetId,
				followeeId: followeeId,
				index: index - 1,
			})
		}
	}
	
	for len(minHeap) > 0 && len(res) < 10 {
		tweet := heap.Pop(&minHeap).(*Tweet)
		res = append(res, tweet.tweetId)  // Add the tweet to the result list
		if tweet.index >= 0 {
			// Push the next tweet of the same followee into the heap
			nextTweet := this.tweetMap[tweet.followeeId][tweet.index]
			heap.Push(&minHeap, &Tweet{
				count: nextTweet.count,
				tweetId: nextTweet.tweetId,
				followeeId: tweet.followeeId,
				index: tweet.index - 1,
			})
		}
	}
	
	return res
}

// Follow makes followerId follow followeeId
func (this *Twitter) Follow(followerId int, followeeId int) {
	if _, ok := this.followMap[followerId]; !ok {
		this.followMap[followerId] = make(map[int]bool)
	}
	this.followMap[followerId][followeeId] = true
}

// Unfollow makes followerId unfollow followeeId
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	if _, ok := this.followMap[followerId]; ok {
		delete(this.followMap[followerId], followeeId)
	}
}
```
Stack 2
# Min Stack
## Company: Amazon
### Level: Medium

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack`.
- `MinStack()` initialises the stack obkject.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

***Break It Down For Me...***
*This challenge is about implementing a special kind of stack called `MinStack` that has the following functionalities:*
- `MinStack()` *creates the stack object.*
- `push(int val)` *adds an element `val` to the top of the stack.*
- `pop()` *removes an element from the top odf the stack.*
- `top()` *returns the element currently at the top of ythe stack.*
- `getMin()` *gets the minimum element present in the satck.*
*The tricky part of this challenge is that we have to implement each of these functions that they have the same time complexity of `O(1)`.*
*This means that the execution time of each function doesn't depend on the size of the stack.*

Click [here](https://leetcode.com/problems/min-stack/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=qkLl7nAwDPo) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) and [HashMap](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used) in Pythopn, JavaScript and Go.

### Example 1
```
Input: 
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
```

## Python
```
class MinStack:
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        val = min(val, self.minStack[-1] if self.minStack else val)
        self.minStack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]
```

## JavaScript
```
class MinStack {
    constructor () {
        this.stack = [];
        this.minStack = [];
    }

    push (val, { minStack } = this) {
        this.stack.push(val);             

        const isMinEmpty = !minStack.length;
        const hasNewMin = val <= this.top(minStack);
        const canAddMin = isMinEmpty || hasNewMin;
        if (canAddMin) minStack.push(val);
    }

    pop ({ stack, minStack } = this) {
        const top = stack.pop();      

        const canPopMin = top === this.getMin();
        if (canPopMin) minStack.pop();
    }

    top (stack = this.stack) {
        return stack.length
            ? stack[stack.length - 1]
            : null;
    }

    getMin (minStack = this.minStack) {
        return this.top(minStack); 
    }
}
```

## Go
```
type MinStack struct {
    top *StackNode
    min int
}

type StackNode struct {
	data int
	next *StackNode
    lastmin int
}

var mystack MinStack = MinStack{top: nil}
var newtop *StackNode

func Constructor() MinStack {
    return mystack
}

func (this *MinStack) Push(val int)  {
    if this.top == nil {
        newtop = &StackNode{data: val, next: this.top}
        this.min = val
    } else {
        newtop = &StackNode{data: val, next: this.top, lastmin: this.min}
    }
    this.top = newtop
    if this.top.data < this.min {
        this.min = this.top.data
    }
}


func (this *MinStack) Pop()  {
    if this.top.next == nil {
        this.top = nil
        return
    } 
    this.min = this.top.lastmin
    *this.top = *this.top.next
}


func (this *MinStack) Top() int {
    return this.top.data
}


func (this *MinStack) GetMin() int {
    return this.min; 
}
```
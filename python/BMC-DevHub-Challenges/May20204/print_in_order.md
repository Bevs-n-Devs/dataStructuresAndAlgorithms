03/05/2024
# Print In Order

Suppose we have a class:
```
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
```
The same instance of `Foo` will be passed to three different threads.
Thread A will call `firsr()`, thread B will call `second()`, and thread C will call `third()`.
Design a mechanism and modify the program to ensure that `second()` is executed after `first()`, and `third()` is executed after `second()`.

**Note:**

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering.
The input format you see is mainly to ensure our tests' comprehensiveness.

***Break It Down For Me...***
**

### Example 1
```
Input: nums = [1, 2, 3]
Output: "firstsecondthird"
```
**Explanation:** There are three threads being fired asynchronsouly.
The input `[1, 2, 3]` means thread A calls `first()`, thread B calls `second()`, asandnd thread C calls `third()`.
`"firstsecondthird"` is the correct ouput.

### Example 2
```
Input: nums = [1, 3, 2]
Output: "firstsecondthird"
```
**Explanation:** The input `[1, 3, 2]` means thread A calls `first()`, thread B calls `third()`, and thread C calls `second()`.
`"firstsecondthird` is the correct output.


## Python
```
import threading

class Foo:
    def __init__(self):
        self.locks = (threading.Lock(), threading.Lock())
        self.locks[0].acquire()
        self.locks[1].acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.locks[0].release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.locks[0]:
            printSecond()
            self.locks[1].release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.locks[1]:
            printThird()

```
# aoa-project-2

In your project report, you should include brief answers to 9 questions. Note that you must use dynamic programming to solve this problem; other solutions will not receive substantial credit.

1. How you can break down a problem instance of the omnidroid construction problem into one or more smaller instances? You may use sprocket[t] to represent the number of sprockets used for part t, and you may use req[t] and use[t] to represent the collection of all parts required to build part t and all parts that part t is used to build, respectively. Your answer should include how the solution to the original problem is constructed from the subproblems.

2. What is the base cases of the omnidroid construction problem?

3. How you can break down a problem instance of robotomaton construction problem into one or more smaller instances? You should assume that you are given sprocket and previous arrays that indicate the number of sprockets required for each stage of construction and the number of previous stages used to construct a particular part. Your answer should include how the solution to the subproblems are combined together to solve the original problem.

4. What are the base cases of the robotomaton construction problem?

5. What data structure would you use to recognize repeated problems for each problem (two answers)? You should describe both the abstract data structures, as well as their implementations.

6. Give pseudocode for a memoized dynamic programming algorithm to calculate the sprockets needed to construct an omnidroid.

7. What is the worst-case time complexity of your memoized algorithm for the omnidroid construction problem?

8. Give pseudocode for a memoized dynamic programming algorithm to calculate the sprockets needed to construct a robotomaton.

9. Give pseudocode for an iterative algorithm to calculate the sprockets needed to construct a robotomaton. This algorithm does not need to have a reduced space complexity, but it should have asymptotically optimal time complexity.
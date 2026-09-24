## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
I used a brute-force approach with two nested loops. For every element `nums[i]`, I check every later element `nums[j]` and see if the two add up to the target. When a pair is found, I store the two indices in a `malloc`'d array of size 2 and return it.

### Complexity
- Time: O(n^2)
- Space: O(1) extra (the returned array is always size 2)

### Notes
- Starting `j` at `i + 1` stops the same element from being used twice, and the `{3, 3}` test confirms that two equal values at different indices still work.
- A cleaner approach for next time is a hash map that stores each value's index and checks whether `target - nums[i]` was already seen. That brings the time down to O(n) at the cost of O(n) space.

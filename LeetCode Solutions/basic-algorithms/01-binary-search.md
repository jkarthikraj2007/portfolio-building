## Problem: Binary Search (Easy)
**Link:** https://leetcode.com/problems/binary-search/

### Approach
The array is sorted, so I keep a search window between `low` and `high`. Each step I look at the middle element. If it equals the target I return its index. If it is smaller than the target, I discard the left half (`low = mid + 1`). If it is larger, I discard the right half (`high = mid - 1`). If the window becomes empty, the target isn't present and I return -1.

### Complexity
- Time: O(log n)
- Space: O(1)

### Notes
- I compute `mid = low + (high - low) / 2` instead of `(low + high) / 2` because the second form can overflow for very large indices.
- The loop condition must be `low <= high`, not `<`. With `<`, a single-element window would be skipped and the answer missed.
- Edge cases tested: target at the first position, target at the last position, a single element, and an empty array.

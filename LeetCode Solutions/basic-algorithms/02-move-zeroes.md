## Problem: Move Zeroes (Easy)
**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
I used a "write position" pointer. I scan the array once, and every non-zero value is copied to `nums[pos]` before `pos` moves forward. This keeps the non-zero values in their original order. After the scan, everything from `pos` to the end is filled with zeroes.

### Complexity
- Time: O(n)
- Space: O(1) (done in place, no extra array)

### Notes
- The problem requires modifying the array in place, so I did not build a second array.
- Edge cases tested: no zeroes, all zeroes, and a single zero.
- A variant swaps `nums[i]` with `nums[pos]` during the scan. That avoids the second loop but does more writes.

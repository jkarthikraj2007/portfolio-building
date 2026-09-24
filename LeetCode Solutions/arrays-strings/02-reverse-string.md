## Problem: Reverse String (Easy)
**Link:** https://leetcode.com/problems/reverse-string/

### Approach
I used the two-pointer technique. One pointer starts at the first character and the other at the last. I swap the characters they point to, move both pointers towards the middle, and stop when they meet. This reverses the string in place without needing a second array.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
- Edge cases: an empty string (`sSize = 0`) makes `right = -1`, so the loop never runs. A single character also needs no swap.
- The loop runs only n/2 times because each swap fixes two positions.

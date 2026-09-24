## Problem: Reverse a Linked List (Easy)
**Link:** https://leetcode.com/problems/reverse-linked-list/

### Approach
I walk the list once with three pointers: `prev`, `curr`, and `next`. At each node I save `curr->next`, point `curr->next` back to `prev`, and then move `prev` and `curr` one step forward. When `curr` reaches NULL, `prev` is the last node of the original list, which is the new head.

### Complexity
- Time: O(n)
- Space: O(1) (only pointers, no new nodes)

### Notes
- Saving `next` before changing `curr->next` is essential. Otherwise the rest of the list is lost.
- An empty list works naturally, because the loop is skipped and `prev` stays NULL.
- A recursive version also works, but it uses O(n) stack space.

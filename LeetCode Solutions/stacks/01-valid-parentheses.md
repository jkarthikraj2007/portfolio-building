## Problem: Valid Parentheses (Easy)
**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
I used a stack, implemented as a `char` array plus a `top` counter. Each opening bracket is pushed. Each closing bracket must match the most recent unmatched opener, so I pop the stack and compare. If the stack is empty or the pair doesn't match, the string is invalid. At the end the string is valid only if the stack is empty, meaning every opener was closed.

### Complexity
- Time: O(n)
- Space: O(n) for the stack in the worst case (a string of only opening brackets)

### Notes
- Two edge cases to remember: a closing bracket arriving when the stack is empty (`"]"`), and leftover openers at the end (`"("`).
- I free the `malloc`'d stack on every return path to avoid a memory leak.
- The stack works because brackets close in last-in, first-out order.

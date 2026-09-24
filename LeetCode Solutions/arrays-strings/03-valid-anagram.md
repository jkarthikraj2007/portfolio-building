## Problem: Valid Anagram (Easy)
**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
I used a frequency-count array of size 26, one slot per lowercase letter. I add 1 for each letter of `s` and subtract 1 for each letter of `t`. If the two strings are anagrams, every slot ends at 0. I check the lengths first, because strings of different lengths can never be anagrams.

### Complexity
- Time: O(n)
- Space: O(1) (the count array is always 26 ints)

### Notes
- The `s[i] - 'a'` trick converts a letter to an index from 0 to 25. It only works for lowercase English letters, which is what the problem guarantees.
- Two empty strings count as anagrams. Checking the length first also protects the loop from reading past the end of `t`.
- Sorting both strings and comparing them also works, but it is O(n log n).

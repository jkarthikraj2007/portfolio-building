## Problem: Best Time to Buy and Sell Stock (Easy)
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
I made one pass through the prices while tracking two values: the lowest price seen so far (the best day to buy) and the best profit so far. On each day, if the price is a new minimum I update it. Otherwise I check whether selling today beats the best profit so far. Because I only ever compare against earlier days, the "buy before sell" rule is respected automatically.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
- If prices only fall, the profit never rises above 0, so the answer is 0. That is the correct result, because we simply don't trade.
- The brute-force version (check every buy/sell pair) is O(n^2). The single pass works because the best buy day for any sell day is just the minimum before it.

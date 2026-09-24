/*
 * 04-best-time-to-buy-and-sell-stock.c
 * LeetCode: Best Time to Buy and Sell Stock (Easy)
 * Paste only the maxProfit() function into LeetCode.
 */
#include <stdio.h>
#include <limits.h>

/* ---- Solution ---- */
int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;
    int best = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];              /* cheapest day seen so far */
        } else if (prices[i] - minPrice > best) {
            best = prices[i] - minPrice;       /* better profit if sold today */
        }
    }
    return best;
}

/* ---- Local tests ---- */
static void run_test(const char* name, int* prices, int n, int expected) {
    printf("%s: %s\n", name, maxProfit(prices, n) == expected ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {7, 1, 5, 3, 6, 4};
    int b[] = {7, 6, 4, 3, 1};
    int c[] = {5};
    int d[] = {2, 2, 2};

    run_test("Test 1 (typical)",        a, 6, 5);  /* buy 1, sell 6 */
    run_test("Test 2 (always falling)", b, 5, 0);
    run_test("Test 3 (single element)", c, 1, 0);
    run_test("Test 4 (all equal)",      d, 3, 0);
    return 0;
}

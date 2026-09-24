/*
 * 01-binary-search.c
 * LeetCode: Binary Search (Easy)
 * Paste only the search() function into LeetCode.
 */
#include <stdio.h>

/* ---- Solution ---- */
int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   /* avoids integer overflow */

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/* ---- Local tests ---- */
static void run_test(const char* name, int* nums, int n, int target, int expected) {
    printf("%s: %s\n", name, search(nums, n, target) == expected ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {-1, 0, 3, 5, 9, 12};
    int b[] = {5};

    run_test("Test 1 (found)",          a, 6, 9,  4);
    run_test("Test 2 (not found)",      a, 6, 2,  -1);
    run_test("Test 3 (first element)",  a, 6, -1, 0);
    run_test("Test 4 (last element)",   a, 6, 12, 5);
    run_test("Test 5 (single element)", b, 1, 5,  0);
    run_test("Test 6 (empty array)",    a, 0, 5,  -1);
    return 0;
}

/*
 * 02-move-zeroes.c
 * LeetCode: Move Zeroes (Easy)
 * Paste only the moveZeroes() function into LeetCode.
 */
#include <stdio.h>
#include <string.h>

/* ---- Solution ---- */
void moveZeroes(int* nums, int numsSize) {
    int pos = 0;   /* next position for a non-zero value */

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }
    while (pos < numsSize) {   /* fill the rest with zeroes */
        nums[pos] = 0;
        pos++;
    }
}

/* ---- Local tests ---- */
static void run_test(const char* name, int* nums, int n, int* expected) {
    moveZeroes(nums, n);
    printf("%s: %s\n", name, memcmp(nums, expected, n * sizeof(int)) == 0 ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {0, 1, 0, 3, 12}, ea[] = {1, 3, 12, 0, 0};
    int b[] = {0},              eb[] = {0};
    int c[] = {1, 2, 3},        ec[] = {1, 2, 3};
    int d[] = {0, 0, 0},        ed[] = {0, 0, 0};

    run_test("Test 1 (typical)",     a, 5, ea);
    run_test("Test 2 (single zero)", b, 1, eb);
    run_test("Test 3 (no zeroes)",   c, 3, ec);
    run_test("Test 4 (all zeroes)",  d, 3, ed);
    return 0;
}

/*
 * 01-two-sum.c
 * LeetCode: Two Sum (Easy)
 * Paste only the twoSum() function into LeetCode; main() is for local testing.
 */
#include <stdio.h>
#include <stdlib.h>

/* ---- Solution ---- */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

/* ---- Local tests ---- */
static void run_test(const char* name, int* nums, int n, int target, int e0, int e1) {
    int returnSize = 0;
    int* res = twoSum(nums, n, target, &returnSize);
    int ok = (returnSize == 2 && res[0] == e0 && res[1] == e1);
    printf("%s: %s\n", name, ok ? "PASS" : "FAIL");
    free(res);
}

int main(void) {
    int a[] = {2, 7, 11, 15};
    int b[] = {3, 3};
    int c[] = {3, 2, 4};

    run_test("Test 1 (typical)",          a, 4, 9, 0, 1);  /* 2 + 7 = 9 */
    run_test("Test 2 (duplicates)",       b, 2, 6, 0, 1);  /* 3 + 3 = 6 */
    run_test("Test 3 (answer not first)", c, 3, 6, 1, 2);  /* 2 + 4 = 6 */
    return 0;
}

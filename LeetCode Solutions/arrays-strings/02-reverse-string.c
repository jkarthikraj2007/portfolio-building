/*
 * 02-reverse-string.c
 * LeetCode: Reverse String (Easy)
 * Paste only the reverseString() function into LeetCode.
 */
#include <stdio.h>
#include <string.h>

/* ---- Solution ---- */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

/* ---- Local tests ---- */
static void run_test(const char* name, const char* input, const char* expected) {
    char buf[100];
    strcpy(buf, input);
    reverseString(buf, (int)strlen(buf));
    printf("%s: %s\n", name, strcmp(buf, expected) == 0 ? "PASS" : "FAIL");
}

int main(void) {
    run_test("Test 1 (typical)",      "hello", "olleh");
    run_test("Test 2 (single char)",  "a",     "a");
    run_test("Test 3 (empty string)", "",      "");
    run_test("Test 4 (even length)",  "abcd",  "dcba");
    return 0;
}

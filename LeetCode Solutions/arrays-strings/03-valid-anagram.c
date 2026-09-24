/*
 * 03-valid-anagram.c
 * LeetCode: Valid Anagram (Easy)
 * Paste only the isAnagram() function into LeetCode.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* ---- Solution ---- */
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

/* ---- Local tests ---- */
static void run_test(const char* name, char* s, char* t, bool expected) {
    printf("%s: %s\n", name, isAnagram(s, t) == expected ? "PASS" : "FAIL");
}

int main(void) {
    char s1[] = "anagram", t1[] = "nagaram";
    char s2[] = "rat",     t2[] = "car";
    char s3[] = "",        t3[] = "";
    char s4[] = "ab",      t4[] = "abc";

    run_test("Test 1 (typical, true)",    s1, t1, true);
    run_test("Test 2 (typical, false)",   s2, t2, false);
    run_test("Test 3 (both empty)",       s3, t3, true);
    run_test("Test 4 (different length)", s4, t4, false);
    return 0;
}

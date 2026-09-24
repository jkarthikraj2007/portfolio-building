/*
 * 01-valid-parentheses.c
 * LeetCode: Valid Parentheses (Easy)
 * Paste only the isValid() function into LeetCode.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ---- Solution ---- */
bool isValid(char* s) {
    int len = (int)strlen(s);
    char* stack = (char*)malloc(len + 1);
    int top = 0;   /* number of items currently in the stack */

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;                    /* push opening bracket */
        } else {
            if (top == 0) {                      /* closing bracket, nothing to match */
                free(stack);
                return false;
            }
            char open = stack[--top];            /* pop */
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == 0);   /* valid only if every opener was closed */
    free(stack);
    return valid;
}

/* ---- Local tests ---- */
static void run_test(const char* name, char* s, bool expected) {
    printf("%s: %s\n", name, isValid(s) == expected ? "PASS" : "FAIL");
}

int main(void) {
    char a[] = "()";
    char b[] = "()[]{}";
    char c[] = "(]";
    char d[] = "([{}])";
    char e[] = "(";
    char f[] = "]";

    run_test("Test 1 (simple pair)",           a, true);
    run_test("Test 2 (three pair types)",      b, true);
    run_test("Test 3 (mismatched)",            c, false);
    run_test("Test 4 (nested)",                d, true);
    run_test("Test 5 (unclosed opener)",       e, false);
    run_test("Test 6 (closer with no opener)", f, false);
    return 0;
}

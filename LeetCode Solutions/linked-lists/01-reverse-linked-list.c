/*
 * 01-reverse-linked-list.c
 * LeetCode: Reverse Linked List (Easy)
 * LeetCode already defines struct ListNode for you. Paste only reverseList().
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/* ---- Solution ---- */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;   /* remember the rest of the list */
        curr->next = prev;                    /* point this node backwards */
        prev = curr;                          /* move prev forward */
        curr = next;                          /* move curr forward */
    }
    return prev;   /* prev is the new head */
}

/* ---- Local test helpers ---- */
static struct ListNode* build_list(int* arr, int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (head == NULL) head = node; else tail->next = node;
        tail = node;
    }
    return head;
}

static int list_matches(struct ListNode* head, int* expected, int n) {
    for (int i = 0; i < n; i++) {
        if (head == NULL || head->val != expected[i]) return 0;
        head = head->next;
    }
    return head == NULL;   /* list must end exactly where expected ends */
}

static void free_list(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

static void run_test(const char* name, int* input, int n, int* expected) {
    struct ListNode* head = build_list(input, n);
    head = reverseList(head);
    printf("%s: %s\n", name, list_matches(head, expected, n) ? "PASS" : "FAIL");
    free_list(head);
}

/* ---- Local tests ---- */
int main(void) {
    int a[] = {1, 2, 3, 4, 5}, ea[] = {5, 4, 3, 2, 1};
    int b[] = {1, 2},          eb[] = {2, 1};
    int c[] = {7},             ec[] = {7};

    run_test("Test 1 (typical)",     a, 5, ea);
    run_test("Test 2 (two nodes)",   b, 2, eb);
    run_test("Test 3 (single node)", c, 1, ec);
    run_test("Test 4 (empty list)",  NULL, 0, NULL);
    return 0;
}

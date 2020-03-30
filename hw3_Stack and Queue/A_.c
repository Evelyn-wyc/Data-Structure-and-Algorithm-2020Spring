#include <stdio.h>
#include <limits.h>

int myStack[10000];
int stack_top;

void init() {
    /* 填空 */
}

void stack_push(int k) {
    /* 填空 */
}

int stack_pop() {
    /* 填空 */
}

void works() {
    int n, next_number, k, i;
    int is_valid = 1;
    init();
    scanf("%d", &n);
    // next_number表示下一个进栈的数
    next_number = 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        while (k >= next_number) {
            /* 填空 */
        }
        if (/* 填空 */) {
            is_valid = 0;
        }
    }
    if (is_valid)
        printf("yes\n");
    else
        printf("no\n");
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        works();
    }
}

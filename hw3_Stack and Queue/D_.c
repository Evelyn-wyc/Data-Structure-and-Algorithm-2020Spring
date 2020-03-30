#include <stdio.h>
#include <limits.h>

int myStack[10000];
int stack_top;
int myQueue[10000];
int queue_head, queue_tail;

int error_flag;

void init() {
    stack_top = -1;
    queue_head = 0; queue_tail = -1;
    error_flag = 0;
}

void stack_push(int k) {
    myStack[++stack_top] = k;
}

void queue_push(int k) {
    /* МоїХ */
}

int stack_pop() {
    if (stack_top < 0) {
        error_flag = 1;
        return INT_MIN;
    } else
        return myStack[stack_top--];
}

int queue_pop() {
    /* МоїХ */
}

void works() {
    int n, k, i;
    char read_string[10];

    init();
    scanf("%d", &n);
    while (n--) {
        scanf(" %s", read_string);
        if (read_string[1] == 'u') {
            scanf(" %d", &k);
            stack_push(k);
            queue_push(k);
        } else {
            /* МоїХ */
        }
    }

    if (error_flag) {
        printf("error\nerror\n");
    } else {
        /* МоїХ */
    }
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        works();
    }
}

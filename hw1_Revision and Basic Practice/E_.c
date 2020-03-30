#include <stdio.h>

int n;

int array[1050];

// 函数，判断k是否是质数。若是返回1，否则返回0。
// 注意优化函数，若从2到k-1循环，可能超时
int is_prime(int k) {
    /* 填空 */
}

int main() {
    int i;
    scanf("%d", &n);
    for (i = 2; ; i++) {
        if (is_prime(i)) {
            n--;
        }
        if (n == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
}

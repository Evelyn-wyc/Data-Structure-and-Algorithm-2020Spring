#include <stdio.h>

int n;

int array[1050];

int main() {
    int i, best = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    /* МоїХ */

    printf("%d\n", best);
}

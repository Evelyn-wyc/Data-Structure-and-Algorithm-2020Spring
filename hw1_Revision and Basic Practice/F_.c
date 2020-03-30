#include <stdio.h>

struct People {
    int month, day;
    char id[30];
};

struct People people[200];
int n;


int count[13][32];

int main() {
    int i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        /* МоїХ*/
        count[people[i].month][people[i].day]++;
    }


    for (i = 1; i <= 12; i++)
        for (j = 1; j <= 31; j++)

            if (/* МоїХ */) {
                printf("%d %d", i, j);
                for (k = 0; k < n; k++)
                    /* МоїХ */
                printf("\n");
            }
}

#include <stdio.h>

// ���������ĸ�����������ֵ
const int delta_x[] = {0, 0, 1, -1};
const int delta_y[] = {1,-1, 0, 0};

int n;

int array[105][105];

int main() {
    int i, j, k, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &array[i][j]);

    for (i = 1; i < n - 1; i++)
        for (j = 1; j < n - 1; j++) {
            int cnt = 0;
            // ö�ٷ���
            for (k = 0; k < 4; k++) {
                int x = i + delta_x[k], y = j + delta_y[k];
                /* ��� */
            }

            if (/* ��� */)
                /* ��� */
        }
    printf("%d\n", ans);
}

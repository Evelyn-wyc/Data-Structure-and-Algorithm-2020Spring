#include <stdio.h>

int n;

int array[1050];

// �������ж�k�Ƿ������������Ƿ���1�����򷵻�0��
// ע���Ż�����������2��k-1ѭ�������ܳ�ʱ
int is_prime(int k) {
    /* ��� */
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

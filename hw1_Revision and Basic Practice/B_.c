#include <stdio.h>

char c;
int n;

int main() {
    int i;
    int is_first_letter = 1; // ��ʾ��ǰ�Ƿ������ַ�

    // ��������ַ�
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <='Z') {
            // �����ǰ������ĸ������Сд��ĸ
            // ��ת��Ϊ��д��ĸ

            if (is_first_letter && c >= 'a' && c <= 'z')
                //fill up the line here************

            is_first_letter = 0;
        } else
            is_first_letter = 1;
        putchar(c);
    }
}

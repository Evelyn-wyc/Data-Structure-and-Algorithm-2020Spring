#include <stdio.h>

char c;
int n;

int main() {
    int i;
    int is_first_letter = 1; // 表示当前是否是首字符

    // 逐个读入字符
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <='Z') {
            // 如果当前是首字母，且是小写字母
            // 则转换为大写字母

            if (is_first_letter && c >= 'a' && c <= 'z')
                //fill up the line here************

            is_first_letter = 0;
        } else
            is_first_letter = 1;
        putchar(c);
    }
}

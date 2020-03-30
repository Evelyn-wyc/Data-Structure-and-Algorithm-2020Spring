#include <stdio.h>

struct Rat {
    int weight;
    char hat_color[15];
};

struct Rat rat[100];
int n;

int main() {
    int i, j;
    struct Rat tmp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        // 使用scanf("%s")可读入字符串
        scanf("%d %s", &rat[i].weight, &rat[i].hat_color);
    }


    for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			/*
			//fill up the lines here
			*/
		}

    for (i = 0; i < n; i++)
        printf("%s\n", rat[i].hat_color);
}

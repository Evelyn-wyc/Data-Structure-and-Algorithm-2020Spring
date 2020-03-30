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

	// 排序，这里使用选择排序
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (rat[j].weight > rat[i].weight) {
				// 交换rat[i]与rat[j]
				tmp = rat[i];
				rat[i] = rat[j];
				rat[j] = tmp;
			}

	for (i = 0; i < n; i++)
		printf("%s\n", rat[i].hat_color);
}

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
		// ʹ��scanf("%s")�ɶ����ַ���
		scanf("%d %s", &rat[i].weight, &rat[i].hat_color);
	}

	// ��������ʹ��ѡ������
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (rat[j].weight > rat[i].weight) {
				// ����rat[i]��rat[j]
				tmp = rat[i];
				rat[i] = rat[j];
				rat[j] = tmp;
			}

	for (i = 0; i < n; i++)
		printf("%s\n", rat[i].hat_color);
}

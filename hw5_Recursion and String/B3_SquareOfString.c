#include<string.h>
#include<stdio.h>

int nex[1000001] = {};
void getnext(char* p)
{
	nex[0] = -1;
	int i = 0, j = -1;
	int len = strlen(p);
	while (i < len)
	{
		if (j == -1 || p[i] == p[j])
		{
			i++;
			j++;
			nex[i] = j;
		}
		else
			j = nex[j];
	}
	return;
}

char str[1000001];
int main()
{
	while (scanf("%s", str) && str[0] != '.')
	{
		getnext(str);
		int len = strlen(str);
		if (len % (len - nex[len]) == 0)
		{
			printf("%d\n", len / (len - nex[len]));
		}
		else
			printf("1\n");
	}
	return 0;
}

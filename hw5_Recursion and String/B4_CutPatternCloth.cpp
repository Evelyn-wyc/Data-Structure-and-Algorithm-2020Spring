#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[1005];
char p[1005];
int num = 0;
int nex[1005] = {};
void getnext(int len)
{
	nex[0] = -1;
	int i = 0, j = -1;
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

void kmp(int len1, int len2)
{
	int i = 0, j = 0;
	while (i < len1)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = nex[j];
		if (j == len2)
		{
			j = 0;
			num++;
		}
	}
	return;
}

int main()
{
	while (scanf("%s", s) != EOF)
	{
	    int len1 = strlen(s);
		if (s[0] == '#' && len1 == 1)
			break;
		scanf("%s", p);
		int len2 = strlen(p);
		getnext(len2);
		kmp(len1, len2);
		cout << num << endl;
		num = 0;
	}
	return 0;
}

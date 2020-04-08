#include<iostream>
#include<cstring>

using namespace std;

void getnext(int next[], char *p)
{
	next[0] = -1;
	int i = 0, j = -1;
	int len = strlen(p);
	while (i < len)
	{
		if (j == -1 || p[i] == p[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
	return;
}

int kmp(char* s, char* p, int next[])
{
	int i = 0, j = 0;
	int len1 = strlen(s);
	int len2 = strlen(p);
	while (i < len1 && j < len2)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == len2)
		return i - j;
	else
		return -1;
}

char s[20001], p[20001];
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> s >> p;
		int next[20001];
		getnext(next, p);
		cout << kmp(s, p, next) << endl;
	}
	return 0;
}
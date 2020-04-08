#include<iostream>
#include<string>

using namespace std;

inline int min(int a, int b)
{
	return (a > b ? b : a);
}

void getnext(int next[], string p)
{
	next[0] = -1;
	int i = 0, j = -1;
	int len = p.length();
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

int main()
{
	string s1;
	string s2;
	while (getline(cin, s1), getline(cin, s2))
	{
		string nstr = s1 + s2;
		int len = nstr.length();
		int len1 = s1.length();
		int len2 = s2.length();
		int next[100001] = {};
		getnext(next, nstr);
		next[len] = min(next[len], min(len1, len2));
		for (int i = 0; i < next[len]; i++)
			cout << nstr[i];
		if (next[len] != 0)
			cout << ' ';
		cout << next[len] << endl;
	}
	return 0;
}
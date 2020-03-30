#include <iostream>
#include <stack>
#include <string>

using namespace std;

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

int CurMax[100001] = {};
int main()
{
	int n;
	cin >> n;
	stack<int> s;
	string p;
	int num;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		if (p == "push")
		{
			cin >> num;
			s.push(num);
			len++;
			CurMax[len] = max(CurMax[len - 1], num);
		}
		else if (p == "pop")
		{
			s.pop();
			len--;
		}
		else
		{
			cout << CurMax[len] << endl;
		}
	}
	return 0;
}
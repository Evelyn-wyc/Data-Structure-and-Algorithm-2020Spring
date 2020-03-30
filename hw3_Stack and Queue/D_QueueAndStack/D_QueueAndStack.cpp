#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int n;
		cin >> n;
		string p;
		queue<int> q;
		stack<int> s;
		int flag1 = 0, flag2 = 0;
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> p;
			if (p == "push")
			{
				cin >> num;
				q.push(num);
				s.push(num);
			}
			else
			{
				if (!q.empty())
					q.pop();
				else
					flag1 = 1;
				if (!s.empty())
					s.pop();
				else
					flag2 = 1;
			}
		}
		if (flag1 == 1)
			cout << "error" << endl;
		else
		{
			while (!q.empty())
			{
				cout << q.front();
				if (q.size() != 1)
					cout << ' ';
				else
					cout << endl;
				q.pop();
			}
		}
		if (flag2 == 1)
			cout << "error" << endl;
		else
		{
			int temp[200] = {};
			int len = s.size();
			for (int i = len - 1; i >= 0; i--)
			{
				temp[i] = s.top();
				s.pop();
			}
			for (int i = 0; i < len; i++)
			{
				if (i != len - 1)
					cout << temp[i] << ' ';
				else
					cout << temp[i] << endl;
			}
		}
	}
	return 0;
}
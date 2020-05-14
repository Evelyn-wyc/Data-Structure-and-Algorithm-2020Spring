#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int t;
	cin >> t;
	stack<int> s;
	queue<int> q;
	while (t--)
	{
		int n;
		cin >> n;
		int flag = 0;
		while (n--)
		{
			int type, val;
			cin >> type >> val;
			if (type == 1)
			{
				s.push(val);
				q.push(val);
			}
			else if (type == 2 && s.size() != 1)
			{
				if (s.top() == val)
				{
					flag = 1;
				}
				s.pop();
				q.pop();
			}
			else
			{
				s.pop();
				q.pop();
			}
		}
		if (flag)
			cout << "Stack" << endl;
		else
			cout << "Queue" << endl;
	}
	return 0;
}
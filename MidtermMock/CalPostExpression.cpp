#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.get();
	int n = t;
	while (t--)
	{
		char c[1005] = {};
		stack<int> s;
		cin.getline(c, sizeof(c), '\n');
		int i = 0;
		int len = strlen(c);
		while (i < len)
		{
			if (c[i] != '+' && c[i] != '*' && c[i] != ' ')
			{
				s.push(c[i] - '0');
			}
			else if (c[i] == '+')
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a + b);
			}
			else if (c[i] == '*')
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a * b);
			}
			i++;
		}
		cout << "Case " << n - t << ": " << s.top() << endl;
	}
	return 0;
}
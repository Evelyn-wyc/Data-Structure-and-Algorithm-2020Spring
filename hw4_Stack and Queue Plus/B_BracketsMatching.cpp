#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> s;
	char c;
	bool flag = true;
	while (cin.get(c), c != '\n')
	{
		if (c == '(')
			s.push(c);
		else
		{
			if (!s.empty())
				s.pop();
			else
				flag = false;
		}
	}
	if (!flag || s.size() != 0)
		cout << "no" << endl;
	else
		cout << "yes" << endl;
	return 0;
}
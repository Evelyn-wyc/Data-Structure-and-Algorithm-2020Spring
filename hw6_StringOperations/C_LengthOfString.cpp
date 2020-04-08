#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (getline(cin, s, '\n'))
	{
		int len = s.length();
		int ans = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				cout << ans << endl;
				break;
			}
			else
			{
				ans++;
			}
		}
	}
	return 0;
}
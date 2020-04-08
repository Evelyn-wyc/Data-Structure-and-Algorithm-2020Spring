#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {
	int len = str.length(), i = 0, sgn = 1;
	while (i < len && str[i] == ' ') ++i;
	if (i == len) return 0;
	if (str[i] == '-')
		sgn = 0, ++i;
	else if (str[i] == '+')
		++i;
	long long ans = 0;
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10 + (str[i] - '0');
			i++;
			if (ans > 0x7fffffff)
			{
				return ans = (sgn ? 0x7fffffff : 0x80000000);
			}
		}
		else if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else
			break;
	}
	return ans * (sgn ? 1 : -1);
}
int main() {
	string s;
	while (getline(cin, s, '\n')) {
		cout << myAtoi(s) << endl;
	}
	return 0;
}

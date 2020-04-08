#include <iostream>
#include <string>

using namespace std;

bool isch(char s)
{ 
	return (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9'); 
}

bool isPalindrome(string s) 
{
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 'A' && s[i] <= 'Z') 
			s[i] = s[i] - 'A' + 'a';
	int i = 0, j = s.length() - 1;
	while (i < j) 
	{
		//将s处理成只包含小写字母和数字的字符串
		while (!isch(s[i]))
			i++;
		while (!isch(s[j]))
			j--;
		if (s[i] != s[j])
			return false;
		else
		{
			i++;
			j--;
		}
	}
	return true;
}

int main() {
	string s;
	while (getline(cin, s, '\n')) 
	{
		cout << (isPalindrome(s) ? "true" : "false") << endl;
	}
	return 0;
}

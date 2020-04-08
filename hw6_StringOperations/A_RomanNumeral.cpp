#include <iostream>
#include <cstring>

using namespace std;

int trans(char* str)
{
	int num = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'I')
		{
			if (i < len - 1 && (str[i + 1] == 'V' || str[i + 1] == 'X'))
				num -= 1;
			else
				num += 1;
		}
		else if (str[i] == 'V')
			num += 5;
		else if (str[i] == 'X')
		{
			if (i < len - 1 && (str[i + 1] == 'L' || str[i + 1] == 'C'))
				num -= 10;
			else
				num += 10;
		}
		else if (str[i] == 'L')
			num += 50;
		else if (str[i] == 'C')
		{
			if (i < len - 1 && (str[i + 1] == 'D' || str[i + 1] == 'M'))
				num -= 100;
			else
				num += 100;
		}
		else if (str[i] == 'D')
			num = num + 500;
		else if (str[i] == 'M')
			num = num + 1000;
	}
	return num;
}

int main()
{
	char n[20] = {};
	while (cin.getline(n, 20))
	{
		cout << trans(n) << endl;
	}
	return 0;
}
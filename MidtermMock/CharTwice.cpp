#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int num;
	cin >> num;
	cin.get();
	for (int i = 0; i < num; i++)
	{
		char s[1002] = {};
		int cnt[300] = {};
		cin.getline(s, sizeof(s));
		
		int len = strlen(s);
		for (int j = 0; s[j]; j++)
		{
			cnt[s[j]]++;
		}
		for (int j = 0; s[j]; j++)
		{
			if (cnt[s[j]] == 2)
			{
				cout << s[j] << endl;
				break;
			}
		}
	}
	return 0;
}
#include<iostream>

using namespace std;

char ss[1030];
char ans(int l, int r) 
{
	char x, y;
	int mid = (l + r) / 2;
	if (l == r)
		//最后一层的IB
	{
		if (ss[l] == '0') 
		{
			cout << 'B';
			return 'B';
		}
		else
		{
			cout << 'I';
			return 'I';
		}
	}

	else
		//其它层根据IB判断
	{
		x = ans(l, mid);
		y = ans(mid + 1, r);
		if (x == y) 
		{
			if (x == 'B')
			{
				cout << 'B';
				return 'B';
			}
			else if (x == 'I') 
			{
				cout << 'I';
				return 'I';
			}
			else if (x == 'F') 
			{
				cout << 'F';
				return 'F';
			}
		}
		else
		{
			cout << 'F';
			return 'F';
		}
	}
}
int main()
{
	int n;
	cin >> n;
	cin.get();
	n = 1 << n;
	cin.getline(ss, sizeof(ss));
	ans(0, n - 1);
	cout << endl;
	return 0;
}
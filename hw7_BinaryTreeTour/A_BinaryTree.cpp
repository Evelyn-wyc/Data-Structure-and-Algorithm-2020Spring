#include <iostream>

using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		int i = m, s = 0, sum = 1, hsum = 1;
		while (i < n)
		{
			i = 2 * i + 1;
			s++; //统计行数
		}
		for (int j = s - 1; j > 0; j--)
		{
			hsum *= 2;
			sum += hsum; //除最后一行个数
		}
		hsum *= 2;
		if (n - m * hsum >= 0)
			sum = sum + (n - m * hsum) + 1;
		cout << sum << endl;
	}
	return 0;
}
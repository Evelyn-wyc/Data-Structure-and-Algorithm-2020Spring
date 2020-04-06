#include <iostream>

using namespace std;

int times = 0;
void total(int st, int num)
{
	for (int i = st; i <= num; i++)
	{
		if (num % i != 0)
			continue;
		else if (i <= num / i)
		{
			times++;
			total(i, num / i);
		}
		else
			break;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		times = 0;
		int num;
		cin >> num;
		total(2, num);
		cout << times + 1 << endl;
	}
    return 0;
}

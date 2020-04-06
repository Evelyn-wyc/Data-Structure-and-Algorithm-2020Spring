#include <iostream>

using namespace std;

int cmb(int n, int m)
{
	if (m == 0 || n == m)
		return 1;
	else if (2 * m > n)
		return cmb(n, n - m);
	else
		return (cmb(n - 1, m) + cmb(n - 1, m - 1)) % 1000007;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << cmb(n, m) << endl;
	system("pause");
	return 0;
}
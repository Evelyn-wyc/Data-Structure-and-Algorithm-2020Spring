#include <iostream>

using namespace std;

int gcd(int n, int m)
{
	if (n == 1 || m == 1)
		return 1;
	else if (n == m)
		return n;
	else if (n < m)
		return gcd(n, m - n);
	else
		return gcd(m, n - m);
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	return 0;
}
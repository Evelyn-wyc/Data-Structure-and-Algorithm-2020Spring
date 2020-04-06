#include<iostream>

using namespace std;

int square(int n)
{
	if (n == 1)
		return 1;
	return square(n - 1) + n * n;
}

int main()
{
	int n;
	cin >> n;
	cout << square(n) << endl;
	return 0;
}
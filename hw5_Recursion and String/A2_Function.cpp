﻿#include<iostream>

using namespace std;

int w[21][21][21];
int func(int a, int b, int c)
{
	if ((a <= 0) || (b <= 0) || (c <= 0))
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return func(20, 20, 20);

	//w[a][b][c] has been calculated
	if (w[a][b][c]) return w[a][b][c];
	else
	{
		if (a < b && b < c)
			w[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
		else
			w[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
		return w[a][b][c];
	}
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == -1 && b == -1 && c == -1)
			break;
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << endl;
	}
	return 0;
}
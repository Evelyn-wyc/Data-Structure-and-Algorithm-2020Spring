#include <iostream>

using namespace std;

void move(int n, char a, char b, char c)
{
	if (n == 0)
		return;
	move(n - 1, a, c, b);
	cout << n << ':' << a << "->" << c << endl;
	move(n - 1, b, a, c);
}

int main()
{
	int n;
	char a, b, c;
	cin >> n >> a >> b >> c;
	move(n, a, b, c);
	return 0;
}

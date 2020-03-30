#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

template <typename A_Type> 
class complex
{
public:
	A_Type a;
	A_Type b;

	complex() {}
	complex(A_Type x, A_Type y)
	{
		a = x;
		b = y;
	}

	complex <A_Type>  multiply(A_Type x, A_Type y)
	{
		complex <A_Type> res;
		res.a = a * x - b * y;
		res.b = a * y + b * x;
		return res;
	}

	complex <A_Type> add(A_Type x, A_Type y)
	{
		complex <A_Type> res;
		res.a = a + x;
		res.b = b + y;
		return res;
	}

	void print()
	{
		if (b == 0)
			cout << a << endl;
		else if (a == 0)
			cout << b << 'i' << endl;
		else if (b > 0)
			cout << a << '+' << b << 'i' << endl;
		else if (b < 0)
			cout << a << '-' << (-b) << 'i' << endl;
	}
};

int main()
{
	int n;
	char type[10], symbol;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> type;
		if (0 == strcmp(type, "int"))
		{
			int r1, i1, r2, i2;
			cin >> r1 >> i1 >> symbol >> r2 >> i2;

			complex<int> result;//无参构造函数初始化
			complex<int> a(r1, i1);//调用构造函数初始化
			if (symbol == '+')
				result = a.add(r2, i2);
			else if (symbol == '*')
				result = a.multiply(r2, i2);
			result.print();
		}
		// double
		else if (0 == strcmp(type, "double"))
		{
			double r1, i1, r2, i2;
			cin >> r1 >> i1 >> symbol >> r2 >> i2;

			complex <double> result;//无参构造函数初始化
			complex <double> a(r1, i1);//调用构造函数初始化
			if (symbol == '+')
				result = a.add(r2, i2);
			else if (symbol == '*')
				result = a.multiply(r2, i2);
			result.print();
		}
	}
	system("pause");
}
#include <iostream>

using namespace std;

class A {
private:
	int value;
	friend class B;
public:
	A() 
	{
		value = 1;
	}
	int getValue()
	{
		return value;
	}
	void changeValue(int i) 
	{
		value = i;
	}

};
class B {
public:
	int getValue(A& a) 
	{
		return a.value;
	}
	void changeValue(A& a, int i) 
	{
		a.value = i;
	}
};

int main() {
	int i;
	cin >> i;
	A a;
	B b;
	/*1.获取a中value的值并输出 */
	cout << b.getValue(a) << endl;
	/*2. 修改a中value的值为i */
	b.changeValue(a, i);
	/*3. 获取a中value的值并输出 */
	cout << b.getValue(a) << endl;
	system("pause");
	return 0;
}
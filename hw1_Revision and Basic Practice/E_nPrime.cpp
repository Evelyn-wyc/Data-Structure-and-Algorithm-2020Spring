#include <iostream>

using namespace std;

//判断素数
bool judge(int p)//对于p >= 3适用
{
    //在根号p之前若没有因子，则p为素数
    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int num[10000] = {};
    num[0] = 2;
    num[1] = 3;
    int len = 2;
    //判断i是否为素数，len代表素数个数，对应着“第几个素数”
    for (int i = 5; len < 10000; i++)
    {
        if (judge(i))
        {
            num[len] = i;
            len++;
        }
    }
    int n;
    cin >> n;
    cout << num[n - 1];
    return 0;
}

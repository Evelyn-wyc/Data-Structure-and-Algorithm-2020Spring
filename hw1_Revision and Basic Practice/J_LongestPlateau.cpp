#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[1004] = {};
    int sum = 1;
    int re = sum;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (i == 0)
            sum = 1;//首位自身为一个平台
        else if (i != 0 && num[i] == num[i - 1])
        {
            sum++;
            re = max(re, sum);//最大值
        }
        else
        {
            sum = 1;
        }
    }
    cout << re << endl;

    return 0;
}

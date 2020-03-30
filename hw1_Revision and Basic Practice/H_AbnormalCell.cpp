#include <iostream>
#include <cmath>

using namespace std;

int arr[102][102];

//������������Ƚϣ��ж��Ƿ�Ϊ�쳣
bool judge(int i, int j)
{
    if (abs(arr[i - 1][j] - arr[i][j]) >= 50 && abs(arr[i + 1][j] - arr[i][j] >= 50) && abs(arr[i][j - 1] - arr[i][j]) >= 50 && abs(arr[i][j + 1] - arr[i][j] >= 50))
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;//�쳣����Ŀ
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (judge(i, j))
                sum++;
        }
    }
    cout << sum;
    return 0;
}

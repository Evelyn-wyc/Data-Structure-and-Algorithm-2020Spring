#include <iostream>

using namespace std;

//�ж�����
bool judge(int p)//����p >= 3����
{
    //�ڸ���p֮ǰ��û�����ӣ���pΪ����
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
    //�ж�i�Ƿ�Ϊ������len����������������Ӧ�š��ڼ���������
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

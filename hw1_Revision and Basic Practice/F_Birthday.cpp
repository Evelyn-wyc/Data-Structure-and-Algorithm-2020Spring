#include <iostream>
#include <cstring>

using namespace std;

struct student
{
    char number[12];//ѧ��
    int month;
    int day;
};

int main()
{
    int n;
    cin >> n;
    struct student a[100];//ÿ��a[i]����һ��ѧ��
    int birth[12][31] = {};//�С��зֱ��������¡��գ���¼�����ڸ��ճ���������
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].number;
        cin >> a[i].month >> a[i].day;
        birth[a[i].month - 1][a[i].day - 1]++;//ÿ�����붼����������
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (birth[i][j] != 0 && birth[i][j] != 1)//�����������⣿�ǲ������������˲������
            {
                //���մ�ǰ�����˳��
                cout << i + 1 << ' ' << j + 1;
                //����ȫ��ѧ��
                for (int k = 0; k < n; k++)
                {
                    if (a[k].month == i + 1 && a[k].day == j + 1)
                    {
                        cout << ' ';
                        //ѧ�ŵ����
                        int len = strlen(a[k].number);
                        for (int g = 0; g < len; g++)
                            cout << a[k].number[g];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}

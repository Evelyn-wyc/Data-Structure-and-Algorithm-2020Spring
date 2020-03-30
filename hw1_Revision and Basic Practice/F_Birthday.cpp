#include <iostream>
#include <cstring>

using namespace std;

struct student
{
    char number[12];//学号
    int month;
    int day;
};

int main()
{
    int n;
    cin >> n;
    struct student a[100];//每个a[i]代表一个学生
    int birth[12][31] = {};//行、列分别代表出生月、日，记录的是在该日出生的人数
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].number;
        cin >> a[i].month >> a[i].day;
        birth[a[i].month - 1][a[i].day - 1]++;//每次输入都更新人数表
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (birth[i][j] != 0 && birth[i][j] != 1)//对于题意的理解？是不是至少两个人才输出？
            {
                //按照从前到后的顺序
                cout << i + 1 << ' ' << j + 1;
                //遍历全部学生
                for (int k = 0; k < n; k++)
                {
                    if (a[k].month == i + 1 && a[k].day == j + 1)
                    {
                        cout << ' ';
                        //学号的输出
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

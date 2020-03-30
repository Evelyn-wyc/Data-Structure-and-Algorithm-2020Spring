#include <iostream>
#include <iomanip>

using namespace std;

//GPA转换表
double tran(int a)
{
    if (a <= 100 && a >= 90)
        return 4.0;
    else if (a <= 89 && a >= 85)
        return 3.7;
    else if (a <= 84 && a >= 82)
        return 3.3;
    else if (a <= 81 && a >= 78)
        return 3.0;
    else if (a <= 77 && a >= 75)
        return 2.7;
    else if (a <= 74 && a >= 72)
        return 2.3;
    else if (a <= 71 && a >= 68)
        return 2.0;
    else if (a <= 67 && a >= 64)
        return 1.5;
    else if (a <= 63 && a >= 60)
        return 1.0;
    else
        return 0;
}

int main()
{
    int n;
    cin >> n;
    int course[11] = {};
    int grade[11] = {};
    int csum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> course[i];
        csum += course[i];//总学分
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i];
        sum += course[i] * tran(grade[i]);//加权后的绩点
    }
    cout << fixed << setprecision(2) << sum / csum << endl;
    return 0;
}

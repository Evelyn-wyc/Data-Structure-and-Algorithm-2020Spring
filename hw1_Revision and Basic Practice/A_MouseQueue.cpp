#include <iostream>

using namespace std;

struct rat
{
    int weight;
    char color[12];
};

int main()
{
    int n;
    cin >> n;
    struct rat a[100] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].weight;
        cin >> a[i].color;
    }
    //冒泡排序
    for (int i = 0; i < n; i++)
    {
        //内层循环每过一遍，都能将未排序的最小数放到后面
        for (int j = 0; j < n - i - 1; j++)
        {
            //如果不符合从大到小，则交换
            if (a[j].weight < a[j + 1].weight)
            {
                struct rat tmp;
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i].color << endl;
    return 0;
}

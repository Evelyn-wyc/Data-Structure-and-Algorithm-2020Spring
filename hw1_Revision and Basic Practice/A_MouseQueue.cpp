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
    //ð������
    for (int i = 0; i < n; i++)
    {
        //�ڲ�ѭ��ÿ��һ�飬���ܽ�δ�������С���ŵ�����
        for (int j = 0; j < n - i - 1; j++)
        {
            //��������ϴӴ�С���򽻻�
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

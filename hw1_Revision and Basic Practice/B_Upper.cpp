#include <iostream>
#include <cstring>

using namespace std;

//����ASCII�����Сд��ĸת��Ϊ��д��ĸ
inline char up(char x)
{
    return (x - 32);
}

int main()
{
    char sen[100] = {};
    int i = 0;
    while (cin.get(sen[i]))
    {
        //��������ĸ
        if (i == 0)
        {
            if (sen[i] >= 'a' && sen[i] <= 'z')//Сд��ĸ
            {
                sen[i] = up(sen[i]);
            }
        }
        //����λ�����Ҷ������ո�
        else if (i > 0 && (sen[i - 1] == ' ' || sen[i - 1] == '\r' || sen[i - 1] == '\t' || sen[i - 1] == '\n'))
        {
            if (sen[i] >= 'a' && sen[i] <= 'z')
            {
                sen[i] = up(sen[i]);
            }
        }
        i++;
    }
    int len = strlen(sen);
    for (int i = 0; i < len; i++)
        cout << sen[i];
    return 0;
}

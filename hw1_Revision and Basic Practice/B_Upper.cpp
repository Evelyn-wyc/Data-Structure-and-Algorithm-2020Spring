#include <iostream>
#include <cstring>

using namespace std;

//根据ASCII码表，将小写字母转化为大写字母
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
        //处理首字母
        if (i == 0)
        {
            if (sen[i] >= 'a' && sen[i] <= 'z')//小写字母
            {
                sen[i] = up(sen[i]);
            }
        }
        //非首位，并且读到“空格”
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

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[26] = {};//s[i]对应第(i+1)个字母的出现次数
    for (int i = 0; i < n; i++)
    {
        char str[1003] = {};
        cin >> str;
        memset(s, 0, sizeof(s));
        int len = strlen(str);
        for (int j = 0; j < len; j++)
        {
            s[(int)(str[j] - 97)]++;
        }
        int re = 0;
        char rx;
        //找出最大的，更新字母和次数
        for (int j = 0; j < 26; j++)
        {
            if (re < s[j])
            {
                re = s[j];
                rx = (char) j+97;
            }
        }
        cout << rx << ' ' << re << endl;
    }
    return 0;
}

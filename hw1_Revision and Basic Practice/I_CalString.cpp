#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[26] = {};//s[i]��Ӧ��(i+1)����ĸ�ĳ��ִ���
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
        //�ҳ����ģ�������ĸ�ʹ���
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

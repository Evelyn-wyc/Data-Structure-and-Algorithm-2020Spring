#include<iostream>
#include<string>

using namespace std;

void getnext(string p, int len, int *nex)
{
    nex[0] = -1;
    int i = 0, j = -1;
    while (i < len)
    {
        if (j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
            j = nex[j];
    }
    return;
}

int kmp(string s, string p, int len1, int len2, int *nex)
{
    int i = 0, j = 0, num = 0;
    while (s[i] != '\0')
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = nex[j];
        if (j == len2)
        {
            j = 0;
            num++;
        }
    }
    return num;
}

int main()
{
    string s, p;
    while (cin >> s && s != "#")
    {
        cin >> p;
        int len1 = s.size();
        int len2 = p.size();
        int nex[4005] = {};
        getnext(p, len2, nex);
        cout << kmp(s, p, len1, len2, nex) << endl;
    }
    return 0;
}








//#include <iostream>
//#include <string>
//
//using namespace std;
//int check(string a,string b) {
//    int d = b.size(),ans = 0;
//    int size = a.size() - d + 1;
//    string t;
//    for(int i = 0;i <= size;i ++) {
//        if(a[i] == b[0]) {
//            t.assign(a,i,d);
//            if(t == b) {
//                ans ++;
//                i += d - 1;
//            }
//        }
//    }
//    return ans;
//}
//int main() {
//    string a,b;
//    while(cin>>a&&a!="#") {
//        cin>>b;
//        cout<<check(a,b)<<endl;
//    }
//}

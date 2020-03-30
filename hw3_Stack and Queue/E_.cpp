#include<bits/stdc++.h>
using namespace std;


int main(){
    //stl::stack 成员函数 .top()为获取栈顶元素  .pop()为弹出栈顶   .push(i)为将i推入栈
    stack<int>stk;//储存当前栈的情况
    stack<int>stkmax;//储存当前栈内最值

    int n;
    cin>>n;
    string s;

    for (int i=0;i<n;++i){
        cin>>s;
        if (s=="queryMax"){
            if (stkmax.empty())
                cout<<"0"<<endl;
            else 
                cout<<stkmax.top()<<endl;
        }
        else if (s=="pop"){
            int f=stk.top();
            stk.pop();
            if (/*填空1内容：此处添加判断条件*/)
                stkmax.pop();
        }
        else {
            int val;
            cin>>val;
            stk.push(val);
            if (/*填空2内容：此处添加判断条件*/)
                stkmax.push(val);
        }
    }    
    fclose(stdin);fclose(stdout);
    return 0;
}


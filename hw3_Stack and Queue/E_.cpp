#include<bits/stdc++.h>
using namespace std;


int main(){
    //stl::stack ��Ա���� .top()Ϊ��ȡջ��Ԫ��  .pop()Ϊ����ջ��   .push(i)Ϊ��i����ջ
    stack<int>stk;//���浱ǰջ�����
    stack<int>stkmax;//���浱ǰջ����ֵ

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
            if (/*���1���ݣ��˴�����ж�����*/)
                stkmax.pop();
        }
        else {
            int val;
            cin>>val;
            stk.push(val);
            if (/*���2���ݣ��˴�����ж�����*/)
                stkmax.push(val);
        }
    }    
    fclose(stdin);fclose(stdout);
    return 0;
}


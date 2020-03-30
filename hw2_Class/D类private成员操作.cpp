#include<bits/stdc++.h>
using namespace std;

class A{
    private:
        int value;
        friend class B;
    public:
        A(){
            value=1;
        }
        int getValue(){
            //完成功能：修改a中value的值
        }
        void changeValue(int i){
            //完成功能：修改a中value的值为i
        }

};
class B{
    public:
        int getValue(A& a){
            //完成功能：返回a中value的值
        }
        void changeValue(A& a,int i){
            //完成功能：修改a中value的值为i
        }
};

int main(){
    int i;
    cin>>i;
    A a;
    /*补全上述函数，并选择使用上述函数完成以下功能：*/
	/*1.获取a中value的值并输出 */
	/*2. 修改a中value的值为i */
	/*3. 获取a中value的值并输出 */
    return 0;
}
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
            //��ɹ��ܣ��޸�a��value��ֵ
        }
        void changeValue(int i){
            //��ɹ��ܣ��޸�a��value��ֵΪi
        }

};
class B{
    public:
        int getValue(A& a){
            //��ɹ��ܣ�����a��value��ֵ
        }
        void changeValue(A& a,int i){
            //��ɹ��ܣ��޸�a��value��ֵΪi
        }
};

int main(){
    int i;
    cin>>i;
    A a;
    /*��ȫ������������ѡ��ʹ����������������¹��ܣ�*/
	/*1.��ȡa��value��ֵ����� */
	/*2. �޸�a��value��ֵΪi */
	/*3. ��ȡa��value��ֵ����� */
    return 0;
}
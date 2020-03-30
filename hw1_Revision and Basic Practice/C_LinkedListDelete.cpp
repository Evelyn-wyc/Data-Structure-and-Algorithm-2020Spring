#include <iostream>

using namespace std;

struct node
{
    int num;
    node * next;
};

int main()
{
    int n;
    cin >> n;

    //输入数组中的元素
    node * head;
    head = new node;
    node * temp = head;
    for (int i = 0; i < n; i++)
    {
        cin >> temp -> num;
        temp -> next = new node;
        temp = temp -> next;
    }
    temp = NULL;

    int del;
    cin >> del;

    //单向链表删除操作
    node * point = head;
    node * follow = head;
    while (point -> next != NULL)
    {
        if (head -> num == del)
        {
            head = head -> next;
            delete point;
            point = head;
        }
        else if (point -> num != del)
        {
            if (point -> next != NULL)
                cout << point -> num << ' ';
            else
                cout << point -> num;
            follow = point;
            point = point -> next;
        }
        else if (point -> num == del)
        {
            follow -> next = point -> next;//改变了follow指向
            delete point;//point还在del的位置，删掉
            point = follow -> next;//新的point
            follow = point;
        }
    }
}

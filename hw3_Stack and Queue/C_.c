
#include<stdio.h>

//�������ȼ�
const int END = -1;
const int VALUE = 0;
const int PLUS_MINUS = 1;
const int MULTI_DIV = 2;
const int OPEN_PAREN = 3;
const int CLOSE_PAREN = 4;

//������Ŷ�������ȼ�
int priority(const char c){
    switch (c){
    case '\0':return END;
    case '+':
    case '-':return PLUS_MINUS;

    /* �˴�������ϰ */

    default: return VALUE;
    }
}

//����ջ
char stack[30] = "\0";
int count = 0;

//ջ����
int empty(){
    return !count;
}

const char top(){
    return stack[count - 1];
}

//����ջ��Ԫ�ز����䵯��
char pop(){
    /* ����� */
}

//��Ԫ��ѹջ
void push(char c){
    /* ����� */
}

//��׺���ʽ
char midfix[30] = "\0";

int main(){
    //�״������ָʾ���������ж��Ƿ�ӿո�
    int flag = 0;

    //������������Ż��ֿ���
    char *p = NULL, *q = NULL;
    int postIndex = 0;
    int curPriority;
    scanf("%s", midfix);
    p = q = midfix;
    while (1){
        curPriority = priority(*p);
        //��ȡ���
        if (/* ����д���� */){
            while (!empty()){
                putchar(' ');
                putchar(pop());
            }
            break;
        }
        //��ǰ������ֵ��ֱ�����
        if (curPriority == VALUE){
            //ʹ��ָ��q����������ֱ��qָ����һ�����Ż��ַ���ĩβΪֹ
            for (/* ����дѭ���� */);
            if (flag++)
                putchar(' ');
            while (p != q)
                putchar(*p++);
        }//�����ţ�ѹջ
        else if (curPriority == OPEN_PAREN){
            push('(');
            ++p;
        }//���������ţ�������ջ��Ԫ�ص�����ֱ������������
        else if (curPriority == CLOSE_PAREN){
            char c = 0;
            while (!empty()){
                c = pop();
                if (c == '(')
                    break;
                putchar(' ');
                putchar(c);
            }
            ++p;
        }//�������������
        else{
            while (/* ��дѭ���壨��ʾ���������ж������� */){
                putchar(' ');
                putchar(pop());
            }
            push(*p++);
        }
    }
    putchar('\n');
    return 0;
}

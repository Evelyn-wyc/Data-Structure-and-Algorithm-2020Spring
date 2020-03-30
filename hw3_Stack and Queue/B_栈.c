#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int type; // ջ���Ԫ������, 0���������, 1��������.
    char op;
    double number;
};

struct NODE myStack[20000];
int top = 0;    //ջ��ָ��
char reads[100];

double calc(double a, double b, char op) {
    double re;
    switch (op) {
        case '+' : re = a + b; break;
        case '-' : re = a - b; break;
        /*
            �벹�����
        */
    }
    return re;
}
void push_op(char op) {
    myStack[top].type = 0;
    myStack[top].op = op;
    top++;
}

void push_number(double num) {
    /*
        �벹�����
    */
}

double pop_number() {
    return myStack[--top].number;
}

char pop_op() {
    /*
        �벹�����
    */
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

int main() {
    while (scanf("%s", reads) != EOF) {
        if (isOperator(reads[0])) {
            push_op(reads[0]);
        } else {
            push_number(atof(reads));
        }
        while (top >= 3 && /* �벹������ */) {
            double b = pop_number();
            double a = pop_number();
            char op = pop_op();
            double re = calc(a, b, op);
            /* �벹����� */
        }
    }
    printf("%f\n", pop_number());
}

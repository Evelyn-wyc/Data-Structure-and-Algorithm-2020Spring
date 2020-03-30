#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int type; // 栈里的元素类型, 0代表运算符, 1代表浮点数.
    char op;
    double number;
};

struct NODE myStack[20000];
int top = 0;    //栈顶指针
char reads[100];

double calc(double a, double b, char op) {
    double re;
    switch (op) {
        case '+' : re = a + b; break;
        case '-' : re = a - b; break;
        /*
            请补充代码
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
        请补充代码
    */
}

double pop_number() {
    return myStack[--top].number;
}

char pop_op() {
    /*
        请补充代码
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
        while (top >= 3 && /* 请补充条件 */) {
            double b = pop_number();
            double a = pop_number();
            char op = pop_op();
            double re = calc(a, b, op);
            /* 请补充代码 */
        }
    }
    printf("%f\n", pop_number());
}

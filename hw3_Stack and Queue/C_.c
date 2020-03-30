
#include<stdio.h>

//定义优先级
const int END = -1;
const int VALUE = 0;
const int PLUS_MINUS = 1;
const int MULTI_DIV = 2;
const int OPEN_PAREN = 3;
const int CLOSE_PAREN = 4;

//定义符号对象的优先级
int priority(const char c){
    switch (c){
    case '\0':return END;
    case '+':
    case '-':return PLUS_MINUS;

    /* 此处留做练习 */

    default: return VALUE;
    }
}

//符号栈
char stack[30] = "\0";
int count = 0;

//栈函数
int empty(){
    return !count;
}

const char top(){
    return stack[count - 1];
}

//返回栈顶元素并将其弹出
char pop(){
    /* 请填空 */
}

//将元素压栈
void push(char c){
    /* 请填空 */
}

//中缀表达式
char midfix[30] = "\0";

int main(){
    //首次输出的指示器，用于判断是否加空格
    int flag = 0;

    //将操作数与符号划分开来
    char *p = NULL, *q = NULL;
    int postIndex = 0;
    int curPriority;
    scanf("%s", midfix);
    p = q = midfix;
    while (1){
        curPriority = priority(*p);
        //读取完毕
        if (/* 请填写条件 */){
            while (!empty()){
                putchar(' ');
                putchar(pop());
            }
            break;
        }
        //当前读入数值，直接输出
        if (curPriority == VALUE){
            //使用指针q进行搜索，直到q指向下一个符号或字符串末尾为止
            for (/* 请填写循环体 */);
            if (flag++)
                putchar(' ');
            while (p != q)
                putchar(*p++);
        }//左括号，压栈
        else if (curPriority == OPEN_PAREN){
            push('(');
            ++p;
        }//读入右括号，将符号栈内元素弹出，直到遇到左括号
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
        }//读入四则运算符
        else{
            while (/* 填写循环体（提示：有三个判断条件） */){
                putchar(' ');
                putchar(pop());
            }
            push(*p++);
        }
    }
    putchar('\n');
    return 0;
}

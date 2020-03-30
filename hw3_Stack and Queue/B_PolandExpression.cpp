#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

double expr()
{
	char temp[20] = {};
	cin >> temp;
	switch(temp[0])
	{
	case '+':
		return expr() + expr();
	case '-':
		return expr() - expr();
	case '*':
		return expr() * expr();
	case '/':
		return expr() / expr();
	default:
		return atof(temp);
		break;
	}
}

int main()
{
	cout << fixed << setprecision(6) << expr();
	system("pause");
	return 0;
}




/*
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
typedef double ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

//初始化栈
void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

//压如栈
void Push(sqStack *s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT)*sizeof(ElemType));
		if (!s->base)
		{
			exit(0);
		}
	}

	*(s->top) = e;
	s->top++;
}

//出栈
void Pop(sqStack *s, ElemType *e)
{
	if (s->top == s->base)
	{
		return;
	}
	*e = *--(s->top);
}

//求栈中还有的元素个数
int StackLen(sqStack s)
{
	return (s.top - s.base);
}
int main()
{
	char c;
	sqStack s;
	char str[MAXBUFFER];
	double d,e;
	int i = 0;
	InitStack(&s);
	cout<<"请将逆波兰表达式输入各个字符之间用空格隔开，最后用#表示输入结束：\n";
	cin>>c;
	//printf();
	//scanf("%c",&c);
	while (c != '#')
	{
		while(isdigit(c) || c=='.')//用于过滤数字,设置缓存区
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				 cout<<"输入数据过大！\n";
				//printf("输入数据过大！\n");
				return -1;
			}
			cin>>c;
			//scanf("%c",&c);

			if(c == ' ')
			{
				d = atof(str);//将字符串转化为数字
				cout<<d;
				Push(&s, d);
				i = 0;
				break;
			}
		}

		switch(c)
		{
			case '+':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, e+d);
				break;
			case '-':
				 Pop(&s, &e);
				 Pop(&s, &d);
				Push(&s, e-d);
				break;
			case '*':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, e*d);
				break;
			case '/':
			   Pop(&s, &e);
				Pop(&s, &d);
				if (e!=0)
				{
					Push(&s, e/d);
				}
				else
				{
					cout<<"出错，除数为0!\n";
					//printf("出错，除数为0!\n");
					return -1;
				}
				break;
		}
		cin>>c;
	}

	Pop(&s, &d);
	cout<<"最终的计算结果为：\n"<<d<<endl;
	//printf("最终的计算结果为：%f\n",d);
	return 0;
}
*/
/*
#include<iostream>
#include<cstring>
#include<stack>
#include<string>

using namespace std;

stack<char> s1;		//运算符栈 
stack<double> s2;		//中间结果栈  

int priority(const char str)
{
	int n;		//优先级 	
	switch (str)
	{
	case '*':n = 2;break;
	case '/':n = 2;break;
	case '+':n = 1;break;
	case '-':n = 1;break;
	}
	return n;
}

int main()
{
	char c[100];
	cin >> c;
	int len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			int endnum = 0;
			for (int j = i; j < len; j++)
			{
				if ((c[j] == '+') || (c[j] == '-') || (c[j] == '*') || (c[j] == '/'))
				{
					endnum = j - 1;
					break;
				}
				//最末尾的数字
				else if (j == len - 1)
				{
					endnum = j;
					break;
				}
			}
			double cur = 0;
			int w = 0;//位数
			int s = 1;//10的方幂
			int point = 0;//小数点的位置
			for (int k = endnum; k >= i; k--)
			{
				if (c[k] != '.')
				{
					cur += s * (int)c[k];
					s *= 10;
					w += 1;
				}
				else
				{
					point = w;
				}
			}
			//处理小数点
			while (point != 0)
			{
				cur /= 10;
				point--;
			}
			//更新i
			i = endnum;
			//将数字压入s2
			s2.push(cur);
		}
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
			while (true)
			{
				if (s1.empty() || s1.top() == '(')
				{
					s1.push(c[i]);
					break;
				}
				else if (priority(c[i]) > priority(s1.top()))
				{
					//当前运算符优先级大于s1栈顶运算符优先级 				
					s1.push(c[i]);
					break;
				}
				else
				{
					//小于等于	
					char s1t1 = s1.top();
					s1.pop();
					s2.push(s1t1);//修改
					//再次进入循环，与新的s1栈顶元素比较
				}
			}
		}
		else
		{
			if (c[i] == '(')
			{
				//直接读入 				
				s1.push(c[i]);
			}
			else
			{
				//是')'
				while (s1.top() != '(')
				{
					char s1t2 = s1.top();
					s1.pop();
					s2.push(s1t2);//修改
				}
				s1.pop();
				//不保留左右括号
			}
		}
	}
	//把剩余的运算符压入到s2
	while (!s1.empty())
	{
		char s1t3 = s1.top();
		s2.push(s1t3);//修改
		s1.pop();
	}
	//s2结果是逆序的，此时s1是空栈
	while (!s2.empty())
	{
		char x = s2.top();
		s1.push(x);//修改
		s2.pop();
	}
	while (!s1.empty())
	{
		cout << s1.top();
		s1.pop();
		if (!s1.empty())
			cout << ' ';
	}
	return 0;
}
*/

#include<iostream>
#include<cstring>

using namespace std;

bool IsNum(char c)
{
	//c是可能包含小数点的数字
	return (c >= '0' && c <= '9') || c == '.';
}

int Compare(char a, char b)
{
	//比较两个符号优先级，左括号优先级最高，记为0；右括号优先级最低，记为1；a>=b，记为1
	if (b == ')') return 1;
	if (b == '(' || a == '(') return 0;

	switch (b)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		switch (a)
		{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
		}

	}
}

int main()
{
	char str1[21] = {};
	char str2[21] = {};
	int flag = 0;//str2的长度
	int space = 0;
	cin >> str1;
	int len = strlen(str1);

	for (int i = 0; i < len; i++)
	{
		if (IsNum(str1[i]))
		{
			//str1[i]是数字则输出
			if (space)
			{
				cout << ' ';
				space = 0;
			}
			cout << str1[i];
		}
		else
		{
			if (flag)
			{
				if (str1[i] == ')')
				{
					//str2出栈，直到遇到'('
					while (flag--)
					{
						if (str2[flag] == '(') 
							break;
						cout << ' ' << str2[flag];
					}
				}
				else
				{
					while (flag)
					{
						//str2内不为空，比较栈顶与str1[i]的优先级
						if (Compare(str2[flag - 1], str1[i]))
						{
							//若str1优先级低，出栈
							flag--;
							cout << ' ' << str2[flag];
						}
						else break;
					}
					str2[flag] = str1[i];
					flag++;
				}
			}
			else
			{
				str2[flag] = str1[i];
				flag++;
			}
			//判断是否输出空格
			for (int j = 0; j < flag; j++)
			{
				if (str2[j] != '(')
				{
					//抛弃掉'('，不输出空格
					space = 1;
					break;
				}
			}
		}
	}
	while (flag)
	{
		flag--;
		cout << ' ' << str2[flag];
	}
	return 0;
}
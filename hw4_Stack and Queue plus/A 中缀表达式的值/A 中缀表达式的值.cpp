/*
中缀转后缀
后缀用栈
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

char expr[700] = {};
char pexpr[700] = {};

bool IsNum(char c)
{
	return (c >= '0' && c <= '9');
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

void change(char str1[])
//转换成后缀表达式
{
	char str2[700] = {};
	int flag = 0;//str2的长度
	int space = 0;
	int len = strlen(str1);
	int plen = 0;//pexpr的长度

	for (int i = 0; i < len; i++)
	{
		if (IsNum(str1[i]))
		{
			//str1[i]是数字则输出
			if (space)
			{
				pexpr[plen] = ' ';
				plen++;
				space = 0;
			}
			pexpr[plen] = str1[i];
			plen++;
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
						pexpr[plen] = ' ';
						pexpr[plen + 1] = str2[flag];
						plen += 2;
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
							pexpr[plen] = ' ';
							pexpr[plen + 1] = str2[flag];
							plen += 2;
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
		pexpr[plen] = ' ';
		pexpr[plen + 1] = str2[flag];
		plen += 2;
	}
}

int operation(char c, int a, int b)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return (int)a / b;
	}
}

int answer(char c[])
//后缀表达式求值
{
	stack<int> s;
	int len = strlen(c);
	char tmp[20] = {};//临时存放数字
	int tlen = 0;//临时数字的长度
	for (int i = 0; i < len; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			tmp[tlen] = c[i];
			tlen++;
		}
		else
		{
			if (c[i - 1] >= '0' && c[i - 1] <= '9')
			{
				int num = atoi(tmp);
				memset(tmp, 0, sizeof(tmp));
				tlen = 0;
				s.push(num);
			}

			if ((c[i] != ' ') && s.size() >=2)
			{
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				s.push(operation(c[i], a2, a1));
			}
		}
	}
	return s.top();
}

int main()
{
	int n;
	cin >> n;
	cin.get();
	while (n--)
	{
		memset(pexpr, 0, sizeof(pexpr));
		cin.getline(expr, 700);
		change(expr);//得到后缀表达式pexpr
		cout << answer(pexpr) << endl;
	}
	return 0;
}
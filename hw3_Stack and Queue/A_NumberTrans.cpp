#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool flag = true;
		int num[1005] = {};
		bool judge[1005] = {};//false
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			if (i != 1)
			{
				//注意到，问题都出现在num[i]<num[i-1]的情况
				//也即，栈顶元素与num[i]不相等
				if (num[i] > num[i - 1])
					judge[num[i - 1]] = true;
				else
				{
					judge[num[i - 1]] = true;
					for (int j = num[i] + 1; j < num[i - 1]; j++)
					{
						if (!judge[j])
							flag = false;
					}
				}
			}
		}
		cout << (flag ? "yes" : "no") << endl;
	}
	return 0;
}
/*
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int num[1005] = {};
		for (int i = 1; i <= n; i++)
			cin >> num[i];//num[0]等于0
		stack<int> s;
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			//根据num数组判断可能进行的操作
			if (i == 1 || (i != 1 && num[i] > num[i - 1]))
			{
				//此时正在压入栈
				for (int j = num[i - 1] + 1; j <= num[i]; j++)
				{
					s.push(j);
				}
				//压入栈的工作进行完毕之后，把最上面的数字弹出
				s.pop();
			}
			else
			{
				//此时正在进行弹出操作
				//栈顶的数字与输入的不一致，就说明输入的不可行
				if (s.top() != num[i])
				{
					flag = false;
					break;
				}
				else
					s.pop();
			}
		}
		cout << ((flag == true) ? "yes" : "no") << endl;
	}
}
*/

/*
#include <iostream>

using namespace std;

int arr[10002] = {};
int index[10002] = {};//代表元素的下标
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//最小值：维护一个单调递增序列
	//后面的一个数尽管可能更大了，但有可能是下一个窗口的最小值，所以应该保存
	//后面的一个数更小了，那么前面的更大的数就不可能为最小值了，弹出队列

	int head = 0, tail = -1;//双“指针”代表头和尾
	for (int i = 0; i < n; i++)
	{
		if (head <= tail && index[head] < i - k + 1)
		//head<=tail说明队列不为空；index[head] < i - k + 1说明队首元素应该出滑窗了
			head++;//队首元素往后移动一位，也即原来队首元素出队
		while (head <= tail && arr[index[tail]] >= arr[i])
		{
			tail--;//把大于等于arr[i]的元素都从队列中删除
		}
		tail++;
		index[tail] = i;//入队
		if (i >= k - 1)
			//此时可以打印队首元素
		{
			if (i != n - 1)
				cout << arr[index[head]] << ' ';
			else
				cout << arr[index[head]];
		}
	}
	cout << endl;

	//最大值：维护一个单调递减序列
	head = 0, tail = -1;
	for (int i = 0; i < n; i++)
	{
		if (head <= tail && index[head] < i - k + 1)
			head++;
		while (head <= tail && arr[index[tail]] <= arr[i])
			tail--;
		tail++;
		index[tail] = i;
		if (i >= k - 1)
		{
			if (i != n - 1)
				cout << arr[index[head]] << ' ';
			else
				cout << arr[index[head]];
		}
	}

	return 0;
}
*/
#include <iostream>
using namespace std;

inline int min(int a, int b)
{
	return (a > b ? b : a);
}

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

int arr[10002] = {};
int mm[10002] = {};
int MM[10002] = {};
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int m = arr[0], M = arr[0];
	for (int i = 0; i <= n - k; i++)
	{
		for (int j = i; j < i + k; j++)
		{
			m = min(m, arr[j]);
			M = max(M, arr[j]);
		}
		mm[i] = m;
		MM[i] = M;
		m = arr[i + k - 1];
		M = arr[i + k - 1];
	}
	for (int i = 0; i <= n - k; i++)
	{
		if (i != n - k)
			cout << mm[i] << ' ';
		else
			cout << mm[i] << endl;
	}
	for (int i = 0; i <= n - k; i++)
	{
		if (i != n - k)
			cout << MM[i] << ' ';
		else
			cout << MM[i] << endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int arr[100005];
int p = 0;

//建立最小堆
void siftdown(int s) //s是角标
{
	int i = s; //父节点
	int j = 2 * i; //左子节点
	int tmp = arr[s];
	while (j <= p)
	{
		if (j <= p - 1 && arr[j] > arr[j + 1])
			j++; //移动到右子节点 (取较小者)
		if (arr[j] < tmp)
		{
			arr[i] = arr[j];
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
	arr[i] = tmp;
}

void siftup(int s)
{
	int i = s;
	int tmp = arr[i];
	while (i > 1 && arr[i / 2] > tmp)
	{
		//交换
		arr[i] = arr[i / 2];
		i /= 2;
	}
	arr[i] = tmp;
}

void insert(int num)
{
	p++;
	arr[p] = num;
	siftup(p);
}

void del()
{
	if (p == 0)
		return;
	cout << arr[1] << endl;
	arr[1] = arr[p];
	p--;
	siftdown(1);
}

int main()
{
	int n;
	cin >> n;
	memset(arr, sizeof(arr), 0);
	p = 0;
	while (n--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int num;
			cin >> num;
			insert(num);
		}
		else
			del();
	}
	return 0;
	system("pause");
}
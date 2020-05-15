#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int ans(int weight[], int p)
{
	if (p == 1)
		return 0;
	else
	{
		sort(weight, weight + p, greater<int>()); //降序排序
		int s = weight[p - 2] + weight[p - 1]; // 贪心，算的是Huffman树里的非叶节点
		weight[p - 2] = s;
		return s + ans(weight, p - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	int weight[105] = {};
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	cout << ans(weight, n) << endl;
	return 0;
}
#include<iostream>

using namespace std;

int arr[50][2];
int dfs(int root)//根为root的树的高度
{
	if (arr[root][0] == -1 && arr[root][1] == -1)
		return 1;
	else
	{
		int lefth = 0, righth = 0;
		if (arr[root][0] > 0)//左子树非空
			lefth = dfs(arr[root][0]);
		if (arr[root][1] > 0)//右子树非空
			righth = dfs(arr[root][1]);
		return (lefth > righth ? lefth : righth) + 1;
	}
}

int main()
{
	int s;
	cin >> s;
	for (int i = 1; i <= s; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l > 0)
			arr[i][0] = l;
		if (r > 0)
			arr[i][1] = r;
	}
	int a = dfs(1);
	cout << a << endl;
	return 0;
}
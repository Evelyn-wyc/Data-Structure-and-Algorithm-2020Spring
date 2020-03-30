/*
使用深度优先搜索
*/
#include <iostream>
#include <cstring>

using namespace std;

char maze[50][50];
int already[50][50];
int dir[4][4] = { {1,0},{0,1},{-1,0},{0,-1} };
int ans = 1;

void dfs(int x, int y, int r, int c, int times)
{
	if (x == r && y == c)
	{
		ans = times;
		return;
	}
		
	for (int k = 0; k < 4; k++)
	{
		int i = x + dir[k][0];
		int j = y + dir[k][1];
		if (!already[i][j] && maze[i][j] == '.')
		{
			already[i][j] = 1;
			dfs(i, j, r, c, times+1);
			already[i][j] = 0;//回溯
		}
	}
}

int main()
{
	int r, c;
	cin >> r >> c;
	memset(maze, 0, sizeof(maze));
	memset(already, 0, sizeof(already));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> maze[i][j];
		}
	}
	already[1][1] = 1;
	dfs(1, 1, r, c, 1);
	cout << ans << endl;
	return 0;
}
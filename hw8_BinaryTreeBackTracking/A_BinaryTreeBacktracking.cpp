#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node* left;
	node* right;
}btree;

btree* build(int n, int* mid, int* post)//后序最后一个数字是根
{
	btree* b;
	if (n <= 0)
		return NULL;
	b = new btree;
	b->data = post[n - 1];
	b->left = NULL;
	b->right = NULL;
	int i = 0;
	while (post[n - 1] != mid[i])
		i++;
	b->left = build(i, mid, post);//递归建立左子数
	b->right = build(n - 1 - i, mid + i + 1, post + i);//递归建立右子数
	return b;
}

int flag = 1;
void order(btree* root)
{
	if (flag)
	{
		cout << root->data;
		flag = 0;
	}
	else
		cout << ' ' << root->data;
	if (root->left)
		order(root->left);
	if (root->right)
		order(root->right);
}

int main()
{
	int mid[100];
	int post[100];
	int i = 0, n;
	char c;
	while (cin >> n)
	{
		mid[i++] = n;
		c = cin.get();
		if (c == '\n')
			break;
	}
	i = 0;
	while (cin >> n) {
		post[i++] = n;
		c = cin.get();
		if (c == '\n')
			break;
	}
	btree* root = NULL;
	root = build(i, mid, post);
	order(root);
	return 0;
}



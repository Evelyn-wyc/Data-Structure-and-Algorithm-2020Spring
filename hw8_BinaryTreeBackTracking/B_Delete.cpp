/*#include<iostream>

using namespace std;

typedef struct node
{
	node* left;
	node* right;
	int data;
}btree;

void buildtree(int* tree, btree* b, int n)
//根据tree数组建立二叉树
{
	btree* l, * r;
	if (tree[b->data] == 0)
		return;
	if (tree[2 * b->data] == 0 && tree[2 * b->data + 1] == 0)
		//叶节点
		return;
	else
	{
		if (tree[2 * b->data] != 0)
			//有左子树
		{
			l = new btree;
			l->left = NULL;
			l->right = NULL;
			l->data = 2 * b->data;
			b->left = l;
			buildtree(tree, l, n);
		}
		if (tree[2 * b->data + 1] != 0)
			//有右子树
		{
			r = new btree;
			r->left = NULL;
			r->right = NULL;
			r->data = 2 * b->data + 1;
			b->right = r;
			buildtree(tree, r, n);
		}
	}
}

void del(int d, int n, int* tree)
{
	if (tree[d] == 0)
		return;
	tree[d] = 0;
	if (2 * d <= n)
		del(2 * d, n, tree);
	if (2 * d + 1 <= n)
		del(2 * d + 1, n, tree);
}

void preorder(btree* b)
{
	if (b != NULL)
	{
		cout << b->data << ' ';
		preorder(b->left);
		preorder(b->right);
	}
}

void inorder(btree* b)
{
	if (b != NULL)
	{
		inorder(b->left);
		cout << b->data << ' ';
		inorder(b->right);
	}
}

void postorder(btree* b)
{
	if (b != NULL)
	{
		postorder(b->left);
		postorder(b->right);
		cout << b->data << ' ';
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		//输入数据
		int n, m, d;
		cin >> n >> m;

		//建立删除结点之后的“完全”二叉树（数组）
		int tree[1050] = {};
		for (int i = 1; i <= n; i++)
			tree[i] = i;
		for (int i = 0; i < m; i++)
		{
			cin >> d;
			del(d, n, tree);
		}

		//根据删除结点之后的tree数组建立完全二叉树（链表）
		btree* b = new btree;
		b->left = NULL;
		b->right = NULL;
		b->data = 1;
		buildtree(tree, b, n);

		//前中后序输出
		if (tree[1] == 1)
		{
			preorder(b);
			cout << endl;
			inorder(b);
			cout << endl;
			postorder(b);
			cout << endl;
		}
		else
			cout << endl << endl << endl;
		delete b;
	}
	return 0;
}*/




#include<iostream>

using namespace std;

int tree[1050] = {};
int n;
void del(int d, int n, int* tree)
{
	if (tree[d] == 0)
		return;
	tree[d] = 0;
	if (2 * d <= n)
		del(2 * d, n, tree);
	if (2 * d + 1 <= n)
		del(2 * d + 1, n, tree);
}

void preorder(int root)
{
	if (tree[root] == 0 || root > n)
		return;
	cout << root << ' ';
	preorder(2 * root);
	preorder(2 * root + 1);
}

void inorder(int root)
{
	if (tree[root] == 0 || root > n)
		return;
	inorder(2 * root);
	cout << root << ' ';
	inorder(2 * root + 1);
}

void postorder(int root)
{
	if (tree[root] == 0 || root > n)
		return;
	postorder(2 * root);
	postorder(2 * root + 1);
	cout << root << ' ';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		//输入数据
		int m, d;
		cin >> n >> m;

		//建立删除结点之后的“完全”二叉树（数组）
		for (int i = 1; i <= n; i++)
			tree[i] = i;
		for (int i = 0; i < m; i++)
		{
			cin >> d;
			del(d, n, tree);
		}

		//前中后序输出
		if (tree[1] == 1)
		{
			preorder(1);
			cout << endl;
			inorder(1);
			cout << endl;
			postorder(1);
			cout << endl;
		}
		else
			cout << endl << endl << endl;
	}
	return 0;
}
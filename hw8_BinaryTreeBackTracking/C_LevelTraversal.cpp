#include<iostream>
#include<queue>

using namespace std;

int a[1002][3];

typedef struct node
{
	node* left;
	node* right;
	int data;
}btree;
btree* b;

void buildtree(btree* b)
{
	btree* l, * r;
	if (a[b->data][0] == 0 && a[b->data][1] == 0)
		return;
	else 
	{
		if (a[b->data][0])
			{
				l = new btree;
				l->left = NULL;
				l->right = NULL;
				l->data = a[b->data][0];
				b->left = l;
				buildtree(l);
			}
		if (a[b->data][1])
		{
			r = new btree;
			r->left = NULL;
			r->right = NULL;
			r->data = a[b->data][1];
			b->right = r;
			buildtree(r);
		}
	}
}

void leveltra(btree* b)
{
	if (b == NULL)
		return;
	queue<btree*> q;
	q.push(b);
	while (q.empty() == false)
	{
		btree* node = q.front();
		cout << node->data << ' ';
		q.pop();
		//左子节点入队
		if (node->left != NULL)
			q.push(node->left);
		//右子节点入队
		if (node->right != NULL)
			q.push(node->right);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		a[i][0] = l;
		a[i][1] = r;
		a[l][2] = i;
		a[r][2] = i;
	}
	int rt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i][2] == 0)
		{
			rt = i;
			break;
		}
	}
	b = new btree;
	b->left = NULL;
	b->right = NULL;
	b->data = rt;
	buildtree(b);
	leveltra(b);
	return 0;
}
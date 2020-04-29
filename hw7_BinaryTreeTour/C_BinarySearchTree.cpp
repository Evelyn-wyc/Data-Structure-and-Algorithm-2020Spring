#include<iostream>

using namespace std;

typedef struct node
{
	struct node* left;
	struct node* right;
	int data;
}btree;
btree* b;

void order(btree* root)
{
	if (root != NULL)
	{
		cout << root->data << ' ';
		order(root->left);
		order(root->right);
	}
}

int main()
{
	int s;
	cin >> s;
	btree *poi, *cur;
	b = new btree;
	b->left = NULL;
	b->right = NULL;
	b->data = s;
	while (cin >> s)
	{
		poi = b;
		cur = new btree;
		cur->data = s;
		cur->left = NULL;
		cur->right = NULL;
		while (poi != NULL)
		{
			if (poi->data == s)
				break;
			if (s < poi->data)
			{
				if (poi->left == NULL)
				{
					poi->left = cur;
					break;
				}
				else
					poi = poi->left;
			}
			else if (s > poi->data)
			{
				if (poi->right == NULL)
				{
					poi->right = cur;
					break;
				}
				else
					poi = poi->right;
			}
		}
	}
	order(b);
	cout << endl;
	return 0;
}
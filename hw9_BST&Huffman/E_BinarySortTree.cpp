#include <iostream>

using namespace std;

typedef struct node 
{
	int data;
	node* left;
	node* right;
	node* parent;
}btree;
btree* b;

int main()
{
	int num;
	cin >> num;
	if (num != 0)
		cout << num << " inserted" << endl;
	else
		return 0;
	b = new btree;
	b->data = num;
	b->left = NULL;
	b->right = NULL;
	b->parent = NULL;
	btree* poi, * cur;
	while (cin >> num)
	{
		if (num == 0)
			break;
		poi = b;
		cur = new btree;
		cur->data = num;
		cur->left = NULL;
		cur->right = NULL;
		while (poi != NULL)
		{
			if (num < poi->data)
			{
				cout << poi->data << ' ';
				if (poi->left == NULL)
				{
					poi->left = cur;
					cur->parent = poi;
					cout << cur->data << " inserted" << endl;
					break;
				}
				else
				{
					poi = poi->left;
				}
			}
			else if (num > poi->data)
			{
				cout << poi->data << ' ';
				if (poi->right == NULL)
				{
					poi->right = cur;
					cur->parent = poi;
					cout << cur->data << " inserted" << endl;
					break;
				}
				else
				{
					poi = poi->right;
				}
			}
			else
			{
				cout << poi->data << endl;
				break;
			}
		}
		while (poi->parent != NULL)
		{
			poi = poi->parent;
		}
		b = poi;
	}
	return 0;
}
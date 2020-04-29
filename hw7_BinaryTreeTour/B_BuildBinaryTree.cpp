#include<iostream>

using namespace std;

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
}btree;
btree* b;

void createtree(char* str)
{
	char* c = str;
	btree* t = b;
	btree* s = b;
	while (*c != '\0')
	{
		switch (*c)
		{
		case '+':
			c++;
			s = new btree;
			s->left = NULL;
			s->right = NULL;
			s->data = *c;
			if (t->left == NULL)
				t->left = s;
			t = t->left;
			break;
		case '-':
			c++;
			s = new btree;
			s->left = NULL;
			s->right = NULL;
			s->data = *c;
			if (t->right == NULL)
				t->right = s;
			t = t->right;
			break;
		}
		c++;
	}
}

void order(btree* root)
{
	if (root != NULL)
	{
		order(root->left);
		cout << root->data;
		order(root->right);
	}
}

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		char str[100];
		b = new btree;
		b->left = NULL;
		b->right = NULL;
		b->data = 'A';
		cin >> n;
		int m = n + 1;
		while (m--)
		{
			cin.getline(str, 100);
			createtree(str);
		}
		order(b);
		cout << endl;
	}
	return 0;
}
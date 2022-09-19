#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct TreeNode {
	element data;
	struct TreeNode* llink, * rlink;
}TreeNode;

TreeNode* new_node(element d)
{
	TreeNode* node = malloc(sizeof(TreeNode));
	node->data = d;
	node->rlink = node->llink = NULL;
}

TreeNode* search_node(TreeNode* node, element d)
{
	if (node != NULL)
	{
		if (node->data == d)
			return node;
		else
		{
			TreeNode* tmp = search_node(node->llink, d);
			if (tmp != NULL)
				return tmp;
			else
				return search_node(node->rlink, d);
		}
	}
	return NULL;
}

void make_node(TreeNode* node, element n, element l, element r)
{
	if (l != '.')
		node->llink = new_node(l);
	if (r != '.')
		node->rlink = new_node(r);
}

void print_one(TreeNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		print_one(root->llink);
		print_one(root->rlink);
	}
}

void print_two(TreeNode* root)
{
	if (root != NULL)
	{
		print_two(root->llink);
		printf("%c", root->data);
		print_two(root->rlink);
	}
}
void print_three(TreeNode* root)
{
	if (root != NULL)
	{
		print_three(root->llink);
		print_three(root->rlink);
		printf("%c", root->data);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();
	TreeNode* root = new_node(NULL);
	TreeNode* tmp;
	for (int i = 0; i < n; i++)
	{
		element d, l, r;
		scanf("%c %c %c", &d, &l, &r);
		getchar();
		tmp = search_node(root, d);
		if (tmp != NULL)
			make_node(tmp, d, l, r);
		else
		{
			root->data = d;
			make_node(root, d, l, r);
		}
	}
	print_one(root);
	printf("\n");
	print_two(root);
	printf("\n");
	print_three(root);
	return 0;
}
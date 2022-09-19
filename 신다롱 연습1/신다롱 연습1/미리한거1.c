#include<stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* node = malloc(sizeof(TreeNode));
	node->data = item;
	node->left = node->right = NULL;
	return node;
}

TreeNode* insert_node(TreeNode* node, int n)
{
	if (node == NULL)
	{
		return new_node(n);
	}
	if (node->data > n)
	{
		node->left = insert_node(node->left, n);
	}
	else if (node->data < n)
	{
		node->right = insert_node(node->right, n);
	}
	return node;
}

void inorder(TreeNode* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("[%d] ", node->data);
		inorder(node->right);
	}
}

void preorder(TreeNode* node)
{
	if (node != NULL)
	{
		printf("[%d] ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(TreeNode* node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("[%d] ", node->data);
	}
}

void plus(TreeNode* node)
{
	if (node != NULL)
	{
		node->data += 1;
		plus(node->left);
		plus(node->right);
	}
}

int total_num(TreeNode* node)
{
	int result1 = 0;
	int result2 = 0;
	if (node != NULL)
	{
		if(node->left != NULL)
			result1 = total_num(node->left);
		if(node->right != NULL)
			result2 = total_num(node->right);
	}
	return (node->data + result1 + result2);
}

int max_num(TreeNode* node)
{
	int num;
	if (node != NULL)
	{
		num = node->data;
		if (node->left != NULL)
		{
			if (num < max_num(node->left))
				num = max_num(node->left);
		}
		if (node->right != NULL)
		{
			if (num < max_num(node->right))
				num = max_num(node->right);
		}
	}
	return num;
}

TreeNode* big_node(TreeNode* node)
{
	TreeNode* big = node;
	if (node != NULL)
	{
		if (node->left != NULL)
		{
			big = big_node(node->left);
			big = node->data > big->data ? node : big;
		}
		if (node->right != NULL)
		{
			big = big_node(node->right);
			big = node->data > big->data ? node : big;
		}
	}
	return big;
}

void xmin(TreeNode* node, int x)
{
	if (node != NULL)
	{
		xmin(node->left, x);
		if(node->data < x)
			printf("[%d] ", node->data);
		xmin(node->right, x);
	}
}

int main(void)
{
	TreeNode n10 = { 12, NULL, NULL };
	TreeNode n9 = { 500, NULL, &n10 };
	TreeNode n8 = { 200, NULL, NULL };
	TreeNode n7 = { 42, NULL, NULL };
	TreeNode n6 = { 2500, NULL, &n7 };
	TreeNode n4 = { 50, &n9, NULL };
	TreeNode n5 = { 28, NULL, &n8 };
	TreeNode n3 = { 10, &n4, &n5 };
	TreeNode n2 = { 55, &n6, NULL };
	TreeNode n1 = { 31, &n2, &n3 };
	
	inorder(&n1);
	printf("\n");
	preorder(&n1);
	printf("\n");
	postorder(&n1);
	printf("\n");

	plus(&n1);
	inorder(&n1);
	printf("\n");
	preorder(&n1);
	printf("\n");
	postorder(&n1);
	printf("\n");
	printf("총합: %d\n", total_num(&n1));
	printf("최대값: %d\n", max_num(&n1));
	TreeNode* big = big_node(&n1);
	int x;
	printf("x값을 입력하시오:");
	scanf("%d", &x);
	xmin(&n1, x);
	return 0;
}
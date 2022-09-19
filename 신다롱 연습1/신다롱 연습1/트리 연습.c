#include<stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

int calc_dir_size(TreeNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int r1 = calc_dir_size(node->llink);
	int r2 = calc_dir_size(node->rlink);
	return (node->data+ r1 + r2);
}

void show(TreeNode* node, int n)
{
	if (node != NULL)
	{
		if (node->data < n)
			printf("%d 보다 작은 노드 %d\n", n, node->data);
		show(node->llink, n);
		show(node->rlink, n);
	}
}

int one(TreeNode* node)
{
	int result = 0;
	if (node != NULL)
	{
		if (node->llink != NULL && node->rlink == NULL)
		{
			return (1 + one(node->llink));
		}
		else if (node->llink == NULL && node->rlink != NULL)
		{
			return (1 + one(node->rlink));
		}
		result = one(node->rlink) + one(node->llink);
	}
	return result;
}

int max(TreeNode* node)
{
	int num = node->data;
	if (node->llink != NULL)
	{
		if (num < max(node->llink))
			num = max(node->llink);
	}
	if (node->rlink != NULL)
	{
		if (num < max(node->rlink))
			num = max(node->rlink);
	}
	return num;
}

int min(TreeNode* node)
{
	int num = node->data;
	if (node->llink != NULL)
	{
		if (num > min(node->llink))
			num = min(node->llink);
	}
	if (node->rlink != NULL)
	{
		if (num > min(node->rlink))
			num = min(node->rlink);
	}
	return num;
}

void print(TreeNode* root)
{
	if (root != NULL)
	{
		print(root->llink);
		printf("%c", root->data);
		print(root->rlink);
	}
}

void set(TreeNode* root)
{
	if (root != NULL)
	{
		if(root->llink != NULL)
		{
			if(root->data <set(root->llink));
		printf("%c", root->data);
		set(root->rlink);
	}
}

int main(void)
{
	TreeNode n9 = { 500, NULL, NULL };
	TreeNode n8 = { 200, NULL, NULL };
	TreeNode n7 = { 42, NULL, NULL };
	TreeNode n6 = { 2500, NULL, &n7 };
	TreeNode n4 = { 50, &n9, NULL };
	TreeNode n5 = { 28, NULL, &n8 };
	TreeNode n3 = { 10, &n4, &n5 };
	TreeNode n2 = { 55, &n6, NULL };
	TreeNode n1 = { 31, &n2, &n3 };

	printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));
	int n;
	printf("입력:");
	scanf("%d", &n);
	show(&n1, n);
	printf("자식이 하나만 있는 노드 개수 : %d\n",one(&n1));

	printf("최소값 %d\n", min(&n1));
	printf("최대값 %d\n", max(&n1));
	set(&n1);
	return 0;
}
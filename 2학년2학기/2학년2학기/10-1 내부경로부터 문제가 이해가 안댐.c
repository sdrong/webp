#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef struct treeNode {
	int data;
	struct treeNode* left, *right;
}treeNode;

treeNode* new_node(int n)
{
	treeNode* node = malloc(sizeof(treeNode));
	node->data = n;
	node->left = node->right = NULL;
	return node;
}

treeNode* insert_Node(treeNode* root, int n)
{
	if (root == NULL)
		return new_node(n);
	if (root->data > n)
		root->left = insert_Node(root->left, n);
	else if (root->data < n)
		root->right = insert_Node(root->right, n);
	return root;
}

void print(treeNode* root)
{
	if (root != NULL)
	{
		print(root->left);
		printf("%d -> ", root->data);
		print(root->right);
	}
}

void search(treeNode* root, int ch_num)
{
	while (root != NULL)
	{
		if (ch_num == root->data)
		{
			printf("%d찾음\n", root->data);
			return;
		}
		if (ch_num < root->data)
			root = root->left;
		else
			root = root->right;
	}
	printf("못찾았습니다.\n");
}

treeNode* min_node(treeNode* root)
{
	treeNode* node = root;
	while (node->left != NULL)
		node = node->left;
	return node;
}

treeNode* del_node(treeNode* root, int ch_num)
{
	if (root == NULL)
		return root;
	if (ch_num < root->data)
		root = root->left;
	else if (ch_num > root->data)
		root = root->right;
	else {
		if (root->left == NULL)
		{
			treeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right = NULL)
		{
			treeNode* temp = root->left;
			free(root);
			return temp;
		}
		treeNode* temp = min_node(root->right);
		root->data = temp->data;
		root->right = del_node(root->right, temp->data);
	}
	return root;
}



int main(void)
{
	treeNode* root = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		root = insert_Node(root, rand() % 100);
	print(root);
	printf("\n");

	bool b = true;
	int ch;
	int ch_num;
	while (b)
	{
		printf("\n1.이진트리에서 검색\n");
		printf("2.이진트리에서 삽입\n");
		printf("3.이진트리에서 삭제\n");
		printf("4.이진트리 내부경로길이\n");
		printf("5.이진트리 평균 검색 성능\n");
		printf("6.이진트리의 노드의 합\n");
		printf("7.출력\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("찾을 노드 검색:");
			scanf("%d", &ch_num);
			search(root, ch_num);
			break;
		case 2:
			printf("삽입할 노드값 입력:");
			scanf("%d", &ch_num);
			insert_Node(root, ch_num);
			break;
		case 3:
			printf("삭제할 노드값 입력:");
			scanf("%d", &ch_num);
			root = del_node(root, ch_num);
			break;
		case 4:
			
			break;
		case 5:
			break;
		case 6:
			
			break;
		case 7:
			print(root);
			printf("\n");
			break;
		case 8:
			b = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
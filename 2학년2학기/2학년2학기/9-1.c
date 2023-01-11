#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* new_Node(int n)
{
	treeNode* node = malloc(sizeof(treeNode));
	node->data = n;
	node->left = node->right = NULL;
	return node;
}

treeNode* insert_Node(treeNode* root, int n)
{
	if (root == NULL)
		return new_Node(n);
	if (n < root->data)
		root->left = insert_Node(root->left, n);
	else if (n > root->data)
		root->right =  insert_Node(root->right, n);
	return root;
}

void print(treeNode* root)
{
	if (root != NULL)
	{
		print(root->left);
		printf("[%d]-> ", root->data);
		print(root->right);
	}
}

int node_cnt(treeNode* root)
{
	if (root != NULL)
		return 1 + node_cnt(root->left) + node_cnt(root->right);
	return 0;
}

int node_height(treeNode* root)
{
	if (root != NULL)
		return 1 + max(node_height(root->left), node_height(root->right));
	return 0;
}

treeNode* copy(treeNode* root, treeNode* root2)
{
	if (root != NULL) {
		printf("%d ����\n", root->data);
		root2 = insert_Node(root2, root->data);
		root2->left = copy(root->left, root2->left);
		root2->right = copy(root->right, root2->right);
	}
	return root2;
}

int compare(treeNode* root, treeNode* root2)
{
	if ((root != NULL && root2 == NULL) || (root == NULL && root2 != NULL))
		return 0;
	return ((!root&& !root2)||(root->data == root2->data)
		&&(root && root2)&&compare(root->left, root2->left)
		&& compare(root->right, root2->right));
}

int check(treeNode* root)
{
	int n = 0;
	if (root == NULL)
	{
		return n;
	}
	treeNode* left = root->left;
	treeNode* right = root->right;
	if (left != NULL)
	{
		if (root->data < left->data)
			n++;
		n += check(root->left);
	}
	if (right != NULL)
	{
		if (root->data > right->data)
			n++;
		n+=check(root->right);
	}
	printf("%d\n", n);
	return n;
}

int main(void)
{
	treeNode* root = NULL;
	srand(time(NULL));
	int key;
	for (int i = 0; i < 10; i++)
	{
		key = rand() % 100;
		printf("key : %d\n", key);
		root = insert_Node(root, key);
	}
	print(root);
	printf("\n");

	treeNode* root2 = NULL;

	bool b = true;
	int ch = 1;
	while (b)
	{
		printf("1.����Ʈ���� ��� ���� ���\n");
		printf("2.����Ʈ���� ���� ���� ���\n");
		printf("3.����Ʈ�� ������ȸ\n");
		printf("4.����Ʈ�� ��\n");
		printf("5.����Ʈ�� ����\n");
		printf("6.�����˻�Ʈ������ �Ǻ�\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("����� ������ %d\n", node_cnt(root));
			break;
		case 2:
			printf("Ʈ���� ���̴� %d\n", node_height(root));
			break;
		case 3:
			print(root);
			break;
		case 4:
			if (compare(root, root2))
				printf("�����ϴ�\n");
			else
				printf("�ٸ��ϴ�\n");
			root = insert_Node(root, 5);
			break;
		case 5:
			root2 = copy(root, root2);
			print(root2);
			printf("\n");
			break;
		case 6:
			if (check(root) == 0)
				printf("�����˻�Ʈ���Դϴ�.\n");
			else
				printf("�����˻�Ʈ���� �ƴմϴ�.\n");
			break;
		case 7:
			b = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
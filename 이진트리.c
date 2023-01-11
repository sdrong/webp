#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

typedef struct treeNode {
	int data;
	struct treeNode* left, * right;
}treeNode;

int arr[1024];
int n = 0;

void check2(treeNode* node)
{
	if (node == NULL)
		return;
	check2(node->left);
	arr[n++] = node->data;
	check2(node->right);
}

int check(treeNode* root)
{
	check2(root);
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1])
			return 1;
	}
	return 0;
}

treeNode* addNewNode(int key, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* tmp = malloc(sizeof(treeNode));
	tmp->data = key;
	tmp->left = leftNode;
	tmp->right = rightNode;
	return tmp;
}

int hasPathSum(treeNode* root, int sum, int key)
{
	int result = 0;
	if (root != NULL)
	{
		sum += root->data;
		if (root->left == NULL && root->right == NULL)
		{
			if (sum == key)
				result = 1;
		}
		else
		{
			result+= hasPathSum(root->left, sum, key);
			result+= hasPathSum(root->right, sum, key);
		}
	}
	return result;
}

int main(void)
{
	treeNode*n8=addNewNode(42,NULL,NULL);
	treeNode*n7=addNewNode(30,NULL,NULL);
	treeNode*n6=addNewNode(55,n8,NULL);
	treeNode*n5=addNewNode(15,n7,NULL); 
	treeNode*n4=addNewNode(2,NULL,NULL); 
	treeNode*n3=addNewNode(10,NULL,n6); 
	treeNode*n2=addNewNode(16,n4,n5);  
	treeNode*n1=addNewNode(22,n2,n3);
	treeNode*T1=n1;	

	treeNode* nn8 = addNewNode(42, NULL, NULL);
	treeNode* nn7 = addNewNode(20, NULL, NULL);
	treeNode* nn6 = addNewNode(55, nn8, NULL);
	treeNode* nn5 = addNewNode(18, NULL, nn7);
	treeNode* nn4 = addNewNode(2, NULL, NULL);
	treeNode* nn3 = addNewNode(30, NULL, nn6);
	treeNode* nn2 = addNewNode(16, nn4, nn5);
	treeNode* nn1 = addNewNode(22, nn2, nn3);
	treeNode* T2 = nn1;
	int use;
	int key;
	bool b = true;
	while (b)
	{
		printf("1.���� Ž�� Ʈ������ Ȯ��\n");
		printf("2.��Ʈ���� ������������ ��λ� �� �ִ��� Ȯ��\n");
		printf("�Է�:");
		scanf("%d", &use);
		switch (use)
		{
		case 1:
			if (check(T2)==0)
				printf("����Ž��Ʈ���̴�.\n");
			else
				printf("����Ʈ���̴�.\n");
			break;
		case 2:
			printf("�� �Է�:");
			scanf("%d", &key);
			if (hasPathSum(T1, 0, key))
				printf("ã�ҽ��ϴ�.\n");
			else
				printf("��ã�ҽ��ϴ�.\n");
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}
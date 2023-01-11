#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

typedef struct treeNode {
	int data;
	struct treeNode* right, * left;
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
	n = 0;
	check2(root);
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1])
			return 1;
	}
	return 0;
}

void print(treeNode* node)
{
	if (node != NULL)
	{
		print(node->left);
		printf("%2d ", node->data);
		print(node->right);
	}
}

treeNode* new_node(int key)
{
	treeNode* node = malloc(sizeof(treeNode));
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	return node;
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
			{
				printf("리프노드 %d까지의 경로의 합: %d\n", root->data, sum);
				result = 1;
			}
		}
		else
		{
			result += hasPathSum(root->left, sum, key);
			result += hasPathSum(root->right, sum, key);
		}
	}
	return result;
}

void search(treeNode* root, int key)
{
	if (root != NULL) {
		if (root->data == key)
			printf("찾았습니다.\n");
		else if (root->data > key)
			search(root->left, key);
		else
			search(root->right, key);
	}
	else
		printf("못찾았습니다.\n");
}

void S1(treeNode* root)
{
	int key;
	printf("찾을 키값 입력:");
	scanf("%d", &key);
	search(root, key);
}

treeNode* insert(treeNode* node, int key)
{
	if (node == NULL)
		node = new_node(key);
	else if (node->data < key)
	{
		node->right = insert(node->right, key);
	}
	else if (node->data > key)
	{
		node->left = insert(node->left, key);
	}
	return node;
}

treeNode* S2(treeNode* root)
{
	int key;
	printf("넣을 키값 입력:");
	scanf("%d", &key);
	root = insert(root, key);
	return root;
}

treeNode* minNode(treeNode* node)
{
	treeNode* min = node;
	while (min->left != NULL)
	{
		min = min->left;
	}
	return min;
}

treeNode* delete(treeNode* node, int key)
{
	if (node == NULL)
		return node;
	if (node->data > key)
		node->left = delete(node->left, key);
	else if (node->data < key)
		node->right = delete(node->right, key);
	else {
		if (node->left == NULL)
		{
			treeNode* tmp = node->right;               
			free(node);                         
			return tmp;                               
		}                                      
		else if (node-> right == NULL)
		{
			treeNode* tmp = node->left;
			free(node);
			return tmp;
		}
		else
		{
			treeNode* tmp = minNode(node->right);
			node->data = tmp->data;
			node->right = delete(node->right, node->data);
		}
	}
	return node;
}

treeNode* S3(treeNode* root)
{
	int key;
	printf("삭제할 키값 입력:");
	scanf("%d", &key);
	root = delete(root, key);
	return root;
}

int countNode(treeNode* node)
{
	int num = 0;
	if (node != NULL)
	{
		num += 1 + countNode(node->left) + countNode(node->right);
	}
	return num;
}

int TOTAL_IPL(treeNode* root, int n)
{
	int result = 0;
	if (root != NULL)
	{
		result += 1 + TOTAL_IPL(root->left, n+1) + TOTAL_IPL(root->right, n+1) + n;
		printf("node:%d 의 경로 길이 %d\n", root->data, n+1);
	}
	return result;
}

void S4(treeNode* root)
{
	int n = TOTAL_IPL(root, 0);
	int n2 = countNode(root);
	float r = (float)n / (float)n2;
	printf("IPL: %d\n", n);
	printf("경로의 평균 % f\n", r);
}

int main(void)
{
	treeNode* root = NULL;
	treeNode* n8 = addNewNode(42, NULL, NULL);
	treeNode* n7 = addNewNode(30, NULL, NULL);
	treeNode* n6 = addNewNode(55, n8, NULL);
	treeNode* n5 = addNewNode(15, n7, NULL);
	treeNode* n4 = addNewNode(2, NULL, NULL);
	treeNode* n3 = addNewNode(10, NULL, n6);
	treeNode* n2 = addNewNode(16, n4, n5);
	treeNode* n1 = addNewNode(22, n2, n3);
	treeNode* T1 = n1;

	treeNode* nn8 = addNewNode(42, NULL, NULL);
	treeNode* nn7 = addNewNode(31, NULL, NULL);
	treeNode* nn6 = addNewNode(55, nn8, NULL);
	treeNode* nn5 = addNewNode(18, NULL, nn7);
	treeNode* nn4 = addNewNode(2, NULL, NULL);
	treeNode* nn3 = addNewNode(30, NULL, nn6);
	treeNode* nn2 = addNewNode(16, nn4, nn5);
	treeNode* nn1 = addNewNode(22, nn2, nn3);
	treeNode* T2 = nn1;
	treeNode* user = root;
	bool b = true;
	while (b) {
		int key;
		int use;
		int u;
		printf("1. 키값 검색\n");
		printf("2. 키 삽입\n");
		printf("3. 키 삭제\n");
		printf("4. 평균검색 길이의 평균검색 성능\n");
		printf("5.이진 탐색 트리인지 확인\n");
		printf("6.루트에서 리프노드까지의 경로상 값 있는지 확인\n");
		printf("선택:");
		scanf("%d", &use);
		int n;
		switch (use)
		{
		case 1:
			S1(root);
			break;
		case 2:
			root = S2(root);
			print(root);
			printf("\n");
			break;
		case 3:
			root = S3(root);
			print(root);
			printf("\n");
			break;
		case 4:
			S4(root);
			break;
		case 5:
			printf("1. t1(이진트리)\n");
			printf("2. t2(왼쪽 서브 트리가 루트보다 큰 서브트리)\n");
			printf("3. root(이진탐색트리)\n");
			scanf("%d", &u);
			if (u == 1)
				user = T1;
			else if (u == 2)
				user = T2;
			else if (u == 3)
				user = root;
			else
			{
				printf("잘못입력했습니다\n");
				break;
			}
			if (check(user) == 0)
				printf("이진탐색트리이다.\n");
			else
				printf("이진트리이다.\n");
			break;
		case 6:
			printf("합 입력:");
			scanf("%d", &key);
			if (hasPathSum(root, 0, key))
				printf("찾았습니다.\n");
			else
				printf("못찾았습니다.\n");
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int big_num(int arr[])
{
	int big = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (big < arr[i])
			big = arr[i];
	}
	return big;
}

int small_num(int arr[])
{
	int small = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (small > arr[i])
			small = arr[i];
	}
	return small;
}

void S1(void)
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++)
		printf("[%d] ", arr[i]);

	printf("���� ū ��: %d\n", big_num(arr));
	printf("���� ���� ��: %d\n", small_num(arr));
}

//2��

int lenth(char ch[])
{
	int i = 0;
	while (ch[i] != NULL)
	{
		i++;
	}
	return i;
}

int lenth2(char ch[], int n)
{
	if (ch[n] == NULL)
		return n;
	else
		return lenth2(ch, n + 1);
		
}

void S2(void)
{
	char ch[100];
	printf("���ڿ��Է�:");
	scanf("%s", ch);
	int n = lenth(ch);
	printf("���ڿ��� ���� �ݺ�:%d\n", n);
	int n2 =lenth2(ch, 0);
	printf("���ڿ��� ���� ��ȯ:%d\n", n2);

}

//S3

void change(int num1, int num2)
{
	if (num1 < num2)
	{
		if (num1 % num2 >= 10)
		{
			printf("%c", 'A' + (num1 % num2 - 10));
		}
		else
			printf("%d", num1 % num2);
	}
	else
	{
		change(num1 / num2, num2);
		if (num1 % num2 >= 10)
		{
			printf("%c", 'A' + (num1 % num2 - 10));
		}
		else
			printf("%d", num1 % num2);
	}
}

void S3(void)
{
	int num1, num2;
	printf("���������Է�: ");
	scanf("%d", &num1);
	printf("�ٲ� ����(2~16) �Է�: ");
	scanf("%d", &num2);
	change(num1, num2);
	printf("(%d)\n", num2);
}

//S4

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}


void inorder(TreeNode* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("[%d] ", node->key);
		inorder(node->right);
	}
}

void del(TreeNode* node)
{
	if (node != NULL)
	{
		del(node->left);
		del(node->right);
		free(node);
	}
}

int hight(TreeNode* node)
{
	int high = 0;
	if (node != NULL)
		high = 1 + max((hight(node->left)), hight(node->right));
	return high;
}


void S4(void)
{
	TreeNode* root = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		root = insert_node(root,num);
		printf("%d����\n", num);
	}
	inorder(root);
	printf("���� %d\n", hight(root));
	del(root);
}


int main(void)
{
	bool b = true;
	while (b)
	{
		printf("\n1.�ִ� �ּҰ�\n");
		printf("2.���ڿ��� ����\n");
		printf("3.������ȯ\n");
		printf("4,����Ʈ�� ���̿� ������ȸ\n");
		printf("�׿�.����\n");
		printf("�Է�");
		int ch;
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			S1();
			break;
		case 2:
			S2();
			break;
		case 3:
			S3();
			break;
		case 4:
			S4();
			break;
		default:
			b = false;
			break;
		}
	}
}
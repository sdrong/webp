#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define MAX(a,b) (a)

typedef struct AVLNode
{
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
}AVLNode;

int get_height(AVLNode* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

int get_balance(AVLNode* node)
{
	if (node == NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key)
{
	AVLNode* node = malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

AVLNode* rotate_right(AVLNode* parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

AVLNode* rotate_left(AVLNode* parent)
{
	AVLNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}


void inorder(AVLNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
		return(create_node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key)
	{
		printf("LL회전\n");
		return rotate_right(node);
	}
	if (balance < -1 && key > node->right->key)
	{
		printf("RR회전\n");
		return rotate_left(node);
	}
	if (balance > 1 && key > node->left->key)
	{
		printf("LR회전\n");
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		printf("RL회전\n");
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

AVLNode* minNode(AVLNode* node)
{
	AVLNode* min = node;
	while (min->left != NULL)
	{
		min = min->left;
	}
	return min;
}

AVLNode* delete(AVLNode* node, int key)
{
	if (node == NULL)
		return node;

	if (key < node->key)
		node->left = delete(node->left, key);
	else if (key > node->key)
		node->right = delete(node->right, key);
	else
	{
		if ((node->left == NULL) || (node->right == NULL))
		{
			AVLNode* tmp = NULL;
			if (tmp == node->left)
				tmp = node->right;
			else
				tmp = node->left;
			if (tmp == NULL)
			{
				tmp = node;
				node = NULL;
			}
			else {
				node = tmp;
			}
		}
		else {
			AVLNode* tmp = minNode(node->right);
			node->key = tmp->key;
			node->right = delete(node->right, tmp->key);
		}
	}

	if (node == NULL)
		return node;


	int balance = get_balance(node);

	if (balance > 1 && get_balance(node->left) >= 0)
	{
		printf("LL회전\n");
		return rotate_right(node);
	}
	if (balance > 1 && get_balance(node->left) < 0)
	{
		printf("LR회전\n");
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && get_balance(node->right) <= 0)
	{
		printf("RR회전\n");
		return rotate_left(node);
	}
	if (balance < -1 && get_balance(node->right) > 0)
	{
		printf("RL회전\n");
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

void all_height(AVLNode* root)
{
	if (root != NULL)
	{
		all_height(root->left);
		printf("[%d]의 높이 %d ", root->key, get_height(root));
		all_height(root->right);
	}
}

int main(void)
{
	AVLNode* root = NULL;
	bool b = true;
	int u;
	int key;
	while (b)
	{
		printf("1. 키 삽입\n");
		printf("2. 키 삭제\n");
		printf("3. 각 노드의 높이\n");
		printf("선택:");
		scanf("%d", &u);
		switch (u)
		{
		case 1:
			printf("입력: ");
			scanf("%d", &key);
			root = insert(root, key);
			inorder(root);
			printf("\n");
			printf("높이: %d\n", get_height(root));
			break;
		case 2:
			printf("입력: ");
			scanf("%d", &key);
			root = delete(root, key);
			inorder(root);
			printf("\n");
			printf("높이: %d\n", get_height(root));
			break;
		case 3:
			all_height(root);
			printf("\n");
			break;
		default:
			b = false;
			break;
		}
	}

	return 0;
}

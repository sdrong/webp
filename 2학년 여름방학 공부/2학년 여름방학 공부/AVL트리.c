#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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
		height = 1 + get_height(node->left) + get_height(node->right);

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


void preorder(AVLNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
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
	printf("balance: %d\n", balance);
	preorder(node);
	printf("\n");

	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}


int main(void)
{
	AVLNode* root = NULL;
	printf("add 10 \n");
	root = insert(root, 10);
	printf("add 20 \n");
	root = insert(root, 20);
	printf("add 30 \n");
	root = insert(root, 30);
	printf("add 40 \n");
	root = insert(root, 40);
	printf("add 50 \n");
	root = insert(root, 50);
	printf("add 29 \n");
	root = insert(root, 29);

	printf("전위 순회 결과\n");
	preorder(root);

	return 0;
}
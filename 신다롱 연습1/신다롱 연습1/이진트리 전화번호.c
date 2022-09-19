#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
	char name[MAX_WORD_SIZE];
	char p_num[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

int compare(element e1, element e2)
{
	return strcmp(e1.name, e2.name);
}

void display(TreeNode* p)
{
	if (p != NULL)
	{
		display(p->left);
		printf("이름: %s\n전화번호: %s\n\n", p->key.name, p->key.p_num);
		display(p->right);
	}
}

TreeNode* search(TreeNode* root, element key)
{
	TreeNode* p = root;
	while (p != NULL)
	{
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p;
}

TreeNode* new_node(element item)
{
	TreeNode* temp = malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key)
{
	if (node == NULL)
		return new_node(key);
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL)
		return root;
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

int get_low_level(TreeNode* node, int level) //가장 낮은 레벨
{
	if (node == NULL)
		return 0;
	int num = level > (get_low_level(node->left, level + 1)) ? level : (get_low_level(node->left, level + 1));
	num = num > (get_low_level(node->right, level + 1)) ? num : (get_low_level(node->right, level + 1));
	return  num;
}

void level_x(TreeNode* node, int level, int x) { //지정된 레벨의 개수 출력
	if (node != NULL)
	{
		if(level == x)
			printf("레벨 %d: %s %s\n", level, node->key.name, node->key.p_num);
		else
		{
			level_x(node->left, level + 1, x);
			level_x(node->right, level + 1, x);
		}
	}
}

void help()
{
	printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main(void)
{
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		getchar();
		switch (command)
		{
		case 'i':
			printf("친구의 이름:");
			gets_s(e.name, MAX_WORD_SIZE);
			printf("친구의 전화번호:");  
			gets_s(e.p_num, MAX_MEANING_SIZE);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("친구의 이름:");
			gets_s(e.name, MAX_WORD_SIZE);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("친구의 이름:");
			gets_s(e.name, MAX_WORD_SIZE);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("전화번호:%s\n", e.p_num);
			else
				printf("찾지 못하였습니다.\n");
			break;
		case 'q':
			break;
		default:
			printf(".\n");
			break;
		}
	} while (command != 'q');
	int low = get_low_level(root, 1);
	for (int i = 1; i <= low; i++)
		level_x(root, 1, i);
	return 0;
}
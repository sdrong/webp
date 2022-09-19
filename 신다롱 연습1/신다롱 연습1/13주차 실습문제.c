#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct element
{
	char name[20];
	int num;
}element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

int compare(char* e1, char* e2)
{
	return strcmp(e1, e2);
}

TreeNode* new_node(char* data)
{
	int len = strlen(data);
	TreeNode* node = malloc(sizeof(TreeNode));
	strcpy(node->data.name, data);
	node->data.num = 1;
	node->left = NULL;
	node->right = NULL;
	printf("새노드\n");
	return node;
}

TreeNode* add_node(TreeNode* root, char* data)
{
	if (root == NULL)
		return new_node(data);
	if (compare(data, root->data.name) < 0)
		root->left = add_node(root->left, data);
	else if (compare(data, root->data.name) > 0)
		root->right = add_node(root->right, data);
	else
		printf("추가댐\n");
	return root;
}

int inorder(TreeNode* root, char* data)
{
	int result = 0;
	if (root != NULL)
	{
		if (strcmp(root->data.name, data) == 0)
		{
			root->data.num += 1;
			return 1;
		}
		if (strcmp(root->data.name, data) > 0)
			result += inorder(root->left, data);
		else if (strcmp(root->data.name, data) < 0)
			result += inorder(root->right, data);
	}
	else
		return result;
}

TreeNode* judgment(TreeNode* root, char* data)
{
	char d[20][11] = { "break", "case", "do", "else", "for", "if", "int", "return", "switch", "while" };
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(d[i], data) == 0)
		{
			printf("조건만족 %s\n", data);
			if (inorder(root, data))
				break;
			else
				root = add_node(root, data);
		}
	}
	return root;
}

void print_copy(TreeNode* node, FILE* fp)
{
	if (node != NULL)
	{
		print_copy(node->left, fp);
		printf("[ %s %d ]-> ", node->data.name, node->data.num);
		fprintf(fp, "[ %s %d ]-> ", node->data.name, node->data.num);
		print_copy(node->right, fp);
	}
}

void print(TreeNode* node)
{
	if (node != NULL)
	{
		print(node->left);
		printf("[ %s %d ]-> ", node->data.name, node->data.num);
		print(node->right);
	}
}

TreeNode* many_node(TreeNode* node)
{
	TreeNode* big = node;
	TreeNode* left = node;
	TreeNode* right = node;
	if (node != NULL)
	{
		if (node->left != NULL)
		{
			left = many_node(node->left);
			left = node->data.num > left->data.num ? node : left;
		}
		if (node->right != NULL)
		{
			right = many_node(right->right);
			right = node->data.num > right->data.num ? node : right;
		}
	}
	big = left->data.num > right->data.num ? left : right;
	return big;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, char* name)
{
	if (root == NULL)
		return root;
	if (compare(name, root->data.name) < 0)
		root->left = delete_node(root->left, name);
	if (compare(name, root->data.name) > 0)
		root->right = delete_node(root->right, name);
	else if (compare(name, root->data.name) == 0)
	{
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
		strcpy(root->data.name, temp->data.name);
		root->data.num = temp->data.num;
		root->right = delete_node(root->right, temp->data.name);
	}
	return root;
}

int main(void)
{
	char data[30];
	TreeNode* root = NULL;
	FILE* fp1 = fopen("bst_in.txt", "r");
	if (fp1 == NULL) {
		printf("파일 오픈 실패");
		exit(1);
	}
	FILE* fp2 = fopen("bst_out.txt", "w");
	if (fp2 == NULL) {
		printf("파일 오픈 실패");
		exit(1);
	}
	char d[20][11] = { "break", "case", "do", "else", "for", "if", "int", "return", "switch", "while" };
	char ch[300000];
	fread(ch, 1, sizeof(ch), fp1);
	ch[299999] = NULL;
	printf("%d\n", strlen(ch));
	char* tmp = strtok(ch, " ");
	char* tmp2 = strstr(tmp, d[0]);
	while (tmp != NULL)
	{
		for (int i = 0; i < 11; i++)
		{
			tmp2 = strstr(tmp, d[i]);
			if (tmp2 != NULL)
				break;
		}
		root = judgment(root, tmp2);
		tmp = strtok(NULL, " ");
	}

	print_copy(root, fp2);
	TreeNode* many = many_node(root);
	printf("\n가장 개수가 많은 노드: %s %d\n", many->data.name, many->data.num);
	char user[30];
	while (1)
	{
		printf("삭제할 노드를 입력('exit'입력시 탈출) :");
		scanf("%s", user);
		if (strcmp(user, "exit") == 0)
			break;
		root = delete_node(root, user);
		printf("\n");
		print(root);
	}

	for (int i = 0; i < 11; i++)
	{
		root = delete_node(root, d[i]);
	}

	printf("\n");
	print(root);

	fflush(stdin);
	fclose(fp1);
	fclose(fp2);
	return 0;
}


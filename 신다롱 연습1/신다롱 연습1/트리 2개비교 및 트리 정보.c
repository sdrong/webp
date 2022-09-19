#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int calc_dir_size(TreeNode* root)
{
	int left_size, right_size;
	if (root == NULL)
		return 0;
	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);
	return (root->data+left_size + right_size);
}

int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = get_node_count(node->left) + get_node_count(node->right) + 1;
	return count;
}

int get_leaf_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

int get_nonterminal_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		if (node->left != NULL || node->right != NULL)
			count = 1 + get_nonterminal_count(node->left) + get_nonterminal_count(node->right);
	}
	return count;
}
int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}

int equal(TreeNode* node, TreeNode* nnode)
{
	return ((!node && !nnode)||(node->data==nnode->data) 
		&& (node && nnode) && equal(node->left, nnode->left) 
		&& equal(node->right, nnode->right));
}

int main(void)
{
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5};
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	TreeNode nn4 = { 500, NULL, NULL };
	TreeNode nn5 = { 200, NULL, NULL };
	TreeNode nn3 = { 100, &nn4, &nn5 };
	TreeNode nn2 = { 50, NULL, NULL };
	TreeNode nn1 = { 0, &nn2, &nn3 };

	printf("노드 개수: %d\n", get_node_count(&n1));
	printf("단말 노드 개수: %d\n", get_leaf_count(&n1));
	printf("비단말 노드 개수: %d\n", get_nonterminal_count(&n1));
	printf("높이: %d\n", get_height(&n1));
	if (equal(&n1, &nn1))
	{
		printf("동일\n");
	}
	else
	{
		printf("같지 않음\n");
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

void preorder(TreeNode* node)
{
	if (node != NULL)
	{
		printf("[%d] ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(TreeNode* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("[%d] ", node->data);
		inorder(node->right);
	}
}

void postorder(TreeNode* node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("[%d] ", node->data);
	}
}

void plus(TreeNode* node)
{
	if (node != NULL)
	{
		plus(node->left);
		node->data += 1;
		plus(node->right);
	}
}

TreeNode* big_node(TreeNode* node)
{
	TreeNode* big = node;
	TreeNode* left = node;
	TreeNode* right = node;
	if (node != NULL)
	{
		if (node->left != NULL)
		{
			left = big_node(node->left);
			left = node->data > left->data ? node : left;
		}
		if (node->right != NULL)
		{
			right = big_node(right->right);
			right = node->data > right->data ? node : right;
		}
	}
	big = left->data > right->data ? left : right;
	return big;
}

int one_node(TreeNode* node)
{
	int result = 0;
	if (node != NULL)
	{
		if (node->left != NULL && node->right == NULL)
		{
			return (1 + one_node(node->left));
		}
		else if (node->left == NULL && node->right != NULL)
		{
			return (1 + one_node(node->right));
		}
		result = one_node(node->right) + one_node(node->left);
	}
	return result;
}


int equal(TreeNode* node, TreeNode* nnode)
{
	return ((!node && !nnode) || ((node->data == nnode->data) && (node && nnode) && equal(node->left, nnode->left) && equal(node->right, nnode->right)));
}

TreeNode* copy_node(TreeNode* node, TreeNode* co_node)
{
	if (co_node == NULL)
		return NULL;
	else
	{
		TreeNode* tmp = malloc(sizeof(TreeNode));
		tmp->data = co_node->data;
		tmp->right = copy_node(tmp->right, co_node->right);
		tmp->left = copy_node(tmp->left, co_node->left);
		return tmp;
	}
}

int main(void)
{

	TreeNode n10 = { 20, NULL, NULL }; //7 
	TreeNode n9 = { 12, NULL, &n10 }; //6 
	TreeNode n8 = { 750, NULL, &n9 }; //5
	TreeNode n7 = { 30, &n8, NULL };//4
	TreeNode n6 = { 34, NULL, &n7 };//3
	TreeNode n5 = { 200, NULL, NULL };//3
	TreeNode n4 = { 400, NULL, NULL };//3
	TreeNode n3 = { 100, &n4, NULL }; //2
	TreeNode n2 = { 50, &n5, &n6 };  //2
	TreeNode n1 = { 40, &n2, &n3 }; //1

	TreeNode nn10 = { 712, NULL, NULL }; //8 
	TreeNode nn9 = { 742, NULL, &nn10 }; //7 
	TreeNode nn8 = { 63, NULL, &nn9 }; //6
	TreeNode nn7 = { 70, &nn8, NULL };//5
	TreeNode nn6 = { 30, NULL, NULL };//5
	TreeNode nn5 = { 20, &nn7, &nn6 };//4
	TreeNode nn4 = { 900, NULL, &nn5 };//3
	TreeNode nn3 = { 12, NULL, NULL }; //3
	TreeNode nn2 = { 51, &nn3, &nn4 };  //2
	TreeNode nn1 = { 53, &nn2, NULL }; //1

	TreeNode nnn10 = { 422, NULL, NULL }; //6 
	TreeNode nnn9 = { 42, NULL, NULL }; //6
	TreeNode nnn8 = { 63, NULL, NULL }; //6
	TreeNode nnn7 = { 71, &nnn8, &nnn9 };//5
	TreeNode nnn6 = { 37, NULL, &nnn10 };//5
	TreeNode nnn5 = { 20, &nnn7, &nnn6 };//4
	TreeNode nnn4 = { 410, NULL, &nnn5 };//3
	TreeNode nnn3 = { 100, NULL, NULL }; //3
	TreeNode nnn2 = { 50, &nnn3, &nnn4 };  //2
	TreeNode nnn1 = { 30, &nnn2, NULL }; //1

	TreeNode temp = { 40, NULL, NULL };

	bool b = true;
	TreeNode* big = NULL;
	TreeNode* copy = &temp;


	while (b)
	{
		printf("1.중위, 전위, 후위순회\n");
		printf("2.PLUS\n");
		printf("3.최대값 노드 반환\n");
		printf("4.자식노드 하나인 트리 개수 반환\n");
		printf("5.이진트리 동일한지 확인\n");
		printf("6.이진트리 복사\n");
		printf("이외 종료\n");
		printf("입력:");
		int n;
		scanf("%d", &n);
		int num1, num2;
		switch (n)
		{
		case 1:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 하나 선택");
			printf("입력:");
			scanf("%d", &num1);
			if (num1 == 1)
			{
				preorder(&n1);
				printf("\n");
				inorder(&n1);
				printf("\n");
				postorder(&n1);
				printf("\n");
			}
			else if (num1 == 2)
			{
				preorder(&nn1);
				printf("\n");
				inorder(&nn1);
				printf("\n");
				postorder(&nn1);
				printf("\n");
			}
			else if (num1 == 3)
			{
				preorder(&nnn1);
				printf("\n");
				inorder(&nnn1);
				printf("\n");
				postorder(&nnn1);
				printf("\n");
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		case 2:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 하나 선택");
			printf("입력:");
			scanf("%d", &num1);
			if (num1 == 1)
			{
				plus(&n1);
			}
			else if (num1 == 2)
			{
				plus(&nn1);
			}
			else if (num1 == 3)
			{
				plus(&nnn1);
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		case 3:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 하나 선택");
			printf("입력:");
			scanf("%d", &num1);
			if (num1 == 1)
			{
				big = big_node(&n1);
				printf("가장 큰 값: %d\n", big->data);
			}
			else if (num1 == 2)
			{
				big = big_node(&nn1);
				printf("가장 큰 값: %d\n", big->data);
			}
			else if (num1 == 3)
			{
				big = big_node(&nnn1);
				printf("가장 큰 값: %d\n", big->data);
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		case 4:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 하나 선택");
			printf("입력:");
			scanf("%d", &num1);
			if (num1 == 1)
			{
				printf("자식노드가 하나인 노드의 개수: %d개\n", one_node(&n1));
			}
			else if (num1 == 2)
			{
				printf("자식노드가 하나인 노드의 개수: %d개\n", one_node(&nn1));
			}
			else if (num1 == 3)
			{
				printf("자식노드가 하나인 노드의 개수: %d개\n", one_node(&nnn1));
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		case 5:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 두개 선택");
			printf("입력:");
			scanf("%d %d", &num1, &num2);
			if (num1 != 1 && num2 != 1)
			{
				if (equal(&nn1, &nnn1))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
			}
			else if (num1 != 2 && num2 != 2)
			{
				if (equal(&n1, &nnn1))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
			}
			else if (num1 != 3 && num2 != 3)
			{
				if (equal(&n1, &nn1))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		case 6:
			printf("\n");
			printf("1.n1 2.nn1 3.nnn1 중 하나 선택");
			printf("입력:");
			scanf("%d", &num1);
			if (num1 == 1)
			{
				copy = copy_node(copy, &n1);
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");
				printf("n1과 copy 비교\n");
				if (equal(&n1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
				printf("n1 증가 후 출력\n");
				plus(&n1);
				preorder(&n1);
				printf("\n");
				inorder(&n1);
				printf("\n");
				postorder(&n1);
				printf("\n");

				printf("copy출력\n");
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");
				printf("n1과 copy 비교\n");
				if (equal(&n1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
			}
			else if (num1 == 2)
			{
				copy = copy_node(copy, &nn1);
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");

				printf("nn1과 copy 비교\n");
				if (equal(&nn1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
				printf("nn1 증가 후 출력\n");
				plus(&nn1);
				preorder(&nn1);
				printf("\n");
				inorder(&nn1);
				printf("\n");
				postorder(&nn1);
				printf("\n");

				printf("copy출력\n");
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");
				printf("nn1과 copy 비교\n");
				if (equal(&nn1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}

			}
			else if (num1 == 3)
			{
				copy = copy_node(copy, &nnn1);
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");
				printf("nnn1과 copy 비교\n");
				if (equal(&nnn1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
				printf("nnn1 증가 후 출력\n");
				plus(&nnn1);
				preorder(&nnn1);
				printf("\n");
				inorder(&nnn1);
				printf("\n");
				postorder(&nnn1);
				printf("\n");

				printf("copy출력\n");
				preorder(copy);
				printf("\n");
				inorder(copy);
				printf("\n");
				postorder(copy);
				printf("\n");
				printf("nnn1과 copy 비교\n");
				if (equal(&nnn1, copy))
				{
					printf("동일\n");
				}
				else
				{
					printf("같지 않음\n");
				}
			}
			else
				printf("잘못 선택 하셧습니다.\n");
			break;
		default:
			b = false;
			break;
		}
	}
	printf("종료\n");
	return 0;
}
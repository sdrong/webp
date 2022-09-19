#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백 상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;
	init_queue(&q);
	if (ptr == NULL)
		return;
	enqueue(&q, ptr);
	while (!is_empty(&q))
	{
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

int level_x(TreeNode* node, int level, int x) { //지정된 레벨의 개수 출력
	if (node == NULL)
		return 0;

	if (level == x) 
		return 1;
	else
		return level_x(node->left, level + 1, x) + level_x(node->right, level + 1, x);
}

int get_low_level(TreeNode* node, int level) //가장 낮은 레벨
{
	if (node == NULL)
		return 0;
	int num = level > (get_low_level(node->left, level + 1)) ? level : (get_low_level(node->left, level + 1));
	num = num > (get_low_level(node->right, level + 1)) ? num : (get_low_level(node->right, level + 1));
	return  num;
}

bool is_balance(TreeNode* node) //균형인지 비교
{
	if (node != NULL)
	{
		if((get_low_level(node->left, 1)- get_low_level(node->right, 1) < 2) && (get_low_level(node->left, 1) - get_low_level(node->right, 1)> -2) && is_balance(node->left) && is_balance(node->right))
			return true;
		else
			return false;
	}
	else
		return true;
}

void swap(TreeNode* node) //두개 바꿔줌
{
	if (node != NULL)
	{
		TreeNode* tmp = node->left;
		node->left = node->right;
		node->right = tmp;
		swap(node->left);
		swap(node->right);
	}
}

TreeNode* new_node(int item)
{
	TreeNode* node = malloc(sizeof(TreeNode));
	node->data = item;
	node->left = node->right = NULL;
	return node;
}

TreeNode* insert_node(TreeNode* node, int n)
{
	if (node == NULL)
	{
		return new_node(n);
	}
	if (node->data > n)
	{
		node->left = insert_node(node->left, n);
	}
	else if (node->data < n)
	{
		node->right = insert_node(node->right, n);
	}
	return node;
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

void preorder(TreeNode* node)
{
	if (node != NULL)
	{
		printf("[%d] ", node->data);
		preorder(node->left);
		preorder(node->right);
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


int main(void)
{

	/*
				     n1
			n2		            n3
		n6	   n12	         n4	     n5
		  n7               n9 n12      n8
		                n10
	*/
	TreeNode n12 = { 5, NULL, NULL };
	TreeNode n11 = { 3, NULL, NULL };
	TreeNode n10 = { 12, NULL, NULL };//5
	TreeNode n9 = { 500, NULL, &n10 };//4
	TreeNode n8 = { 200, NULL, NULL };//4
	TreeNode n7 = { 42, NULL, NULL };//4
	TreeNode n6 = { 2500, NULL, &n7 };//3
	//TreeNode n4 = { 50, &n9, NULL };//3
	TreeNode n4 = { 50, &n9, &n12 };
	TreeNode n5 = { 28, NULL, &n8 };//3
	TreeNode n3 = { 10, &n4, &n5 }; //2
	//TreeNode n2 = { 55, &n6, NULL }; //2
	TreeNode n2 = { 55, &n6, &n11 }; //2
	TreeNode n1 = { 31, &n2, &n3 }; //1

	inorder(&n1);
	printf("\n");
	preorder(&n1);
	printf("\n");
	postorder(&n1);
	printf("\n");
	level_order(&n1);
	printf("\n");
	int x;
	printf("개수를 알고 싶은 레벨을 입력하시오:");
	scanf("%d", &x);
	printf("%d레벨의 개수:%d \n", x, level_x(&n1, 1, x));
	printf("최 하단 레벨%d \n", get_low_level(&n1, 1));
	if (is_balance(&n1))
		printf("균형트리입니다.\n");
	else
		printf("균형트리가 아닙니다.\n");
	printf("변경 전\n");
	level_order(&n1);
	printf("변경 후\n");
	swap(&n1);
	level_order(&n1);
	return 0;
}
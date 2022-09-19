#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct Listnode* link;
}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* insert_last(ListNode* head, element value)
{
	if (head == NULL)
	{
		return insert_first(head, value);
	}
	ListNode* tmp = malloc(sizeof(ListNode));
	tmp = head;
	while (tmp->link != NULL)
	{
		tmp = tmp->link;
	}
	ListNode* p = malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	tmp->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

element get_entry(ListNode* head, int index)
{
	ListNode* tmp = head;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->link;
	}
	return tmp->data;
}

int get_length(ListNode* head)
{
	int result = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		result++;
	return result;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

ListNode* add_list(ListNode* head, ListNode* head2) //�ΰ� ���ϱ�
{
	if (head == NULL)
		return head2;
	else if (head2 == NULL)
		return head;
	else
	{
		ListNode* total = head;
		while (total->link != NULL)
			total = total->link;
		total->link = head2;
		return head;
	}
}

ListNode* reverse(ListNode* head) // ������
{
	ListNode* tmp = head;
	ListNode* result = NULL;
	while (tmp != NULL)
	{
		result = insert_first(result, tmp->data);
		tmp = tmp->link;
	}
	return result;
}
/*
ListNode* del_find(ListNode* head, char find[]) //ã�Ƽ� ���ֱ�
{
	ListNode* tmp = head;
	ListNode* tmp2 = NULL;
	while (strcmp(tmp->data, find) != 0 && tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->link;
	}
	if (strcmp(tmp->data, head->data) == 0)
	{
		head = delete_first(head);
		return head;
	}
	else if (tmp == NULL)
	{
		printf("�����Ұ��� ã�� ���Ͽ����ϴ�.\n");
		return head;
	}
	ListNode* tmp3 = tmp2->link;
	tmp2->link = tmp3->link;
	return head;
}*/
ListNode* sort_list(ListNode* head) //����Ʈ �������� ����
{
	ListNode* base;
	base = head;
	for (; base->link != NULL; base = base->link)
	{
		for (ListNode* p = base->link; p != NULL; p = p->link)
		{
			if (base->data > p->data)
			{
				element temp = base->data;
				base->data = p->data;
				p->data = temp;
			}
		}
	}
	return head;
}

ListNode* sort_list(ListNode* head) //����Ʈ �������� ����
{
	ListNode* base;
	base = head;
	for (; base->link != NULL; base = base->link)
	{
		for (ListNode* p = base->link; p != NULL; p = p->link)
		{
			if (base->data > p->data)
			{
				element temp = base->data;
				base->data = p->data;
				p->data = temp;
			}
		}
	}
	return head;
}

void show_head(ListNode* head) //����Ʈ ��� ���
{
	printf("%d\n", head->data);
}

void show_tail(ListNode* head) //����Ʈ �� ���
{
	ListNode* p;
	p = head;
	while (p->link != NULL)
	{
		p = p->link;
	}
	printf("%d\n", p->data);
}

ListNode* del_odd_number(ListNode* head, int n) //Ȧ���� �����ϱ�
{
	ListNode* tmp = head;
	for (int i = 0; i < n - 1; i++)
	{
		if (i == 0)
		{
			head = delete_first(head);
			continue;
		}
		else if (i % 2 == 0)
			head = delete(head, tmp);
		tmp = tmp->link;
	}
	return head;
}

ListNode* alternate(ListNode* head, ListNode* head2) //�ϳ��� ��������
{
	ListNode* head3 = NULL;
	ListNode* h1 = head;
	ListNode* h2 = head2;
	while (h1 != NULL && h2 != NULL)
	{
		head3 = insert_last(head3, h1->data);
		head3 = insert_last(head3, h2->data);
		h1 = h1->link;
		h2 = h2->link;
	}
	if (h1 == NULL)
	{
		while (h2 != NULL)
		{
			head3 = insert_last(head3, h2->data);
			h2 = h2->link;
		}
	}
	else
	{
		while (h1 != NULL)
		{
			head3 = insert_last(head3, h1->data);
			h1 = h1->link;
		}
	}
	return head3;
}

ListNode* merge(ListNode* head1, ListNode* head2)//�������� �����Ͽ� ���� ����� ��
{
	ListNode* head3 = NULL;
	ListNode* h1 = head1;
	ListNode* h2 = head2;
	while (h1 != NULL & h2 != NULL)
	{
		if (h1->data < h2->data)
		{
			head3 = insert_last(head3, h1->data);
			h1 = h1->link;
		}
		else if (h1->data > h2->data)
		{
			head3 = insert_last(head3, h2->data);
			h2 = h2->link;
		}
		else
		{
			head3 = insert_last(head3, h1->data);
			head3 = insert_last(head3, h2->data);
			h1 = h1->link;
			h2 = h2->link;
		}
	}
	if (h1 != NULL)
	{
		while (h1 != NULL)
		{
			head3 = insert_last(head3, h1->data);
			h1 = h1->link;
		}
	}
	else
	{
		while (h1 != NULL)
		{
			head3 = insert_last(head3, h2->data);
			h2 = h2->link;
		}
	}
	return head3;
}

void split(ListNode* head, ListNode** head2, ListNode** head3)//Ȧ�� ¦�� ��° �� 2���� ����Ʈ ������
{
	ListNode* tmp = head;
	int i = 1;
	for (; tmp != NULL; tmp = tmp->link)
	{
		if (i % 2 == 1)
			*head2 = insert_last(*head2, tmp->data);
		else
			*head3 = insert_last(*head3, tmp->data);
		i++;
	}
}

int main(void)
{
	ListNode* head = NULL;
	printf("head�� ����� ���� : ");
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		printf("%d��° ���� �Է�:", i + 1);
		scanf("%d", &num);
		head = insert_last(head, num);
	}
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	split(head, &head2, &head3);
	print_list(head2);
	print_list(head3);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int num[MAX_STACK_SIZE];
	int top;
}Stack_Type;

void init(Stack_Type* s)
{
	s->top = -1;
}

int is_empty(Stack_Type* s)
{
	return (s->top == -1);
}

int is_full(Stack_Type* s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stack_Type* s, element n)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화에러입니다.\n");
		exit(1);
	}
	s->data[++(s->top)] = n;
}

void push_2(Stack_Type* s, int n)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화에러입니다.\n");
		exit(1);
	}
	s->num[++(s->top)] = n;
}
element pop(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->data[(s->top)--];
}
int pop_2(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->num[(s->top)--];
}
element peek(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->data[s->top];
}
int peek_2(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->num[s->top];
}

void check(element* data)
{
	char ch;
	Stack_Type s;
	init(&s);
	int op1, op2;
	int value;
	char* temp = strtok(data, " ");
	while (temp != NULL)
	{
		ch = temp[0];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != '<' && ch != '>' && ch != '=' && ch != '|' && ch != '&')
		{
			value = atoi(temp);
			push_2(&s, value);
			printf("push:%d\n", value);
			temp = strtok(NULL, " ");
		}
		else
		{
			ch = temp[0];
			op1 = pop_2(&s);
			printf("op1 pop:%d\n", op1);
			op2 = pop_2(&s);
			printf("op2 pop:%d\n", op2);
			switch (ch)
			{
			case '+':
				printf("=====================================================\n");
				printf("%d + %d = %d\n", op2, op1, op2 + op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 + op1);
				printf("push:%d\n", op2 + op1);
				temp = strtok(NULL, " ");
				break;
			case '-':
				printf("=====================================================\n");
				printf("%d - %d = %d\n", op2, op1, op2 - op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 - op1);
				printf("push:%d\n", op2 - op1);
				temp = strtok(NULL, " ");
				break;
			case '*':
				printf("=====================================================\n");
				printf("%d * %d = %d\n", op2, op1, op2 * op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 * op1);
				printf("push:%d\n", op2 * op1);
				temp = strtok(NULL, " ");
				break;
			case '/':
				printf("=====================================================\n");
				printf("%d / %d = %d\n", op2, op1, op2 / op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 / op1);
				printf("push:%d\n", op2 / op1);
				temp = strtok(NULL, " ");
				break;
			case '^':
				printf("=====================================================\n");
				printf("%d ^ %d = %.0f\n", op2, op1, pow(op2, op1));
				printf("=====================================================\n\n");
				push_2(&s, pow(op2, op1));
				printf("push:%.0f\n", pow(op2, op1));
				temp = strtok(NULL, " ");
				break;
			case '%':
				printf("=====================================================\n");
				printf("%d %% %d = %d\n", op2, op1, op2 % op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 % op1);
				printf("push:%d\n", (op2 % op1));
				temp = strtok(NULL, " ");
				break;
			case '>':
				printf("=====================================================\n");
				printf("%d > %d = %d\n", op2, op1, op2 > op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 > op1);
				printf("push:%d\n", op2 > op1);
				temp = strtok(NULL, " ");
				break;
			case '<':
				printf("=====================================================\n");
				printf("%d < %d = %d\n", op2, op1, op2 < op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 < op1);
				printf("push:%d\n", op2 < op1);
				temp = strtok(NULL, " ");
				break;
			case '=':
				printf("=====================================================\n");
				printf("%d == %d = %d\n", op2, op1, op2 == op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 == op1);
				printf("push:%d\n", op2 == op1);
				temp = strtok(NULL, " ");
				break;
			case '&':
				printf("=====================================================\n");
				printf("%d & %d = %d\n", op2, op1, op2 && op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 && op1);
				printf("push:%d\n", op2 == op1);
				temp = strtok(NULL, " ");
				break;
			case '|':
				printf("=====================================================\n");
				printf("%d | %d = %d\n", op2, op1, op2 || op1);
				printf("=====================================================\n\n");
				push_2(&s, op2 || op1);
				printf("push:%d\n", op2 || op1);
				temp = strtok(NULL, " ");
				break;
			default:
				break;
			}
		}
	}
	printf("=====================================================\n");
	printf("result: %d\n", pop_2(&s));
	printf("=====================================================\n\n");
}

int prec(char ch)
{
	switch (ch)
	{
	case '(':
	case ')':
		return 0;
	case '|':
		return 1;
	case '&':
		return 2;
	case '=':
		return 3;
	case '<':
	case '>':
		return 4;
	case '+':
	case '-':
		return 5;
	case '*':
	case '/':
	case '%':
		return 6;
	case '^':
		return 7;
	default:
		break;
	}
}

void change(char* data)
{
	char ch, open_ch;
	int len = strlen(data);
	char* temp = malloc(sizeof(char) * MAX_STACK_SIZE);
	int t = 0;
	int a = 0;
	Stack_Type s;
	init(&s);
	for (int i = 0; i < len; i++)
	{
		ch = data[i];
		switch (ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '&':
		case '|':
		case '=':
		case '%':
		case '<':
		case '>':
		case '^':
			if (!is_empty(&s) && ch == '^' && peek(&s) == '^')
			{
				temp[t++] = ' ';
				push(&s, ch);
				printf("push: %c", ch);
				break;
			}
			temp[t++] = ' ';
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
			{
				temp[t] = pop(&s);
				printf("pop:%c\n", temp[t++]);
				temp[t++] = ' ';
			}
			push(&s, ch);
			printf("push:%c\n", ch);
			break;
		case '(':
			push(&s, ch);
			printf("push:%c\n", ch);
			break;
		case ')':
			open_ch = pop(&s);
			printf("pop:%c\n", open_ch);
			while (open_ch != '(')
			{
				temp[t++] = ' ';
				temp[t++] = open_ch;
				open_ch = pop(&s);
				printf("pop:%c\n", open_ch);
			}
			break;
		default:
			temp[t++] = ch;
			break;
		}
	}
	while (!is_empty(&s))
	{
		temp[t++] = ' ';
		temp[t] = pop(&s);
		printf("pop:%c\n", temp[t++]);
	}
	temp[t] = NULL;
	printf("후위 표기식으로 변환: %s\n", temp);
	check(temp);
	free(temp);
}

int main(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("중위표기식을 입력하시오:");
	scanf("%[^\n]s", data);
	change(data);
	return 0;
}


// (4+9-1)%(2+1)
// 3+2^3^2–1
// 3+4–2>2*3^2
// 3+4–2>2*2^2&(5–3)%2<5*2
//  2*(10+2)-32
// 23*2+(1+3*3)
// (1-13)+3^2^3

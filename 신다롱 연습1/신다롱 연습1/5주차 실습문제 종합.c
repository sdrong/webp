#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
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

element pop(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->data[(s->top)--];
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
//1번
void check1(char* p)
{
	int ch, open_ch;
	int len = strlen(p);
	Stack_Type s;
	init(&s);
	Stack_Type n;
	init(&n);
	int num = 1;
	for (int i = 0; i < len; i++)
	{
		ch = p[i];
		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			printf("%d", num);
			push(&n, num++);
			break;
		case ')':
		case ']':
		case '}':
			if (is_empty(&s))
			{
				printf("괄호 오류\n");
				exit(1);
			}
			open_ch = pop(&s);
			if ((open_ch == '(' && ch != ')') ||
				(open_ch == '[' && ch != ']') ||
				(open_ch == '{' && ch != '}')) {
				printf("괄호 오류\n");
				exit(1);
			}
			printf("%d", pop(&n));
		default:
			break;
		}
	}
	printf("\n");
}


void S1(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("괄호시스템을 입력하시오:");
	scanf("%s", data);
	check1(data);
	free(data);
}

//2번
void run_lenght(char* p)
{
	element ch, ch2;
	Stack_Type s;
	init(&s);   
	Stack_Type s2;
	init(&s2);
	int len = strlen(p);
	for (int i = 0; i < len; i++)
	{
		ch = p[i];
		ch = tolower(ch);
		push(&s, ch);
	}
	int num = 1;
	for (int i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			ch = pop(&s);
			push(&s2, ch);
			if (num != 1)
				push(&s2, num + '0');
			break;
		}
		ch = pop(&s);
		ch2 = peek(&s);
		if (ch == ch2)
			num++;
		else
		{
			push(&s2, ch);
			if (num != 1)
				push(&s2, num + '0');
			num = 1;
		}
	}
	while (!is_empty(&s2))
		printf("%c", pop(&s2));
	printf("\n");
}
void S2(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("연속되는 알파벳을 입력하시오:");
	scanf("%s", data);
	run_lenght(data);
	free(data);
}

//3번
void check2(element* data)
{
	char ch;
	char ch2;
	int len = strlen(data);
	Stack_Type s;
	init(&s);
	for (int i = 0; i < len; i++)
	{
		if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
		{
			if ((data[i] >= 'A' && data[i] <= 'Z'))
			{
				data[i] = tolower(data[i]);
			}
			push(&s, data[i]);
		}
	}
	int n = s.top;
	int n2 = 0;
	for (int i = 0; i < n / 2; i++)
	{
		ch = pop(&s);
		ch2 = data[n2++];
		while (ch2 > 'z' || ch2 < 'a')
			ch2 = data[n2++];
		printf("%c %c\n", ch, ch2);
		if (ch != ch2)
		{
			printf("회문이 아닙니다.\n");
			exit(1);
		}
	}
	printf("회문입니다.\n");
}

void S3(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("입력:");
	getchar();
	scanf("%[^\n]s", data);
	check2(data);
	free(data);
}

//4번

void check(element* data)
{
	char ch;
	int op1, op2;
	int value;
	Stack_Type s;
	init(&s);
	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		ch = data[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^' && ch != '<' && ch != '>' && ch != '&' && ch != '|' && ch != '=')
		{
			value = ch - '0';
			push(&s, value);
		}
		else
		{
			op1 = pop(&s);
			op2 = pop(&s);
			switch (ch)
			{
			case '+':
				printf("%d + %d = %d\n", op2, op1, op2 + op1);
				push(&s, op2 + op1);
				break;
			case '-':
				printf("%d - %d = %d\n", op2, op1, op2 - op1);
				push(&s, op2 - op1);
				break;
			case '*':
				printf("%d * %d = %d\n", op2, op1, op2 * op1);
				push(&s, op2 * op1);
				break;
			case '/':
				printf("%d / %d = %d\n", op2, op1, op2 / op1);
				push(&s, op2 / op1);
				break;
			case '^':
				printf("%d ^ %d = %.0f\n", op2, op1, pow(op2, op1));
				push(&s, pow(op2, op1));
				break;
			case '&':
				printf("%d & %d = %d\n", op2, op1, op2 && op1);
				push(&s, op2 && op1);
				break;
			case '|':
				printf("%d | %d = %d\n", op2, op1, op2 || op1);
				push(&s, op2 || op1);
				break;
			case '=':
				printf("%d = %d = %d\n", op2, op1, op2 == op1);
				push(&s, op2 == op1);
				break;
			case '>':
				printf("%d > %d = %d\n", op2, op1, op2 > op1);
				push(&s, op2 > op1);
				break;
			case '<':
				printf("%d < %d = %d\n", op2, op1, op2 < op1);
				push(&s, op2 < op1);
				break;
			}
		}
	}
	printf("%d", pop(&s));
}

void S4(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("후위표기식을 입력하시오:");
	scanf("%s", data);
	check(data);
}

int main(void)
{
	int n;
	while (1)
	{
		printf("1.괄호검사\n2.숫자압축\n3.회문검사\n4.후위연산\n0.종료\n");
		scanf("%d", &n);
		if (n == 1)
			S1();
		else if (n == 2)
			S2();
		else if (n == 3)
			S3();
		else if (n == 4)
			S4();
		else if (n == 0)
		{
			printf("종료\n");
			break;;
		}
		else
		{
			printf("다시입력\n");
		}
		
	}
	return 0;
}
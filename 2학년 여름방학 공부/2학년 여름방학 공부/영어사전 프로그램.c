#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y) = (t))
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define SIZE 5

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;
element list[SIZE];

int main(void)
{
	int i, j;
	element temp;
	
	printf("5개의 단어와 뜻을 입력하시오\n");
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%d번째 단어 입력:", i+1);
		scanf("%s", list[i].word);
		printf("뜻 입력:");
		scanf("%s", list[i].meaning);
	}
	
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = i + 1; j < SIZE; j++)
		{
			if (strcmp(list[i].word, list[j].word) > 0)
				SWAP(list[i], list[j], temp);
		}
	}

	printf("정렬후 사전 출력\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("단어:%s  / 뜻:%s \n", list[i].word, list[i].meaning);
	}
	return 0;
}
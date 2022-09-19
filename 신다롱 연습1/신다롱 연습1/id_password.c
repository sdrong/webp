#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct user {
	char id[11];
	char pass[7];
}User;

void Put_Pass(User* you, User* arr, int base, int count);

void Print(User* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%s %s\n", arr[i].id, arr[i].pass);
}

void Sort(User* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(arr[i].id, arr[j].id) > 0)
			{
				User temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int Search_ID(User* you, User* arr, int s, int e)
{
	int mid = (s + e) / 2;
	if (s > e)
	{
		return -1;
	}
	else if (strcmp(you->id, arr[mid].id) == 0)
	{
		return mid;
	}
	else if (strcmp(you->id, arr[mid].id) < 0)
	{
		Search_ID(you, arr, s, mid - 1);
	}
	else
	{
		Search_ID(you, arr, mid + 1, e);
	}

}

int Put_id(User* you, User* arr)
{
	printf("아이디를 입력하시오:");
	scanf("%s", you->id);
	int result = Search_ID(you, arr, 0, 8);
	return result;
}

void Change_Pass(User* you, User* arr, int base)
{
	printf("변경할 비밀번호를 입력하여 주십시오:");
	scanf("%s", arr[base].pass);
	Print(arr, 9);
	printf("변경된 비밀번호를 확인하였습니다.\n");
	printf("변경이 잘 되었는지 다시 비밀번호를 입력해 보십시오:");
	scanf("%s", you->pass);
	if (strcmp(you->pass, arr[base].pass) == 0)
	{
		printf("비밀번호가 잘 변경확인되었습니다.\n");
	}
	else
	{
		printf("비밀번호를 제대로 입력하십시오.\n");
		return 0;
	}
	/*
	int choice;
	printf("다른 아이디로도 로그인 하고싶다면 1을 입력하여 주십시오:");
	scanf("%d", &choice);
	if (choice == 1)
	{
		base = Put_id(&you, arr);
		if (base == -1)
		{
			printf("없는 아이디 입니다.");
			return 0;
		}
		Put_Pass(&you, arr, base, 1);
	}
	*/
}

void Put_Pass(User* you, User* arr, int base, int count)
{
	printf("비밀번호를 입력하시오");
	scanf("%s", you->pass);
	if (strcmp(you->pass, arr[base].pass) == 0)
	{
		printf("로그인 되어습니다.\n");
		printf("비밀번호를 바꾸시고 싶으시면 1을 입력하시오:");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
			Change_Pass(you, arr, base);
	}
	else
	{
		printf("틀렸습니다(%d회 오류 3번 오류시 종료)\n", count);
		if (count == 3)
		{
			printf("3회 오류이므로 종료합니다.\n");
			return 0;
		}
		count++;
		Put_Pass(you, arr, base, count);
	}
}

int main(void)
{
	User arr[9] = {
		{"apple","123411"},
		{"banana", "234599"},
		{"orange","345688"},
		{"peach","456777"},
		{"tomato", "567866"},
		{"lemon","678955"},
		{"melon","135744"},
		{"watermelon","357333"},
		{"strawberry", "246222"},
	};
	Sort(arr, 9);
	Print(arr, 9);
	User you;
	int base = Put_id(&you, arr);
	if (base == -1)
	{
		printf("없는 아이디 입니다.");
		return 0;
	}
	Put_Pass(&you, arr, base, 1);
	Print(arr, 9);
	printf("종료\n");
	return 0;
}
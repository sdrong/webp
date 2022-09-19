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
	printf("���̵� �Է��Ͻÿ�:");
	scanf("%s", you->id);
	int result = Search_ID(you, arr, 0, 8);
	return result;
}

void Change_Pass(User* you, User* arr, int base)
{
	printf("������ ��й�ȣ�� �Է��Ͽ� �ֽʽÿ�:");
	scanf("%s", arr[base].pass);
	Print(arr, 9);
	printf("����� ��й�ȣ�� Ȯ���Ͽ����ϴ�.\n");
	printf("������ �� �Ǿ����� �ٽ� ��й�ȣ�� �Է��� ���ʽÿ�:");
	scanf("%s", you->pass);
	if (strcmp(you->pass, arr[base].pass) == 0)
	{
		printf("��й�ȣ�� �� ����Ȯ�εǾ����ϴ�.\n");
	}
	else
	{
		printf("��й�ȣ�� ����� �Է��Ͻʽÿ�.\n");
		return 0;
	}
	/*
	int choice;
	printf("�ٸ� ���̵�ε� �α��� �ϰ�ʹٸ� 1�� �Է��Ͽ� �ֽʽÿ�:");
	scanf("%d", &choice);
	if (choice == 1)
	{
		base = Put_id(&you, arr);
		if (base == -1)
		{
			printf("���� ���̵� �Դϴ�.");
			return 0;
		}
		Put_Pass(&you, arr, base, 1);
	}
	*/
}

void Put_Pass(User* you, User* arr, int base, int count)
{
	printf("��й�ȣ�� �Է��Ͻÿ�");
	scanf("%s", you->pass);
	if (strcmp(you->pass, arr[base].pass) == 0)
	{
		printf("�α��� �Ǿ���ϴ�.\n");
		printf("��й�ȣ�� �ٲٽð� �����ø� 1�� �Է��Ͻÿ�:");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
			Change_Pass(you, arr, base);
	}
	else
	{
		printf("Ʋ�Ƚ��ϴ�(%dȸ ���� 3�� ������ ����)\n", count);
		if (count == 3)
		{
			printf("3ȸ �����̹Ƿ� �����մϴ�.\n");
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
		printf("���� ���̵� �Դϴ�.");
		return 0;
	}
	Put_Pass(&you, arr, base, 1);
	Print(arr, 9);
	printf("����\n");
	return 0;
}
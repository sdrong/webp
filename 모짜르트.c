#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define N 5 //�����ϱⰹ��

typedef struct sound SOUND;
typedef struct note NOTE;

int MainMenu();
int RecordMenu(NOTE* nhead[]);
int PlayMenu(NOTE* nhead[]);

void Init(SOUND* head);   //����ü �ʱ�ȭ�ϴ� �Լ�
void Piano(SOUND* head, char name[10], char key, double frq, int id); //�ǾƳ��� ������ Linked List�� ������ִ� �Լ�
void Show();  //�ǾƳ� �����ִ� �Լ�
SOUND* PlaythePiano(SOUND* head, int num); //�Ҹ����ִ��Լ�
void Practice(SOUND* head); //�������
void Recording(SOUND* head, NOTE* nhead);  //�������
void RecordNote(NOTE* nhead, double frq, int length);
void PlaytheRecord(NOTE* nhead);  //�������
int TotalLength(NOTE* nhead);
int InputKey(SOUND* head); //Ű�Է� 
void Save(NOTE* nhead[]); //�����ϱ�
void Load(NOTE* nhead); //�ҷ�����
void gotoxy(int x, int y);
void Effect(int id);

struct sound {
    char name[10];
    char key; //�ش� Ű����Ű
    double frq; //frequency
    int id;
    SOUND* next;
};
struct note {
    double frq;
    int push_time; //Ű������ �� clock�Լ���
    int length;    //���Ǳ���
    NOTE* next;
};

int main()
{
    int menu;
    int num;
    int i;

    SOUND* head;  //head����ü �����ͷ� ����
    NOTE* nhead[N];

    head = (SOUND*)malloc(sizeof(SOUND));  //�����Ҵ�
    head->next = NULL; // equals (*head).next = NULL
    for (i = 0; i < N; i++)
    {
        nhead[i] = (NOTE*)malloc(sizeof(NOTE));
        nhead[i]->next = NULL;
    }


    //�Լ�ȣ�� -�ʱ�ȭ�ϰ� ������
    Init(head);

    while (1)
    {
        system("cls");

        menu = MainMenu();

        switch (menu)
        {
        case 1:
            Show();
            Practice(head);
            break;
        case 2:
            num = RecordMenu(nhead);
            if (num == N + 1)
                break;
            Show();
            Recording(head, nhead[num - 1]);
            break;

        case 3:
            num = PlayMenu(nhead);
            if (num == N + 1)
                break;
            Show();
            PlaytheRecord(nhead[num - 1]);
            break;

        case 4:
            //for(i=0; i<N; i++)
            Save(nhead);
            break;

        case 5:
            //for(i=0; i<N; i++)
            Load(nhead[0]);
            break;
        }

    }//while end
    return 0;
}

int MainMenu()
{
    int num;

    printf("1 �����ϱ�\n");
    printf("2 �����ϱ�\n");
    printf("3 �������\n");
    printf("4 �����ϱ�\n");
    printf("5 �ҷ�����\n");
    scanf("%d", &num);

    system("cls");
    return num;

}

void Init(SOUND* head)
{
    //������ �̸�, ���ļ���, �ĺ���ȣ �־ Piano�Լ� ȣ��. �� ������ ����ü�� ����
    Piano(head, "��", 'a', 523.3, 1);
    Piano(head, "��#", 'w', 554.4, 2);
    Piano(head, "��", 's', 587.4, 3);
    Piano(head, "��#", 'e', 622.3, 4);
    Piano(head, "��", 'd', 659.3, 5);
    Piano(head, "��", 'f', 698.4, 6);
    Piano(head, "��#", 't', 740.0, 7);
    Piano(head, "��", 'g', 784.0, 8);
    Piano(head, "��#", 'y', 830.7, 9);
    Piano(head, "��", 'h', 880.0, 10);
    Piano(head, "��#", 'u', 932.4, 11);
    Piano(head, "��", 'j', 987.8, 12);
    Piano(head, "��", 'k', 1046.5, 13);

}
void Piano(SOUND* head, char name[10], char key, double frq, int id) //���ο� ����ü ����
{
    SOUND* newsound; //�� ����ü ����
    SOUND* cursor = head;//��ó�� Ŀ���� ��带 ����Ű�� �Ѵ�

    newsound = (SOUND*)malloc(sizeof(SOUND));
    newsound->next = NULL;

    //Piano�Լ� ���ڷ� ���� ������ ���� ���� ����ü(newsound)�� �־���
    strcpy(newsound->name, name);
    newsound->key = key;
    newsound->frq = frq;
    newsound->id = id;

    if (head->next == NULL) //��常 �ִ� ���
    {
        head->next = newsound;
    }
    else //��忡 �ٸ� ����ü�� link�Ǿ��ִ� ���
    {
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
        cursor->next = newsound;//
    }
}

void Show()
{
    printf("       ��#     ��#            ��#     ��#     ��# \n");
    printf("       (w)     (e)            (t)     (y)     (u) \n");
    printf(" ������������������������������������������������������������������\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��    *****   *****     ��    *****   *****   *****     ��      ��\n");
    printf(" ��      ��      ��      ��      ��      ��      ��      ��      ��\n");
    printf(" ��      ��      ��      ��      ��      ��      ��      ��      ��\n");
    printf(" ��      ��      ��      ��      ��      ��      ��      ��      ��\n");
    printf(" ��  ��  ��  ��  ��  ��  ��  ��  ��   �� ��  ��  ��  ��  ��  ��  ��\n");
    printf(" ��  (a) ��  (s) ��  (d) ��  (f) ��   (g)��  (h) ��  (j) ��  (k) ��\n");
    printf(" ������������������������������������������������������������������\n");
    /*SOUND* cursor = head;
    while(cursor->next != NULL)
    {
       cursor = cursor->next;
       printf("id : %d  ���̸� : %s  ���ļ� : %.1lf\n",cursor->id,cursor->name,cursor->frq);

    }
    */
}

SOUND* PlaythePiano(SOUND* head, int num)
{
    SOUND* cursor = head;

    while (cursor->next != NULL)
    {
        cursor = cursor->next;

        if (cursor->id == num) // Ŀ���� id�� num�� ����ü�� ã��
            break;
    }

    Beep(cursor->frq, 100);// ex)Beep(523.3,1000) ->1�ʰ� �����.
    return cursor;
}

void Practice(SOUND* head)
{
    int num;

    printf("\n������ �ƹ� Ű�� �Է��ϼ���");
    while (1)
    {

        num = InputKey(head);
        if (num == -1)
            break;
        else
            PlaythePiano(head, num); //�Ҹ����� �Լ� ȣ��
    }
}

int RecordMenu(NOTE* nhead[])
{
    int i, num;
    int total;

    while (1)
    {

        for (i = 0; i < N; i++)
        {
            total = TotalLength(nhead[i]);

            printf("\n %d) ����%d�� : %d.%d ��\n", i + 1, i + 1, total / 1000, total % 1000);

        }
        printf("\n\n %d) ������\n", N + 1);

        printf("\n\n��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &num);
        fflush(stdin);

        if (num < 1 || N + 1 < num)
        {
            system("cls");
            printf("\n\n��ȣ�� �߸� �����߽��ϴ�. �ٸ� ��ȣ�� �����ϼ���.!\n");
            system("pause");
            system("cls");
        }
        else if (num == N + 1)  //������
        {
            break;
        }
        else
        {
            total = TotalLength(nhead[num - 1]);

            if (total != 0)
            {
                system("cls");
                printf("\n\n�̹� �����Ǿ� �ֽ��ϴ�. �ٸ� ��ȣ�� �����ϼ���.!\n");
                system("pause");
                system("cls");
            }
            else
                break;
        }
    }


    system("cls");

    return num;
}
void Recording(SOUND* head, NOTE* nhead)
{
    int num;
    time_t push_time;  //Ű �Է����� ���� clock�Լ� ��
    NOTE* cursor = nhead;
    NOTE* newnote;
    SOUND* target;

    newnote = (NOTE*)malloc(sizeof(NOTE));
    newnote->next = NULL;
    printf("\n������ �ƹ� Ű�� �Է��ϼ���");
    while (1)
    {

        num = InputKey(head);
        push_time = clock();

        if (num == -1)
        {
            printf("\n�����̳������ϴ�\n");
            RecordNote(nhead, 0, push_time);
            break;
        }
        else
        {
            target = PlaythePiano(head, num);

            RecordNote(nhead, target->frq, push_time);
        }
    }

}
void RecordNote(NOTE* nhead, double frq, int push_time) //���ο� ����ü ����
{
    NOTE* newnote;
    NOTE* cursor = nhead;

    newnote = (NOTE*)malloc(sizeof(NOTE));
    newnote->next = NULL;

    newnote->frq = frq;
    newnote->push_time = push_time;

    if (nhead->next == NULL) //��常 �ִ� ���
    {
        nhead->next = newnote;
    }
    else //��忡 �ٸ� ����ü�� link�Ǿ��ִ� ���
    {
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }

        cursor->length = push_time - cursor->push_time;
        cursor->next = newnote;

        if (newnote->frq == 0) //������������
            newnote->length = 0;

    }
}

int PlayMenu(NOTE* nhead[])  //���� �ȵǾ��ִ� �� ������ �� ����߰�!
{
    int i, num;
    int total;

    while (1)
    {

        for (i = 0; i < N; i++)
        {
            total = TotalLength(nhead[i]);

            printf("\n %d) ����%d�� : %d.%d ��\n", i + 1, i + 1, total / 1000, total % 1000);
        }
        printf("\n\n %d) ������\n", N + 1);

        printf("\n\n��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &num);
        fflush(stdin);

        if (num < 1 || N + 1 < num)
        {
            system("cls");
            printf("\n\n��ȣ�� �߸� �����߽��ϴ�. �ٸ� ��ȣ�� �����ϼ���.!\n");
            system("pause");
            system("cls");
        }
        else if (num == N + 1)  //������
        {
            break;
        }
        else
        {
            break;
        }
    }


    system("cls");

    return num;
}
void PlaytheRecord(NOTE* nhead)
{
    NOTE* cursor = nhead;

    int i = 0;

    /*
    while(cursor->next != NULL)
    {
       cursor = cursor->next;
       Effect(cursor->frq);
       Beep(cursor->frq,cursor->length);

    }
    */

    while (cursor->next != NULL)
    {

        system("cls");

        printf("\n�� �� �� . . .");
        if (i % 3 == 0)printf("��\n");
        else if (i % 3 == 1)printf("��\n");
        else printf("��\n");
        cursor = cursor->next;
        Beep(cursor->frq, cursor->length);
        i++;
    }


}

int TotalLength(NOTE* nhead)
{
    NOTE* cursor = nhead;
    int total_length = 0;

    if (nhead->next == NULL)
    {
        total_length = 0;
    }
    else
    {
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            total_length += cursor->length;
        }
    }

    return total_length;
}

int InputKey(SOUND* head)
{
    SOUND* cursor = head;
    char input = _getch();
    fflush(stdin);

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        if (input == cursor->key)
        {
            Effect(cursor->id);
            return cursor->id;
        }
    }
    return -1;
}

void Save(NOTE* nhead[])
{
    FILE* fp;
    NOTE* cursor;
    int i = 0;

    cursor = nhead[0];

    fp = fopen("����.txt", "w+");

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        fprintf(fp, "%.1lf %d ", cursor->frq, cursor->push_time);
    }
    fprintf(fp, "0 %d", cursor->push_time); //������ ����Ǿ����� ����
    fclose(fp);

}
void Load(NOTE* nhead)
{
    FILE* fp;
    //NOTE* cursor = nhead;
    double frq;
    int push_time;

    fp = fopen("����.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%lf %d", &frq, &push_time);
        RecordNote(nhead, frq, push_time);
    }
    fclose(fp);
}

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void Effect(int id)
{



    switch (id) {
    case 1: //��
        gotoxy(4, 3); printf("��");
        gotoxy(4, 4); printf("��");
        gotoxy(4, 5); printf("��");
        gotoxy(4, 6); printf("��");
        gotoxy(4, 7); printf("��");
        gotoxy(4, 8); printf("��");
        gotoxy(4, 9); printf("���");
        gotoxy(4, 10); printf("���");
        gotoxy(4, 11); printf("���");
        Sleep(100);
        gotoxy(4, 3); printf(" ");
        gotoxy(4, 4); printf(" ");
        gotoxy(4, 5); printf(" ");
        gotoxy(4, 6); printf(" ");
        gotoxy(4, 7); printf(" ");
        gotoxy(4, 8); printf(" ");
        gotoxy(4, 9); printf("   ");
        gotoxy(4, 10); printf("   ");
        gotoxy(4, 11); printf("   ");
        gotoxy(28, 16);
        break;


    case 6: //��
        gotoxy(28, 3); printf("��");
        gotoxy(28, 4); printf("��");
        gotoxy(28, 5); printf("��");
        gotoxy(28, 6); printf("��");
        gotoxy(28, 7); printf("��");
        gotoxy(28, 8); printf("��");
        gotoxy(28, 9); printf("���");
        gotoxy(28, 10); printf("���");
        gotoxy(28, 11); printf("���");
        Sleep(100);
        gotoxy(28, 3); printf(" ");
        gotoxy(28, 4); printf(" ");
        gotoxy(28, 5); printf(" ");
        gotoxy(28, 6); printf(" ");
        gotoxy(28, 7); printf(" ");
        gotoxy(28, 8); printf(" ");
        gotoxy(28, 9); printf("   ");
        gotoxy(28, 10); printf("   ");
        gotoxy(28, 11); printf("   ");
        gotoxy(28, 16);
        break;
    }
}
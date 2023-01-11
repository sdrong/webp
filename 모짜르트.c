#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define N 5 //녹음하기갯수

typedef struct sound SOUND;
typedef struct note NOTE;

int MainMenu();
int RecordMenu(NOTE* nhead[]);
int PlayMenu(NOTE* nhead[]);

void Init(SOUND* head);   //구조체 초기화하는 함수
void Piano(SOUND* head, char name[10], char key, double frq, int id); //피아노의 음들을 Linked List로 만들어주는 함수
void Show();  //피아노 보여주는 함수
SOUND* PlaythePiano(SOUND* head, int num); //소리내주는함수
void Practice(SOUND* head); //연습모드
void Recording(SOUND* head, NOTE* nhead);  //녹음모드
void RecordNote(NOTE* nhead, double frq, int length);
void PlaytheRecord(NOTE* nhead);  //녹음듣기
int TotalLength(NOTE* nhead);
int InputKey(SOUND* head); //키입력 
void Save(NOTE* nhead[]); //저장하기
void Load(NOTE* nhead); //불러오기
void gotoxy(int x, int y);
void Effect(int id);

struct sound {
    char name[10];
    char key; //해당 키보드키
    double frq; //frequency
    int id;
    SOUND* next;
};
struct note {
    double frq;
    int push_time; //키눌렀을 시 clock함수값
    int length;    //음의길이
    NOTE* next;
};

int main()
{
    int menu;
    int num;
    int i;

    SOUND* head;  //head구조체 포인터로 선언
    NOTE* nhead[N];

    head = (SOUND*)malloc(sizeof(SOUND));  //동적할당
    head->next = NULL; // equals (*head).next = NULL
    for (i = 0; i < N; i++)
    {
        nhead[i] = (NOTE*)malloc(sizeof(NOTE));
        nhead[i]->next = NULL;
    }


    //함수호출 -초기화하고 보여줌
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

    printf("1 연습하기\n");
    printf("2 녹음하기\n");
    printf("3 녹음듣기\n");
    printf("4 저장하기\n");
    printf("5 불러오기\n");
    scanf("%d", &num);

    system("cls");
    return num;

}

void Init(SOUND* head)
{
    //각각의 이름, 주파수값, 식별번호 넣어서 Piano함수 호출. 각 음들의 구조체를 생성
    Piano(head, "도", 'a', 523.3, 1);
    Piano(head, "도#", 'w', 554.4, 2);
    Piano(head, "레", 's', 587.4, 3);
    Piano(head, "레#", 'e', 622.3, 4);
    Piano(head, "미", 'd', 659.3, 5);
    Piano(head, "파", 'f', 698.4, 6);
    Piano(head, "파#", 't', 740.0, 7);
    Piano(head, "솔", 'g', 784.0, 8);
    Piano(head, "솔#", 'y', 830.7, 9);
    Piano(head, "라", 'h', 880.0, 10);
    Piano(head, "라#", 'u', 932.4, 11);
    Piano(head, "시", 'j', 987.8, 12);
    Piano(head, "도", 'k', 1046.5, 13);

}
void Piano(SOUND* head, char name[10], char key, double frq, int id) //새로운 구조체 생성
{
    SOUND* newsound; //새 구조체 선언
    SOUND* cursor = head;//맨처음 커서는 헤드를 가리키게 한다

    newsound = (SOUND*)malloc(sizeof(SOUND));
    newsound->next = NULL;

    //Piano함수 인자로 받은 값들을 새로 만들 구조체(newsound)에 넣어줌
    strcpy(newsound->name, name);
    newsound->key = key;
    newsound->frq = frq;
    newsound->id = id;

    if (head->next == NULL) //헤드만 있는 경우
    {
        head->next = newsound;
    }
    else //헤드에 다른 구조체가 link되어있는 경우
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
    printf("       도#     레#            파#     솔#     라# \n");
    printf("       (w)     (e)            (t)     (y)     (u) \n");
    printf(" ┏━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━┓\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃    *****   *****     ┃    *****   *****   *****     ┃      ┃\n");
    printf(" ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃\n");
    printf(" ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃\n");
    printf(" ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃      ┃\n");
    printf(" ┃  도  ┃  레  ┃  미  ┃  파  ┃   솔 ┃  라  ┃  시  ┃  도  ┃\n");
    printf(" ┃  (a) ┃  (s) ┃  (d) ┃  (f) ┃   (g)┃  (h) ┃  (j) ┃  (k) ┃\n");
    printf(" ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
    /*SOUND* cursor = head;
    while(cursor->next != NULL)
    {
       cursor = cursor->next;
       printf("id : %d  계이름 : %s  주파수 : %.1lf\n",cursor->id,cursor->name,cursor->frq);

    }
    */
}

SOUND* PlaythePiano(SOUND* head, int num)
{
    SOUND* cursor = head;

    while (cursor->next != NULL)
    {
        cursor = cursor->next;

        if (cursor->id == num) // 커서로 id가 num인 구조체를 찾음
            break;
    }

    Beep(cursor->frq, 100);// ex)Beep(523.3,1000) ->1초간 도재생.
    return cursor;
}

void Practice(SOUND* head)
{
    int num;

    printf("\n끝나면 아무 키나 입력하세요");
    while (1)
    {

        num = InputKey(head);
        if (num == -1)
            break;
        else
            PlaythePiano(head, num); //소리내는 함수 호출
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

            printf("\n %d) 녹음%d번 : %d.%d 초\n", i + 1, i + 1, total / 1000, total % 1000);

        }
        printf("\n\n %d) 나가기\n", N + 1);

        printf("\n\n번호를 입력하세요 : ");
        scanf("%d", &num);
        fflush(stdin);

        if (num < 1 || N + 1 < num)
        {
            system("cls");
            printf("\n\n번호를 잘못 선택했습니다. 다른 번호를 선택하세요.!\n");
            system("pause");
            system("cls");
        }
        else if (num == N + 1)  //나가기
        {
            break;
        }
        else
        {
            total = TotalLength(nhead[num - 1]);

            if (total != 0)
            {
                system("cls");
                printf("\n\n이미 녹음되어 있습니다. 다른 번호를 선택하세요.!\n");
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
    time_t push_time;  //키 입력했을 때의 clock함수 값
    NOTE* cursor = nhead;
    NOTE* newnote;
    SOUND* target;

    newnote = (NOTE*)malloc(sizeof(NOTE));
    newnote->next = NULL;
    printf("\n끝나면 아무 키나 입력하세요");
    while (1)
    {

        num = InputKey(head);
        push_time = clock();

        if (num == -1)
        {
            printf("\n녹음이끝났습니다\n");
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
void RecordNote(NOTE* nhead, double frq, int push_time) //새로운 구조체 생성
{
    NOTE* newnote;
    NOTE* cursor = nhead;

    newnote = (NOTE*)malloc(sizeof(NOTE));
    newnote->next = NULL;

    newnote->frq = frq;
    newnote->push_time = push_time;

    if (nhead->next == NULL) //헤드만 있는 경우
    {
        nhead->next = newnote;
    }
    else //헤드에 다른 구조체가 link되어있는 경우
    {
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }

        cursor->length = push_time - cursor->push_time;
        cursor->next = newnote;

        if (newnote->frq == 0) //녹음끝냈을때
            newnote->length = 0;

    }
}

int PlayMenu(NOTE* nhead[])  //녹음 안되어있는 것 눌렀을 시 경고추가!
{
    int i, num;
    int total;

    while (1)
    {

        for (i = 0; i < N; i++)
        {
            total = TotalLength(nhead[i]);

            printf("\n %d) 녹음%d번 : %d.%d 초\n", i + 1, i + 1, total / 1000, total % 1000);
        }
        printf("\n\n %d) 나가기\n", N + 1);

        printf("\n\n번호를 입력하세요 : ");
        scanf("%d", &num);
        fflush(stdin);

        if (num < 1 || N + 1 < num)
        {
            system("cls");
            printf("\n\n번호를 잘못 선택했습니다. 다른 번호를 선택하세요.!\n");
            system("pause");
            system("cls");
        }
        else if (num == N + 1)  //나가기
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

        printf("\n재 생 중 . . .");
        if (i % 3 == 0)printf("♩\n");
        else if (i % 3 == 1)printf("♪\n");
        else printf("♬\n");
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

    fp = fopen("녹음.txt", "w+");

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        fprintf(fp, "%.1lf %d ", cursor->frq, cursor->push_time);
    }
    fprintf(fp, "0 %d", cursor->push_time); //녹음이 종료되었음을 뜻함
    fclose(fp);

}
void Load(NOTE* nhead)
{
    FILE* fp;
    //NOTE* cursor = nhead;
    double frq;
    int push_time;

    fp = fopen("녹음.txt", "r");

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
    case 1: //도
        gotoxy(4, 3); printf("■");
        gotoxy(4, 4); printf("■");
        gotoxy(4, 5); printf("■");
        gotoxy(4, 6); printf("■");
        gotoxy(4, 7); printf("■");
        gotoxy(4, 8); printf("■");
        gotoxy(4, 9); printf("■■");
        gotoxy(4, 10); printf("■■");
        gotoxy(4, 11); printf("■■");
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


    case 6: //파
        gotoxy(28, 3); printf("■");
        gotoxy(28, 4); printf("■");
        gotoxy(28, 5); printf("■");
        gotoxy(28, 6); printf("■");
        gotoxy(28, 7); printf("■");
        gotoxy(28, 8); printf("■");
        gotoxy(28, 9); printf("■■");
        gotoxy(28, 10); printf("■■");
        gotoxy(28, 11); printf("■■");
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

#include<stdio.h>
#include<Windows.h>
char arr[12][31] = {
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   0,0,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
};

void date_show();
void plus(int month, int date_);
void print_date(int month, int date_);
void del(int month, int date_);
void print_month(int month);

struct date
{
    char todo[10][50];
    int cnt = 0;
};

struct date a[12][31];

int main() {
    int month, day, date_;
    int n;
    while (1) {
        printf("\n1.추가, 2.삭제, 3.원하는 월 출력, 4.원하는 일 출력, 5.달력\n");
        scanf("%d", &n);
        if (n == 1 || n == 2 || n == 4) {
            printf("월과 일을 띄어 쓰기로 구분해주세요\n[ex)4월 5 -> 4 5]\n");
            scanf("%d %d", &month, &date_);
            if (arr[month-1][date_-1] == 0) {
                printf("없는 날짜입니다\n");
            }
        }
        else if (n == 3) {
            printf("숫자(월)만 입력해주세요\n[ex)4월 -> 4]\n");
            scanf("%d", &month);
            if (month-1 > 12) {
                printf("없는 월입니다\n");
            }
        }
        switch (n) {
        case 1: plus(month, date_); break;
        case 2: del(month, date_); break;
        case 3: print_month(month); break;
        case 4: print_date(month, date_); break;
        case 5: date_show(); break;
        default: system("cls");
        }
    }
    return 0;
}

void plus(int month, int date_) {
    printf("추가할 일을 입력해주세요\n");
    scanf("%s", a[month - 1][date_ - 1].todo[a[month - 1][date_ - 1].cnt]);
    a[month - 1][date_ - 1].cnt++;
}

void print_date(int month, int date_) {
    for (int i = 0; i < a[month - 1][date_ - 1].cnt; i++) {
        printf("%d. %s\n", i + 1, a[month - 1][date_ - 1].todo[i]);
    }
}

void print_month(int month) {
    printf("----------------------\n");
    for (int i = 0; i < 31; i++) {
        if (a[month - 1][i].cnt == 0) {
            continue;
        }
        printf("[%d일]\n", i+1);
        print_date(month, i+1);
        printf("----------------------\n");
    }
}

void del(int month, int date_) {
    int t;
    print_date(month, date_);
    printf("몇번째 것을 지우겠습니까\n");
    scanf("%d", &t);
    char* temp;
    for (int i = t - 1; i < a[month - 1][date_ - 1].cnt; i++) {
        temp = a[month - 1][date_ - 1].todo[i];
        *a[month - 1][date_ - 1].todo[i] = *a[month - 1][date_ - 1].todo[i + 1];
        *a[month - 1][date_ - 1].todo[i + 1] = *temp;
    }
    a[month-1][date_-1].cnt--;
}

void date_show() {
    printf("해야할일이 있는 날짜들은 빨간색으로 보여집니다.\n");
    int count = 2;
    for (int i = 0; i < 12; i++) {
        printf("[%d월]\n", i + 1);
        for (int k = 0; k < count; k++) {
            printf("    ");
        }
        for (int j = 0; j < 31; j++) {
            if (arr[i][j] == 0) {
                break;
            }
            if (a[i][j].cnt != 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            printf("%3d ", j + 1);
            count++;
            if (count == 6) {
                count = 0;
                printf("\n");
            }
        }
        printf("\n---------------------------\n");
    }
}
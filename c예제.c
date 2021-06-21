#define _CRT_SECURE_NO_WARNINGS //scanf 사용
#include <stdio.h>
#include <Windows.h> //문자의 색깔을 정할 수 있게 하기 위해서
#include <string.h> //strcmp, strcpy, memcpy
#include <conio.h> //getch

int i = 0; // 물건이 몇개인지 알려주는 변수

typedef struct _p {
    char name[20];
    int price;
    int count;
}Pdt; //Product 상품

int act[4] = { 1,2,3,4, }; //입고, 구매, 위치확인, 위치변경
int act_s; //입고, 구매, 폐기 중에서 숫자로 입력받기

typedef struct p
{
    int position; // ■ 물건이 존재한다. 갯수에 따라 10개 이하면 어떤 색깔 또 그 이상이면 다른 색깔로 표현하여 물건이 충분한지 부족한지 확인
    char name[20];
}position;

void Show(Pdt* p, position position_[7][7]) //현재 물품의 위치를 보여주는 함수
{
    int com;

    for (int k = 0; k < 7; k++) {
        for (int j = 0; j < 7; j++) {
            if (position_[k][j].position == 1) {
                for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                if (p[com].count <= 3) { //물품이 3개 이하면 빨간색
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                }
                if (p[com].count > 3 && p[com].count <= 10) { //물품이 3개보다 많고 10개 이하면 노랑색
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                }
                if (p[com].count > 10) { //물품이 10개보다 많으면 초록색
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                }
                printf("■");
            }
            else { //나머지 빈 자리는 흰색 빈 네모
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("□");
            }
        }
        printf("\n");
    }
}


int main()
{
    position abc = { 0, };
    Pdt ab = { 0, };
    char name[20];
    Pdt p[100] = { 0, };
    position position_[7][7]; // {0, ""},

    while (1)
    {
        printf("--------------------------------------------------\n");
        printf("\"1. 입고\", \"2. 구매\", \"3. 확인\" \"4. 위치변경\" \n");
        printf("--------------------------------------------------\n");
        scanf("%d", &act_s);
        //어떤 행동을 할지
        //입고, 구매, 확인, 위치변경 중에서 입력받기
        int com4;
        int com, com2;
        for (com = 0; act_s != act[com] && com < 3; com++);
        //무슨 행동을 할지 입력받고 
        //그 정보를 저장하는 변수 com을 만듬

        int x, y; // 배치할 위치
        int count; //입고할 상품의 개수를 입력받아서 더해주는 변수
        int mcount; //구매할 상품의 개수를 입력받아서 빼주는 변수
        int com3;

        char tt; //비밀번호를 입력받는 함수
        char pw[100] = { "1234" }; //입고할 때 입력해야하는 비밀번호 정답
        char pwcom[100] = { 0, }; //비밀번호를 입력받을 곳

        switch (com) {

        case 0: //입고
            printf("-------------------------------------------------------\n");
            printf("\n입고\n\n");
            printf("password : ");

            for (int h = 0;; h++) {
                tt = getch();
                if (tt == 13) {
                    break;
                    //enter을 입력받았다면 빠져나가기
                }
                else {
                    pwcom[h] = tt;
                    printf("*"); //누가 비밀번호를 볼 수 없도록 *로 보이도록 하기
                }
            }
            printf("\n");

            if (strcmp(pw, pwcom) == 0) {
                printf("\n어떤 상품을 입고하시겠습니까? ");
                scanf("%s", p[i].name);
                printf("그 상품의 가격은 얼마입니까? ");
                scanf("%d", &p[i].price);
                printf("상품의 개수는 몇개입니까? ");
                scanf("%d", &count);
                p[i].count += count;
                //이미 있는 상품을 추가로 입고할 때 
                //상품의 개수가 새로 정해지지 않도록 count를 새로 만들어서 += 해줌
                printf("배치\n");
                scanf("%d", &x);
                scanf("%d", &y);
                //상품의 위치 정보 입력받기
                position_[y - 1][x - 1].position = 1;
                strcpy(position_[y - 1][x - 1].name, p[i].name);
                printf("%s %d개가 성공적으로 입고되었습니다.\n", p[i].name, count);
                i++;
                //예를 들어서 첫번째 상품의 정보를 입력받았다면
                //다음에 입고받을 때 두번째 상품을 입력받기 위해서 i++ 을 해줌
                Show(&p, position_); //현재 물품의 위치정보 확인
            }
            else {
                printf("비밀번호가 잘못되었습니다.\n");
                //비밀번호를 1234가 아닌 다른 문자나 숫자가 입력되었을 때 
                //비밀번호가 잘못되었음을 알려주는 코드
            }
            break;

        case 1: //구매
            printf("\n구매\n\n");
            printf("어떤 상품을 구매하시겠습니까? ");
            scanf("%s", name); //구매할 상품의 이름 입력받기
            for (com2 = 0; strcmp(name, p[com2].name) != 0 && com2 < 3; com2++);
            //com2번째 물품의 이름이 구매하고자하는 물품의 이름과 같을 때까지 더해주기
            printf("상품을 몇개 구매하실건가요? ");
            scanf("%d", &mcount); //구매할 개수 입력받기
            if (p[com2].count - mcount < 0) {
                //구매한 만큼 물품의 개수에서 빼주기
                printf("재고가 부족합니다.\n");
            }
            p[com2].count -= mcount;
            //입력받은 물품의 수에서 구매할 물품의 수만큼 빼주기
            if (p[com2].count - mcount == 0) {
                memcpy(&p[com], &ab, sizeof(Pdt));
                memcpy(&position_[com4][com3], &abc, sizeof(position));
                //구매 후에 그 상품의 남은 개수가 0개라면 그 상품의 정보를 없애기
            }
            for (com4 = 0; com4 < 7; com4++) {
                for (com3 = 0; com3 < 7; com3++) {
                    if (strcmp(position_[com4][com3].name, name) == 0) {
                        break;
                        //전체 공간을 하나씩 확인하고 입력한 이름의 좌표가 
                        //그 좌표에 있는 상품의 이름과 같다면 for문을 떠나기
                    }
                }
                if (strcmp(position_[com4][com3].name, name) == 0) {
                    break;
                    //전체 공간을 하나씩 확인하고 입력한 이름의 좌표가 
                    //그 좌표에 있는 상품의 이름과 같다면 for문을 떠나기
                }
            }

            printf("%s은(는) %d개 남아있습니다.\n", p[com2].name, p[com2].count);
            break;

        case 2: //물품 위치정보 확인
            printf("\n물품 위치정보 확인\n\n");
            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) { //전체 물품의 위치정보를 출력하는 코드
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        //com번째 좌표에 할당된 이름이 입력받은 이름과 같다면 도형으로 출력
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3개 이하라면 빨간색
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3개 초과 10개 이하라면 노랑색
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10개 초과라면 초록색
                        }
                        printf("■");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("□");
                        //나머지 칸은 하얀색 네모로 출력
                    }
                }
                printf("\n");
            }
            break;

        case 3: //물품 위치 변경
            printf("\n물품 위치 변경\n\n");
            printf("어떤 물품의 위치를 변경하시겠습니까? ");
            scanf("%s", name);
            for (com2 = 0; com2 < 7; com2++) {
                for (com3 = 0; com3 < 7; com3++) {
                    if (strcmp(position_[com2][com3].name, name) == 0) {
                        break;
                        //전체 공간을 하나씩 확인하고 입력한 이름의 좌표가 
                        //그 좌표에 있는 상품의 이름과 같다면 for문을 떠나기
                    }
                }
                if (strcmp(position_[com2][com3].name, name) == 0) {
                    break;
                    //전체 공간을 하나씩 확인하고 입력한 이름의 좌표가 
                    //그 좌표에 있는 상품의 이름과 같다면 for문을 떠나기
                }
            }

            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) {
                    //물품의 위치를 변경하기 전에
                    //전체 물품의 위치정보를 출력하는 코드
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        //com번째 좌표에 할당된 이름이 입력받은 이름과 같다면 
                        //if문에 있는 색깔로 ■으로 출력
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3개 이하면 빨강색
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3개 초과 10개 이하면 노랑색
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10개 초과면 초록색
                        }
                        if (k == com2 && j == com3) {
                            //변경할 좌표라고 입력받은 위치에는 바뀔 물품이 있으므로
                            //파란색으로 표시되도록 하는 코드
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        }
                        printf("■");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("□");
                        //나머지 칸은 하얀색 네모로 출력
                    }
                }
                printf("\n");
            }
            printf("\n");
            printf("(파란색은 변경할 물품의 위치)\n");
            printf("\n");
            printf("어디로 변경하시겠습니까? ");
            //변경할 위치 입력받기
            scanf("%d %d", &x, &y);
            if (position_[y - 1][x - 1].position == 1) {
                printf("그 자리에는 다른 물품이 있습니다\n");
                break;
            }
            memcpy(&position_[y - 1][x - 1], &position_[com2][com3], sizeof(position));
            memcpy(&position_[com2][com3], &abc, sizeof(position));
            //변경할 좌표에 물품의 정보를 복사하고
            //빈공간의 정보를 바뀔 위치에 복사하기

            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) {
                    //물품의 위치를 변경하고 나서 다시 한 번 물품의 위치를 보여주는 코드
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3개 이하라면 빨간색
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3개 초과 10개 이하라면 노랑색
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10개 초과라면 초록색
                        }
                        printf("■");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("□");
                        //나머지는 하얀색 네모로 출력
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
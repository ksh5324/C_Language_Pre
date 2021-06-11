#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct bankBook
{
	char userName[10];
	char id[30];
	char password[30];
	double money;
	FILE* fp;
};

struct people
{
	char id[30];
	char userName[30];
	char password[30];
	int phoneNum;
	char addresss[50];
};

typedef struct bank
{
	struct bankBook bank[100];
	struct people people[20];
	int i = 0, j = 0;
}bank;

// 은행 아이디 만들기 (O)
// 통장 만들기
// 돈 넣기
// 돈 보내기
// 돈 꺼내기
// 로그인
// 액수 확인
// 비번 바꾸기
// 통장 없애기
// 기록 확인

bank bank1;

void makeBankID() { // 은행 아이디 만들기
	printf("----------은행 아이디 만들기----------\n");
	printf("사용자 이름: ");
	scanf("%s", bank1.people[bank1.j].userName);
	printf("Id: ");
	scanf("%s", bank1.people[bank1.j].id);
re:
	printf("password: ");
	for (int k = 0;; k++) {
		bank1.people[bank1.j].password[k] = getch();
		if (bank1.people[bank1.j].password[k] == 13) {
			break;
		}
		printf("*");
	}
	printf("\n");
	char bankEx[30] = { 0, };
	printf("한번 더 입력해 주세요: ");
	for (int k = 0;; k++) {
		bankEx[k] = getch();
		if (bankEx[k] == 13) {
			break;
		}
		printf("*");
	}
	if (strcmp(bank1.people[bank1.j].password, bankEx) != 0) {
		printf("\n");
		printf("틀렸습니다\n비밀번호를 다시 설정해주세요\n");
		goto re;
	}
	printf("\n전화번호: ");
	scanf("%d", &bank1.people[bank1.j].phoneNum);
	printf("주소: ");
	scanf("%s", bank1.people[bank1.j].addresss);
	bank1.i++;
}



void makeBankBook() { // 통장 생성
	int searchBankBook;
	int searchBankBookPassword;
	int num[10];
	printf("----------통장 만들기-----------\n");
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	printf("아이디: ");
	scanf("%s", userId);
	for (searchBankBook = 0; strcmp(bank1.people[bank1.j].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++);
	if (searchBankBook <= bank1.j) {
		printf("비밀번호: ");
		for (int k = 0;; k++) {
			pass[k] = getch();
			if (pass[k] == 13) {
				break;
			}
			printf("*");
		}
		printf("\n");
		for (searchBankBookPassword = 0; strcmp(bank1.people[bank1.j].id, userId) != 0 && searchBankBookPassword <= bank1.j; searchBankBookPassword++);
		if (searchBankBookPassword <= bank1.j) {
			printf("%s님 반갑습니다\n", bank1.people[bank1.j].userName);
		}
	}
	printf("계좌번호는: ");
	for (int zz = 0; zz < 10; zz++) {
		bank1.bank[bank1.i].id[zz] = rand() % 10;
		printf("%d", bank1.bank[bank1.i].id[zz]);
	}
	printf("\n");


	/*printf("\n");
	char bankEx[30] = { 0, };
	printf("한번 더 입력해 주세요: ");
	for (int k = 0;; k++) {
		bankEx[k] = getch();
		if (bankEx[k] == 13) {
			break;
		}
		printf("*");
	}
	if (strcmp(bank1.bank[bank1.i].password, bankEx) != 0) {
		printf("\n");
		printf("틀렸습니다\n비밀번호를 다시 설정해주세요\n");
		goto re;
	}*/
}

int main() {
	srand(time(NULL));
	makeBankID();
	makeBankBook();


	return 0;
}
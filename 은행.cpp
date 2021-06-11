#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

FILE* fp[20];

FILE* fpp[10];


struct bankBook
{
	char Name[10];
	char id[30];
	char password[30];
	int money = 0;
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
	struct people people[10];
	int i = 0, j = 0;
}bank;

// 은행 아이디 만들기 (O)
// 통장 만들기 (0)
// 돈 넣기 
// 돈 보내기
// 돈 꺼내기
// 액수 확인
// 비번 바꾸기
// 통장 없애기
// 기록 확인 (X)

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



int makeBankBook() { // 통장 생성
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
		else {
			return 0;
		}
	}
	printf("계좌번호는: ");
	for (int zz = 0; zz < 10; zz++) {
		bank1.bank[bank1.i].id[zz] = rand() % 10;
		printf("%d", bank1.bank[bank1.i].id[zz]);
	}
	printf("\n");
	printf("통장이름: ");
	scanf("%s", bank1.bank[bank1.i].Name);
re:
	printf("비밀번호: ");
	for (int k = 0;; k++) {
		bank1.bank[bank1.i].password[k] = getch();
		if (bank1.bank[bank1.i].password[k] == 13) {
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
	if (strcmp(bank1.bank[bank1.i].password, bankEx) != 0) {
		printf("\n");
		printf("틀렸습니다\n비밀번호를 다시 설정해주세요\n");
		goto re;
	}
	bank1.i++;
	printf("\n통장이 생성되었습니다\n");
	return 0;
}

int checkMoney() { // 액수 확인
	int searchBankBook;
	int searchBankBookPassword;
	int searchBankBookPassword2;
	int num[10];
	char pass2[30] = { 0, };
	printf("\n----------액수 확인하기-----------\n");
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	char Name[30] = { 0, };
	int bankBook;
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
		if (strcmp(bank1.people[searchBankBook].password, pass) == 0) {
			printf("%s님 반갑습니다\n", bank1.people[searchBankBook].userName);
		}
		else {
			printf("비밀번호가 틀렸습니다\n");
			return 0;
		}
	}
	else {
		printf("없는 아이디입니다\n");
		return 0;
	}
	printf("통장을 선택해주세요: ");
	scanf("%s", Name);
	for (bankBook = 0; strcmp(bank1.bank[bankBook].Name, Name) != 0 && bankBook <= bank1.i; bankBook++);
	if (bankBook <= bank1.i) {
		printf("비밀번호: ");
		for (int k = 0;; k++) {
			pass2[k] = getch();
			if (pass2[k] == 13) {
				break;
			}
			printf("*");
		}
		if (strcmp(pass2, bank1.bank[bankBook].password) == 0) {
			printf("\n잔액: ");
			printf("%d", bank1.bank[bankBook].money);
		}
		else {
			printf("비밀번호가 틀렸습니다\n");
		}
		
	}
	else {
		printf("없는 통장입니다\n");
	}
	return 0;
}

int putMoney() {
	int searchBankBook;
	int searchBankBookPassword, money = 0;
	int num[10];
	printf("\n----------돈 넣기-----------\n");
	char pass2[30] = { 0, };
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	char Name[30] = { 0, };
	int bankBook;
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
		if (strcmp(bank1.people[searchBankBook].password, pass) == 0) {
			printf("%s님 반갑습니다\n", bank1.people[searchBankBook].userName);
		}
		else {
			printf("비밀번호가 틀렸습니다\n");
			return 0;
		}
	}
	else {
		printf("없는 아이디입니다\n");
		return 0;
	}
	printf("통장을 선택해주세요: ");
	scanf("%s", Name);
	for (bankBook = 0; strcmp(bank1.bank[bankBook].Name, Name) != 0 && bankBook <= bank1.i; bankBook++);
	if (bankBook <= bank1.i) {
		printf("비밀번호: ");
		for (int k = 0;; k++) {
			pass2[k] = getch();
			if (pass2[k] == 13) {
				break;
			}
			printf("*");
		}
		if (strcmp(pass2, bank1.bank[bankBook].password) == 0) {
			printf("\n넣을 금액: ");
			int result;
			scanf("%d", &result);
			bank1.bank[bankBook].money += result;
			printf("%d원\n", bank1.bank[bankBook].money);
			printf("추가 되었습니다\n");
		}
		else {
			printf("비밀번호가 틀렸습니다\n");
		}

	}
	else {
		printf("없는 통장입니다\n");
	}
	return 0;

}

void makeFile() {
	fp[0] = fopen("통장1.txt", "w");
	fp[1] = fopen("통장2.txt", "w");
	fp[2] = fopen("통장3.txt", "w");
	fp[3] = fopen("통장4.txt", "w");
	fp[4] = fopen("통장5.txt", "w");
	fp[5] = fopen("통장6.txt", "w");
	fp[6] = fopen("통장7.txt", "w");
	fp[7] = fopen("통장8.txt", "w");
	fp[8] = fopen("통장9.txt", "w");
	fp[9] = fopen("통장10.txt", "w");
	fp[10] = fopen("통장11.txt", "w");
	fp[11] = fopen("통장12.txt", "w");
	fp[12] = fopen("통장13.txt", "w");
	fp[13] = fopen("통장14.txt", "w");
	fp[14] = fopen("통장15.txt", "w");
	fp[15] = fopen("통장16.txt", "w");
	fp[16] = fopen("통장17.txt", "w");
	fp[17] = fopen("통장18.txt", "w");
	fp[18] = fopen("통장19.txt", "w");
	fp[19] = fopen("통장20.txt", "w");

	fpp[0] = fopen("아이디1.txt", "w");
	fpp[1] = fopen("아이디2.txt", "w");
	fpp[2] = fopen("아이디3.txt", "w");
	fpp[3] = fopen("아이디4.txt", "w");
	fpp[4] = fopen("아이디5.txt", "w");
	fpp[5] = fopen("아이디6.txt", "w");
	fpp[6] = fopen("아이디7.txt", "w");
	fpp[7] = fopen("아이디8.txt", "w");
	fpp[8] = fopen("아이디9.txt", "w");
	fpp[9] = fopen("아이디10.txt", "w");
}

int main() {
	makeFile();
	srand(time(NULL));
	makeBankID();
	makeBankBook();
	putMoney();
	checkMoney();

	return 0;
}
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//FILE* fp[20];
//
//FILE* fpp[10];
//

struct bankBook
{
	char Name[10];
	char id[30];
	char password[30];
	int money;
	FILE* fp;
}; // 통장을 위한 구조체

struct people
{
	char id[30];
	char userName[30];
	char password[30];
	int phoneNum;
	char addresss[50];
}; // 사람들에 은행 아이디 및 기본정보를 위한 구조체

typedef struct bank
{
	struct bankBook bank[100];
	struct people people[10];
	int i, j;
}bank; // 은행 자체를 말하는 구조체

// 기능들 //

// 은행 아이디 만들기 (O)
// 통장 만들기 (0)
// 돈 넣기 (O)
// 돈 보내기 (O)
// 돈 꺼내기
// 액수 확인 (0)
// 비번 바꾸기
// 통장 없애기
// 기록 확인 (X)

bank bank1; // 은행 생성

void makeBankID() { // 은행 아이디 만들기
	printf("----------은행 아이디 만들기----------\n");
	printf("사용자 이름: ");
	scanf("%s", bank1.people[bank1.j].userName); // 사용자 이름 입력
	//fprintf(fpp[bank1.i], "%s\n", bank1.people[bank1.j].userName);
	printf("Id: ");
	scanf("%s", bank1.people[bank1.j].id); // 사용자 아이디 입력
	//fprintf(fpp[bank1.i], "%s\n", bank1.people[bank1.j].id);
re:
	printf("password: ");
	for (int k = 0;; k++) {
		bank1.people[bank1.j].password[k] = getch();
		if (bank1.people[bank1.j].password[k] == 13) {
			break;
		}
		printf("*");
	} // 사용자 비밀번호를 입력 받는 코드 입력시에 *로 출력되기 위한 코드
	printf("\n");
	char bankEx[30] = { 0, };
	printf("한번 더 입력해 주세요: ");
	for (int k = 0;; k++) {
		bankEx[k] = getch();
		if (bankEx[k] == 13) {
			break;
		}
		printf("*");
	} // 비밀번호 한번더 입력

	if (strcmp(bank1.people[bank1.j].password, bankEx) != 0) {
		printf("\n");
		printf("틀렸습니다\n비밀번호를 다시 설정해주세요\n");
		goto re;
	} // 틀렸을 시 다시 비밀번호 입력창으로 돌아가기

	//fprintf(fpp[bank1.i], "%s", bank1.people[bank1.j].password);
	printf("\n전화번호: ");
	scanf("%d", &bank1.people[bank1.j].phoneNum); // 전화번호 입력
	//fprintf(fpp[bank1.i], "%d\n", bank1.people[bank1.j].phoneNum);
	printf("주소: ");
	scanf("%s", bank1.people[bank1.j].addresss); // 주소 입력
	//fprintf(fpp[bank1.i], "%s\n", bank1.people[bank1.j].addresss);
	bank1.j++;
}



int makeBankBook() { // 통장 생성
	int searchBankBook;
	int searchBankBookPassword;
	int num[10];
	printf("----------통장 만들기-----------\n");
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	printf("아이디: ");
	scanf("%s", userId); // 아이디 입력
	for (searchBankBook = 0; strcmp(bank1.people[searchBankBook].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++); // 아이디가 유효한지 확인
	if (searchBankBook <= bank1.j) {
		printf("비밀번호: ");
		for (int k = 0;; k++) {
			pass[k] = getch();
			if (pass[k] == 13) {
				break;
			}
			printf("*");
		} // 비밀번호 입력
		printf("\n");
		if (strcmp(bank1.people[searchBankBook].password, pass) == 0) {
			printf("%s님 반갑습니다\n", bank1.people[searchBankBook].userName);
		} // 일치하면 출력
		else {
			return 0;
		} // 그렇지 않다면 함수 종료
	}
	printf("계좌번호는: ");
	for (int zz = 0; zz < 10; zz++) {
		bank1.bank[bank1.i].id[zz] = rand() % 10;
		printf("%d", bank1.bank[bank1.i].id[zz]);
	} // 계좌번호를 랜덤으로 지정해주기
	printf("\n");
	printf("통장이름: ");
	scanf("%s", bank1.bank[bank1.i].Name); // 통장이름 설정
re:
	printf("비밀번호: ");
	for (int k = 0;; k++) {
		bank1.bank[bank1.i].password[k] = getch();
		if (bank1.bank[bank1.i].password[k] == 13) {
			break;
		}
		printf("*");
	}// 비밀번호 설정

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
	for (searchBankBook = 0; strcmp(bank1.people[searchBankBook].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++); // 아이디 확인
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
	} // 아이디와 비밀번호 유무 상태 확인
	printf("통장을 선택해주세요: ");
	scanf("%s", Name); // 통장 선택
	for (bankBook = 0; strcmp(bank1.bank[bankBook].Name, Name) != 0 && bankBook <= bank1.i; bankBook++);
	if (bankBook <= bank1.i) {
		printf("비밀번호: ");
		for (int k = 0;; k++) {
			pass2[k] = getch();
			if (pass2[k] == 13) {
				break;
			}
			printf("*");
		} // 존재하고, 비밀번호와 일치한지 확인
		if (strcmp(pass2, bank1.bank[bankBook].password) == 0) {
			printf("\n잔액: ");
			printf("%d", bank1.bank[bankBook].money);
		} // 일치하면 잔액 확인
		else {
			printf("비밀번호가 틀렸습니다\n");
		}

	}
	else {
		printf("없는 통장입니다\n");
	}
	return 0;
}

int putMoney() { // 돈 넣기
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
	for (searchBankBook = 0; strcmp(bank1.people[searchBankBook].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++);
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
	} // 아이디 비번 확인
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

int send() {
	int searchBankBook;
	int searchBankBookPassword, money = 0;
	int num[10];
	printf("\n----------돈 보내기-----------\n");
	char pass2[30] = { 0, };
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	char Name[30] = { 0, };
	int bankBook;
	printf("아이디: ");
	scanf("%s", userId);
	for (searchBankBook = 0; strcmp(bank1.people[searchBankBook].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++);
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
			printf("보낼 계좌번호\n"); 
			int account;
			int search, p;
			scanf("%d", &account); // 계좌번호 입력
			for (search = 0; search <= bank1.i; search++) {
				if (bank1.bank[search].id == account) {
					int put;
					printf("보낼 금액\n");
					scanf("%d", &put);
					bank1.bank[bankBook].money -= put;
					bank1.bank[search].money += put;
					printf("보냈습니다.\n");
				}
			}
		}
	}
}


//
//void makeFile() {
//	fp[0] = fopen("통장1.txt", "w");
//	fp[1] = fopen("통장2.txt", "w");
//	fp[2] = fopen("통장3.txt", "w");
//	fp[3] = fopen("통장4.txt", "w");
//	fp[4] = fopen("통장5.txt", "w");
//	fp[5] = fopen("통장6.txt", "w");
//	fp[6] = fopen("통장7.txt", "w");
//	fp[7] = fopen("통장8.txt", "w");
//	fp[8] = fopen("통장9.txt", "w");
//	fp[9] = fopen("통장10.txt", "w");
//	fp[10] = fopen("통장11.txt", "w");
//	fp[11] = fopen("통장12.txt", "w");
//	fp[12] = fopen("통장13.txt", "w");
//	fp[13] = fopen("통장14.txt", "w");
//	fp[14] = fopen("통장15.txt", "w");
//	fp[15] = fopen("통장16.txt", "w");
//	fp[16] = fopen("통장17.txt", "w");
//	fp[17] = fopen("통장18.txt", "w");
//	fp[18] = fopen("통장19.txt", "w");
//	fp[19] = fopen("통장20.txt", "w");
//
//	fpp[0] = fopen("아이디1.txt", "w");
//	fpp[1] = fopen("아이디2.txt", "w");
//	fpp[2] = fopen("아이디3.txt", "w");
//	fpp[3] = fopen("아이디4.txt", "w");
//	fpp[4] = fopen("아이디5.txt", "w");
//	fpp[5] = fopen("아이디6.txt", "w");
//	fpp[6] = fopen("아이디7.txt", "w");
//	fpp[7] = fopen("아이디8.txt", "w");
//	fpp[8] = fopen("아이디9.txt", "w");
//	fpp[9] = fopen("아이디10.txt", "w");
//}

int main() {
	//makeFile();
	srand(time(NULL));
	char i[20] = { 0, };
	char k[10][20] = {"아이디추가", "통장생성", "돈넣기", "돈보내기", "액수확인"}; // 기능
	while (1)
	{
		printf("\n\"아이디추가\", \"통장생성\", \"돈넣기\", \"돈보내기\", \"액수확인\"\n"); // 기능 보여주기
		scanf("%s", i);
		int p;
		for (p = 0; p < 10; p++) {
			if (strcmp(k[p], i) == 0) {
				break;
			}
		}
		switch (p)
		{
		case 0: makeBankID(); break;
		case 1: makeBankBook(); break;
		case 2: putMoney(); break;
		case 3: send(); break;
		case 4: checkMoney(); break;
		default:
			exit(1); //그외에 다른 값이 입력된다면 종료
		}
	}
	return 0;
}
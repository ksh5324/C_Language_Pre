#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
struct student
{
	int student_num;
	char name[10];
	char address[50];
	int Phone_num;
	int kor;
	int str;
};
struct student a[100];
int len = 0;

void mix(int i) {
	struct student temp;
	for (; i < len; i++) {
		temp.student_num = a[i].student_num;
		a[i].student_num = a[i - 1].student_num;
		a[i - 1].student_num = temp.student_num;

		*temp.name = *a[i].name;
		*a[i].name = *a[i - 1].name;
		*a[i - 1].name = *temp.name;

		*temp.address = *a[i].address;
		*a[i].address = *a[i - 1].address;
		*a[i - 1].address = *temp.address;


		temp.Phone_num = a[i].Phone_num;
		a[i].Phone_num = a[i - 1].Phone_num;
		a[i - 1].Phone_num = temp.Phone_num;

		temp.kor = a[i].kor;
		a[i].kor = a[i - 1].kor;
		a[i - 1].kor = temp.kor;

		temp.str = a[i].str;
		a[i].str = a[i - 1].str;
		a[i - 1].str = temp.str;
	}
}

void p(int i) {
	printf("----------%d---------\n", i + 1);
	printf("학번: %d\n", a[i].student_num);
	printf("이름: %s\n", a[i].name);
	printf("주소: %s\n", a[i].address);
	printf("전화번호: %d\n", a[i].Phone_num);
	printf("국어점수: %d\n", a[i].kor);
	printf("알고리즘 점수: %d\n", a[i].str);
	printf("---------------------\n\n");
}
void create() {
	printf("생성\n");
	Sleep(500);
	printf("학번: ");
	scanf_s("%d", &a[len].student_num);

	printf("이름: ");
	scanf("%s", a[len].name);
	fflush(stdout);
	printf("주소: ");
	scanf("%s", a[len].address);

	printf("전화번호: ");
	scanf_s("%d", &a[len].Phone_num);

	printf("국어점수: ");
	scanf_s("%d", &a[len].kor);

	printf("알고리즘 점수: ");
	scanf_s("%d", &a[len].str);
	printf("\n\n\n");
	len++;
}

void print() {
	printf("출력\n");
	Sleep(500);
	for (int i = 0; i < len; i++) {
		p(i);
	}
	printf("\n\n\n");
}

void search() {
	printf("검색\n");
	Sleep(500);
	int Sea;
	printf("찾고싶은 학번: ");
	scanf("%d", &Sea);
	int i = 0;
	while (1) {
		if (Sea == a[i].student_num) {
			p(i); printf("\n\n\n");  break;
		}
		else {
			i++;
		}
	}
}

void delete_() {
	printf("삭제\n");
	Sleep(500);
	printf("삭제할 학번: ");
	int R;
	scanf("%d", &R);
	int i = 0;
	while (1) {
		if (R == a[i].student_num)
		{
			mix(i);
			len--;
			Sleep(300);
			printf("삭제됨\n");
			printf("\n\n\n");
			break;
		}
		else {
			i++;
		}
	}
}

void mix_2(int j, int i) {
	struct student temp;
	temp.student_num = a[j].student_num;
	a[j].student_num = a[i].student_num;
	a[i].student_num = temp.student_num;

	*temp.name = *a[j].name;
	*a[j].name = *a[i].name;
	*a[i].name = *temp.name;

	*temp.address = *a[j].address;
	*a[j].address = *a[i].address;
	*a[i].address = *temp.address;


	temp.Phone_num = a[j].Phone_num;
	a[j].Phone_num = a[i].Phone_num;
	a[i].Phone_num = temp.Phone_num;

	temp.kor = a[j].kor;
	a[j].kor = a[i].kor;
	a[i].kor = temp.kor;

	temp.str = a[j].str;
	a[j].str = a[i].str;
	a[i].str = temp.str;
}

void num() {
	printf("1.오름차순  2.내림차순\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].student_num >= a[i].student_num) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].student_num <= a[i].student_num) {
					mix_2(j, i);
				}
			}
		}
	}
	Sleep(300);
	printf("정렬됨\n\n\n\n");
}

void name() {
	printf("1.오름차순  2.내림차순\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].name[0] >= a[i].name[0]) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for(int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].name[0] <= a[i].name[0]) {
					mix_2(j, i);
				}
			}
		}
	}
}

void grade() {
	printf("1.오름차순  2.내림차순\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].str >= a[i].str) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].str <= a[i].str) {
					mix_2(j, i);
				}
			}
		}
	}
}

void Sort() {
	printf("정렬\n");
	Sleep(500);
	printf("정렬에 기준\n1.학번 2.이름//영어만 적용 3.알고리즘 성적\n");
	int c;
	c = getch() - 48;
	switch (c) {
	case 1: num(); break;
	case 2: name(); break;
	case 3: grade(); break;
	}
}

void Change() {
	printf("변경\n");
	printf("변경시킬 사람의 학번: ");
	int c;
	scanf("%d", &c);
	int i;
	for (i = 0; c != a[i].student_num; i++) {
	}
	printf("학번: ");
	scanf_s("%d", &a[i].student_num);

	printf("이름: ");
	scanf("%s", a[i].name);
	fflush(stdout);
	printf("주소: ");
	scanf("%s", a[i].address);

	printf("전화번호: ");
	scanf_s("%d", &a[i].Phone_num);

	printf("국어점수: ");
	scanf_s("%d", &a[i].kor);

	printf("알고리즘 점수: ");
	scanf_s("%d", &a[i].str);
	printf("\n\n\n");
}

int main() {
	int choose=0; 
	printf("* 이 프로그램에서 선택할시 약 0.5초 가략에 기다림이 있습니다 *\n");
	system("pause");
	system("cls");
	while (1) {
		printf("1.생성  2.검색  3.삭제  4.모두 출력  5.정렬  6.변경  7.화면삭제\n");
		choose = getch() - 48;
		switch (choose)
		{
		case 1: create(); break;
		case 2: search(); break;
		case 3: delete_(); break;
		case 4: print(); break;
		case 5: Sort(); break;
		case 6: Change(); break;
		case 7: system("cls"); break;
		}
	}
	return 0;
}
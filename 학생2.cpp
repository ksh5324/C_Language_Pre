#include<stdio.h>
#include<string.h>

struct Student {
	char name[20];
	int stuNum;
	int age;
	char address[100];
};

int main() {
	struct Student a[5];
	for (int i = 0; i < 5; i++) {
		printf("이름: ");
		scanf("%s", a[i].name);
		printf("학번: ");
		scanf("%d", &a[i].stuNum);
		printf("나이: ");
		scanf("%d", &a[i].age);
		printf("주소: ");
		scanf("%s", a[i].address);
	}
	for (int i = 0; i < 5; i++) {
		printf("이름 : %s\n", a[i].name);
		printf("나이 : %d\n", a[i].age);
		printf("학번 : %d\n", a[i].stuNum);
		printf("주소 : %s\n", a[i].address);
		printf("\n");
	}
}
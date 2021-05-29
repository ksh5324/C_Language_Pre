#include<stdio.h>
#include<string.h>

struct Student {
	char name[20];
	int stuNum;
	int age;
	char address[100];
};

int main() {
	struct Student class13[20];
	strcpy(class13[0].name, "강성훈");
	class13[0].age = 17;
	class13[0].stuNum = 1301;
	strcpy(class13[0].address, "대구시 달성군 창리로 11길");
	printf("1학년 3반 학생 정보\n");
	printf("이름 : %s\n", class13[0].name);
	printf("나이 : %d\n", class13[0].age);
	printf("학번 : %d\n", class13[0].stuNum);
	printf("주소 : %s\n", class13[0].address);
	return 0;
}
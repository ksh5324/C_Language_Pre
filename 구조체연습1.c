#include<stdio.h>
// 이름과 나이를 입력받아 출력하는 프로그램

typedef struct person
{
	char name[20];
	int age;
} Student;
int main() {
	Student me;
	printf("이름 입력 : ");
	scanf("%s", me.name);
	printf("나이 입력 : ");
	scanf("%d", &me.age);
	printf("이름: %s, 나이: %d", me.name, me.age);
	return 0;
}
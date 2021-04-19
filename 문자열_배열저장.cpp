#include<stdio.h>
// 문자열 저장하는 배열에 대하여
int main() {
	char str[] = "Hello World\n";
	printf("str=%s\n", str);
	printf("str의 크기 : %d\n", sizeof(str));
	printf("%d\n", sizeof("Hello"));
	char str1[10];
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	str1[4] = 'd';
	printf("str1=%s\n", str1);
	printf("str1=%d\n", sizeof(str1));
	return 0;
}
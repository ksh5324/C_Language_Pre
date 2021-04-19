#include<stdio.h>

int main() {
	char str[20] = "I Love you";
	str[5] = '\0';
	printf("%s\n", str);
	return 0;
}
#include<stdio.h>
#include<string.h>
int main() {
	char str[100];
	int num;
	scanf("%[^\n]", str);
	num = strlen(str);
	for (int i = num-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}
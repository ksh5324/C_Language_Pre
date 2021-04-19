#include<stdio.h>

int main() {
	char str[20];
	int i = 0;
	scanf("%s", str);
	while (str[i] == '\0') {
		printf("%c", str[i]);
		i++;
	}
	printf("   %s\n", str);
	return 0;
}
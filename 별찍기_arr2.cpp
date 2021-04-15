#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, j;
	int s = 1;
	scanf("%d", &a);
	for (j = 1; j <= a; j++) {
		s = 1;
		if (j == 1) {
			printf("1!= 1\n");
			continue;
		}
		printf("%d!= ", j);
		for (int i = j; i > 0; i--) {
			printf("%d ", i);
			s *= i;
			if (i != 1) {
				printf("* ");
			}
		}
		printf("= %d\n", s);
	}
	return 0;
}

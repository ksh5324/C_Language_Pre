#include<stdio.h>
#include<conio.h>
int main() {
	int ra[10] = { 0 };
	int num;
	for (int i = 0; ; i++) {
		num = getche() - 48;
		ra[num]++;
		putchar(32);
		if (num == 0) {
			break;
		}
	}
	printf("\n");
	for (int i = 1; i < 10; i++) {
		if (ra[i] == 0) {
			continue;
		}
		printf("%d : %d°³\n", i, ra[i]);
	}
}
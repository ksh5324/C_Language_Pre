#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void make_triangle(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 || i == n-1 || i - j == 0) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	make_triangle(n);
	return 0;
}
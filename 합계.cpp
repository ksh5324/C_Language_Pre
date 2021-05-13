#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int n;

int f(int n) {
	int sum=0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}
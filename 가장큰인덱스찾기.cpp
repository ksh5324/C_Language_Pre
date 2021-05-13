#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int n, d[110];

int f() {
	int max = 0;
	int i;
	for (i = 0; i < n-1; i++) {
		if (d[i] < d[i + 1]) {
			max = i+1;
		}
	}
	return max+1;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	printf("%d", f());
	return 0;
}
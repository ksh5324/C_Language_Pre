#include <stdio.h>
int main() {
	int i, j;
	int a;
	scanf("%d %d", &i, &j);
	if (i > j) {
		a = i;
		i = j;
		j = a;
	}
	printf("%d", j - i);

	return 0;
}
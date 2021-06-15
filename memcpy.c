#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _p {
	char name[20];
	int x;
	int y;
}Point;

int main() {
	Point p1, p2;
	strcpy(p1.name, "구조체 복사");
	p1.x = 10;
	p1.y = 20;
	memcpy(&p2, &p1, sizeof(Point));
	// p2=p1
	printf("%s %d %d", p2.name, p2.x, p2.y);
	return 0;
}
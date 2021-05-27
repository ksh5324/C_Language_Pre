#include<stdio.h>

struct Point{
	int x, y;
};

int main() {
	struct Point p = { 4, 5 };
	printf("x=%d, y=%d\n", p.x, p.y);
	p.x = 10;
	p.y = 20;
	printf("x=%d, y=%d\n", p.x, p.y);
	struct Point pp[100];
	pp[0].x = 10;
	pp[0].y = 20;

	return 0;
}
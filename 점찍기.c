#include<stdio.h>
#include<math.h>

struct Point
{
    int x, y;
};


int main(){
    struct Point p1, p2;
    p1.x=1;
    p1.y=2;
    printf("x좌표 : %d, y좌표 : %d\n", p1.x, p1.y);
    p2.x = 3;
    p2.y = 4;
    printf("x좌표 : %d, y좌표 : %d\n", p2.x, p2.y);
    return 0;
}
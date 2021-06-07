#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt", "w");
    int age[3];
    char name[3][6] = {0,};
    for(int i=0; i<3; i++){
        scanf("%s %d", name[i], &age[i]);
        fprintf("%s %d\n", name[i], age[i]);
    }
}
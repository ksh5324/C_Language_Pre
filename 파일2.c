#include<stdio.h>

int main(){
    FILE* fp = fopen("myData.txt", "w");
    fprintf(fp, "%s %d", "홍길동" ,34);
    fclose(fp);
}
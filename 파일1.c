#include<stdio.h>

int main(){
    FILE* fp;
    fp = fopen("myfile.txt", "r");
    char name[80] = "";
    int myAge;
    while(!feof(fp)){
        fscanf(fp, "%s %d", name, &myAge);
        printf("%s %d\n", name, myAge);
    }
    fclose(fp);
}
#include<stdio.h>

typedef struct Books
{
    char name[20];
    char auth[30];
    char publ[30];
    int borrowed;
}Book;

int main(){
    Book book_list[3];
    for(int i=0; i<3; i++){
        printf("책 %d 정보 입력 : ", i);
        scanf("%s%s%s", book_list[i].name,book_list[i].auth,book_list[i].publ);
        
    }
}
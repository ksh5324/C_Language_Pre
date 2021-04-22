#include <stdio.h>



int main() {

    char arr[30] = { 0 };

    int i;

    char j;

    printf("초기값을 입력하세요: ");

    scanf("%s", arr);

    while (1) {

        printf("고치고 싶은 인덱스: ");

        scanf("%d", &i);

        getchar();

        printf("바꿀 값: ");

        scanf("%c", &j);

        arr[i - 1] = j;

        printf("%s\n", arr);

    }

    return 0;

}
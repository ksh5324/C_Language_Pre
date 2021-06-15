//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//typedef struct _m {
//    int num; //계좌번호
//    int money; //입금된 돈
//}Money;
//
//Money maxMoney(Money m[], int n) {
//    Money max = m[0];
//    for (int i = 1; i < n; i++) {
//        if (max.money < m[i].money)
//            max = m[i];
//    }
//    return max;
//}
//
//int main()
//{
//    Money m[5], king; //저축왕
//    int i;
//    for (i = 0; i < 5; i++) {
//        printf("계좌번호와 금액\n");
//        m[i].num = i; //계좌번호는 자동 입력
//        scanf("%d", &m[i].money);
//    }
//    king = maxMoney(m, 5); //5명의 계좌정보를 넘김
//    printf("저축왕 %d번 %d원\n", king.num, king.money);
//    return 0;
//}
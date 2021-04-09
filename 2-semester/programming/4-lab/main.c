#include <stdio.h>

int main(){
    int i = 10; // Начинаем с 10, т.к. сумма цифр в числе с 1 разрядом никогда не будет больше 9
    int k = 0;
    int sum = 0;
    int tmp;
    while(k != 120){
        tmp = i;
        sum = 0;
        while (tmp != 0){
            sum += tmp%10;
            tmp /= 10;
        }
        if (sum == 10){
            ++k;
            if(k%12 == 1){
                printf("\n%4d\t", i);
            } else{
                printf("%4d\t", i);
            }
        }
        ++i;
    }
    return 0;
}
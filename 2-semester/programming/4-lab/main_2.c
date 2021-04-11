#include <stdio.h>

int main(){
    unsigned int i = 1;
    unsigned int array[10][12];
    unsigned int k = 0;
    unsigned int sum = 0;
    unsigned int tmp;
    while(k != 120){
        tmp = i;
        sum = 0;
        while (tmp != 0){
            sum += tmp%10;
            tmp /= 10;
        }
        if (sum == 10){
            array[k/12][k%12] = i;
            ++k;
        }
        ++i;
    }
    for(i = 0; i<10; ++i){
        for(int j = 0; j<12; ++j){
            printf("%4u\t", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
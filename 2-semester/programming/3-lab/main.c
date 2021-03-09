
#include <stdio.h>

int main(){
    short int N = 150; // number of elements
    short int sum = 0;
    short int target = N*(N+1)/2;
    for(unsigned i = 1; i <= N; ++i){
        sum+=i;
    }
    if (sum == target){
        printf("Sum of 1+2+...+%i = %i\n", N, sum);
        printf("Target sum = %i\n", target);
        puts("The required amount is equal to the received");
    } else{
        puts("Error! The required amount is not equal to the received");
        printf("Target sum = %i\n", target);
        printf("Received sum = %i\n", sum);
    }
    return 0;
}
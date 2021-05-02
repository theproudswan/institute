#define N 140000000000

#include <stdio.h>

unsigned int IsSimple(const long long unsigned n); // Функция для проверки числа на простоту

int main(){
    unsigned long long int prev = 0;
    unsigned long long int i = 1;
    unsigned long long int tmp;
    while(1){
        if(IsSimple(i+1)){
            tmp = (1 << (i+1)) - 1;
            if(IsSimple(tmp)){
                tmp =  tmp << i;
                if(tmp > N || tmp<prev)
                    return 0;
                printf("%ld\n", tmp);
                prev = tmp;
            }
        }
        ++i;
    }
}

unsigned int IsSimple(const long long unsigned n){
    for (long long unsigned i = 2; i*i <= n; ++i){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

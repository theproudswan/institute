#include <stdio.h>

#define N 15

float CalculateA(int i);

int main(){
    printf("Вычисление суммы %d членов последовательности\n", N+1);

    float sum = 0;
    float a;

    for (unsigned i = 0; i<=N; ++i){
        a = CalculateA(i);
        sum += a;
    }
    printf("Сумма последовательности равна %.5f\n", sum);

    return 0;
}

float CalculateA(int i){
    float result = 0;
    for (unsigned j = 0; j<=i; ++j){
        result += 1/(float)(i*i + j + 1);
    }
    return result;
}
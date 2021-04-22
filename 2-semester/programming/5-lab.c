// Вариант 6: поиск совершенных чисел
#define N 10000000000

#include <stdio.h>

double powerFast(long long  num, long long deg); // Быстрое возведение числа num в степень deg(в том числе может быть отрицательной)
unsigned int sqrt(unsigned int x); // Функция поиска корня
unsigned int IsSimple(const long long unsigned n); // Функция для проверки числа на простоту
void IsPerfect(const long long unsigned *x); // Функция для проверки числа на совершенность

int main(){
    for(long long unsigned i = 2; i<=N; i+=2){
        IsPerfect(&i);
    }
    return 0;
}

double powerFast(long long  num, long long deg) {
    double result = 1;
    if(deg < 0) {
        deg = -deg;

        while(deg) {
            if (deg % 2 == 0) {
                deg /= 2;
                num *= num;
            }
            else {
                deg--;
                result *= num;
            }
        }

        return 1 / result;
    }
    else {
        while(deg) {
            if (deg % 2 == 0) {
                deg /= 2;
                num *= num;
            }
            else {
                deg--;
                result *= num;
            }
        }

        return result;
    }
}

unsigned int sqrt(unsigned int x){ // Алгоритм основан на итерационной формуле Герона Xn+1 = (A/Xn + Xn)*1/2
                                  // Итерационная формула задаёт убывающую (начиная со 2-го элемента) последовательность, которая при любом выборе X1 быстро сходится к квадратному корню из числа А
    unsigned int m, y, b;
    m = 16384;
    y = 0;
    while (m != 0){
        b = y | m;
        y = y >> 1;
        if (x >= b) {
            x = x - b;
            y = y | m;
        }
        m = m >> 2;
    }
    return y;
}
unsigned int IsSimple(const long long unsigned n){
    for (long long unsigned i = 2; i <= sqrt(n); ++i){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
void IsPerfect(const long long unsigned *x){
    for(long long unsigned i = 1; i < *x; ++i){
        if(((*x == powerFast(2, i) * (powerFast(2, i+1) - 1))) && IsSimple( powerFast(2, i + 1) - 1)){
            printf("%d\n", *x);
            return;
        }
        if(powerFast(2, i)*(powerFast(2, i+1)-1) > *x){ // Шажок в сторону эффективности - не перебираем значения, которые больше исходного значения
            return;
        }
    }
    return;
}

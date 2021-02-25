#include <iostream>
#include <cstring>

#define SIZE 256

using namespace std;

int main(){

    int i = 0; // Счётчик
    char first_string[SIZE] = {0}; // Массив для хранения первой строки
    char second_string[SIZE] = {0}; // Массив для хранения второй строки
    int second_string_length = 0; // Длина первой строки
    int first_string_length = 0; // Длина второй строки

    cout<<"\nВведите первую строку: ";
    while(1) {
        scanf("%c", &first_string[i]); // Посимвольно считываем первую строку в бесконечном цикле
        if ((int)first_string[i] == 10){ // Если встретили символ с кодом 10 (возврат каретки по таблице ASCII)
            first_string_length++; // К длине строки добавляется 0-байт
            break; // Выходим из цикла
        }
        i++; // Переходим к следующему символу
        first_string_length++; // Перезаписываем количество введённых символов
    }

    cout<<"Введите вторую строку: ";
    i = 0; // Возвращаем счётчик символов к нулю
    while(1) {
        scanf("%c", &second_string[i]); // Посимвольно считываем вторую строку в бесконечном цикле
        if ((int)second_string[i] == 10){ // Если встретили символ с кодом 10 (возврат каретки по таблице ASCII)
            second_string_length++; // К длине строки добавляется 0-байт
            break;// Выходим из цикла
        }
        i++; // Переходим к следующему символу
        second_string_length++; // Перезаписываем количество введённых символов
    }

    i = 0; // Обнуляем счётчик
    int buf = 0; // Переменная для хранения результата
    while (first_string[i] && second_string[i] && first_string[i] == second_string[i]) ++i; // Ищем индекс первого различного символа или конца строки
    buf = first_string[i] - second_string[i]; // Когда нашли, записываем разность символов первой и второй строк
    /*
    Аналогично можно записать:
    while (*s1 && *s2 && *s1 == *s2)
        ++s1, ++s2;
    cout<<"\n\nРезультат сравнения через собственную функцию: "<<*s1 - *s2<<endl;
    */
    cout<<"\n-----------------------------------------------\n";
    cout<<"Результат сравнения через strcmp: "<<strcmp(first_string, second_string);
    cout<<"\n-----------------------------------------------\n";
    cout<<"Символов в первой строке: "<<first_string_length<<endl;
    cout<<"Символов во второй строке: "<<second_string_length<<endl;
    cout<<"\nСравнение через собственную функцию \n"<<endl;
    if(!buf) {
        cout<<"Все символы в строках равны\n";
    } else {
        if(first_string_length > second_string_length){
            cout<<"Первая строка длиннее второй\n";
        } else if(first_string_length < second_string_length) {
            cout<<"Первая строка короче второй\n";
        } else {
            cout<<"Длины строк совпадают\n";
        }
        cout<<'\n';
        cout<<"Первый различный символ 1-й строки: "<<first_string[i]<<endl
            <<"Его код: "<<(int)first_string[i]<<endl<<endl;
        cout<<"Первый различный символ 2-й строки: "<<second_string[i]<<endl
            <<"Его код: "<<(int)second_string[i]<<endl;
    }
    cout<<"\n-----------------------------------------------\n";
    cout<<"Их разность (результат работы функции): "<<buf;
    cout<<"\n-----------------------------------------------\n";

    return 0;
}

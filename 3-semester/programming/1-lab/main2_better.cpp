/* =================================================
*  Выполнил: Студент Лебедев И. И. 
*  Группа: М3О-211Б-20
*  ================================================= */

#include <iostream>  // Библиотека для работы с входным и выходным потоками
#include <cmath>     // Библиотека для работы с математическими функциями
#include <chrono>    // Библиотека для вычисления времени работы
#include <string>    // Библиотека для работы со строками

#define RANDOM_RANGE 100 // Диапазон случайных чисел (от 0 до 99 включительно)
#define SAWTOOTH_HIGH 5  // Высота пилообразной последовательности минус 1
#define STAIRS_LENGTH 5  // Длина ступенчатой последовательности

using namespace std;         // Пространство имён std для использования функций стандартной библиотеки
using namespace std::chrono; // Пространство имён std::chrono для использования функций работы со временем

/* ============================================================================================================================
*                                                  ФУНКЦИИ ДЛЯ ГЕНЕРАЦИИ ПОСЛЕДОВАТЕЛЬНОСТЕЙ
*  ============================================================================================================================ */
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void IncreasingSequenceGeneration(T* result, const size_t size){ // Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = i;                                           // Присваивание соответствующего значения по возрастанию ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Возрастающая последовательность: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void DescendingSequenceGeneration(T* result, const size_t size){ // Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = size - i - 1;                                // Присваивание соответствующего значения по убыванию ячейке массива с индексом i
    }                                                            // Конец цикла по i  
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Убывающая последовательность: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void RandomGeneration(T* result, const size_t size){             // Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = rand() % RANDOM_RANGE;                       // Присваивание соответствующего случайного значения ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Случайное заполнение: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void SinusSequenceGeneration(T* result, const size_t size){      // Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = sin(i) * 10;                                 // Присваивание соответствующего значения синуса i ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Синусоидальная последовательность: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void SawtoothSequenceGeneration(T* result, const size_t size){   // Функция, принимает указатель на массив для работы и его размер 
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = i % SAWTOOTH_HIGH;                           // Присваивание соответствующего значения пилообразной последовательности по формуле i % SAWTOOTH_HIGH ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Пилообразная последовательность: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void StairsSequenceGeneration(T* result, const size_t size){     // Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = i / STAIRS_LENGTH;                           // Присваивание соответствующего значения ступенчатой последовательности по формуле i / SAWTOOTH_HIGH ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Последовательность лестницей: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}
template <typename T>                                            // Шаблон для функции (для универсализации работы с типами входных массивов)
void QuasiRandomSequenceGeneration(T* result, const size_t size){// Функция, принимает указатель на массив для работы и его размер
    steady_clock::time_point start = steady_clock::now();        // Засечь начальный момент времени
    for(size_t i = 0; i < size; ++i){                            // Цикл по i для перебора всего массива
        result[i] = i / STAIRS_LENGTH + rand() % 5;              // Присваивание соответствующего значения ступенчатой последовательности по формуле i / SAWTOOTH_HIGH ячейке массива с индексом i
    }                                                            // Конец цикла по i
    auto finish = steady_clock::now();                           // Засечь время окончания выполнения функции
    cout << "Квазислучайная последовательность: "
         << duration_cast<microseconds>(finish - start).count()  // Вывести, сколько времени потребовалось для выполнения функции
         << " mcs" << endl;
}

typedef void (*MENU_INT)(int*, const size_t);       // Создание прототипа для использования массива указателей на целочисленные функции
typedef void (*MENU_FLOAT)(float*, const size_t);   // Создание прототипа для использования массива указателей на функции с плавающей точкой

int main(){            // Главная исполняемая функция
    srand(time(NULL)); // Обнуление "зерна" времени для генерации случайных чисел
    size_t size;       // Объявление переменной (беззнаковая, целая), в которой будет храниться размер массива
    cout << "Введите размер массива: "; // Вывод с помощью стандратного потока вывода сообщения о вводе размера массива
    cin >> size;       // Ввод с помощью стандартного потока ввода объявленного размера
    cout << endl;      // Вывод  с помощью стандартного потока вывода переноса строки

    MENU_INT Sequences[] = {IncreasingSequenceGeneration, DescendingSequenceGeneration,         // Создание массива указателей на функции,
                        RandomGeneration, SinusSequenceGeneration,                              // где в качестве параметра будет массив 
                        SawtoothSequenceGeneration, StairsSequenceGeneration,                   // целых чисел
                        QuasiRandomSequenceGeneration};

    MENU_FLOAT Float_Sequences[] = {IncreasingSequenceGeneration, DescendingSequenceGeneration, // Создание массива указателей на функции
                        RandomGeneration, SinusSequenceGeneration,                              // где в качестве параметра будет массив 
                        SawtoothSequenceGeneration, StairsSequenceGeneration,                   // чисел с плавающей точкой
                        QuasiRandomSequenceGeneration};

    /* ============================================================================================================================
    *                                                  ЦЕЛОЧИСЛЕННЫЕ ПОСЛЕДОВАТЕЛЬНОСТИ
    *  ============================================================================================================================ */
    cout << "=====================      ЦЕЛОЧИСЛЕННЫЕ ПОСЛЕДОВАТЕЛЬНОСТИ       =====================" << endl;
    int *arr_int = new int [size];                      // Создание указателя на область в памяти для работы с целочисленным массивом
    for (unsigned short int i = 0; i < 7; ++i){         // Перебор всего массива указателей на функции
        Sequences[i](arr_int, size);                    // Вызов соответствующей функции для генерации последовательности
        if (size >= 100 && size <= 200){                // Проверка размера массива 
            string filename = "int_" + to_string(i);    // Создание строчки с названием выходного файла для текущей последовательности
            FILE* output;                               // Объявление выходного файла
            output = fopen(filename.c_str(), "w");      // Открытие выходного файла в режиме записи
            if(output){                                 // Если файл удалось открыть/создать
                for(size_t j = 0; j < size; ++j){       // Перебор всех элементов сформированного массива
                    fprintf(output, "%d\n", arr_int[j]);// Занесение текущего значения ячейки массива в выходной файл
                }                                       // Конец перебора элементов массива
                fclose(output);                         // Закрытие выходного файла
            } else {                                    // Если файл не удалось открыть
                cerr << "Невозможно открыть файл " << filename << endl; // Вывести сообщение об ошибке
            }
        }
    }                                                   // Конец перебора массива указателей на функции
    delete[] arr_int;                                   // Высвобождение памяти из-под динамического массива целых чисел


    /* ============================================================================================================================
    *                                             ПОСЛЕДОВАТЕЛЬНОСТИ С ПЛАВАЮЩЕЙ ТОЧКОЙ
    *  ============================================================================================================================ */
    cout << endl << endl;
    cout << "=====================      ПОСЛЕДОВАТЕЛЬНОСТИ С ПЛАВАЮЩЕЙ ТОЧКОЙ       ================" << endl;
    float *arr_float = new float [size];                  // Создание указателя на область в памяти для работы с целочисленным массивом
    for (unsigned short int i = 0; i < 7; ++i){         // Перебор всего массива указателей на функции
        Float_Sequences[i](arr_float, size);            // Вызов соответствующей функции для генерации последовательности
        if (size >= 100 && size <= 200){                // Проверка размера массива 
            string filename = "float_" + to_string(i);  // Создание строчки с названием выходного файла для текущей последовательности
            FILE* output;                               // Объявление выходного файла
            output = fopen(filename.c_str(), "w");      // Открытие выходного файла в режиме записи
            if(output){                                 // Если файл удалось открыть/создать
                for(size_t j = 0; j < size; ++j){       // Перебор всех элементов сформированного массива
                    fprintf(output, "%f\n", arr_float[j]);// Занесение текущего значения ячейки массива в выходной файл
                }                                       // Конец перебора элементов массива
                fclose(output);                         // Закрытие выходного файла
            } else {                                    // Если файл не удалось открыть
                cerr << "Невозможно открыть файл " << filename << endl; // Вывести сообщение об ошибке
            }
        }
    }                                                   // Конец перебора массива указателей на функции
    delete[] arr_float;                                   // Высвобождение памяти из-под динамического массива чисел с плавающей точкой
    return 0;                                             // Программа возвращает 0 - корректное завершение работы
}

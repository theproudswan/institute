 /* =================================================
  *  Выполнил: Студент Лебедев И. И. 
  *  Группа: М3О-211Б-20
  *  Файл: main.cpp
  *  Содержание: Основная функция программы
  *  Компилятор: g++ v. 10.2.1
  *  ================================================= */

#include "sort.h" // Подключение заголовочного файла с функциями сортировок
#include "test.h" // Подключение заголовочного файла с функциями тестирования

#include <iostream>     // Библиотека для работы со стандартным потоком ввода/вывода

using namespace std; // Пространство имён std для использования функций стандартной библиотеки

int main() {   // Главная функция программы
  FirstTask(); // Вызов функции для тестирования первого задания
  cout << endl << endl;   // Перенос строк
  BestAndWorstCaseTest(); // Вызов функции для тестирования производительность в разных случаях
  cout << endl << endl;   // Перенос строк
  SecondTask();           // Вызов функции для тестирования второго задания
  return 0;               // Вернуть ноль - пограмма завершилась корректо
} // Конец главной функции
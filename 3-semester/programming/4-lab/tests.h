//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : tests.h
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Прототипы функций для тестирования
//============================================================================

#pragma once // Для избежания проблемы двойного включения

#include "LinkedList.h" // Заголовочный файл со списком

#include <iostream> // Библиотека для работы с потоками ввода/вывода
#include <string>   // Библиотека для работы со строками
#include <utility>  // Библиотека для работы с парами

using namespace std; // Пространство имён для работы с функциями стандартной библиотеки

namespace Tests{ // Пространство имён, содержащее тесты
    void Find(const LinkedList<string>& list);              // Функция поиска в списке
    void RingPrint (const LinkedList<string>& list);        // Кольцевая печать списка
    void PrintList (const LinkedList<string>& list);        // Вывод всего списка
    void PushFront (LinkedList<string>& list, string to_push = "begin_test_string"); // Добавление в начало списка заданной строки
    void PushBack (LinkedList<string>& list, string to_push = "end_test_string");    // Добавление в конец списка заданной строки
    void PopFront (LinkedList<string>& list);               // Удаление из начала списка
    void PopBack (LinkedList<string>& list);                // Удаление из конца списка
    void Ring (LinkedList<string>& list);                   // Проверка, является ли список кольцевым
    void FindMax (const LinkedList<string>& list);          // Поиск максимального элемента
    void RemoveAndInsertAfter(LinkedList<string>& list);    // Вставка и удаление элемента после заданного
} // Конец пространства имён Tests
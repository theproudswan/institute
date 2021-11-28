//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : tests.cpp
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Определение функций для тестирования
//============================================================================

#include "LinkedList.h" // Заголовочный файл с классом LinkedList
#include "tests.h"      // Заголовочный файл с описанием тестов

#include <iostream>     // Библиотека для работы с потоками ввода/вывода
#include <string>       // Библиотека для работы со строками
#include <utility>      // Библиотека для работы с парами

using namespace std; // Пространство имён для работы с функциями стандартной библиотеки

    void Tests::Find(const LinkedList<string>& list) {  // Функция для тестирования функции поиска в списке list
        cout << "===== Поиск элемента =====" << endl;
        string to_find;                                 // Переменная, куда будет записываться искомая строка
        cout << "Введите имеющееся слово для поиска: ";
        cin >> to_find;                                 // Ввод искомого слова
        cout << "Первое вхождение: " << list.LowerBound(to_find) << endl;   // Поиск и вывод первого вхождения искомого слова
        cout << "Последнее вхождение: " << list.UpperBound(to_find) << endl;// Поиск и вывод последнего вхождения искомого слова
        cout << endl;
        cout << "Введите отсутствующее слово для поиска: ";
        cin >> to_find;                                // Ввод искомого слова
        cout << "Первое вхождение: " << list.LowerBound(to_find) << endl;   // Поиск и вывод первого вхождения искомого слова
        cout << "Последнее вхождение: " << list.UpperBound(to_find) << endl;// Поиск и вывод последнего вхождения искомого слова
        cout << endl << endl;
    } // Конец Tests::Find


    void Tests::RingPrint (const LinkedList<string>& list) {    // Функция для кольцевой печати списка list
        for (size_t i = 0; i < 2 * list.GetSize(); ++i){        // Цикл по всем элементам дважды
            cout << "list[" << i << "] = " << list[i]->value << endl;   // Вывод текущего элемента
        }                                                       // Конец цикла
    } // Конец Tests::RingPrint


    void Tests::PrintList (const LinkedList<string>& list) {    // Функция для печати списка list
        for (size_t i = 0; i < list.GetSize(); ++i){            // Перебор всех элементов
            cout << "list[" << i << "] = " << list[i]->value << endl;   // Печать текущего элемента
        }                                                       // Конец цикла
    }   // Конец Tests::PrintList


    void Tests::PushFront (LinkedList<string>& list, const string to_push){ // Функция для добавления строки to_push в начало списка list
        list.PushFront(to_push);    // Добавление строки to_push в начало списка list
    } // Конец Tests::PushFront


    void Tests::PushBack (LinkedList<string>& list, const string to_push){ // Функция для добавления строки to_push в конец списка list
        list.PushBack(to_push);    // Добавление строки to_push в конец списка list
    } // Конец Tests::PushBack


    void Tests::PopFront (LinkedList<string>& list){ // Функция для удаления начального элемента из списка list
        list.PopFront();    // Удаление начального элемента списка list
    } // Конец Tests::PopFront


    void Tests::PopBack (LinkedList<string>& list){ // Функция для удаления последнего элемента из списка list
        list.PopBack(); // Удаление последнего элемента из списка list
    } // Конец Tests::PopBack


    void Tests::Ring (LinkedList<string>& list){    // Функция для проверки, является ли список кольцевым
        cout << "===== Проверка, является ли список кольцевым =====" << endl;
        cout << "Убедимся, что список кольцевой. Выведем элементы от 0 до "
            << 2 * list.GetSize() - 1 << " включительно: " << endl;
        Tests::RingPrint(list); // Кольцевая печать списка
        cout << endl << endl;
        cout << "Теперь добавим строку \"begin_test_string\" в начало и \"end_test_string\" в конец." << endl;
        Tests::PushFront(list); // Добавить элемент в начало списка
        Tests::PushBack(list);  // Добавить элемент в конец списка
        cout << "Проверим, не случилась ли инвалидация указателей и выполним кольцевую печать:" << endl;
        Tests::RingPrint(list); // Кольцевая печать списка
        cout << endl << endl << "Удалим вспомогательные строки и заново проверим целостность списка:\n";
        Tests::PopFront(list);  // Удаление головы списка
        Tests::PopBack(list);   // Удаление конца списка
        Tests::RingPrint(list); // Кольцевая печать списка
    } // Конец Tests::Ring


    void Tests::FindMax (const LinkedList<string>& list){   // Функция поиска максимального элемента в списке list
        cout << endl << endl;
        cout << "===== Поиск максимального элемента =====" << endl;
        auto max = list.FindMax();  // Поиск максимального элемента
        cout << "Максимальный элемент \"" << max.second << "\" находится на " << max.first << " месте" << endl; // Вывод полученной информации
    } // Конец Tests::FindMax


    void Tests::RemoveAndInsertAfter(LinkedList<string>& list){ // Тестирование вставления и удаления узла в списке list
        cout << endl << endl;
        cout << "===== Удаление после заданного элемента =====" << endl;
        string tmp = list.GetHead()->next->value;   // Запомнить значение удаляемого узла
        auto after_head = list.GetHead();           // Получить удаляемый узел (сразу после головы)
        cout << "Текущий список:" << endl;
        Tests::PrintList(list);                     // Распечатать текущий лист
        cout << endl << "Удалим элемент после головы списка." << endl;
        list.RemoveAfter(after_head);               // Удалить лист после головы
        cout << "Получен список:" << endl;
        Tests::PrintList(list);                     // Напечатать получившийся результат
        cout << endl << endl;
        cout << "===== Вставка после заданного элемента =====" << endl;
        cout << "Вставим удалённый элемент на прежнее место." << endl;
        list.InsertAfter(after_head, tmp);          // Вставить после головы узел со значением удалённого
        cout << "Получен список:" << endl;
        Tests::PrintList(list);                     // Напечатать получившийся список
        cout << endl << endl;
    } // Конец Tests::RemoveAndInsertAfter


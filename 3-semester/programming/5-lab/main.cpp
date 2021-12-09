//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : main.cpp
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Главная функция программы, а также набор тестов
//============================================================================

#include "Deque.h"      // Заголовочный файл с реализацией Дека
#include <iostream>		// Библиотека для использования стандартного потока ввода/вывода

using namespace std; // Пространство имён для использования функций стандратной библиотеки

#define SIZE_TO_TEST 10 // Размер массива для автоматического тестирования

void RunAutoTest(){     // Функция автоматического тестирования
    Deque<int> deque;   // Объявление дека целых чисел

    cout << "Распечатаем пустой дек: " << endl << endl;
    deque.Print();  // Вывод дека
    cout << endl << endl;

    cout << "Заполним дек по возрастанию" << endl << endl;
    for (size_t i = 0; i < SIZE_TO_TEST; i++){  // Цикл для заполнения дека
        deque.PushBack(i);  // Вставить очередной элемент в конец дека
    }   // Конец цикла
    deque.Print();  // Вывести дек
    cout << endl << endl;

    cout << "Добавим в конец дека число 99. \nПолучился дек:" << endl << endl;
    deque.PushBack(99); // Добавить в конец дека "99"
    deque.Print();      // Распечатать дек
    cout << endl << endl;

    cout << "Добавим в начало дека число 101. \nПолучился дек:" << endl << endl;
    deque.PushFront(101); // Добавить в начало дека "101"
    deque.Print();        // Распечатать дек
    cout << endl << endl;

    cout << "Удалим добавленные значения" << endl << endl;
    deque.PopBack();    // Удалить последний элемент
    deque.PopFront();   // Удалить первый элемент
    deque.Print();      // Распечатать дек
    cout << endl << endl;

    cout << "Очистим дек.\nЕго размер до очистки: " << deque.GetSize() << endl;
    deque.Clear();  // Очистить дек
    cout << "Его размер после очистки: " << deque.GetSize() << endl;
    cout << "Очистим ещё раз." << endl;
    deque.Clear();  // Очистить дек
} // Конец функции RunAutoTest

void PrintMenu(){   // Функция для печати меню
    cout << "1. Ввести дек" << endl 
         << "2. Вывести дек" << endl
         << "3. Очистить дек" << endl
         << "4. Удалить элемент из начала дека" << endl
         << "5. Удалить элемент из конца дека" << endl
         << "6. Добавить элемент в начало дека" << endl
         << "7. Добавить элемент в конец дека" << endl
         << "0. Выйти из программы" << endl;
}   // Конец функции PrintMenu

int main() { // Главная функция
    bool auto_tests_flag = 0; // Переменная отвечает за способ тестирования:
                              // 0 - Ручное тестирование
                              // 1 - Автоматическое тестирование
    cout << "Выберите способ тестирования: ручной или автоматический (0/1): ";
    cin >> auto_tests_flag; // Ввод способа ввода 
    if (auto_tests_flag){   // Если выбран автоматический способ тестирования
        RunAutoTest();      // Запустить тестирование
        return 0;           // Завершить программу возвратом 0 - успех
    }                       // Конец Если 

    Deque<int> deque;       // Создать дек
    int command = 1;        // Переменная отвечает за очередную команду для тестирования
    while (command){        // Пока не было команды на выход
        PrintMenu();        // Вывести меню
        cout << "Команда: "; cin >> command; // Считать команду
        switch (command){   // "Переключатель" по командам
        case 1:     // Команда для ввода дека
            size_t size;    // Перемнная отвечает за размер дека
            cout << "Введите размер дека: "; cin >> size;
            for (size_t i = 0; i < size; ++i){  // Цикл ввода дека
                int tmp; // Вспомогательная переменная
                cout << "deque[" << i << "] = "; cin >> tmp;
                deque.PushBack(tmp); // Добавить в конец вспомогательную переменную
            }
            // cout << endl << endl << "Введён дек:" << endl;
            // deque.Print();
            break;  // Закончить
        case 2:     // Команда для вывода дека
            deque.Print();  // Распечатать дек
            break;  // Закончить
        case 3:     // Команда для очистки дека
            deque.Clear();  // Очистить дек
            cout << "Дек очищен" << endl;
            break;  // Закончить
        case 4:     // Команда для удаления последнего элемента
            deque.PopBack();    // Удалить последний элемент
            cout << "Элемент удалён из конца" << endl;
            break;  // Закончить
        case 5:     // Команда для удаления начального элемента
            deque.PopFront();   // Удалить начальный элемент
            cout << "Элемент удалён из начала" << endl;
            break;  // Закончить
        case 6:     // Команда для вставки в начало
            int tmp;    // Вспомогательная переменная
            cout << "Введите элемент для вставки в начало: "; cin >> tmp;
            deque.PushFront(tmp);   // Добавить вспомогательную переменную в начало
            cout << "Элемент вставлен" << endl;
            break;  // Закончить
        case 7:     // Команда для вставки в конец
            int tmp2;   // Вспомогательная переменная
            cout << "Введите элемент для вставки в конец: "; cin >> tmp2;
            deque.PushBack(tmp2);   // Добавить вспомогательную переменную в конец
            cout << "Элемент вставлен" << endl;
            break;  // Закончить
        case 0:     // Команда для завершения
            return 0;           // Завершить программу возвратом 0 - успех
        default:    // Если поступила какая-то другая команда
            cout << "Неизвестный номер операции. Попробуйте ещё раз." << endl;
            break;  // Закончить
        }
        cin.ignore(1); // Для игнорирования нажатого ранее Enter
        cout << "Нажмите Enter для перехода в меню" << endl;
        cin.get(); // Ожидание нажатия клавиши
        system("clear");    // Очистка терминала в Linux

    } // Конец Пока
    
    return 0;           // Завершить программу возвратом 0 - успех

} // Конец главной функции
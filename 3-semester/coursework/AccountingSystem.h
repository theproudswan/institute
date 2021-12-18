//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : AccountingSystem.h
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Прототип класса AccountingSystem, прототипы перегрузок и определение вспомогательных структур
//============================================================================

#pragma once    // Для избежания проблемы двойного включения

#include "LinkedList.h" // Заголовочный файл с реализацией списка

#include <iostream> // Библиотека для работы с потоками ввода/вывода
#include <mutex>    // Библиотека для работы с мьютексами


////////////////////////////////////////////
// В С П О М О Г А Т Е Л Ь Н Ы Е 
// С Т Р У К Т У Р Ы
////////////////////////////////////////////

enum class TechnicType{ // Перечисление для определения типа техники
    UNDEFINED = 0,      // Неопределённый тип техники
    PC = 1,             // Компьютер
    NOTEBOOK = 2,       // Ноутбук
    SCREEN = 3,         // Экран
    PERIPHERY = 4,      // Периферия
    PRINTER = 5         // Принтер
};                      // Конец перечисления

struct Date{            // Структура для даты
    uint day;           // День
    uint month;         // Месяц
    uint year;          // Год
};                      // Конец структуры даты

struct TechnicInformation{  // Структура для описания информации о технике
    uint faculty;           // Факультет
    uint department;        // Кафедра
    string computer_class;  // Компьютерный класс
    TechnicType type;       // Тип техники
    string serial_number;   // Серийный номер
    uint release_year;      // Год выпуска
    bool is_working;        // Работоспособность
    Date prevention_date;   // Дата предыдущего обслуживания
};                          // Конец структуры описания техники

////////////////////////////////////////////
// К О Н Е Ц
// В С П О М О Г А Т Е Л Ь Н Ы Х
// С Т Р У К Т У Р
////////////////////////////////////////////


////////////////////////////////////////////
// П Е Р Е Г Р У З К А   О П Е Р А Т О Р О В
////////////////////////////////////////////

ostream& operator << (ostream& stream, const Date& date);   // Перегрузка оператора вывода даты
istream& operator >> (istream& stream, Date& date);         // Перегрузка ввода даты (разделяющий знак - пробел)

ostream& operator << (ostream& stream, const TechnicType& technic); // Перегрузка оператора вывода структуры TechnicType
istream& operator >> (istream& stream, TechnicType& technic);       // Перегрузка оператора ввода структуры TechnicType


ostream& operator<<(ostream& stream, const TechnicInformation& accounting); // Перегрузка оператора вывода структуры TechnicInformation

bool operator< (const Date& lhs, const Date& rhs);  // Перегрузка оператора сравнения для дат
bool operator== (const Date& lhs, const Date& rhs); // Перегрузка оператора эквивалентности для дат

//* В конце файла имеется ещё одна перегрузка

////////////////////////////////////////////
// К О Н Е Ц   П Е Р Е Г Р У З О К
////////////////////////////////////////////

const TechnicInformation UNDEFINED_TECHNIC = {0, 0, "0", TechnicType::UNDEFINED, "0", 0, 0, {0, 0, 0}}; // Глобальная константа для неопределённого устройства

class AccountingSystem { // Класс учёта техники
public: // Публичная секция
    void AddElement(const TechnicInformation& technic); // Добавления элемента
    void UpdateElem(LinkedList<TechnicInformation>::Node* to_change, const TechnicInformation& new_technic); // Изменение заданного элемента
    bool ReadFromFile(const string& file_name); // Заполнение списка из файла

    /* * * * * * * * * * * * * * * * * * * * *
     *    ПОИСК ПО РАЗНЫМ ПАРАМЕТРАМ         *
     * * * * * * * * * * * * * * * * * * * * */
    LinkedList<TechnicInformation> SerachByFaculty(const uint& faculty) const;  // Поиск по факультету
    LinkedList<TechnicInformation> SerachByDepartment(const uint& department) const; // Поиск по кафедре
    LinkedList<TechnicInformation> SerachByClass(const string& __class) const;  // Поиск по классу
    LinkedList<TechnicInformation> SerachByType(const TechnicType& type) const; // Поиск по типу устройства
    TechnicInformation SerachBySerial(const string& serial) const;              // Поиск по серийному номеру
    LinkedList<TechnicInformation> SerachByYear(const uint& year) const;        // Поиск по году выпуска
    LinkedList<TechnicInformation> SerachByWorking(const bool& working) const;  // Поиск по работоспособности
    LinkedList<TechnicInformation> SerachByDate(const Date& date) const;        // Поиск по дате обслуживания
    /* * * * * * * * * * * * * * * * * * * * *
     * КОНЕЦ ПОИСКА ПО РАЗНЫМ ПАРАМЕТРАМ
     * * * * * * * * * * * * * * * * * * * * */

    void Erase (const size_t index);                           // Удаление элемента
    TechnicInformation operator[] (const size_t index) const;  // Перегрузка скобок []
    TechnicInformation& operator[] (const size_t index);       // Перегрузка скобок []
    size_t GetSize() const;                                    // Получение размера базы данных
private:    // Приватная секция класса
    LinkedList<TechnicInformation> data; // Список устройств
    mutex m;    // Мьютекс для избежания состояния гонки
};  // Конец Объявления класса AccountingSystem

ostream& operator<<(ostream& stream, const AccountingSystem& accounting);   // Перегрузка оператора вывода класса AccountingSystem
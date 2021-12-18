//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : AccountingSystem.h
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Определение класса AccountingSystem, определение перегрузок
//============================================================================

#pragma once    // Избежание проблемы двойного включения

#include "AccountingSystem.h"   // Заголовочный файл с объявлением класса

#include <iostream> // Библиотека для работы с потоками
#include <mutex>    // Библиотека для работы с мьютексами
#include <iomanip>  // Библиотека для работы с форматированием вывода
#include <fstream>  // Библиотека для работы с файлами

#define FILE_STRING_SIZE 64 // Максимальная длина строки в файле с входными данными

////////////////////////////////////////////
// П Е Р Е Г Р У З К А   О П Е Р А Т О Р О В
////////////////////////////////////////////

ostream& operator << (ostream& stream, const Date& date){ // Перегрузка оператора вывода даты
    stream << setfill('0') << setw(2) 
           << date.day << '.' 
           << setfill('0') << setw(2)           // Вывода даты в формате ДД.ММ.ГГГГ
           << date.month << '.' 
           << setw(4) << date.year;
    return stream;  // Возврат потока
}   // Конец перегрузки вывода даты

istream& operator >> (istream& stream, Date& date){ // Перегрузка оператора ввода даты
    stream >> date.day;     // Ввод из потока дня
    stream >> date.month;   // Ввод месяца
    stream >> date.year;    // Ввод года

    return stream;  // Возврат потока
} // Конец перегрузки ввода даты


bool operator< (const Date& lhs, const Date& rhs){  // Перегрузка сравнения дат
    return tie(lhs.day, lhs.month, lhs.year) < tie(rhs.day, rhs.month, rhs.year); // Представляем дату в виде кортежа
}   // Конец перегрузки сравнения дат

bool operator== (const Date& lhs, const Date& rhs){ // Перегрузка эквивалентности дат
    return tie(lhs.day, lhs.month, lhs.year) == tie(rhs.day, rhs.month, rhs.year);// Пердставляем в виде кортежей и сравниваем их
} // Конец перегрузки оператора эквивалентности дат


ostream& operator << (ostream& stream, const TechnicType& technic){ // Перегрузка оператора вывода структуры TechnicType
    if (technic == TechnicType::PC){    // Если техника - ПК
        stream << "ПК";
    } else if (technic == TechnicType::NOTEBOOK){ // Если техника - ноутбук
        stream << "Ноутбук";
    } else if (technic == TechnicType::SCREEN){   // Если техника - монитор
        stream << "Монитор";
    } else if (technic == TechnicType::PERIPHERY){// Если техника - периферия
        stream << "Периферия";
    } else if (technic == TechnicType::PRINTER){  // Если техника - принтер
        stream << "Принтер";
    } // Конец Если
    return stream;  // Вернуть поток
}   // Конец перегрузки вывода типа техники

istream& operator >> (istream& stream, TechnicType& technic){ // Перегрузка ввода типа техники
    string s;   // Вспомогательная переменная
    stream >> s;// Считать значение из потока в переменную

    if (s == "ПК") {
        technic = TechnicType::PC;
    } else if (s == "Ноутбук") {
        technic = TechnicType::NOTEBOOK;
    } else if (s == "Монитор") {
        technic = TechnicType::SCREEN;
    } else if (s == "Периферия") {
        technic = TechnicType::PERIPHERY;
    } else if (s == "Принтер") {
        technic = TechnicType::PRINTER;
    } else {
        technic = TechnicType::UNDEFINED;
    }

    return stream; // Вернуть поток
} // Конец перегрузки

ostream& operator<<(ostream& stream, const AccountingSystem& accounting){ // Перегрузка вывода базы техники
    for (size_t i = 0; i < accounting.GetSize(); i++){  // Цикл по всем элементам
        stream << "Факультет: " << accounting[i].faculty << endl
               << "Кафедра: "   << accounting[i].department << endl
               << "Классы: "    << accounting[i].computer_class << endl
               << "Тип: "       << accounting[i].type << endl
               << "Серийный номер: " << accounting[i].serial_number << endl
               << "Год выпуска: " << accounting[i].release_year << endl
               << "Исправен: "  << (accounting[i].is_working ? "Да" : "Нет") << endl
               << "Дата профилактики: " << accounting[i].prevention_date << endl << endl;
    } // Конец цикла
    return stream; // Вернуть поток
} // Конец перегрузки

ostream& operator<<(ostream& stream, const TechnicInformation& technic){ // Перегрузка вывода информации об 1 единице техники
        stream << "Факультет: " << technic.faculty << endl
               << "Кафедра: "   << technic.department << endl
               << "Классы: "    << technic.computer_class << endl
               << "Тип: "       << technic.type << endl
               << "Серийный номер: " << technic.serial_number << endl
               << "Год выпуска: " << technic.release_year << endl
               << "Исправен: "  << (technic.is_working ? "Да" : "Нет") << endl
               << "Дата профилактики: " << technic.prevention_date << endl << endl;
    return stream;  // Вернуть поток
} // Конец перегрузки

////////////////////////////////////////////
// К О Н Е Ц   П Е Р Е Г Р У З О К
////////////////////////////////////////////

////////////////////////////////////////////
// О П И С А Н И Е   М Е Т О Д О В
////////////////////////////////////////////

    void AccountingSystem::AddElement(const TechnicInformation& technic){ // Метод добавления нового элемента
        lock_guard<mutex> lock(m);  // Заблокировать все потоки, кроме 1
        data.PushBack(technic);     // Добавить информацию о поступившей технике в базу
    } // Конец метода AddElement

    void AccountingSystem::UpdateElem(LinkedList<TechnicInformation>::Node* to_change, const TechnicInformation& new_technic){ // Изменение элемента
        lock_guard<mutex> lock(m);  // Заблокировать все потоки, кроме 1
        to_change -> value = new_technic; // Обновить информацию
    } // Конец метода UpdateElem

    bool AccountingSystem::ReadFromFile(const string& file_name){ // Метод заполнения базы из файла
        lock_guard<mutex> lock(m);  // Допустить к работе только 1 поток
        ifstream input(file_name);  // Открыть файл с входными данными
        if(!input){ // Если не удалось открыть
            cerr << "Ошибка! Невозможно открыть файл" << endl; // Сообщение об ошибке
            return false; // Вернуть 0 - 
        } // Конец Если
        char buffer[FILE_STRING_SIZE]; // Буффер для считывания строки данных
        stringstream ss; // Строковый поток для упрощения жизни
        
        while(input.getline(buffer, FILE_STRING_SIZE, '\n')){ // Пока можем, построчно считываем данные из входного файла
            TechnicInformation tmp; // Заводим вспомогательную переменную
            ss.clear();     // Очищаем поток
            ss << buffer;   // Записываем в поток считанную строку данных
            
            // Далее - заполнение вспомогательной структуры
            ss >> tmp.faculty;
            ss >> tmp.department;
            ss >> tmp.computer_class;
            ss >> tmp.type;
            ss >> tmp.serial_number;
            ss >> tmp.release_year;
            ss >> tmp.is_working;
            ss >> tmp.prevention_date;

            data.PushBack(tmp); // Добавляем новые данные в конец списка
        } // Конец Пока
        return true; // Вернуть истину - удалось успешно считать данные из файла
    } // Конец метода ReadFromFile


    /* * * * * * * * * * * * * * * * * * * * *
     *    ПОИСК ПО РАЗНЫМ ПАРАМЕТРАМ         *
     * * * * * * * * * * * * * * * * * * * * */
    
    LinkedList<TechnicInformation> AccountingSystem::SerachByFaculty(const uint& faculty) const { // Поиск по факультету
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.faculty == faculty)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByFaculty

    LinkedList<TechnicInformation> AccountingSystem::SerachByDepartment(const uint& department) const { // Поиск по кафедре
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.department == department)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByDepartment

    LinkedList<TechnicInformation> AccountingSystem::SerachByClass(const string& __class) const{ // Поиск по классу
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.computer_class == __class)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByClass

    LinkedList<TechnicInformation> AccountingSystem::SerachByType(const TechnicType& type) const{ // Поиск по типу техники
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.type == type)        // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByType

    TechnicInformation AccountingSystem::SerachBySerial(const string& serial) const { // Поиск по серийному номеру
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.serial_number == serial)  // Если очередной элемент удовлетворяет ключу поиска
                return data[i]->value;              // Вернуть найденный элемент
        }                                           // Конец перебора
        return UNDEFINED_TECHNIC;                   // Вернуть неопределённый тип
    } // Конец метода SerachBySerial

    LinkedList<TechnicInformation> AccountingSystem::SerachByYear(const uint& year) const { // Поиск по году изготовления
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.release_year == year)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByYear

    LinkedList<TechnicInformation> AccountingSystem::SerachByWorking(const bool& working) const { // Поиск по работоспособности
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.is_working == working)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByWorking

    LinkedList<TechnicInformation> AccountingSystem::SerachByDate(const Date& date) const { // Поиск по дате профилактики
        LinkedList<TechnicInformation> result;      // Список с результатами поиска
        for (size_t i = 0; i < GetSize(); i++){     // Перебор всей базы
            if (data[i]->value.prevention_date == date)  // Если очередной элемент удовлетворяет ключу поиска
                result.PushBack(data[i]->value);    // Добавить этот элемент в конец списка с результатами
        }                                           // Конец перебора
        return result;                              // Вернуть список найденных элементов
    } // Конец метода SerachByDate


    /* * * * * * * * * * * * * * * * * * * * *
     * КОНЕЦ ПОИСКА ПО РАЗНЫМ ПАРАМЕТРАМ
     * * * * * * * * * * * * * * * * * * * * */

    void AccountingSystem::Erase (const size_t index){ // Метод удаления элемента
        if (index == 0) {   // Если надо удалить из начала
            data.PopFront();// Вызвать метод удаления из начала
            return;         // Закончить выполнение метода
        }                   // Конец Если

        if (index == data.GetSize() - 1){ // Если надо удалить последний элемент
            data.PopBack();               // Вызвать метод удаления из конца
            return;                       // Закончить выполнение метода
        }                                 // Конец Если
        LinkedList<TechnicInformation>::Node* tmp_node = data.GetHead(); // Завести вспомогательный узел и установить на голову списка
        for(int i = 0; i < index - 1; i++){ // Цикл до элемента перед удаляемым
            tmp_node = tmp_node->next;      // Перейти к следующему узлу после вспомогательного
        }                                   // Конец цикла
        data.RemoveAfter(tmp_node);         // Вызвать метод удаления после заданного (после текущего вспомогательного)
    } // Конец метода Erase

    TechnicInformation AccountingSystem::operator[] (const size_t index) const { // Перегрузка скобок []
        return data[index] -> value; // Вернуть соответствующий элемент
    } // Конец перегрузки

    TechnicInformation& AccountingSystem::operator[] (const size_t index) { // Перегрузка скобок [] с доступом к элементу
        return data[index] -> value; // Вернуть соответствующий элемент
    } // Конец перегрузки
    
    size_t AccountingSystem::GetSize() const{ // Получение размера базы устройств
        return data.GetSize(); // Вернуть размер списка
    } // Конец метода GetSize


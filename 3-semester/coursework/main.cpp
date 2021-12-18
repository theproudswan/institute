//============================================================================
// Компилятор  : g++ v. 10.2.1
// Название    : main.cpp
// Автор       : Лебедев Иван
// Группа      : М3О-211Б-20
// Содержание  : Файл с главной ф-цией и тестирующими функциями
//============================================================================

#include "AccountingSystem.h" // Заголовочный файл с системой учёта

#include <iostream> // Библиотека для работы с входным/выходным потоками
#include <sstream>  // Библиотека для работы с stringstream

using namespace std; // Пространство имён для работы с функциями стандартной библиотеки

////////////////////////////////////////////
// С Л У Ж Е Б Н Ы Е   Ф У Н К Ц И И 
////////////////////////////////////////////

bool CheckSystem(const AccountingSystem& system) {  // Проверка корректности введённых данных
                                                    // ОСТОРОЖНО: ОЧЕНЬ БОЛЬШАЯ СЛОЖНОСТЬ !!!
    bool correct = 1;   // Переменная служит флагом корректности введённых данных
    for (size_t i = 0; i < system.GetSize() - 1; i++){ // Для каждого элемента
        for (size_t j = i + 1; j < system.GetSize(); j++){ // Проверить все другие элементы
            if (system[i].serial_number == system[j].serial_number) { // Если нашлось совпадение серийных номеров
                cout << "Ошибка! Изделие с серийным номером " << system[i].serial_number 
                     << " уже существует." << endl;
                correct = 0; // Ввод не был корректным
            } // Конец Если
        } // Конец проверки других элментов для заданного
    } // Конец перебора всех элементов

    return correct; // Вернуть корректность ввода
} // Конец функции CheckSystem

void RunTests(AccountingSystem& system){
    cout << "=========  АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ  =========" << endl << endl;
    char add[] = "4 404 2 Ноутбук VHRBECH39H 2007 0 1 5 2012";
    cout << "Добавим элемент: " << add << endl << endl;
    stringstream ss; // Строковый поток для упрощения жизни
    TechnicInformation tmp; // Заводим вспомогательную переменную
            ss.clear();     // Очищаем поток
            ss << add;   // Записываем в поток считанную строку данных
            
            // Далее - заполнение вспомогательной структуры
            ss >> tmp.faculty;
            ss >> tmp.department;
            ss >> tmp.computer_class;
            ss >> tmp.type;
            ss >> tmp.serial_number;
            ss >> tmp.release_year;
            ss >> tmp.is_working;
            ss >> tmp.prevention_date;

    system.AddElement(tmp); // Добавление сгенерированнаого элемента
    
    cout << "Получена следующая база: " << endl << endl << system << endl << endl;
    cout << "Удалим последний элемент" << endl << endl;
    system.Erase(system.GetSize() - 1); // Удаление последнего элемента
    cout << "Получена следующая база: " << endl << endl << system << endl << endl;

    cout << "Поиск по факультету "        << system[1].faculty          << ": " << endl << system.SerachByFaculty(system[1].faculty)[0]->value       << endl;
    cout << "Поиск по кафедре "           << system[1].department       << ": " << endl << system.SerachByDepartment(system[1].department)[0]->value << endl;
    cout << "Поиск по классу "            << system[1].computer_class   << ": " << endl << system.SerachByClass(system[1].computer_class)[0]->value  << endl;
    cout << "Поиск по типу техники "      << system[1].type             << ": " << endl << system.SerachByType(system[1].type)[0]->value             << endl;
    cout << "Поиск по серийному номеру "  << system[1].serial_number    << ": " << endl << system.SerachBySerial(system[1].serial_number)            << endl;
    cout << "Поиск по году выпуска "      << system[1].release_year     << ": " << endl << system.SerachByYear(system[1].release_year)[0]->value     << endl;
    cout << "Поиск по работоспособности " << system[1].is_working       << ": " << endl << system.SerachByWorking(system[1].is_working)[0]->value    << endl;
    cout << "Поиск по дате профилактики " << system[1].prevention_date  << ": " << endl << system.SerachByDate(system[1].prevention_date)[0]->value  << endl;
    CheckSystem(system) == 1 ? cout << "Все серийные номера уникальны" << endl : cout << "Есть совпадения серийных номеров" << endl;

}

void PrintMenu(){   // Функция для печати меню
    cout << "1. Добавить элемент" << endl 
         << "2. Удалить элемент" << endl
         << "3. Поиск по факультету" << endl
         << "4. Поиск по кафедре" << endl
         << "5. Поиск по классу" << endl
         << "6. Поиск по типу техники" << endl
         << "7. Поиск по серийному номеру" << endl
         << "8. Поиск по году выпуска" << endl
         << "9. Поиск по работоспособности" << endl
         << "10. Поиск по дате профилактики" << endl
         << "11. Проверить уникальность серийных номеров" << endl
         << "12. Вывести базу" << endl
         << "0. Выйти из программы" << endl;
}   // Конец функции PrintMenu


////////////////////////////////////////////
// К О Н Е Ц  С Л У Ж Е Б Н Ы Х   Ф У Н К Ц И Й 
////////////////////////////////////////////


int main(){

    AccountingSystem table; // База данных
    
    bool load_from_file; // Булева переменная отвечает за способ формирования информации:
                         // 0 - автоматическая генерация
                         // 1 - загрузка из файла
    cout << "Сгенерировать данные или ввести из файла? (0/1) > ";
    cin >> load_from_file;
    if (load_from_file){    // Если выбрана загрузка из файла
        string file_name;   // Переменная будет хранить название файла
        cout << "Введите название файла > ";
        cin >> file_name;
        table.ReadFromFile(file_name); // Загрузить информацию в базу из файла
    } else {    // Если выбрана автоматическая генерация
        cout << "Значение сгенерируются самостоятельно" << endl;
        TechnicInformation a = {1, 102, "5" , TechnicType::NOTEBOOK , "2OPE847FN" , 2005, 1, {5, 12, 2015}}; // Очередное значение для базы данных
        TechnicInformation b = {2, 201, "6" , TechnicType::PC       , "PO3487FN"  , 2009, 0, {8, 8 , 2017}}; // Очередное значение для базы данных
        TechnicInformation c = {3, 304, "10", TechnicType::NOTEBOOK , "DNEU8723HB", 2011, 1, {6, 3 , 2018}}; // Очередное значение для базы данных
        table.AddElement(a); // Добавить очередное значение в конец базы данных
        table.AddElement(b); // Добавить очередное значение в конец базы данных
        table.AddElement(c); // Добавить очередное значение в конец базы данных
    } // Конец Если
    cout << endl << endl;

    cout << "Получена следующая база: " << endl << endl << table << endl;

    bool auto_test; // Булева переменная отвечает за способ тестирования:
                    // 0 - ручное тестирование
                    // 1 - Автоматическое тестирование
    
    cout << "Провести ручное или автоматическое тестирование? (0/1) > ";
    cin >> auto_test;
    if (auto_test){      // Если выбрано автоматическое тестирование
        cout << endl;
        RunTests(table); // Вызвать тестирующую функцию
        return 0;        // Завершить программу возвратом 0 - корректное завершение
    }                    // Конец Если

    int command = 1;        // Переменная отвечает за очередную команду для тестирования
    while (command){        // Пока не было команды на выход
        PrintMenu();        // Вывести меню
        cout << "Команда > "; cin >> command; // Считать команду
        if(command == 1){   // Команда на добавление элемента

            cout << "Введите добавляемый элемент в следующем формате: " << endl
                 << "Факультет Кафедра Класс Тип_Техники Серийный_Номер Год_Выпуска Работоспособность Дата_Обслуживания (Без разделяющих символов)" << endl;
            TechnicInformation tmp;
            cin >> tmp.faculty;
            cin >> tmp.department;
            cin >> tmp.computer_class;
            cin >> tmp.type;
            cin >> tmp.serial_number;
            cin >> tmp.release_year;
            cin >> tmp.is_working;
            cin >> tmp.prevention_date;

        } else if (command == 2){    // Команда для удаления элемента

            cout << "Введите индекс удаляемого элемента > ";
            size_t ind; cin >> ind;
            table.Erase(ind);

        } else if (command == 3){     // Команда для поиска по факультету

            cout << "Введите номер факультета для поиска > ";
            uint find; cin >> find; // Искомое значение
            auto res = table.SerachByFaculty(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }  // Конец перебора

        } else if (command == 4) {     // Команда поиска по кафедре

            cout << "Введите номер кафедры для поиска > ";
            uint find; cin >> find; // Искомое значение
            auto res = table.SerachByDepartment(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 5) {     // Команда для поиска по классу

            cout << "Введите класс для поиска > ";
            string find; cin >> find; // Искомое значение
            auto res = table.SerachByClass(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 6) {   // Команда для поиска по типу техники

            cout << "Введите тип техники для поиска > ";
            TechnicType find; cin >> find; // Искомое значение
            auto res = table.SerachByType(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 7) {     // Команда для поиска по серийному номеру

            cout << "Введите серийный номер для поиска > ";
            string find; cin >> find; // Искомое значение
            auto res = table.SerachBySerial(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            cout << res << endl;                   // Вывод найденного значения

        } else if (command == 8) {     // Команда для поиска по году выпуска

            cout << "Введите год выпуска для поиска > ";
            uint find; cin >> find; // Искомое значение
            auto res = table.SerachByYear(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 9){       // Команда для поиска по работоспособности

            cout << "Введите параметр работоспособности для поиска > ";
            uint find; cin >> find; // Искомое значение
            auto res = table.SerachByWorking(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 10) {     // Команда для поиска по дате обслуживания

            cout << "Введите дату обслуживания для поиска > ";
            Date find; cin >> find; // Искомое значение
            auto res = table.SerachByDate(find); // Поиск по параметру
            cout << "Результаты поиска" << endl;
            if (res.GetSize() == 0) cout << "Ничего не найдено" << endl; // Если ничего не найдено
            for (size_t i = 0; i < res.GetSize(); ++i){ // Перебор всех результатов поиска
                cout << res[i] << endl;                 // Вывод очередного найденного значения
            }   // Конец перебора

        } else if (command == 11) {     // Команда для проверки уникальности серийных номеров

        CheckSystem(table) == 1 ? cout << "Все серийные номера уникальны" << endl : cout << "Есть совпадения серийных номеров" << endl;

        } else if (command == 12){      // Команда для вывода базы данных

            cout << "Имеющаяся база данных: " << endl << endl;
            cout << table << endl;

        } else if (command == 0){     // Команда для завершения

            return 0;           // Завершить программу возвратом 0 - успех

        } else {    // Если поступила какая-то другая команда

            cout << "Неизвестный номер операции. Попробуйте ещё раз." << endl;
            
        }
        cin.ignore(1); // Для игнорирования нажатого ранее Enter
        cout << "Нажмите Enter для перехода в меню" << endl;
        cin.get(); // Ожидание нажатия клавиши
        system("clear");    // Очистка терминала в Linux

    } // Конец Пока
    
    return 0;           // Завершить программу возвратом 0 - успех

} // Конец главной функции
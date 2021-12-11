#pragma once

#include "LinkedList.h"

#include <iostream>
#include <mutex>
#include <iomanip>
#include <fstream>

struct Date{
    uint day;
    uint month;
    uint year;
};

ostream& operator << (ostream& stream, const Date& date);
bool operator< (const Date& lhs, const Date& rhs);
bool operator== (const Date& lhs, const Date& rhs);

enum class TechnicType{
    UNDEFINED = 0,
    PC = 1,
    NOTEBOOK = 2,
    SCREEN = 3,
    PERIPHERY = 4,
    PRINTER = 5
};
ostream& operator << (ostream& stream, const TechnicType& technic);

struct TechnicInformation{
    uint faculty;
    uint department;
    string computer_class;
    TechnicType type;
    string serial_number;
    uint release_year;
    bool is_working;
    Date prevention_date;
};

const TechnicInformation UNDEFINED_TECHNIC = {0, 0, "0", TechnicType::UNDEFINED, "0", 0, 0, {0, 0, 0}};

class AccountingSystem{
public:
    void AddElement(const TechnicInformation& technic);
    void UpdateElem(LinkedList<TechnicInformation>::Node* to_change, const TechnicInformation& new_technic);
    bool ReadFromFile(const string& file_name);
    /* * * * * * * * * * * * * * * * * * * * *
     *    ПОИСК ПО РАЗНЫМ ПАРАМЕТРАМ         *
     * * * * * * * * * * * * * * * * * * * * */
    
    LinkedList<TechnicInformation> SerachByFaculty(const uint& faculty);

    LinkedList<TechnicInformation> SerachByDepartment(const uint& department);

    LinkedList<TechnicInformation> SerachByClass(const string& __class);

    LinkedList<TechnicInformation> SerachByType(const TechnicType& type);

    TechnicInformation SerachByType(const string& serial);

    LinkedList<TechnicInformation> SerachByYear(const uint& year);

    LinkedList<TechnicInformation> SerachByWorking(const bool& working);

    LinkedList<TechnicInformation> SerachByDate(const Date& date);
    /* * * * * * * * * * * * * * * * * * * * *
     * КОНЕЦ ПОИСКА ПО РАЗНЫМ ПАРАМЕТРАМ
     * * * * * * * * * * * * * * * * * * * * */

    void Erase (const size_t index);

    TechnicInformation operator[] (const size_t index) const;
    TechnicInformation& operator[] (const size_t index);
    size_t GetSize() const;
private:
    LinkedList<TechnicInformation> data;
    mutex m;
};

ostream& operator<<(ostream& stream, const AccountingSystem& accounting);

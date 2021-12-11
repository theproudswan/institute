#pragma once

#include "LinkedList.h"
#include "AccountingSystem.h"

#include <iostream>
#include <mutex>
#include <iomanip>
#include <fstream>




ostream& operator << (ostream& stream, const Date& date){
    stream << setfill('0') << setw(2) << date.day << '.' << setfill('0') << setw(2) << date.month << '.' << setw(4) << date.year;
    return stream;
}

bool operator< (const Date& lhs, const Date& rhs){
    return tie(lhs.day, lhs.month, lhs.year) < tie(rhs.day, rhs.month, rhs.year);
}

bool operator== (const Date& lhs, const Date& rhs){
    return tie(lhs.day, lhs.month, lhs.year) == tie(rhs.day, rhs.month, rhs.year);
}


ostream& operator << (ostream& stream, const TechnicType& technic){
    if (technic == TechnicType::PC){
        stream << "ПК";
    } else if (technic == TechnicType::NOTEBOOK){
        stream << "Ноутбук";
    } else if (technic == TechnicType::SCREEN){
        stream << "Монитор";
    } else if (technic == TechnicType::PERIPHERY){
        stream << "Перифирия";
    } else if (technic == TechnicType::PRINTER){
        stream << "Принтер";
    }
    return stream;
}





    void AccountingSystem::AddElement(const TechnicInformation& technic){
        lock_guard<mutex> lock(m);
        data.PushBack(technic);
    }
    void AccountingSystem::UpdateElem(LinkedList<TechnicInformation>::Node* to_change, const TechnicInformation& new_technic){
        lock_guard<mutex> lock(m);
        to_change -> value = new_technic;
    }
    bool AccountingSystem::ReadFromFile(const string& file_name){
        ifstream input(file_name.c_str());
        if(!input){
            cerr << "Ошибка! Невозможно открыть файл" << endl;
            return false;
        }
        string buf;
        TechnicInformation tmp;
        while(getline(cin, buf)){
            buf >> tmp.faculty;
        }
        return true;
    }
    /* * * * * * * * * * * * * * * * * * * * *
     *    ПОИСК ПО РАЗНЫМ ПАРАМЕТРАМ         *
     * * * * * * * * * * * * * * * * * * * * */
    
    LinkedList<TechnicInformation> AccountingSystem::SerachByFaculty(const uint& faculty){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.faculty == faculty)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByDepartment(const uint& department){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.department == department)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByClass(const string& __class){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.computer_class == __class)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByType(const TechnicType& type){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.type == type)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    TechnicInformation AccountingSystem::SerachByType(const string& serial){
        lock_guard<mutex> lock(m);
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.serial_number == serial)
                return data[i]->value;
        }
        return UNDEFINED_TECHNIC;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByYear(const uint& year){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.release_year == year)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByWorking(const bool& working){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.is_working == working)
                result.PushBack(data[i]->value);
        }
        return result;
    }

    LinkedList<TechnicInformation> AccountingSystem::SerachByDate(const Date& date){
        lock_guard<mutex> lock(m);
        LinkedList<TechnicInformation> result;
        for (size_t i = 0; i < GetSize(); i++){
            if (data[i]->value.prevention_date == date)
                result.PushBack(data[i]->value);
        }
        return result;
    }
    /* * * * * * * * * * * * * * * * * * * * *
     * КОНЕЦ ПОИСКА ПО РАЗНЫМ ПАРАМЕТРАМ
     * * * * * * * * * * * * * * * * * * * * */

    void AccountingSystem::Erase (const size_t index){
        size_t tmp = 0;
        if (index == 0) {
            data.PopFront();
            return;
        }
        if (index == data.GetSize() - 1){
            data.PopBack();
            return;
        }
        LinkedList<TechnicInformation>::Node* tmp_node = data.GetHead();
        for(int i = 0; i < index - 1; i++){
            tmp_node = tmp_node->next;
        }
        data.RemoveAfter(tmp_node);
    }

    TechnicInformation AccountingSystem::operator[] (const size_t index) const {
        return data[index] -> value;
    }
    TechnicInformation& AccountingSystem::operator[] (const size_t index) {
        return data[index] -> value;
    }
    size_t AccountingSystem::GetSize() const{
        return data.GetSize();
    }

ostream& operator<<(ostream& stream, const AccountingSystem& accounting){
    for (size_t i = 0; i < accounting.GetSize(); i++){
        stream << "Факультет: " << accounting[i].faculty << endl
               << "Кафедра: "   << accounting[i].department << endl
               << "Классы: "    << accounting[i].computer_class << endl
               << "Тип: "       << accounting[i].type << endl
               << "Серийный номер: " << accounting[i].serial_number << endl
               << "Год выпуска: " << accounting[i].release_year << endl
               << "Исправен: "  << (accounting[i].is_working ? "Да" : "Нет") << endl
               << "Дата профилактики: " << accounting[i].prevention_date << endl << endl;
    }
    return stream;
}

#include "AccountingSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    AccountingSystem table;
    TechnicInformation a = {1, 102, "5" , TechnicType::NOTEBOOK , "2OPE847FN" , 2005, 1, {5, 12, 2015}};
    TechnicInformation b = {2, 201, "6" , TechnicType::PC       , "PO3487FN"  , 2009, 0, {8, 8 , 2017}};
    TechnicInformation c = {3, 304, "10", TechnicType::NOTEBOOK , "DNEU8723HB", 2011, 1, {6, 3 , 2018}};
    bool load_from_file;
    cout << "Сгенерировать данные или ввести из файла? (0/1) > ";
    cin >> load_from_file;
    if (load_from_file){
        string file_name;
        cout << "Введите название файла >";
        cin >> file_name;
        table.ReadFromFile(file_name);
    }
    table.AddElement(c);
    table.AddElement(b);
    table.AddElement(a);
    cout << table;
    cout << endl << endl;
    table.Erase(2);
    cout << table;
    return 0;
}
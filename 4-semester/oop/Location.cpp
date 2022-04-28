/*
* ______________________________________________
*| 												|
*| 	Файл:				Location.cpp			|
*|	Описание:	 Определение методов Location	|
*|												|
*|==============================================|
*|												|
*|	Автор:			  Лебедев И.И.				|
*|	Группа:			  М3О-211Б-20				|
*|												|
*|==============================================|
*|												|
*|	Для связи:		lebivan2002@ya.ru			|
*|______________________________________________|
*/

/*
*			И Е Р А Р Х И Я   К Л А С С О В
*
*							   Location <--
*								  |
*								  |
*								Point
*							   /     \
*							  /       \
*						  Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite
*				      House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/


#include "Location.h"  // Заголовочный файл с объявлением класса

Location::Location() {  // Конструктор по умолчанию
    //cout << "Location()" << endl;
}                       // Конец Location()

Location::~Location() { // Деструктор
    //cout << "~Location()" << endl;
}                       // Конец ~Location()

Location::Location(const int InitX, const int InitY) // Конструктор через координаты точки
    : x_pos(InitX), y_pos(InitY) {}                  // Инициализация полей

int Location::GetX() const {    // Метод для получения значения координаты Х
    return x_pos;               // Вернуть значение координаты Х
}                               // Конец GetX()

int Location::GetY() const {    // Метод для получения значения координаты Y
    return y_pos;               // Вернуть значение координаты Y
}                               //  Конец GetY()

void Location::SetX(const int InitX) {  // Метод для установления значения Х
    x_pos = InitX;                      // Установить значение Х
}                                       // Конец SetX()

void Location::SetY(const int InitY) {  // Метод для установления значения У
    y_pos = InitY;                      // Установить значение У
}                                       // Конец SetY()


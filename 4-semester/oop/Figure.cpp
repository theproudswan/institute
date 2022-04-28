/*
* ______________________________________________
*| 												|
*| 	Файл:				Figure.cpp				|
*|	Описание:	Определение методов Figure		|
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
*							   Location
*								  |
*								  |
*								Point
*							   /     \
*							  /       \
*					  --> Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Figure.h" // Файл с объявлениями класса

IFigure::IFigure() { // Конструктор по умолчанию
    //cout << "Figure()" << endl;
}                  // Конец Figure()

IFigure::~IFigure() { // Деструктор
    //cout << "~Figure()" << endl;
}                   // Конец ~Figure()


IFigure::IFigure(const Point& InitPoint) // Конструктор через объект точки
    : Point(InitPoint) {}                // Инициализация базового класса

IFigure::IFigure(const int InitX, const int InitY) // Конструктор через координаты точки
    : Point(InitX, InitY) {}                       // Инициализация базового класса


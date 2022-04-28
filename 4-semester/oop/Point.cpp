/*
* ______________________________________________
*| 												|
*| 	Файл:				Point.cpp				|
*|	Описание:	Определение методов Point		|
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
*								Point <--
*							   /     \
*							  /       \
*						  Figure    Circle
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


#include "Point.h"  // Заголовочный файл с объявлениями

Point::Point() {    // Конструктор по умолчанию
    //cout << "Point()" << endl;
}                   // Point()

Point::~Point() {   // Деструктор
    //cout << "~Point()" << endl;
}                   //~Point() 

Point::Point(const Point& InitPoint)                    // Конструктор через другой объект этого класса
    : Location(InitPoint.GetX(), InitPoint.GetY()) {    // Инициализируем базовый класс
    *this = InitPoint;                                  // Инициализация текущего объекта новым значением
}                                                       // Конец Point()

Point::Point(const int x, const int y)  // Конструктор
    : Location(x, y) {}                 // с инициализацией через базовый класс

Point::Point(const int x, const int y, COLORREF new_color) // Констурктор, задающий ещё и цвет точки,
    : Location(x, y) {                                     // с инициализацией через базовый класс
    color = new_color;                                     // Задать цвет точки
}                                                          // Конец Point()

void Point::SetColor(COLORREF new_color) { // Метод для установки цвета точки
    color = new_color;                     // Установить цвет точки
}                                          // Конец SetColor()

COLORREF Point::GetColor() const { // Получить цвет точки
    return color;                  // Вернуть цвет точки
}                                  //  Конец GetColor()

void Point::Show() {                    // Отображение точки
    visible = true;                     // Установить видимость на true
    SetPixel(hdc, x_pos, y_pos, color); // Поставить пиксель
}                                       // Конец Show()

void Point::Hide() {                               // Сокрытие точки
    visible = false;                               // Установить видимость на false
    SetPixel(hdc, x_pos, y_pos, BACKGROUND_COLOR); // Установить пиксель цвета фона
}                                                  // Конец Hide()

bool Point::IsVisible() const { // Узнать видимость точки
    return visible;             // Вернуть видимость
}                               // Конец IsVisible()

void Point::MoveTo(const int NewX, const int NewY) { // Перемещение точки
    Hide();                                          // Скрыть точку
    *this = Point(NewX, NewY);                       // Создать новый объект точки на другом месте
    Show();                                          // Показать точку
}                                                    // Конец MoveTo()

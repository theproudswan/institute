/*
//______________________________________________
//												|
//	Файл:				Circle.cpp				|
//	Описание:	Определение методов Circle		|
//												|
//==============================================|
//												|
//	Автор:			  Лебедев И.И.				|
//	Группа:			  М3О-211Б-20				|
//												|
//==============================================|
//												|
//	Для связи:		lebivan2002@ya.ru			|
//______________________________________________|
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
*						  Figure    Circle <--
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

#include "Circle.h"		// Заголовочный файл с объявлением базового класса

Circle::Circle() {}		// Конструктор по умолчанию
Circle::Circle(const int InitX, const int InitY, const int InitRadius) // Конструктор через координаты
	: Point(InitX, InitY) {	// Инициализация родительского класса
	radius = InitRadius;	// Задать назначенный радиус
} // Конец Circle()

Circle::Circle(const Point& InitPoint, const int InitRadius) // Конструктор через объект точки
	: Point(InitPoint) {									 // Инициализация родительского класса
	radius = InitRadius;									 // Задать назначенный радиус
} // Конец Circle()

Circle::~Circle() {}	// Виртуальный радиус

void Circle::SetRadius(const int InitRadius) {	// Метод для установления радиуса окружности
	radius = InitRadius;						// Задать новый радиус
} // Конец SetRadius()

int Circle::GetRadius() const {					// Метод для получения радиуса окружности
	return radius;								// Вернуть значения радиуса
} // GetRadius()

bool Circle::Touch(const int AnotherObjX, const int AnotherObjY) const { // Узнать о столкновении
	// Столкновение вычисляется по формуле:
	// (x - x0)^2 + (y - y0)^2 <= R^2
	// 
	// x  - координаты другого объекта Х
	// х0 - координаты метеорита по Х
	// у  - координаты другого объекта У
	// у0 - координаты метеорита по У
	// R  - радиус метеорита

	// Если формула выше истинна, вернуть true, иначе - false
	if (pow(AnotherObjX - x_pos, 2) + pow(AnotherObjY - y_pos, 2) <= pow(radius, 2)) return true;
	return false;
} // Конец Touch()

void Circle::Hide() { // Сокрытие Метеорита
	visible = false;	// Убрать видимость
	HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
	SelectObject(hdc, brush);				// Активировать кисть
	// Нарисовать эллипс поверх имеющегося
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);
} // Конец Hide()
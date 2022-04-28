/*
//______________________________________________
//												|
//	Файл:				Sun.cpp    				|
//	Описание:	    Определение методов Sun		|
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
*						  Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /	    Moon  Sun  Meteorite
*					 House             /\
*					  / \              ||
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Sun.h"			// Заголовочный файл с объявлением класса

Sun::Sun(int InitX = 10, int InitY = 10, int InitRadius = 10) // Конструктор с параметрами
	: Circle(InitX, InitY, InitRadius) {					  // Инициализация полей базового класса
} // Конец Meteorite()

Sun::Sun(const Point& InitPoint, int InitRadius)			  // Конструктор через объект точки
	: Circle(InitPoint, InitRadius) {						  // Инициализация полей базового класса
} // Конец Meteorite()

Sun::~Sun() {}		// Виртуальный деструктор

void Sun::Show() {  // Отображение Метеорита
	visible = true;	// Установить видимость
	HBRUSH brush = CreateSolidBrush(RGB(255, 249, 23));
	SelectObject(hdc, brush);				// Активировать кисть
	// Нарисуем круг установленным цветом
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);

} // Конец Show()

uint8_t Sun::GetTypeId() const {	// Метод для получения уникального Id класса
	return type_id;					// Вернуть значение Id
} // Конец GetTypeId()
/*
* ______________________________________________
*| 												|
*| 	Файл:			  Meteorite.cpp				|
*|	Описание:	Определение методов Meteorite   |
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
*						  Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite <--
*				      House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Meteorite.h"	// Заголовочный файл с базовым классом

Meteorite::Meteorite(int InitX = 10, int InitY = 10, int InitRadius = 10) // Конструктор с параметрами
	: Circle(InitX, InitY, InitRadius) { // Инициализация полей класса
} // Конец Meteorite()

Meteorite::Meteorite(const Point& InitPoint, int InitRadius)
	: Circle(InitPoint, InitRadius) {
}

Meteorite::~Meteorite() {}	// Виртуальный деструктор

void Meteorite::Show() {	// Отображение Метеорита
	visible = true;			// Установить видимость
	HBRUSH brush = CreateSolidBrush(RGB(73, 66, 61));
	SelectObject(hdc, brush);// Активировать кисть
	// Нарисуем круг установленным цветом
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);

	brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, brush);				// Активировать кисть
	// Кратеры
	Ellipse(hdc, x_pos, y_pos, x_pos - radius / 2 + 2, y_pos - radius / 2 + 3);
	Ellipse(hdc, x_pos + radius / 2 - 15, y_pos + radius / 2 - 15, x_pos + radius / 2 + 2, y_pos + radius / 2 + 3);
	Ellipse(hdc, x_pos - radius / 2, y_pos + radius / 2 - 15, x_pos + 5, y_pos + radius / 2);
	DeleteObject(brush);
} // Конец Show()

uint8_t Meteorite::GetTypeId() const {	// Метод для получения уникального Id класса
	return type_id;						// Вернуть значение Id
} // Конец GetTypeId()
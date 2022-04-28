/*
//______________________________________________
//												|
//	Файл:				Moon.cpp  				|
//	Описание:	  Определение методов Moon		|
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
*						 /	--> Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Moon.h"	// Подключение заголовочного файла с объявлением класса

Moon::Moon(int InitX = 10, int InitY = 10, int InitRadius = 10) // Конструктор с параметрами
	: Circle(InitX, InitY, InitRadius) { // Инициализация полей класса
} // Конец Meteorite()

Moon::Moon(const Point& InitPoint, int InitRadius) // Конструктор через объект точки
	: Circle(InitPoint, InitRadius) {			   // Инициализация базового класса
} // Конец Meteorite()

Moon::~Moon() {}	// Виртуальный деструктор

void Moon::Show() { // Отображение Метеорита
	visible = true;	// Установить видимость
	HBRUSH brush = CreateSolidBrush(RGB(189, 208, 228));
	SelectObject(hdc, brush);// Активировать кисть
	// Нарисуем круг установленным цветом
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);	 // Удалить объект кисти

} // Конец Show()

uint8_t Moon::GetTypeId() const {	// Метод для получения уникального Id класса
	return type_id;						// Вернуть значение Id
} // Конец GetTypeId()
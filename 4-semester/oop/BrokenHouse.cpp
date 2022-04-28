/*
* _______________________________________________
*|												|
*|	Файл:			 BrokenHouse.cpp			|
*|	Описание:	Определение методов BrokenHouse	|
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
*						 /		Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*	  --> BrokenHouse	  HappyHouse
*
*/


#include "BrokenHouse.h"		// Заголовочный файл с объявлением методов

BrokenHouse::BrokenHouse() {}	// Конструктор по умолчанию
BrokenHouse::~BrokenHouse() {}	// Деструктор (виртуальный)

BrokenHouse::BrokenHouse(const int InitX, const int InitY)		// Конструктор через координаты точки
	: House(InitX, InitY) {}									// Передаём координаты в базовый класс

BrokenHouse::BrokenHouse(const Point& point)					// Конструктор через объект точки
	: House(point) {}											// Передаём объект в базовый класс

void BrokenHouse::Show() {	// Отображение

	visible = true;	// Установить видимость
	House::Show();	// Нарисовать объект родительского класса, 
					// поверх которого будет рисоваться дочерний

	/*БОК КРЫШИ -- ПАРАЛЛЕЛОГРАММ*/
	SideRoof(RGB(150, 30, 30), 4, 
				  x_pos + 65, y_pos
				, x_pos + 280, y_pos
				, x_pos + 345, y_pos + 40
				, x_pos + 130, y_pos + 40
			);

	/*ДЫРА В КРЫШЕ*/
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, brush);				// Активировать кисть
	Ellipse(hdc, x_pos + 190, y_pos + 10
			, x_pos + 230, y_pos + 30
			);
	DeleteObject(brush);
	/*ОКНА*/
	FrontSide(   x_pos + 150, y_pos + 100
				, x_pos + 190, y_pos + 140
				, RGB(0, 0, 0)
			  );

	FrontSide(	  x_pos + 220, y_pos + 100
				, x_pos + 260, y_pos + 140
				, RGB(0, 0, 0)
			  );

	FrontSide(	  x_pos + 290, y_pos + 100
				, x_pos + 330, y_pos + 140
				, RGB(0, 0, 0)
			  );
	
} // Конец Show()

uint8_t BrokenHouse::GetTypeId() const { // Метод для получения уникального идентификатора класса
	return type_id;						 // Вернуть идентификатор
}										 // Конец GetTypeId()
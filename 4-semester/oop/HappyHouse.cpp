/*
* ______________________________________________
*|												|
*|	Файл:			 HappyHouse.cpp				|
*|	Описание:	Определение методов HappyHouse	|
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
*					      Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse <--
*
*/



#include "HappyHouse.h"			// Заголовочный файл с объявлением класса HappyHouse

HappyHouse::HappyHouse() {}		// Конструктор класса по умолчанию
HappyHouse::~HappyHouse() {}	// Деструктор класса

HappyHouse::HappyHouse(const int InitX, const int InitY)	// Конструктор через координаты точки
	: House(InitX, InitY) {}								// Передаём координаты в базовый класс

HappyHouse::HappyHouse(const Point& point)					// Конструктор через объект точки
	: House(point) {}										// Передаём точку в базовый класс

void HappyHouse::Show() {	// Отображение

	visible = true;	// Установить видимость
	House::Show();	// Нарисовать объект родительского класса, 
					// поверх которого будет рисоваться дочерний

	/*БОК КРЫШИ ПАРАЛЛЕЛОГРАММ*/
	SideRoof(RGB(255, 0, 0), 4, 
					  x_pos + 65, y_pos
					, x_pos + 280, y_pos
					, x_pos + 345, y_pos + 40
					, x_pos + 130, y_pos + 40
			);

	/*ОКНА*/
	FrontSide(	  x_pos + 150, y_pos + 100
				, x_pos + 190, y_pos + 140
				, RGB(226, 88, 34)
			  );

	FrontSide(	  x_pos + 220, y_pos + 100
				, x_pos + 260, y_pos + 140
				, RGB(226, 88, 34)
			  );

	FrontSide(	  x_pos + 290, y_pos + 100
				, x_pos + 330, y_pos + 140
				, RGB(226, 88, 34)
			  );
} // Конец Show()

uint8_t HappyHouse::GetTypeId() const { // Получить уникальный Id класса
	return type_id;						// Вернуть id класса
} // Конец GetTypeId()
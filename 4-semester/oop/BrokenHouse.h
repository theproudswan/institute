/*
* ______________________________________________
*|												|
*|	Файл:			 BrokenHouse.h				|
*|	Описание:	Объявление методов BrokenHouse	|
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

#pragma once        // Для избежания проблемы двойного включения
#include "House.h"  // Заголовочный файл с базовым классом

class BrokenHouse : // Начало объявления класса BrokenHouse
    public House    // Публично наследуется от класса House
{
public:             // Начало публичной секции
    BrokenHouse();  // Конструктор по умолчанию
    BrokenHouse(const int InitX, const int InitY);  // Конструктор через координаты точки
    BrokenHouse(const Point& point);                // Конструктор через объект точки
    virtual ~BrokenHouse() override;                // Виртуальный деструктор
    virtual void Show() override;                   // Виртуальный метод отображения
    virtual uint8_t GetTypeId() const;              // Получение уникального идентификатора класса

private:            // Начало приватной секции
    uint8_t type_id = 2;
}; // Конец объявления BrokenHouse


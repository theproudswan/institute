/*
//______________________________________________
//												|
//	Файл:				Circle.h				|
//	Описание:	Объявление методов Circle		|
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

#pragma once       // Для избежания проблемы двойного включения

#include "Point.h" // Заголовочный файл с базовым классом

class Circle :      // Начало объявления класса
    public Point    // Публично наследуется от Point
{
public:             // Начало публичной секции
    Circle();       // Конструктор по умолчанию
    Circle(const int InitX, const int InitY, const int InitRadius = 10); // Конструктор через координаты
    Circle(const Point& InitPoint, const int InitRadius = 10);           // Конструктор через объект точки
    virtual ~Circle() override;                                          // Виртуальный деструктор

    void SetRadius(const int InitRadius);                                // Метод для установления радиуса
    int GetRadius() const;                                               // Метод для получения радиуса

    virtual void Show() = 0;                                             // Виртуальный метод отображения
    virtual void Hide();                                                 // Виртуальный метод сокрытия
    bool Touch(const int AnotherOgjX, const int AnotherObjY) const;      // Метод для проверки касания
    virtual uint8_t GetTypeId() const = 0;                               // Виртуальный метод для получения уникального Id класса

protected:              // Защищенная секция класса
    int radius = 10;    // Радиус окружности
};  // Конец объявления Circle


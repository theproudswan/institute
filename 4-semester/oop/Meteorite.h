/*
* ______________________________________________
*| 												|
*| 	Файл:			  Meteorite.h				|
*|	Описание:	Объявление методов Meteorite    |
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

#pragma once        // Для избежания проблемы двойного включения

#include "Circle.h" // Заголовочный файл с базовым классом
#include <cmath>    // Библиотека с математическими функциями

class Meteorite :   // Объявление класса Meteorite
    public Circle   // Публично наследуется от Figure
{
public: // Публичная секция

    Meteorite() = default; // Конструктор по умолчанию
    Meteorite(int InitX, int InitY, int InitRadius); // Конструктор с параметрами
    Meteorite(const Point& InitPoint, int InitRadius); // Конструктор с параметрами
    ~Meteorite() override; // Виртуальный деструктор

    virtual void Show() override;       // Виртуальный метод отображения
    virtual uint8_t GetTypeId() const;  // Метод для получения уникального Id класса

private:                                // Приватная секция
    uint8_t type_id = 0;                // Уникальный Id класса
}; // Конец объявления Meteorite


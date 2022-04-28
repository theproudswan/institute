/*
* ______________________________________________
*| 												|
*| 	Файл:				Point.h 				|
*|	Описание:	  Объявление методов Point		|
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

#pragma once          // Избежание проблемы двойного включения

#include "Location.h" // Заголовочный файл с объявлением базового класса

class Point :       // Класс Point
    public Location // Наследуется от класса Location
{ 
public: // Начало публичной секции
    Point();            // Конструктор по умолчанию
    ~Point() override;  // Деструктор по умолчанию
    Point(const Point& InitPoint);      // Конструктор через другой объект этого класса
    Point(const int x, const int y);    // Конструктор через координаты
    Point(const int x, const int y, COLORREF new_color);    // Конструктор через координаты и цвет

    void SetColor(COLORREF new_color); // Метод для изменения цвета точки
    COLORREF GetColor() const;         // Метод для получения цвета точки

    virtual void Show();    // Виртуальный метод для демонстрации точки
    virtual void Hide();    // Виртуальный метод для сокрытия точки

    void MoveTo(const int NewX, const int NewY);    // Виртуальный метод для перемещения точки

    bool IsVisible() const; // Метод, чтобы узнать видимость точки

protected: // Защищённая секция
    COLORREF color = BACKGROUND_COLOR; // Поле цвета точки
    bool visible = false;              // Поле видимости точки
}; // Конец Point


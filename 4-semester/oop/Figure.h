/*
* ______________________________________________
*| 												|
*| 	Файл:				Figure.h				|
*|	Описание:	Объявление методов Figure		|
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
*					  --> Figure    Circle 
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

#pragma once        // Для избежания проблемы двойного включения

#include "Point.h"  // Заголовочный файл с базовым классом

class IFigure :      // Класс Figure
    public Point    // Наследуется от класса Point
{
public:             // Начало публичной секции
    IFigure();									// Конструктор по умолчанию
    ~IFigure() override;							// Виртуальный деструктор 
    IFigure(const Point& InitPoint);				// Конструктор объект точки
    IFigure(const int InitX, const int InitY);	// Конструктор через координаты точки

    virtual void FrontSide(						// Метод для отрисовки фронтальной стены дома
		const int InitX1, const int InitY1		// Координаты левого нижнего угла
		, const int InitX2, const int InitY2	// Координаты правого верхнего угла
		, const COLORREF& color					// Цвет прямоугольника
	) = 0;										// Метод является абстрактным

	virtual void SideWall(						// Метод для отрисовки боковой стены дома
		const int InitX1, const int InitY1		// Координаты левой, верхней
		, const int InitX2, const int InitY2	// правой и нижней сторон
		, const COLORREF& color					// Цвет эллипса
	) = 0;										// Метод является абстрактным
	
	virtual void FrontRoof(						// Метод для отрисовки треугольной крыши
		const int InitX1, const int InitY1		// Координаты первой вершины
		, const int InitX2, const int InitY2	// Координаты второй вершины
		, const int InitX3, const int InitY3	// Координаты третьей вершины
		, const COLORREF& color					// Цвет треугольника
	) = 0;										// Метод является абстрактным

	virtual void SideRoof(						// Метод для отрисовки полигона (многоугольника)
		const COLORREF& color					// Цвет полигона
		, const int points_count				// Количество вершин
		, ...									// Сами вершины
	) = 0;										// Метод является абстрактным

    virtual void Show() override = 0;   // Метод для отображения фигуры
    virtual void Hide() override = 0;   // Метод для сокрытия фигуры

	virtual void Earthquake() = 0;			// Метод для иммитации землетрясения
	virtual uint8_t GetTypeId() const = 0;	// Метод для получения уникального Id класса

}; // Конец Figure


/*
* ______________________________________________
*| 												|
*| 	Файл:				House.h					|
*|	Описание:	Объявление методов House		|
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
*				  --> House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#pragma once			// Для избежания проблемы двойного включения

#include "Figure.h"		// Заголовочный файл с базовым классом

class House : public IFigure {	// Класс House публично наследуется от класса Figure
public:	// Начало публичной секции
	House();	// Конструктор по умолчанию
	House(const int InitX, const int InitY);	// Конструктор через координаты точки
	House(const Point& point);					// Конструктор через объект точки
	~House() override;							// Виртуальный деструктор

	void Hide() override;						// Виртуальный метод отображения
	void Show() override;						// Вирртуальный метод сокрытия
	void Earthquake();							// Метод для землетрясения
	virtual uint8_t GetTypeId() const;			// Метод для получения уникального Id класса

protected:	// Защищённая секция

	virtual void FrontSide(						// Метод для отрисовки фронтальной стены дома
		const int InitX1, const int InitY1		// Координаты левого нижнего угла
		, const int InitX2, const int InitY2	// Координаты правого верхнего угла
		, const COLORREF& color					// Цвет квадрата
	) override;									// Метод является абстрактным

	virtual void SideWall(						// Метод для отрисовки боковой стены дома
		const int InitX1, const int InitY1		// Координаты левой, верхней
		, const int InitX2, const int InitY2	// правой и нижней сторон
		, const COLORREF& color					// Цвет эллипса
	) override;									// Метод является абстрактным

	virtual void FrontRoof(						// Метод для отрисовки треугольной крыши
		const int InitX1, const int InitY1		// Координаты первой вершины
		, const int InitX2, const int InitY2	// Координаты второй вершины
		, const int InitX3, const int InitY3	// Координаты третьей вершины
		, const COLORREF& color					// Цвет треугольника
	) override;									// Метод является абстрактным

	virtual void SideRoof(						// Метод для отрисовки бока крыши
		const COLORREF& color					// Цвет полигона
		, const int points_count				// Количество вершин у крыши
		, ...									// Сами вершины
	) override;									// Метод является абстрактным


private:										// Приватная секция класса
	uint8_t type_id = 0;						// Уникальный Id класса
};	// Конец объявления House
/*
* ______________________________________________
*| 												|
*| 	Файл:				House.cpp				|
*|	Описание:	Определение методов House		|
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

#include "House.h"	// Заголовочный файл с объявлением класса

House::House() : IFigure() {}					// Конструктор по умолчанию
House::House(const int InitX, const int InitY)	// Конструктор через координаты точки
	: IFigure(InitX, InitY) {}					// Передаём координаты в базовый класс
House::House(const Point& point)				// Конструктор через объект точки
	: IFigure(point) {}							// Передаём объект в базовый класс
House::~House() {}								// Виртуалььный деструктор

void House::Show() {// Метод для отображения
	visible = true; // Объект видимый
	/*ФАСАД ДОМА*/
	FrontSide(x_pos, y_pos + 40, x_pos + 130, y_pos + 180, RGB(254, 255, 220));

	/*ТРЕУГОЛЬНАЯ КРЫША*/
	FrontRoof(x_pos, y_pos + 40, x_pos + 130, y_pos + 40, x_pos + 65, y_pos, RGB(199, 214, 255));

	/*БОК КРЫШИ ПАРАЛЛЕЛОГРАММ*/
	SideRoof(RGB(200, 10, 10), 4, x_pos + 65, y_pos, x_pos + 280, y_pos, x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 40);

	/*БОК ДОМА*/
	FrontSide(x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 180, RGB(200, 255, 200));

	/*ДВЕРЬ*/
	FrontSide(x_pos + 70, y_pos + 100, x_pos + 110, y_pos + 180, RGB(175, 75, 0));

	/*РУЧКА ДВЕРИ*/
	SideWall(x_pos + 100, y_pos + 140, x_pos + 105, y_pos + 145, RGB(0, 0, 0));

	/*ОКНА*/
	FrontSide(x_pos + 150, y_pos + 100, x_pos + 190, y_pos + 140, RGB(255, 243, 0));
	FrontSide(x_pos + 220, y_pos + 100, x_pos + 260, y_pos + 140, RGB(255, 243, 0));
	FrontSide(x_pos + 290, y_pos + 100, x_pos + 330, y_pos + 140, RGB(255, 243, 0));
} // Конец Show()

void House::Hide() { // Метод для сокрытия
	visible = false; // Объект невидимый
	/*ФАСАД ДОМА*/
	FrontSide(x_pos, y_pos + 40, x_pos + 130, y_pos + 180, BACKGROUND_COLOR);

	/*ТРЕУГОЛЬНАЯ КРЫША*/
	FrontRoof(x_pos, y_pos + 40, x_pos + 130, y_pos + 40, x_pos + 65, y_pos, BACKGROUND_COLOR);

	/*БОК КРЫШИ ПАРАЛЛЕЛОГРАММ*/
	SideRoof(BACKGROUND_COLOR, 4, x_pos + 65, y_pos, x_pos + 280, y_pos, x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 40);

	/*БОК ДОМА*/
	FrontSide(x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 180, BACKGROUND_COLOR);

	/*ДВЕРЬ*/
	FrontSide(x_pos + 70, y_pos + 100, x_pos + 110, y_pos + 180, BACKGROUND_COLOR);
} // Конец Hide()

void House::Earthquake() {			// Метод землетрясение
	int x0 = GetX();				// Получить и запомнить текущие координаты дома по Х
	int y0 = GetY();				// Получить и запомнить текущие координаты дома по У

	for (short i = 0; i < 5; ++i) {	// Сделать 5 толчков
		x0 += 50;					// Изменить координаты дома
		MoveTo(x0, y0);				// Переместить дом правее
		Sleep(50);					// Подождать 50 мс

		x0 -= 50;					// Изменить координаты дома
		MoveTo(x0, y0);				// Переместить дом левее
		Sleep(50);					// Подождать 50 мс
		
		y0 -= 50;					// Изменить координаты дома
		MoveTo(x0, y0);				// Поднять дом выше
		Sleep(50);					// Подождать 50 мс

		y0 += 50;					// Изменить координаты дома
		MoveTo(x0, y0);				// Опустить дом
		Sleep(50);					// Подождать 50 мс
	}								// Конец For
} // Конец Earthquake()



void House::FrontSide(						// Метод для отрисовки прямоугольника
	const int InitX1, const int InitY1		// Координаты левого нижнего угла
	, const int InitX2, const int InitY2	// Координаты правого верхнего угла
	, const COLORREF& color					// Цвет прямоугольника
	){										// Метод является виртуальным

	HBRUSH brush = CreateSolidBrush(color);	// Создать кисть и установить её цвет
	SelectObject(hdc, brush);				// Активировать кисть
	Rectangle(hdc, InitX1, InitY1			// Нарисовать прямоугольник
				 , InitX2, InitY2);
	DeleteObject(brush);					// Удалить кисть
} // Конец FrontSide()

void House::SideWall(						// Метод для отрисовки боковой стороны дома
	const int InitX1, const int InitY1		// Координаты левой, верхней
	, const int InitX2, const int InitY2	// правой и нижней сторон
	, const COLORREF& color					// Цвет эллипса
	){										// Метод является виртуальным

	HBRUSH brush = CreateSolidBrush(color);	// Создать кисть и установить её цвет
	SelectObject(hdc, brush);				// Активировать кисть
	Rectangle(hdc, InitX1, InitY1			// Нарисовать прямоугольник
		, InitX2, InitY2);
	DeleteObject(brush);					// Удалить кисть
} // Конец Ellipse()

void House::FrontRoof(						// Метод для отрисовки треугольной крыши
	const int InitX1, const int InitY1		// Координаты первой вершины
	, const int InitX2, const int InitY2	// Координаты второй вершины
	, const int InitX3, const int InitY3	// Координаты третьей вершины
	, const COLORREF& color					// Цвет треугольника
	){										// Метод является виртуальным

	POINT poly[3] = {						// Массив точек для отрисовки полигона
					    {InitX1, InitY1 }	// Первая вершина
					  , { InitX2 , InitY2 } // Вторая вершина
					  , {InitX3, InitY3}	// Третья вершина
					};						// Конец массива

	HBRUSH brush = CreateSolidBrush(color);	// Создать кисть и установить её цвет
	SelectObject(hdc, brush);				// Активировать кисть
	Polygon(hdc, poly, 3);					// Нарисовать нужный полигон
	DeleteObject(brush);					// Удалить кисть
} // Конец FrontRoof()

void House::SideRoof(						// Метод для отрисовки боковой стороны крыши
	const COLORREF& color					// Цвет полигона
	, const int points_count				// Количество вершин
	, ...									// Сами вершины
	){										// Метод является виртуальным

	va_list vl;								// Для извлечения дополнительных параметров функции с переменным числом параметров
	POINT* points = new POINT[points_count];// Динамический массив точек
	int x;									// Служебная переменная для записи в массив точек
	va_start(vl, points_count);				// Установить указатель на последний известный элемент
	for (int i = 0; i < points_count * 2; ++i) { // Пройти по всем координатам каждой точки
		if ((i + 1) % 2 == 1) {				// Известна координата Х для текущей точки?
			x = va_arg(vl, int);			// Запомнить координату Х для текущей точки
		} else {							// Иначе (известна координата Х)
			points[i / 2] = { x, va_arg(vl, int) };	// Записать в массив координаты очередной точки
		}									// Конец Если
	}										// Конец For
	va_end(vl);								// Для нормального завершения работы функции, работает в паре с макросом va_start

	HBRUSH brush = CreateSolidBrush(color);	// Создать кисть и установить её цвет
	SelectObject(hdc, brush);				// Активировать кисть
	Polygon(hdc, points, points_count);		// Нарисовать нужный полигон
	DeleteObject(brush);					// Удалить кисть

	delete[] points;						// Удалить динамический массив

} // Конец SideRoof()

uint8_t House::GetTypeId() const {			// Метод для получения уникального Id класса
	return type_id;							// Вернуть значение Id
} // Конец GetTypeId()
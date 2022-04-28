/*
//______________________________________________ 
//												|
//	Файл:				main.cpp				|
//	Описание:	Текст основной программы		|
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
*						 /		Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
* 
*/

#include "Utility.h"    // Заголовочный файл с вспомогательными объявлениями

#include "Meteorite.h"	// Заголовочный файл с классом Meteorite
#include "House.h"		// Заголовочный файл с классом House
#include "BrokenHouse.h"// Заголовочный файл с классом BrokenHouse
#include "HappyHouse.h"	// Заголовочный файл с классом HappyHouse
#include "Sun.h"		// Заголовочный файл с классом Sun
#include "Moon.h"		// Заголовочный файл с классом Moon


#define HOUSES_COUNT 3	// Количество типов домов
#define CIRCLES_COUNT 3	// Количество типов небесных объектов

#define START_SKY_OBJECT_X 700	// Стартовые координаты по Х небесного тела
#define START_SKY_OBJECT_Y 700	// Стартовые координаты по У небесного тела

#define START_HOUSE_OBEJCT_X 200	// Стартовые координаты по Х дома
#define START_HOUSE_OBEJCT_Y 200	// Стартовые координаты по У дома


int main()  // Главная функция
{
	int h_x0, h_y0; h_x0 = h_y0 = START_HOUSE_OBEJCT_X;			// Стартовые координаты дома
	int s_x0 = START_SKY_OBJECT_X, s_y0 = START_SKY_OBJECT_Y;  	// Стартовые небесного тела

	IFigure* figure;	// Указатель на фигуру (любой дом)
	Circle* sky_object; // Указатель на окружность (любой небесный объект)


	/*
	*			  М А Т Р И Ц А   П Е Р Е Х О Д О В
	*  ________________________________________________________
	* |				|	Meteorite	|	 Sun	 |	   Moon    |
	* |_____________|_______________|____________|_____________|
	* |				|				|			 |			   |
	* |   House		|  BrokenHouse	| HappyHouse |	  House	   |
	* |_____________|_______________|____________|_____________|
	* |				|				|			 |			   |
	* | HappyHouse	|	  House		| HappyHouse | BrokenHouse |
	* |_____________|_______________|____________|_____________|
	* |				|				|			 |			   |
	* | BrokenHouse	|  BrokenHouse	|   House 	 |  HappyHouse |
	* |_____________|_______________|____________|_____________|
	* 
	*/

	// Матрица переходов
	IFigure* transition_matrix[HOUSES_COUNT][CIRCLES_COUNT] = {
		{ new BrokenHouse(h_x0, h_y0), new HappyHouse(h_x0, h_y0), new House(h_x0, h_y0)		},
		{ new House(h_x0, h_y0)		 , new HappyHouse(h_x0, h_y0), new BrokenHouse(h_x0, h_y0)	},
		{ new BrokenHouse(h_x0, h_y0), new House(h_x0, h_y0)	 , new HappyHouse(h_x0, h_y0)	}
	};

	sky_object = new Meteorite(s_x0, s_y0, 50);	// Первоначальная инициализация небесного тела
	figure = new House(h_x0, h_y0);				// Первоначальная инициализация дома

	figure->Show();								// Отобразиьт дом
	sky_object->Show();							// Отобразить небесное тело


	while (1) {				// Бесконечный цикл чтения с клавиатуры

		if (KEY_DOWN(49)) { // 1
			sky_object->Hide();
			sky_object = new Meteorite(s_x0, s_y0, 50); // Переключить на метеорит
			sky_object->Show();
		}
		if (KEY_DOWN(50)) { // 2
			sky_object->Hide();
			sky_object = new Sun(s_x0, s_y0, 80);		// Переключить на Солнце
			sky_object->Show();
		}
		if (KEY_DOWN(51)) { // 3
			sky_object->Hide();
			sky_object = new Moon(s_x0, s_y0, 50);		// Переключить на Луну
			sky_object->Show();
		}

		// Стрелками регулируется движение небесного тела
		if (KEY_DOWN(37)) {	// Стрелка влево  
			s_x0 -= 50;
			sky_object->MoveTo(s_x0, s_y0);
		}
		if (KEY_DOWN(38)) { // Стрелка вверх
			s_y0 -= 50;
			sky_object->MoveTo(s_x0, s_y0);
		}
		if (KEY_DOWN(39)) {   // Стрелка вправо
			s_x0 += 50;
			sky_object->MoveTo(s_x0, s_y0);
		}
		if (KEY_DOWN(40)) {	// Стрелка вниз     
			s_y0 += 50;
			sky_object->MoveTo(s_x0, s_y0);
		}


		if (KEY_DOWN(82)) { // Клавиша R
			figure->Hide();
			figure = new House(figure->GetX(), figure->GetY()); // Сброс дома до первоначального состояния
			figure->Show();
		}
		if (KEY_DOWN(69)) { // Клавиша E
			figure->Earthquake(); // <-- Яркий пример динамического полиморфизма
		}
	
		if (sky_object->Touch(figure->GetX(), figure->GetY())) { // Изменение состояния дома при касании окружности
			figure->Hide();
			figure = transition_matrix[figure->GetTypeId()][sky_object->GetTypeId()]; // Определение нового состояния
			figure->Show();
			s_x0 = START_SKY_OBJECT_X;
			s_y0 = START_SKY_OBJECT_Y;
			sky_object->MoveTo(s_x0, s_y0);	// Вернуть небесное тело на стартовые координаты
		}
		Sleep(100); // Подождать 100 мс для корректной работы
	} // Конец While

	delete figure;		// Высвободить память из-под дома
	delete sky_object;	// Высвободить память из-под небесного тела

    return 0; // Вернуть 0 - программа завершается корректно
} // Конец main()


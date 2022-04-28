/*
* ______________________________________________
*| 												|
*| 	����:				House.cpp				|
*|	��������:	����������� ������� House		|
*|												|
*|==============================================|
*|												|
*|	�����:			  ������� �.�.				|
*|	������:			  �3�-211�-20				|
*|												|
*|==============================================|
*|												|
*|	��� �����:		lebivan2002@ya.ru			|
*|______________________________________________|
*/

/*
*			� � � � � � � �   � � � � � � �
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

#include "House.h"	// ������������ ���� � ����������� ������

House::House() : IFigure() {}					// ����������� �� ���������
House::House(const int InitX, const int InitY)	// ����������� ����� ���������� �����
	: IFigure(InitX, InitY) {}					// ������� ���������� � ������� �����
House::House(const Point& point)				// ����������� ����� ������ �����
	: IFigure(point) {}							// ������� ������ � ������� �����
House::~House() {}								// ������������ ����������

void House::Show() {// ����� ��� �����������
	visible = true; // ������ �������
	/*����� ����*/
	FrontSide(x_pos, y_pos + 40, x_pos + 130, y_pos + 180, RGB(254, 255, 220));

	/*����������� �����*/
	FrontRoof(x_pos, y_pos + 40, x_pos + 130, y_pos + 40, x_pos + 65, y_pos, RGB(199, 214, 255));

	/*��� ����� ��������������*/
	SideRoof(RGB(200, 10, 10), 4, x_pos + 65, y_pos, x_pos + 280, y_pos, x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 40);

	/*��� ����*/
	FrontSide(x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 180, RGB(200, 255, 200));

	/*�����*/
	FrontSide(x_pos + 70, y_pos + 100, x_pos + 110, y_pos + 180, RGB(175, 75, 0));

	/*����� �����*/
	SideWall(x_pos + 100, y_pos + 140, x_pos + 105, y_pos + 145, RGB(0, 0, 0));

	/*����*/
	FrontSide(x_pos + 150, y_pos + 100, x_pos + 190, y_pos + 140, RGB(255, 243, 0));
	FrontSide(x_pos + 220, y_pos + 100, x_pos + 260, y_pos + 140, RGB(255, 243, 0));
	FrontSide(x_pos + 290, y_pos + 100, x_pos + 330, y_pos + 140, RGB(255, 243, 0));
} // ����� Show()

void House::Hide() { // ����� ��� ��������
	visible = false; // ������ ���������
	/*����� ����*/
	FrontSide(x_pos, y_pos + 40, x_pos + 130, y_pos + 180, BACKGROUND_COLOR);

	/*����������� �����*/
	FrontRoof(x_pos, y_pos + 40, x_pos + 130, y_pos + 40, x_pos + 65, y_pos, BACKGROUND_COLOR);

	/*��� ����� ��������������*/
	SideRoof(BACKGROUND_COLOR, 4, x_pos + 65, y_pos, x_pos + 280, y_pos, x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 40);

	/*��� ����*/
	FrontSide(x_pos + 345, y_pos + 40, x_pos + 130, y_pos + 180, BACKGROUND_COLOR);

	/*�����*/
	FrontSide(x_pos + 70, y_pos + 100, x_pos + 110, y_pos + 180, BACKGROUND_COLOR);
} // ����� Hide()

void House::Earthquake() {			// ����� �������������
	int x0 = GetX();				// �������� � ��������� ������� ���������� ���� �� �
	int y0 = GetY();				// �������� � ��������� ������� ���������� ���� �� �

	for (short i = 0; i < 5; ++i) {	// ������� 5 �������
		x0 += 50;					// �������� ���������� ����
		MoveTo(x0, y0);				// ����������� ��� ������
		Sleep(50);					// ��������� 50 ��

		x0 -= 50;					// �������� ���������� ����
		MoveTo(x0, y0);				// ����������� ��� �����
		Sleep(50);					// ��������� 50 ��
		
		y0 -= 50;					// �������� ���������� ����
		MoveTo(x0, y0);				// ������� ��� ����
		Sleep(50);					// ��������� 50 ��

		y0 += 50;					// �������� ���������� ����
		MoveTo(x0, y0);				// �������� ���
		Sleep(50);					// ��������� 50 ��
	}								// ����� For
} // ����� Earthquake()



void House::FrontSide(						// ����� ��� ��������� ��������������
	const int InitX1, const int InitY1		// ���������� ������ ������� ����
	, const int InitX2, const int InitY2	// ���������� ������� �������� ����
	, const COLORREF& color					// ���� ��������������
	){										// ����� �������� �����������

	HBRUSH brush = CreateSolidBrush(color);	// ������� ����� � ���������� � ����
	SelectObject(hdc, brush);				// ������������ �����
	Rectangle(hdc, InitX1, InitY1			// ���������� �������������
				 , InitX2, InitY2);
	DeleteObject(brush);					// ������� �����
} // ����� FrontSide()

void House::SideWall(						// ����� ��� ��������� ������� ������� ����
	const int InitX1, const int InitY1		// ���������� �����, �������
	, const int InitX2, const int InitY2	// ������ � ������ ������
	, const COLORREF& color					// ���� �������
	){										// ����� �������� �����������

	HBRUSH brush = CreateSolidBrush(color);	// ������� ����� � ���������� � ����
	SelectObject(hdc, brush);				// ������������ �����
	Rectangle(hdc, InitX1, InitY1			// ���������� �������������
		, InitX2, InitY2);
	DeleteObject(brush);					// ������� �����
} // ����� Ellipse()

void House::FrontRoof(						// ����� ��� ��������� ����������� �����
	const int InitX1, const int InitY1		// ���������� ������ �������
	, const int InitX2, const int InitY2	// ���������� ������ �������
	, const int InitX3, const int InitY3	// ���������� ������� �������
	, const COLORREF& color					// ���� ������������
	){										// ����� �������� �����������

	POINT poly[3] = {						// ������ ����� ��� ��������� ��������
					    {InitX1, InitY1 }	// ������ �������
					  , { InitX2 , InitY2 } // ������ �������
					  , {InitX3, InitY3}	// ������ �������
					};						// ����� �������

	HBRUSH brush = CreateSolidBrush(color);	// ������� ����� � ���������� � ����
	SelectObject(hdc, brush);				// ������������ �����
	Polygon(hdc, poly, 3);					// ���������� ������ �������
	DeleteObject(brush);					// ������� �����
} // ����� FrontRoof()

void House::SideRoof(						// ����� ��� ��������� ������� ������� �����
	const COLORREF& color					// ���� ��������
	, const int points_count				// ���������� ������
	, ...									// ���� �������
	){										// ����� �������� �����������

	va_list vl;								// ��� ���������� �������������� ���������� ������� � ���������� ������ ����������
	POINT* points = new POINT[points_count];// ������������ ������ �����
	int x;									// ��������� ���������� ��� ������ � ������ �����
	va_start(vl, points_count);				// ���������� ��������� �� ��������� ��������� �������
	for (int i = 0; i < points_count * 2; ++i) { // ������ �� ���� ����������� ������ �����
		if ((i + 1) % 2 == 1) {				// �������� ���������� � ��� ������� �����?
			x = va_arg(vl, int);			// ��������� ���������� � ��� ������� �����
		} else {							// ����� (�������� ���������� �)
			points[i / 2] = { x, va_arg(vl, int) };	// �������� � ������ ���������� ��������� �����
		}									// ����� ����
	}										// ����� For
	va_end(vl);								// ��� ����������� ���������� ������ �������, �������� � ���� � �������� va_start

	HBRUSH brush = CreateSolidBrush(color);	// ������� ����� � ���������� � ����
	SelectObject(hdc, brush);				// ������������ �����
	Polygon(hdc, points, points_count);		// ���������� ������ �������
	DeleteObject(brush);					// ������� �����

	delete[] points;						// ������� ������������ ������

} // ����� SideRoof()

uint8_t House::GetTypeId() const {			// ����� ��� ��������� ����������� Id ������
	return type_id;							// ������� �������� Id
} // ����� GetTypeId()
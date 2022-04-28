/*
* ______________________________________________
*| 												|
*| 	����:			  Meteorite.cpp				|
*|	��������:	����������� ������� Meteorite   |
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
*						 /		Moon  Sun  Meteorite <--
*				      House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Meteorite.h"	// ������������ ���� � ������� �������

Meteorite::Meteorite(int InitX = 10, int InitY = 10, int InitRadius = 10) // ����������� � �����������
	: Circle(InitX, InitY, InitRadius) { // ������������� ����� ������
} // ����� Meteorite()

Meteorite::Meteorite(const Point& InitPoint, int InitRadius)
	: Circle(InitPoint, InitRadius) {
}

Meteorite::~Meteorite() {}	// ����������� ����������

void Meteorite::Show() {	// ����������� ���������
	visible = true;			// ���������� ���������
	HBRUSH brush = CreateSolidBrush(RGB(73, 66, 61));
	SelectObject(hdc, brush);// ������������ �����
	// �������� ���� ������������� ������
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);

	brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, brush);				// ������������ �����
	// �������
	Ellipse(hdc, x_pos, y_pos, x_pos - radius / 2 + 2, y_pos - radius / 2 + 3);
	Ellipse(hdc, x_pos + radius / 2 - 15, y_pos + radius / 2 - 15, x_pos + radius / 2 + 2, y_pos + radius / 2 + 3);
	Ellipse(hdc, x_pos - radius / 2, y_pos + radius / 2 - 15, x_pos + 5, y_pos + radius / 2);
	DeleteObject(brush);
} // ����� Show()

uint8_t Meteorite::GetTypeId() const {	// ����� ��� ��������� ����������� Id ������
	return type_id;						// ������� �������� Id
} // ����� GetTypeId()
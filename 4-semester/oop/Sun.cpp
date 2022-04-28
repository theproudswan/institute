/*
//______________________________________________
//												|
//	����:				Sun.cpp    				|
//	��������:	    ����������� ������� Sun		|
//												|
//==============================================|
//												|
//	�����:			  ������� �.�.				|
//	������:			  �3�-211�-20				|
//												|
//==============================================|
//												|
//	��� �����:		lebivan2002@ya.ru			|
//______________________________________________|
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
*						 /	    Moon  Sun  Meteorite
*					 House             /\
*					  / \              ||
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Sun.h"			// ������������ ���� � ����������� ������

Sun::Sun(int InitX = 10, int InitY = 10, int InitRadius = 10) // ����������� � �����������
	: Circle(InitX, InitY, InitRadius) {					  // ������������� ����� �������� ������
} // ����� Meteorite()

Sun::Sun(const Point& InitPoint, int InitRadius)			  // ����������� ����� ������ �����
	: Circle(InitPoint, InitRadius) {						  // ������������� ����� �������� ������
} // ����� Meteorite()

Sun::~Sun() {}		// ����������� ����������

void Sun::Show() {  // ����������� ���������
	visible = true;	// ���������� ���������
	HBRUSH brush = CreateSolidBrush(RGB(255, 249, 23));
	SelectObject(hdc, brush);				// ������������ �����
	// �������� ���� ������������� ������
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);

} // ����� Show()

uint8_t Sun::GetTypeId() const {	// ����� ��� ��������� ����������� Id ������
	return type_id;					// ������� �������� Id
} // ����� GetTypeId()
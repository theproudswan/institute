/*
//______________________________________________
//												|
//	����:				Circle.cpp				|
//	��������:	����������� ������� Circle		|
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

#include "Circle.h"		// ������������ ���� � ����������� �������� ������

Circle::Circle() {}		// ����������� �� ���������
Circle::Circle(const int InitX, const int InitY, const int InitRadius) // ����������� ����� ����������
	: Point(InitX, InitY) {	// ������������� ������������� ������
	radius = InitRadius;	// ������ ����������� ������
} // ����� Circle()

Circle::Circle(const Point& InitPoint, const int InitRadius) // ����������� ����� ������ �����
	: Point(InitPoint) {									 // ������������� ������������� ������
	radius = InitRadius;									 // ������ ����������� ������
} // ����� Circle()

Circle::~Circle() {}	// ����������� ������

void Circle::SetRadius(const int InitRadius) {	// ����� ��� ������������ ������� ����������
	radius = InitRadius;						// ������ ����� ������
} // ����� SetRadius()

int Circle::GetRadius() const {					// ����� ��� ��������� ������� ����������
	return radius;								// ������� �������� �������
} // GetRadius()

bool Circle::Touch(const int AnotherObjX, const int AnotherObjY) const { // ������ � ������������
	// ������������ ����������� �� �������:
	// (x - x0)^2 + (y - y0)^2 <= R^2
	// 
	// x  - ���������� ������� ������� �
	// �0 - ���������� ��������� �� �
	// �  - ���������� ������� ������� �
	// �0 - ���������� ��������� �� �
	// R  - ������ ���������

	// ���� ������� ���� �������, ������� true, ����� - false
	if (pow(AnotherObjX - x_pos, 2) + pow(AnotherObjY - y_pos, 2) <= pow(radius, 2)) return true;
	return false;
} // ����� Touch()

void Circle::Hide() { // �������� ���������
	visible = false;	// ������ ���������
	HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
	SelectObject(hdc, brush);				// ������������ �����
	// ���������� ������ ������ ����������
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);
} // ����� Hide()
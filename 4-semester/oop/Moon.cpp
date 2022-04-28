/*
//______________________________________________
//												|
//	����:				Moon.cpp  				|
//	��������:	  ����������� ������� Moon		|
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
*						 /	--> Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#include "Moon.h"	// ����������� ������������� ����� � ����������� ������

Moon::Moon(int InitX = 10, int InitY = 10, int InitRadius = 10) // ����������� � �����������
	: Circle(InitX, InitY, InitRadius) { // ������������� ����� ������
} // ����� Meteorite()

Moon::Moon(const Point& InitPoint, int InitRadius) // ����������� ����� ������ �����
	: Circle(InitPoint, InitRadius) {			   // ������������� �������� ������
} // ����� Meteorite()

Moon::~Moon() {}	// ����������� ����������

void Moon::Show() { // ����������� ���������
	visible = true;	// ���������� ���������
	HBRUSH brush = CreateSolidBrush(RGB(189, 208, 228));
	SelectObject(hdc, brush);// ������������ �����
	// �������� ���� ������������� ������
	Ellipse(hdc, x_pos - radius, y_pos - radius, x_pos + radius, y_pos + radius);
	DeleteObject(brush);	 // ������� ������ �����

} // ����� Show()

uint8_t Moon::GetTypeId() const {	// ����� ��� ��������� ����������� Id ������
	return type_id;						// ������� �������� Id
} // ����� GetTypeId()
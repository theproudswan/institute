/*
* _______________________________________________
*|												|
*|	����:			 BrokenHouse.cpp			|
*|	��������:	����������� ������� BrokenHouse	|
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
*					 House
*					  / \
*					 /   \
*					/	  \
*	  --> BrokenHouse	  HappyHouse
*
*/


#include "BrokenHouse.h"		// ������������ ���� � ����������� �������

BrokenHouse::BrokenHouse() {}	// ����������� �� ���������
BrokenHouse::~BrokenHouse() {}	// ���������� (�����������)

BrokenHouse::BrokenHouse(const int InitX, const int InitY)		// ����������� ����� ���������� �����
	: House(InitX, InitY) {}									// ������� ���������� � ������� �����

BrokenHouse::BrokenHouse(const Point& point)					// ����������� ����� ������ �����
	: House(point) {}											// ������� ������ � ������� �����

void BrokenHouse::Show() {	// �����������

	visible = true;	// ���������� ���������
	House::Show();	// ���������� ������ ������������� ������, 
					// ������ �������� ����� ���������� ��������

	/*��� ����� -- ��������������*/
	SideRoof(RGB(150, 30, 30), 4, 
				  x_pos + 65, y_pos
				, x_pos + 280, y_pos
				, x_pos + 345, y_pos + 40
				, x_pos + 130, y_pos + 40
			);

	/*���� � �����*/
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, brush);				// ������������ �����
	Ellipse(hdc, x_pos + 190, y_pos + 10
			, x_pos + 230, y_pos + 30
			);
	DeleteObject(brush);
	/*����*/
	FrontSide(   x_pos + 150, y_pos + 100
				, x_pos + 190, y_pos + 140
				, RGB(0, 0, 0)
			  );

	FrontSide(	  x_pos + 220, y_pos + 100
				, x_pos + 260, y_pos + 140
				, RGB(0, 0, 0)
			  );

	FrontSide(	  x_pos + 290, y_pos + 100
				, x_pos + 330, y_pos + 140
				, RGB(0, 0, 0)
			  );
	
} // ����� Show()

uint8_t BrokenHouse::GetTypeId() const { // ����� ��� ��������� ����������� �������������� ������
	return type_id;						 // ������� �������������
}										 // ����� GetTypeId()
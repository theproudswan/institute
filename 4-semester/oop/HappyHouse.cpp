/*
* ______________________________________________
*|												|
*|	����:			 HappyHouse.cpp				|
*|	��������:	����������� ������� HappyHouse	|
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
*					      Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite
*					 House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse <--
*
*/



#include "HappyHouse.h"			// ������������ ���� � ����������� ������ HappyHouse

HappyHouse::HappyHouse() {}		// ����������� ������ �� ���������
HappyHouse::~HappyHouse() {}	// ���������� ������

HappyHouse::HappyHouse(const int InitX, const int InitY)	// ����������� ����� ���������� �����
	: House(InitX, InitY) {}								// ������� ���������� � ������� �����

HappyHouse::HappyHouse(const Point& point)					// ����������� ����� ������ �����
	: House(point) {}										// ������� ����� � ������� �����

void HappyHouse::Show() {	// �����������

	visible = true;	// ���������� ���������
	House::Show();	// ���������� ������ ������������� ������, 
					// ������ �������� ����� ���������� ��������

	/*��� ����� ��������������*/
	SideRoof(RGB(255, 0, 0), 4, 
					  x_pos + 65, y_pos
					, x_pos + 280, y_pos
					, x_pos + 345, y_pos + 40
					, x_pos + 130, y_pos + 40
			);

	/*����*/
	FrontSide(	  x_pos + 150, y_pos + 100
				, x_pos + 190, y_pos + 140
				, RGB(226, 88, 34)
			  );

	FrontSide(	  x_pos + 220, y_pos + 100
				, x_pos + 260, y_pos + 140
				, RGB(226, 88, 34)
			  );

	FrontSide(	  x_pos + 290, y_pos + 100
				, x_pos + 330, y_pos + 140
				, RGB(226, 88, 34)
			  );
} // ����� Show()

uint8_t HappyHouse::GetTypeId() const { // �������� ���������� Id ������
	return type_id;						// ������� id ������
} // ����� GetTypeId()
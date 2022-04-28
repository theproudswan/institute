/*
* ______________________________________________
*| 												|
*| 	����:				Location.cpp			|
*|	��������:	 ����������� ������� Location	|
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
*							   Location <--
*								  |
*								  |
*								Point
*							   /     \
*							  /       \
*						  Figure    Circle
*						   /		/  |  \
*						  /        /   |   \
*						 /		Moon  Sun  Meteorite
*				      House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/


#include "Location.h"  // ������������ ���� � ����������� ������

Location::Location() {  // ����������� �� ���������
    //cout << "Location()" << endl;
}                       // ����� Location()

Location::~Location() { // ����������
    //cout << "~Location()" << endl;
}                       // ����� ~Location()

Location::Location(const int InitX, const int InitY) // ����������� ����� ���������� �����
    : x_pos(InitX), y_pos(InitY) {}                  // ������������� �����

int Location::GetX() const {    // ����� ��� ��������� �������� ���������� �
    return x_pos;               // ������� �������� ���������� �
}                               // ����� GetX()

int Location::GetY() const {    // ����� ��� ��������� �������� ���������� Y
    return y_pos;               // ������� �������� ���������� Y
}                               //  ����� GetY()

void Location::SetX(const int InitX) {  // ����� ��� ������������ �������� �
    x_pos = InitX;                      // ���������� �������� �
}                                       // ����� SetX()

void Location::SetY(const int InitY) {  // ����� ��� ������������ �������� �
    y_pos = InitY;                      // ���������� �������� �
}                                       // ����� SetY()


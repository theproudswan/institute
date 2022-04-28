/*
* ______________________________________________
*| 												|
*| 	����:				Point.cpp				|
*|	��������:	����������� ������� Point		|
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
*								Point <--
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


#include "Point.h"  // ������������ ���� � ������������

Point::Point() {    // ����������� �� ���������
    //cout << "Point()" << endl;
}                   // Point()

Point::~Point() {   // ����������
    //cout << "~Point()" << endl;
}                   //~Point() 

Point::Point(const Point& InitPoint)                    // ����������� ����� ������ ������ ����� ������
    : Location(InitPoint.GetX(), InitPoint.GetY()) {    // �������������� ������� �����
    *this = InitPoint;                                  // ������������� �������� ������� ����� ���������
}                                                       // ����� Point()

Point::Point(const int x, const int y)  // �����������
    : Location(x, y) {}                 // � �������������� ����� ������� �����

Point::Point(const int x, const int y, COLORREF new_color) // �����������, �������� ��� � ���� �����,
    : Location(x, y) {                                     // � �������������� ����� ������� �����
    color = new_color;                                     // ������ ���� �����
}                                                          // ����� Point()

void Point::SetColor(COLORREF new_color) { // ����� ��� ��������� ����� �����
    color = new_color;                     // ���������� ���� �����
}                                          // ����� SetColor()

COLORREF Point::GetColor() const { // �������� ���� �����
    return color;                  // ������� ���� �����
}                                  //  ����� GetColor()

void Point::Show() {                    // ����������� �����
    visible = true;                     // ���������� ��������� �� true
    SetPixel(hdc, x_pos, y_pos, color); // ��������� �������
}                                       // ����� Show()

void Point::Hide() {                               // �������� �����
    visible = false;                               // ���������� ��������� �� false
    SetPixel(hdc, x_pos, y_pos, BACKGROUND_COLOR); // ���������� ������� ����� ����
}                                                  // ����� Hide()

bool Point::IsVisible() const { // ������ ��������� �����
    return visible;             // ������� ���������
}                               // ����� IsVisible()

void Point::MoveTo(const int NewX, const int NewY) { // ����������� �����
    Hide();                                          // ������ �����
    *this = Point(NewX, NewY);                       // ������� ����� ������ ����� �� ������ �����
    Show();                                          // �������� �����
}                                                    // ����� MoveTo()

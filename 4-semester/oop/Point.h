/*
* ______________________________________________
*| 												|
*| 	����:				Point.h 				|
*|	��������:	  ���������� ������� Point		|
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

#pragma once          // ��������� �������� �������� ���������

#include "Location.h" // ������������ ���� � ����������� �������� ������

class Point :       // ����� Point
    public Location // ����������� �� ������ Location
{ 
public: // ������ ��������� ������
    Point();            // ����������� �� ���������
    ~Point() override;  // ���������� �� ���������
    Point(const Point& InitPoint);      // ����������� ����� ������ ������ ����� ������
    Point(const int x, const int y);    // ����������� ����� ����������
    Point(const int x, const int y, COLORREF new_color);    // ����������� ����� ���������� � ����

    void SetColor(COLORREF new_color); // ����� ��� ��������� ����� �����
    COLORREF GetColor() const;         // ����� ��� ��������� ����� �����

    virtual void Show();    // ����������� ����� ��� ������������ �����
    virtual void Hide();    // ����������� ����� ��� �������� �����

    void MoveTo(const int NewX, const int NewY);    // ����������� ����� ��� ����������� �����

    bool IsVisible() const; // �����, ����� ������ ��������� �����

protected: // ���������� ������
    COLORREF color = BACKGROUND_COLOR; // ���� ����� �����
    bool visible = false;              // ���� ��������� �����
}; // ����� Point


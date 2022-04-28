/*
//______________________________________________
//												|
//	����:				Circle.h				|
//	��������:	���������� ������� Circle		|
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

#pragma once       // ��� ��������� �������� �������� ���������

#include "Point.h" // ������������ ���� � ������� �������

class Circle :      // ������ ���������� ������
    public Point    // �������� ����������� �� Point
{
public:             // ������ ��������� ������
    Circle();       // ����������� �� ���������
    Circle(const int InitX, const int InitY, const int InitRadius = 10); // ����������� ����� ����������
    Circle(const Point& InitPoint, const int InitRadius = 10);           // ����������� ����� ������ �����
    virtual ~Circle() override;                                          // ����������� ����������

    void SetRadius(const int InitRadius);                                // ����� ��� ������������ �������
    int GetRadius() const;                                               // ����� ��� ��������� �������

    virtual void Show() = 0;                                             // ����������� ����� �����������
    virtual void Hide();                                                 // ����������� ����� ��������
    bool Touch(const int AnotherOgjX, const int AnotherObjY) const;      // ����� ��� �������� �������
    virtual uint8_t GetTypeId() const = 0;                               // ����������� ����� ��� ��������� ����������� Id ������

protected:              // ���������� ������ ������
    int radius = 10;    // ������ ����������
};  // ����� ���������� Circle


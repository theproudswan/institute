/*
* ______________________________________________
*| 												|
*| 	����:			  Meteorite.h				|
*|	��������:	���������� ������� Meteorite    |
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

#pragma once        // ��� ��������� �������� �������� ���������

#include "Circle.h" // ������������ ���� � ������� �������
#include <cmath>    // ���������� � ��������������� ���������

class Meteorite :   // ���������� ������ Meteorite
    public Circle   // �������� ����������� �� Figure
{
public: // ��������� ������

    Meteorite() = default; // ����������� �� ���������
    Meteorite(int InitX, int InitY, int InitRadius); // ����������� � �����������
    Meteorite(const Point& InitPoint, int InitRadius); // ����������� � �����������
    ~Meteorite() override; // ����������� ����������

    virtual void Show() override;       // ����������� ����� �����������
    virtual uint8_t GetTypeId() const;  // ����� ��� ��������� ����������� Id ������

private:                                // ��������� ������
    uint8_t type_id = 0;                // ���������� Id ������
}; // ����� ���������� Meteorite


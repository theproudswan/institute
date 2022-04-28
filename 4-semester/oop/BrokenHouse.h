/*
* ______________________________________________
*|												|
*|	����:			 BrokenHouse.h				|
*|	��������:	���������� ������� BrokenHouse	|
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

#pragma once        // ��� ��������� �������� �������� ���������
#include "House.h"  // ������������ ���� � ������� �������

class BrokenHouse : // ������ ���������� ������ BrokenHouse
    public House    // �������� ����������� �� ������ House
{
public:             // ������ ��������� ������
    BrokenHouse();  // ����������� �� ���������
    BrokenHouse(const int InitX, const int InitY);  // ����������� ����� ���������� �����
    BrokenHouse(const Point& point);                // ����������� ����� ������ �����
    virtual ~BrokenHouse() override;                // ����������� ����������
    virtual void Show() override;                   // ����������� ����� �����������
    virtual uint8_t GetTypeId() const;              // ��������� ����������� �������������� ������

private:            // ������ ��������� ������
    uint8_t type_id = 2;
}; // ����� ���������� BrokenHouse


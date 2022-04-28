/*
* ______________________________________________
*| 												|
*| 	����:				Figure.h				|
*|	��������:	���������� ������� Figure		|
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
*					  --> Figure    Circle 
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

#pragma once        // ��� ��������� �������� �������� ���������

#include "Point.h"  // ������������ ���� � ������� �������

class IFigure :      // ����� Figure
    public Point    // ����������� �� ������ Point
{
public:             // ������ ��������� ������
    IFigure();									// ����������� �� ���������
    ~IFigure() override;							// ����������� ���������� 
    IFigure(const Point& InitPoint);				// ����������� ������ �����
    IFigure(const int InitX, const int InitY);	// ����������� ����� ���������� �����

    virtual void FrontSide(						// ����� ��� ��������� ����������� ����� ����
		const int InitX1, const int InitY1		// ���������� ������ ������� ����
		, const int InitX2, const int InitY2	// ���������� ������� �������� ����
		, const COLORREF& color					// ���� ��������������
	) = 0;										// ����� �������� �����������

	virtual void SideWall(						// ����� ��� ��������� ������� ����� ����
		const int InitX1, const int InitY1		// ���������� �����, �������
		, const int InitX2, const int InitY2	// ������ � ������ ������
		, const COLORREF& color					// ���� �������
	) = 0;										// ����� �������� �����������
	
	virtual void FrontRoof(						// ����� ��� ��������� ����������� �����
		const int InitX1, const int InitY1		// ���������� ������ �������
		, const int InitX2, const int InitY2	// ���������� ������ �������
		, const int InitX3, const int InitY3	// ���������� ������� �������
		, const COLORREF& color					// ���� ������������
	) = 0;										// ����� �������� �����������

	virtual void SideRoof(						// ����� ��� ��������� �������� (��������������)
		const COLORREF& color					// ���� ��������
		, const int points_count				// ���������� ������
		, ...									// ���� �������
	) = 0;										// ����� �������� �����������

    virtual void Show() override = 0;   // ����� ��� ����������� ������
    virtual void Hide() override = 0;   // ����� ��� �������� ������

	virtual void Earthquake() = 0;			// ����� ��� ��������� �������������
	virtual uint8_t GetTypeId() const = 0;	// ����� ��� ��������� ����������� Id ������

}; // ����� Figure


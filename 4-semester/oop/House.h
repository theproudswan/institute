/*
* ______________________________________________
*| 												|
*| 	����:				House.h					|
*|	��������:	���������� ������� House		|
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
*				  --> House
*					  / \
*					 /   \
*					/	  \
*			BrokenHouse	  HappyHouse
*
*/

#pragma once			// ��� ��������� �������� �������� ���������

#include "Figure.h"		// ������������ ���� � ������� �������

class House : public IFigure {	// ����� House �������� ����������� �� ������ Figure
public:	// ������ ��������� ������
	House();	// ����������� �� ���������
	House(const int InitX, const int InitY);	// ����������� ����� ���������� �����
	House(const Point& point);					// ����������� ����� ������ �����
	~House() override;							// ����������� ����������

	void Hide() override;						// ����������� ����� �����������
	void Show() override;						// ������������ ����� ��������
	void Earthquake();							// ����� ��� �������������
	virtual uint8_t GetTypeId() const;			// ����� ��� ��������� ����������� Id ������

protected:	// ���������� ������

	virtual void FrontSide(						// ����� ��� ��������� ����������� ����� ����
		const int InitX1, const int InitY1		// ���������� ������ ������� ����
		, const int InitX2, const int InitY2	// ���������� ������� �������� ����
		, const COLORREF& color					// ���� ��������
	) override;									// ����� �������� �����������

	virtual void SideWall(						// ����� ��� ��������� ������� ����� ����
		const int InitX1, const int InitY1		// ���������� �����, �������
		, const int InitX2, const int InitY2	// ������ � ������ ������
		, const COLORREF& color					// ���� �������
	) override;									// ����� �������� �����������

	virtual void FrontRoof(						// ����� ��� ��������� ����������� �����
		const int InitX1, const int InitY1		// ���������� ������ �������
		, const int InitX2, const int InitY2	// ���������� ������ �������
		, const int InitX3, const int InitY3	// ���������� ������� �������
		, const COLORREF& color					// ���� ������������
	) override;									// ����� �������� �����������

	virtual void SideRoof(						// ����� ��� ��������� ���� �����
		const COLORREF& color					// ���� ��������
		, const int points_count				// ���������� ������ � �����
		, ...									// ���� �������
	) override;									// ����� �������� �����������


private:										// ��������� ������ ������
	uint8_t type_id = 0;						// ���������� Id ������
};	// ����� ���������� House
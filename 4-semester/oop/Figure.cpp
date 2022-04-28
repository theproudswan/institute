/*
* ______________________________________________
*| 												|
*| 	����:				Figure.cpp				|
*|	��������:	����������� ������� Figure		|
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

#include "Figure.h" // ���� � ������������ ������

IFigure::IFigure() { // ����������� �� ���������
    //cout << "Figure()" << endl;
}                  // ����� Figure()

IFigure::~IFigure() { // ����������
    //cout << "~Figure()" << endl;
}                   // ����� ~Figure()


IFigure::IFigure(const Point& InitPoint) // ����������� ����� ������ �����
    : Point(InitPoint) {}                // ������������� �������� ������

IFigure::IFigure(const int InitX, const int InitY) // ����������� ����� ���������� �����
    : Point(InitX, InitY) {}                       // ������������� �������� ������


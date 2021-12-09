//============================================================================
// ����������  : g++ v. 10.2.1
// ��������    : LinkedList.h
// �����       : ������� ����
// ������      : �3�-211�-20
// ����������  : �������� � ����������� ������ LinkedList
//============================================================================
#include "Deque.h" // ������������ ���� � ���������� �������
#include <iostream>		// ���������� ��� ������ � �������/�������� ��������

using namespace std; // ������������ ��� ��� ������ � ��������� ����������� ����������


int main() {
	Deque<int> d;
	d.Clear();
	d.PushBack(3);
	cout << d.GetFirst() << endl;
	d.GetFirst() = 5;
	cout << d.GetFirst() << endl;
	d[0] = 22;
	cout << d.GetFirst() << endl;
	Deque<int> d2;
	d2 = d;
	cout << d2[0] << endl;
	d[0] = 77;
	cout << d2[0] << endl;
	return 0;
}
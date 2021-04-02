// Здесь несолько вариантов. Их номера из года в год меняются, а суть нет

#include <iostream>

using namespace std;

int main() {
	/*
	short a = 23;
	short b = -30;
	short c = 42;
	short d = 21;
	short answer = 0;
	__asm {
		MOV AX, a;
		MUL AX;
		ADD answer, AX;
		MOV AX, c;
		MOV DX, 0;
		MOV BX, b;
		IDIV BX;
		SUB answer, AX;
		MOV BX, d;
		MOV AX, 2;
		IMUL BX;
		ADD answer, AX;
	}
	cout << answer << endl;
	cout << "Correct answer: " << a * a - (c / b) + 2 * d << endl;
	*/
	/*
	short a = 29;
	short b = 18;
	short c = -34;
	short d = 44;
	short answer = 0;
	__asm {
		MOV AX, b;
		MUL AX;
		SUB AX, a;
		ADD answer, AX;
		MOV AX, c;
		ADD AX, 12
		MOV DX, 0;
		MOV BX, AX;
		MOV AX, answer;
		IDIV BX;
		MOV answer, AX;
		MOV BX, d;
		MOV AX, 4;
		IMUL BX;
		ADD answer, AX;
	}
	cout << answer << endl;
	cout << "Correct answer: " << ((b * b - a) / (c + 12)) + 4 * d << endl;
	*/
	/*
	short a = 25;
	short b = 71;
	short c = 56;
	short d = -35;
	short answer = 0;
	__asm {
		MOV AX, c;
		MUL AX;
		MOV answer, AX;

		MOV BX, b;
		MOV AX, a;
		IMUL BX;

		MOV BX, d;
		ADD BX, 10;

		MOV DX, 0;
		IDIV BX;

		MOV AX, 2;
		IMUL DX;

		SUB answer, AX;

	}
	cout << answer << endl;
	cout << "Correct answer: " << c * c - 2 * ((a * b) % (d + 10)) << endl;
	*/
	short a = 30;
	short b = -14;
	short c = 28;
	short d = 36;
	short answer = 0;
	__asm {
		MOV BX, d
		MOV AX, 2;
		IMUL BX;
		MOV answer, AX;

		MOV AX, a;
		ADD AX, b;

		MOV BX, c;
		SUB BX, 17;

		IDIV BX;
		ADD answer, AX;

	}
	cout << answer << endl;
	cout << "Correct answer: " << 2 * d + ((a + b) / (c - 17)) << endl;
	system("pause");
}

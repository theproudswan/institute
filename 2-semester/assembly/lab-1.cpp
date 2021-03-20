// a^2-(c Div b)+2·d
#include <iostream>

using namespace std;

int main() {
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
	system("pause");
}

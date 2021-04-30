// Вариант 8

#include <iostream>

int main() {
	short int x = -3;
	short int a = 5;
	short int b = -3;
	short int c = 4;
	short int d = 16;
	short int y = 0;
	printf(" x |\t y\n");

	__asm {
	next_x:
		INC x;
		CMP x, 6;
		JG quit;
		CMP x, 0;
		JL lower_zero;
		JE equal_zero;
		JG greater_zero;
	}
	__asm {
	print_x_y:
	}
	puts("----------------------");
	printf("%2d |\t %3d\n", x, y);
	__asm {
		JMP next_x;
	}
	__asm {
	lower_zero:
		MOV y, 0;
		MOV AX, a;
		MUL AX;
		SUB AX, x;
		MOV BX, c;
		IDIV BX;
		MOV y, AX;
		JMP print_x_y;
	}
	__asm {
	equal_zero:
		MOV y, 0;
		MOV AX, a;
		MUL AX;
		SUB y, AX;
		MOV AX, b;
		MOV BX, d;
		IMUL BX;
		ADD y, AX;
		JMP print_x_y;
	}
	__asm {
	greater_zero:
		MOV y, 0;
		MOV AX, a;
		MUL AX;
		ADD AX, x;
		MOV BX, b;
		IMUL BX;
		ADD y, AX;
		JMP print_x_y;
	}
	__asm {
	quit:
	}
	printf("\n\n\n");
	x = -3;
	a = 5;
	b = -3;
	c = 4;
	d = 16;
	y = 0;
	printf(" x |\t y\n");

	for (x = -2; x <= 6; ++x) {

		if (x < 0) {
			y = (a * a - x) / c;
		}
		else if (x == 0) {
			y = b * d - a * a;
		}
		else {
			y = (a * a + x) * b;
		}
		puts("----------------------");
		printf("%2d |\t %3d\n", x, y);
	}
	return 0;
}
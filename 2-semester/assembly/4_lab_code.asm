.model small

.stack 100h

.data

a dw 5

b dw -3

c dw 4

d dw 16

x dw -3

y dw 0

w2 db 32 dup (0)

w1 db 32 dup (0)

ten dw 10

printNumber proc

lea SI, w1

lea DI, w2

mov BX, 0h

mov DX, 0h

cmp AX, 0;//Проверка на отрицательное число

JNL printL1

mov [DI], '-'

inc BX

add DI, 1

neg AX

printL1:; //Перевод числа в 10-ричную

div ten

add DL, 30h

mov [SI], DL

mov DX, 0

add SI, 1

inc BX

cmp AX, 0

jg printL1

sub SI, 1

printL2:; //Записывание числа в строку

mov AL, [SI]

mov [DI], AL

sub SI, 1

add DI, 1

cmp SI, offset w1

jge printL2

add BL, 3;//Добавления перевода строки и конца вывода

mov [DI], 13; \r

add DI, 1

mov [DI], 10; \n

add DI, 1

mov [DI], '$'

mov AH, 09h ;//Вывод данных в консоль

mov DX, offset w2

int 21h ; Вызов DOS

add SI, BX; //Очистить стэк

printL3:

mov [SI], 0h

mov [DI], 0h

sub DI, 1

sub SI, 1

cmp SI, offset w1

jge printL3

ret

printNumber endp

start:

mov	ax, @data

mov	ds, ax

MOV CX,9 ; number of iterations from -2 to 6

next_x:

INC x;

CMP x, 0;

JL lower_zero;

JE equal_zero;

JG greater_zero;

back:

LOOP next_x

JMP quit

print_x_y:

MOV AX, y

;MOV BX, y

CALL printNumber

JMP back;

lower_zero:

MOV y, 0;

MOV AX, a;

MUL AX;

SUB AX, x;

MOV BX, c;

IDIV BX;

MOV y, AX;

JMP print_x_y;

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

greater_zero:

MOV y, 0;
MOV AX, a;
MUL AX;
ADD AX, x;
MOV BX, b;
IMUL BX;
ADD y, AX;
JMP print_x_y;
quit:
mov	ah, 4ch
int	21h
end	start


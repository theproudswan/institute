.model small
.stack 100h

.data
string1 db 8 dup ('$')				; ������ ��� �������������� �����
							; (����� ����� �������� ��������)
string2 db 8 dup ('$')				; ������ ��� ��������� ������
; EndStr db 0Dh, 0Ah, '$'			; ����� �� ��������� �����
count db 0						; ���������� ���� � �����
a db 30
b db -14
c db 28
d db 36

.code
; ��������� ByteToString ���������:
; bh - �����, ������� ����� ��������� � ������
; ���������� string2 - ������, ������������ �� ���� �����
ByteToString Proc
mov count, 0
mov si, 0

; ����, � ������� �������� ����� � ������� � ������ string1
CycleDiv:
cmp bh, 0					; ��������� �������� �������� � ����,
						; ����� ������, ���� �� ��� ����� � �����
jg Branch_1
je Branch_2
jl Branch_3

; �����, ���������� �� ���������� ��������� �����
Branch_1:
mov al, bh
cbw
mov cl, 10
div cl     							; bh ����� �� 10
mov bh, al  						; ������� � bh
add ah, '0'
mov byte ptr string1 + [si], ah		; �������� ����� � ����� ������
add si, 1
inc count
jmp CycleDiv

Branch_3:
neg bh
mov byte ptr string1, '-'
add si, 1
inc count
jmp CycleDiv

; ����� ������ �� �����
Branch_2:
mov al, count
cbw
mov cx, ax
mov bl, byte ptr string1
mov si, 0
mov di, cx
sub di, 1
cmp bl, '-'
je SkipNeg
jne NotNeg
SkipNeg:
mov si, 1
sub cx, 1
mov byte ptr string2, '-'
NotNeg:
; ����, � ������� ���������� ������ string1 � �������� ������� � string2
ChangeStrings:
mov bl, byte ptr string1 + [si]
mov byte ptr string2 + [di], bl
add si, 1
sub di, 1
loop ChangeStrings

ret
ByteToString Endp


start:
mov	ax, @data
mov	ds, ax

; mov ah, 09h
; lea dx, EndStr
; int 21h

mov al, c
mov ah, b
and al, ah              ; c/\b
mov ah, d
mov bl, a
or ah, bl               ; a\/d
not ah                  ; !(a\/d)
or al, ah               ; (c/\b)\/!(a\/d)
mov bh, al


Call ByteToString

mov ah, 09h
mov dx, offset string2
int 21h

mov	ah, 4ch					
int	21h
end	start

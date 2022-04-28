#pragma once	//  Избежание проблемы двойного включения

#include <iostream>	// Библиотека для работы с входными/выходными потоками
#include <Windows.h>// Библиотека для работы с WinAPI
#include <conio.h>	// Библиотека для работы с консолью

using std::cout; // Использовать cout из пространства имён std;
using std::cin;	 // Использовать cin из пространства имён std;
using std::endl; // Использовать endl из пространства имён std;

const HWND hWnd = FindWindowA("ConsoleWindowClass", NULL);	// Получим дескриптор окна   
const HDC hdc = GetDC(hWnd);	// Объявим контекст устройства
								// Контекст устройства по сути это структура,
								// содержащая описание видеокарты на вашем компьютере
								// и всех необходимых графических элементов


#define BACKGROUND_COLOR RGB(0, 0, 0)	// Цвет фона для при сокрытии объектов
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) // Макрос для определения кода нажатой клавиши
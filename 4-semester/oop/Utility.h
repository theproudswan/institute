#pragma once	//  ��������� �������� �������� ���������

#include <iostream>	// ���������� ��� ������ � ��������/��������� ��������
#include <Windows.h>// ���������� ��� ������ � WinAPI
#include <conio.h>	// ���������� ��� ������ � ��������

using std::cout; // ������������ cout �� ������������ ��� std;
using std::cin;	 // ������������ cin �� ������������ ��� std;
using std::endl; // ������������ endl �� ������������ ��� std;

const HWND hWnd = FindWindowA("ConsoleWindowClass", NULL);	// ������� ���������� ����   
const HDC hdc = GetDC(hWnd);	// ������� �������� ����������
								// �������� ���������� �� ���� ��� ���������,
								// ���������� �������� ���������� �� ����� ����������
								// � ���� ����������� ����������� ���������


#define BACKGROUND_COLOR RGB(0, 0, 0)	// ���� ���� ��� ��� �������� ��������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) // ������ ��� ����������� ���� ������� �������
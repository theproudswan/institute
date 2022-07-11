#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <unordered_set>
#include <vector>
#include <string>
#include <dshow.h>

#pragma comment (lib, "Winmm.lib")
#pragma comment( lib, "Strmiids.lib" )

using namespace std;

const HWND hWnd = FindWindowA("ConsoleWindowClass", NULL);	// ������� ���������� ����   
const HDC hdc = GetDC(hWnd);	// ������� �������� ����������
                                // �������� ���������� �� ���� ��� ���������,
                                // ���������� �������� ���������� �� ����� ����������
                                // � ���� ����������� ����������� ���������


#define BACKGROUND_COLOR RGB(0, 0, 0)	// ���� ���� ��� ��� �������� ��������

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) // ������ ��� ����������� ���� ������� �������

#define GetStockPen(i) ((HPEN)GetStockObject(i))

#define SelectPen(hdc, hpen) \
  ((HPEN)SelectObject((hdc), (HGDIOBJ)(HPEN)(hpen)))

#define PACMAN_START_POS 900, 850

#define PACMAN_DOESNT_TOUCH_WALL points.find(POINT({ pacman->GetX() + pacman->GetRadius(), pacman->GetY()})) == points.end()   \
                        && points.find(POINT({ pacman->GetX(), pacman->GetY() + pacman->GetRadius() })) == points.end()        \
                        && points.find(POINT({ pacman->GetX() - pacman->GetRadius(), pacman->GetY() })) == points.end()        \
                        && points.find(POINT({ pacman->GetX(), pacman->GetY() - pacman->GetRadius() })) == points.end()

#define PACMAN_EAT_FOOD food.find(Food({ pacman->GetX() + pacman->GetRadius(), pacman->GetY()})) != food.end()   \
                        && food.find(Food({ pacman->GetX(), pacman->GetY() + pacman->GetRadius() })) != food.end()        \
                        && food.find(Food({ pacman->GetX() - pacman->GetRadius(), pacman->GetY() })) != food.end()        \
                        && food.find(Food({ pacman->GetX(), pacman->GetY() - pacman->GetRadius() })) != food.end()
#define CASTS_SPEED 2
#define PACMANS_COUNT 2
#define FOOD_COUNT 2


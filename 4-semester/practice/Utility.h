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

const HWND hWnd = FindWindowA("ConsoleWindowClass", NULL);	// Получим дескриптор окна   
const HDC hdc = GetDC(hWnd);	// Объявим контекст устройства
                                // Контекст устройства по сути это структура,
                                // содержащая описание видеокарты на вашем компьютере
                                // и всех необходимых графических элементов


#define BACKGROUND_COLOR RGB(0, 0, 0)	// Цвет фона для при сокрытии объектов

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) // Макрос для определения кода нажатой клавиши

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


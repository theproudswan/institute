// Pacman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Utility.h"
#include "classes_declaration.h"

int main()
{
    
    srand(time(NULL));
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
    GameManager gm;
    gm.CreateFirstLevel();
    gm.Play();
    system("pause");
}

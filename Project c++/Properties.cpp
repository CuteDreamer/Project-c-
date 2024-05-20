#include "Properties.h"
#include <Windows.h>
void Properties::SetupConsole()                                  // <summary> Комплексная функция для настройки окна консоли </summary>
{
    HWND consoleWindow = GetConsoleWindow();                     // Получаем дескриптор окна консоли     

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);             // <summary> Получаем разрешение экрана </summary>
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);            // <param name> Размеры по оси х или y;

    RECT r;                                                      // Магическим образом, путём заклинания CTRL + С - CTRL + V (порядок очень важен), Получаем размеры окна консоли.
    GetWindowRect(consoleWindow, &r);
    int width = r.right - r.left;
    int height = r.bottom - r.top;

    // Вычисляем новые координаты окна                               
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2 - 150;

    MoveWindow(consoleWindow, x, y, width, height, TRUE);        // <summary> И размещаем его по центру экрана 15,6 </summary>
    // <param names> дескриптор окна, новые координаты окна консоли по х у, новые размеры окна, если TRUE, то перерисовываем.

    system("mode con cols=120 lines=50");                        // <summary> Функция изменяет размеры консоли</summary>
    // <param name> размеры консольного окна на 107 столбцов и 49 строк </param name>
    
}
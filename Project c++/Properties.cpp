#include "Properties.h"
#include <Windows.h>
void Properties::SetupConsole()                                  // <summary> ����������� ������� ��� ��������� ���� ������� </summary>
{
    HWND consoleWindow = GetConsoleWindow();                     // �������� ���������� ���� �������     

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);             // <summary> �������� ���������� ������ </summary>
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);            // <param name> ������� �� ��� � ��� y;

    RECT r;                                                      // ���������� �������, ���� ���������� CTRL + � - CTRL + V (������� ����� �����), �������� ������� ���� �������.
    GetWindowRect(consoleWindow, &r);
    int width = r.right - r.left;
    int height = r.bottom - r.top;

    // ��������� ����� ���������� ����                               
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2 - 150;

    MoveWindow(consoleWindow, x, y, width, height, TRUE);        // <summary> � ��������� ��� �� ������ ������ 15,6 </summary>
    // <param names> ���������� ����, ����� ���������� ���� ������� �� � �, ����� ������� ����, ���� TRUE, �� ��������������.

    system("mode con cols=120 lines=50");                        // <summary> ������� �������� ������� �������</summary>
    // <param name> ������� ����������� ���� �� 107 �������� � 49 ����� </param name>
    
}
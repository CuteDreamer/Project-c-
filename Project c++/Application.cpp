#include "Application.h"
#include "Admin.h"
#include "Shop.h"


int Application::GetMoney() {
    return money;
}

//void Application::Login(Shop& shop) {
//    string role;
//    cout << "�� ������ ��� �������������? ������� client ��� admin, ����� ����������: ";
//    cin >> role;
//
//    if (role == "admin") {
//        Admin admin;
//        if (admin.Authenticate()) {
//            admin.ManageShop(shop);
//        }
//    }
//    else if (role == "client") {
//        cout << "����� ����������, ������!\n";
//    }
//    else {
//        cout << "����������� ����. ����������, ������� '������' ��� '�������������'.\n";
//    }
//}

void Application::AskMoney() {
    
    cout << "������� � ��� �����? ";
    cin >> money;
    cout << "\n\n";
    if (money < 50)
    {
        cout << "����� ������, ���������!! �������� ���)))\n\n\n\n";
        cout << "����� ��������� ���� ����� � ����� - ��������������������. �������� 500 ��� �� �.�.\n\n\n";
        exit(0);
        return;
    }
}

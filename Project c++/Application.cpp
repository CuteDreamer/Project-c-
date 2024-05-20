#include "Application.h"
#include "Admin.h"
#include "Shop.h"


int Application::GetMoney() {
    return money;
}

//void Application::Login(Shop& shop) {
//    string role;
//    cout << "Вы клиент или администратор? Введите client или admin, чтобы продолжить: ";
//    cin >> role;
//
//    if (role == "admin") {
//        Admin admin;
//        if (admin.Authenticate()) {
//            admin.ManageShop(shop);
//        }
//    }
//    else if (role == "client") {
//        cout << "Добро пожаловать, клиент!\n";
//    }
//    else {
//        cout << "Неизвестная роль. Пожалуйста, введите 'клиент' или 'администратор'.\n";
//    }
//}

void Application::AskMoney() {
    
    cout << "Сколько у вас денег? ";
    cin >> money;
    cout << "\n\n";
    if (money < 50)
    {
        cout << "Будут деньги, приходите!! Хорошего дня)))\n\n\n\n";
        cout << "Самая нелюбимая мною черта в людях - неплатежеспособность. Конфуций 500 год до н.э.\n\n\n";
        exit(0);
        return;
    }
}

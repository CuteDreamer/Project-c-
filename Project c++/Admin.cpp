#include "Admin.h"
#include "Application.h"
#include <clocale>
#include <string>
#include <Windows.h>


bool Admin::Authenticate() {
    string enteredPassword;
    cout << "Введите пароль: ";
    cin >> enteredPassword;

    if (enteredPassword == password) {
        cout << "Добро пожаловать, администратор!\n";
        return true;
    }
    else {
        cout << "Неверный пароль.\n";
        return false;
    }
}

void Admin::AddProduct(Shop& shop) {
    setlocale(LC_ALL, "Russian");
    string name;
    float price;
    cout << "Введите цену нового продукта: ";
    cin >> price;
    cin.ignore();
    cout << "Введите имя нового продукта: ";
    setlocale(0, "");
    char buffer[256];
    cin.getline(buffer, 256);
    AnsiToOem(buffer, buffer);
    name = buffer;

    Product newProduct(name, price);
    shop.AddProduct(newProduct);

    cout << "Продукт успешно добавлен!\n";
}

void Admin::EditProduct(Shop& shop) {
    setlocale(LC_ALL, "Russian");

    int productIndex;
    cout << "Введите номер продукта, который вы хотите редактировать: ";
    cin >> productIndex;
    cin.ignore();  // очистка буфера ввода
    productIndex--; // уменьшаем индекс на 1, так как нумерация в векторе начинается с 0

    if (productIndex >= 0 && productIndex < shop.all_products.size()) {
        string newName;
        float newPrice;
        cout << "Введите новое имя продукта: ";
        cin >> newName; 
        cout << "Введите новую цену продукта: ";
        cin >> newPrice;

        shop.all_products[productIndex].SetName(newName);
        shop.all_products[productIndex].SetPrice(newPrice);

        cout << "Продукт успешно обновлен!\n";
    }
    else {
        cout << "Неверный номер продукта. Пожалуйста, попробуйте снова.\n";
    }
}

void Admin::DeleteProduct(Shop& shop) {
    int productIndex;
    cout << "Введите номер продукта, который вы хотите удалить: ";
    cin >> productIndex;
    productIndex--; // уменьшаем индекс на 1, так как нумерация в векторе начинается с 0

    if (productIndex >= 0 && productIndex < shop.all_products.size()) {
        shop.all_products.erase(shop.all_products.begin() + productIndex);
        cout << "Продукт успешно удален!\n";
    }
    else {
        cout << "Неверный номер продукта. Пожалуйста, попробуйте снова.\n";
    }
}
void Admin::ManageShop(Shop& shop) {
    while (true) {
        cout << "\nВот весь ассортимент магазина:\n";
        shop.ShowBuyProducts();

        cout << "\nВыберите действие:\n";
        cout << "1. Добавить продукт\n";
        cout << "2. Редактировать продукт\n";
        cout << "3. Удалить продукт\n";
        cout << "4. Завершить\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            AddProduct(shop);
            break;
        case 2:
            EditProduct(shop);
            break;
        case 3:
            DeleteProduct(shop);
            break;
        case 4:
            cout << "Хорошо, сессия администратора завершена!Будем считать, что теперь вы потенциальный клиент!)))\n";
            return;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }
}
#include "Admin.h"
#include "Application.h"
#include <clocale>
#include <string>
#include <Windows.h>


bool Admin::Authenticate() {
    string enteredPassword;
    cout << "������� ������: ";
    cin >> enteredPassword;

    if (enteredPassword == password) {
        cout << "����� ����������, �������������!\n";
        return true;
    }
    else {
        cout << "�������� ������.\n";
        return false;
    }
}

void Admin::AddProduct(Shop& shop) {
    setlocale(LC_ALL, "Russian");
    string name;
    float price;
    cout << "������� ���� ������ ��������: ";
    cin >> price;
    cin.ignore();
    cout << "������� ��� ������ ��������: ";
    setlocale(0, "");
    char buffer[256];
    cin.getline(buffer, 256);
    AnsiToOem(buffer, buffer);
    name = buffer;

    Product newProduct(name, price);
    shop.AddProduct(newProduct);

    cout << "������� ������� ��������!\n";
}

void Admin::EditProduct(Shop& shop) {
    setlocale(LC_ALL, "Russian");

    int productIndex;
    cout << "������� ����� ��������, ������� �� ������ �������������: ";
    cin >> productIndex;
    cin.ignore();  // ������� ������ �����
    productIndex--; // ��������� ������ �� 1, ��� ��� ��������� � ������� ���������� � 0

    if (productIndex >= 0 && productIndex < shop.all_products.size()) {
        string newName;
        float newPrice;
        cout << "������� ����� ��� ��������: ";
        cin >> newName; 
        cout << "������� ����� ���� ��������: ";
        cin >> newPrice;

        shop.all_products[productIndex].SetName(newName);
        shop.all_products[productIndex].SetPrice(newPrice);

        cout << "������� ������� ��������!\n";
    }
    else {
        cout << "�������� ����� ��������. ����������, ���������� �����.\n";
    }
}

void Admin::DeleteProduct(Shop& shop) {
    int productIndex;
    cout << "������� ����� ��������, ������� �� ������ �������: ";
    cin >> productIndex;
    productIndex--; // ��������� ������ �� 1, ��� ��� ��������� � ������� ���������� � 0

    if (productIndex >= 0 && productIndex < shop.all_products.size()) {
        shop.all_products.erase(shop.all_products.begin() + productIndex);
        cout << "������� ������� ������!\n";
    }
    else {
        cout << "�������� ����� ��������. ����������, ���������� �����.\n";
    }
}
void Admin::ManageShop(Shop& shop) {
    while (true) {
        cout << "\n��� ���� ����������� ��������:\n";
        shop.ShowBuyProducts();

        cout << "\n�������� ��������:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������������� �������\n";
        cout << "3. ������� �������\n";
        cout << "4. ���������\n";

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
            cout << "������, ������ �������������� ���������!����� �������, ��� ������ �� ������������� ������!)))\n";
            return;
        default:
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    }
}
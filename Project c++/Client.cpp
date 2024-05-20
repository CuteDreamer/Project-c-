#include "Client.h"
#include "Shop.h"
#include "Order.h"
#include <ctime>
void Client::SetMoney(int money)
{
	this->money = money;
}

int Client::GetMoney() const                                           
{
	cout << "� ��� �������� �����: " <<  money << "\n\n";
	return money;
}

void Client::AddProductToOrder(const Product& product) {               // ��������� ������� � �����
	order.AddProductToOrder(product);
}
void Client::ShowOrder() {                                             // ���������� �������� �����
    cout << "\n\n��� ���� ��� �����: \n\n";
    for (int i = 0; i < order.order_products.size(); i++) {
        cout << "����� ��������: " << i + 1 << "\n";
        cout << "�������: " << order.order_products[i].GetName() << "\n";
        cout << "����: " << order.order_products[i].GetPrice() << "\n\n";
    }
}
void Client::ShowTotal() {                                             // ���������� ����� ����� ������
    cout << "����� ����� ������: " << order.�alculateTotal() << "\n\n";
}
void Client::MakeOrder(Shop& shop)
{
    while (true) {
        int productIndex;
        cout << "\n������� ����� ��������, ������� �� ������ �������� � �����, ��� -1, ��������� �����: \n";
        cin >> productIndex;

        if (productIndex == -1) {
            break;
        }

        productIndex--;

        if (productIndex >= 0 && productIndex < shop.all_products.size())     // ��������� ��������� ������� � �����
        {
            order.AddProductToOrder(shop.all_products[productIndex]);
            cout << "\n������� �������� � �����! ���������!!\n";
        }
        else
        {
            cout << "�������� ����� ��������. ����������, ���������� �����.\n\n��� ������� -1 ��� �������� � ���������� ����.\n\n";
        }
    }
    ShowOrder();
    while (true) {
        cout << "\n������� 1, ����� �������� �����, ��� 2, ����� ������������� �����: \n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            break;
        }
        else if (choice == 2) {
            EditOrder();
        }
        else {
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    }
}
void Client::EditOrder() {
    int productIndex;
    while (true) {
        ShowOrder();
        cout << "\n������� ����� ��������, ������� �� ������ ������� �� ������, ��� -1, ����� ��������� ��������������: \n";
        cin >> productIndex;

        if (productIndex == -1) {
            break;
            ShowOrder();
        }

        productIndex--;

        if (productIndex >= 0 && productIndex < order.order_products.size()) {
            order.order_products.erase(order.order_products.begin() + productIndex);
            cout << "\n������� ������ �� ������!\n";
            ShowOrder();
        }
        else {
            cout << "�������� ����� ��������. ����������, ���������� �����.\n\n��� ������� -1 ��� �������� � ���������� ����.\n\n";
        }
    }
}
bool Client::CanAffordOrder() {
    // �������� ����� ��������� ������
    float totalOrderCost = order.�alculateTotal();

    // ���� � ������� ���������� ����� ��� ������ ������, ���������� true
    if (money >= totalOrderCost) {
        return true;
    }
    // � ��������� ������ ���������� false
    else {
        return false;
    }
}
void Client::CompletePurchase() {
    while (true) {
        // ��������� ����� ��������� ������
        float totalCost = order.�alculateTotal();

        // ���������, ����� �� ������ �������� �����
        if (money >= totalCost) {
            // ���� ��, �������� ��������� ������ �� ������� �������
            money -= totalCost;
            cout << "������� ������� ���������!\n\n";
            break;
        }
        else {
            // ���� ���, ������� ��������� �� ������
            float shortage = totalCost - money;
            cout << "� ��� ������������ ������� ��� ������ ����� ������. ��� �� ������� " << shortage << " �����.\n\n";
            cout << "�� ������ ������������� ��� �����.\n";
            EditOrder();
        }
    }
}

void Client::SavePurchaseHistory() {
    ofstream file("purchase_history.txt", ios::app);         // ������� �������� ����� ��� ������

    time_t now = std::time(0);
    char dt[26];
    ctime_s(dt, sizeof dt, &now);

    if (!file) {                                             // ���� ���� �� ������� �������, ������� ��������� �� ������
        cout << "�� ������� ������� ���� ��� ������.\n";
        return;
    }
    file << "����� �������: " << dt << "\n\n";
                    // ���������� ������� ������� � ����
    for (const auto& product : order.order_products) { 
        file << "�������: " << product.GetName() << "\n";
        file << "����: " << product.GetPrice() << "\n\n";
    }

    file << "����� �������: " << order.GetTotal() << "\n\n\n";
    file.close();  // ��������� ����
    cout << "������� ������� ������� ��������� � ����.\n";
}
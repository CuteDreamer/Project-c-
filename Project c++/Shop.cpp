#include <fstream> 
#include "Shop.h"
#include <string>
#include <vector>
#include "Product.h"
#include "Vegetable.h"
#include "Order.h"
#include "Admin.h"




void Shop::Welcome()                              // ���� ����� ������������ ������������
{
	cout << "������ ����! ���� ��� �������������� � ����� ����������� �������� ShopShop\n\n";
	cout << "� ��� �� ������ ���������� ��������� ���������� �������� ����������� �������� �� ������� �����! \n\n";
	cout << "������ �� ��������� ��� � ����� ������������� � �� ������ ���� ���-������ �����������!\n\n";
}



bool Shop::AskToContinue() {                             // ������ �� ����������� ������ � ����������
    string answer;
    cout << "������ �� �� ����������? (yes/no): ";
    getline(cin, answer);
    if (answer == "Yes" || answer == "yes" || answer == "YES") {
        cout << "\n\n�������!\n\n";
        return true;
    }
    else if (answer == "No" || answer == "no" || answer == "NO") {
        cout << "\n\n�� ����� ������!!! ����� ���� ��� ������!!\n\n\n";
        return false;
    }
	else if (answer == "admin") {
		cout << "\n\n�������� ����� ��������������!!!\n\n\n";
		Admin admin;
		admin.ManageShop(*this);
		return true;
		
	}
    else {
        return AskToContinue();
    }
}

void Shop::AddProduct(const Product& product)     // ���� ����� ��������� �������� � ����� ��� ������
{
	all_products.push_back(product);
}

void Shop::ShowProducts()                         // ���� ����� ������� ������� ��� ��������� ��������
{
	for (const auto& product : all_products)
	{
		cout << product.GetName() << " - " << product.GetPrice() << " ���" << "\n";

	}
}
void Shop::ShowVegetables()                      // ���������� ��� ����� � ������ � �����
{
	for (const auto& product : all_products)
	{
		// ���������, �������� �� ������� ������
		if (dynamic_cast<const Vegetable*>(&product))
		{
			cout << product.GetName() << " : " << product.GetPrice() << "\n";
		}
	}
}
void Shop::ShowBuyProducts()                      // ���������� �������� � �������� ��� ���������� �������
{
	for (int i = 0; i < all_products.size(); i++)
	{
		cout << "����� ��������: " << i+1 << ", �������: " << all_products[i].GetName() << ", ����: " << all_products[i].GetPrice() << "\n";
	}
}

#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Shop.h"
using namespace std;

class Client
{
	int money;

public:

	Client() : Client(100)                                  // �� ��������� � ������� 10000 �����
	{

	}

	Client(int money)
	{
		SetMoney(money);
	}
	~Client()
	{
		cout << "������� �� �������! �������� ���! (����������)" << "\n\n";
	}

	void SetMoney(int money);
	int GetMoney() const;

	Order order;

	void AddProductToOrder(const Product& product);

	void ShowOrder();
	void ShowTotal();
	void MakeOrder(Shop& shop);
	void RemoveProductFromOrder(const Product& product);
	bool CanAffordOrder();
	void CompletePurchase();
	void SavePurchaseHistory();
};


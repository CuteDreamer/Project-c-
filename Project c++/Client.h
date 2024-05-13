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

	Client() : Client(100)                                  // по умолчанию у клиента 10000 денег
	{

	}

	Client(int money)
	{
		SetMoney(money);
	}
	~Client()
	{
		cout << "Спасибо за покупку! Хорошего дня! (деструктор)" << "\n\n";
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


#include <iostream>
#include <vector>
#include <clocale>
#include "Client.h"
#include "Shop.h"
#include "Vegetable.h"

using namespace std;




int main()
{
	setlocale(LC_ALL, "Russian");

    while (true) {
        Shop shop;

        // Создаем продукты
        Product apple("Яблоко", 10.0);
        Product bread("Хлеб", 15.0);

        // Создаем овощи
        Vegetable carrot("Морковь", 7.0, "овощ");
        Vegetable potato("Картофель", 5.0, "овощ");

        // Добавляем продукты и овощи в магазин
        shop.AddProduct(apple);
        shop.AddProduct(bread);
        shop.AddProduct(carrot);
        shop.AddProduct(potato);

        // Приветствуем пользователя
        shop.Welcome();

        // Создаем клиента с 100 денег
        Client client(100);

        shop.AskToContinue();
        shop.ShowProducts();
        shop.AskToContinue();
        shop.ShowBuyProducts();
        client.MakeOrder(shop);
        client.ShowOrder();
        client.ShowTotal();
        client.CompletePurchase();
        client.GetMoney();
        client.SavePurchaseHistory();
    }
}


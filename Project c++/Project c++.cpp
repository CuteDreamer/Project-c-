#include <iostream>
#include <vector>
#include <clocale>
#include "Client.h"
#include "Shop.h"
#include "Vegetable.h"
#include "Application.h"
#include "Properties.h"

using namespace std;

int main()
{

    Properties console;
    console.SetupConsole();
    setlocale(LC_ALL, "Russian");
    
    Shop shop; // создали наш магазин
    Application app;
    Product apple("Яблоко", 30.0);
    Product bread("Хлеб", 25.0);

    // Создаем овощи
    Vegetable carrot("Морковь", 15.0, "овощ");
    Vegetable potato("Картофель", 25.0, "овощ");



    // Добавляем продукты в магазин
    shop.AddProduct(apple);
    shop.AddProduct(bread);
    shop.AddProduct(carrot);
    shop.AddProduct(potato);
   // app.Login(shop);

   // 
 
    

    bool continueShopping = true;
    while (continueShopping) {

        // Приветствуем пользователя
        shop.Welcome();
        shop.ShowProducts();

        // Создаем клиента с 100 денег
        

        continueShopping = shop.AskToContinue();
        if (!continueShopping) {
            break;
        }
        app.AskMoney();

        Client client(app.GetMoney());
            
        shop.ShowBuyProducts();
        client.MakeOrder(shop);
        client.ShowOrder();
        client.ShowTotal();
        client.CompletePurchase();
        client.GetMoney();
        client.SavePurchaseHistory();
    }
}


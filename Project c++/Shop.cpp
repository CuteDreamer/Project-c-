#include <fstream> 
#include "Shop.h"
#include <string>
#include <vector>
#include "Product.h"
#include "Vegetable.h"
#include "Order.h"
#include "Admin.h"




void Shop::Welcome()                              // этот метод приветствует пользователя
{
	cout << "Добрый день! Рады вас приветствовать в нашем продуктовом магазине ShopShop\n\n";
	cout << "У нас вы можете приобрести свежайшие фермерские продукты высочайшего качества по хорошим ценам! \n\n";
	cout << "Сейчас мы ознакомим вас с нашим ассортиментом и вы купите себе что-нибудь вкусненькое!\n\n";
}



bool Shop::AskToContinue() {                             // Запрос на продолжение работы с программой
    string answer;
    cout << "Хотите ли вы продолжить? (yes/no): ";
    getline(cin, answer);
    if (answer == "Yes" || answer == "yes" || answer == "YES") {
        cout << "\n\nОтлично!\n\n";
        return true;
    }
    else if (answer == "No" || answer == "no" || answer == "NO") {
        cout << "\n\nДо новых встреч!!! Будем рады вас видеть!!\n\n\n";
        return false;
    }
	else if (answer == "admin") {
		cout << "\n\nВключаем режим администратора!!!\n\n\n";
		Admin admin;
		admin.ManageShop(*this);
		return true;
		
	}
    else {
        return AskToContinue();
    }
}

void Shop::AddProduct(const Product& product)     // этот метод добавляет продукты в админ это делает
{
	all_products.push_back(product);
}

void Shop::ShowProducts()                         // этот метод выводит клиенту все доступные продукты
{
	for (const auto& product : all_products)
	{
		cout << product.GetName() << " - " << product.GetPrice() << " грн" << "\n";

	}
}
void Shop::ShowVegetables()                      // показываем все овощи с именем и ценой
{
	for (const auto& product : all_products)
	{
		// Проверяем, является ли продукт овощем
		if (dynamic_cast<const Vegetable*>(&product))
		{
			cout << product.GetName() << " : " << product.GetPrice() << "\n";
		}
	}
}
void Shop::ShowBuyProducts()                      // Показываем продукты с индексом для наполнения корзины
{
	for (int i = 0; i < all_products.size(); i++)
	{
		cout << "Номер продукта: " << i+1 << ", Продукт: " << all_products[i].GetName() << ", Цена: " << all_products[i].GetPrice() << "\n";
	}
}

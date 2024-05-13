#include "Shop.h"
#include <string>
#include <vector>
#include "Product.h"
#include "Vegetable.h"



void Shop::Welcome()                              // этот метод приветствует пользователя
{
	cout << "Добрый день! Рады вас приветствовать в нашем продуктовом мазагине ShopShop\n\n";
	cout << "У нас вы можете приобрести свежайшие фермерские продукты высочайшего качества по хорошим ценам! \n\n";
	cout << "Сейчас мы ознакомим вас с нашим ассортиментом и вы купите себе что-нибудь вкусненькое!\n\n";
}



bool Shop::AskToContinue()                        // этот метод спрашивает готов ли пользователь продолжать покупки
{
	string answer;
	cout << "Хотите ли вы продолжить? (yes/no): ";
	getline(cin, answer);
	if (answer == "Yes" || answer == "yes" || answer == "YES") {
		
		cout << "\n\nОтлично! Вот перечень товаров которые есть в наличии!!\n\n";
		return true;
	}
	else if (answer == "No" || answer == "no" || answer == "NO") {
		cout << "\n\nДо новых встреч!!! Будем рады вас видеть!!\n\n\n";
		exit(0);                                                           // завершаем программу полностью если клиент не хочет продолжать
	}
	else {
		cout << "\n\nЯ не понял ваш ответ. Пожалуйста, введите 'yes' или 'no'.\n\n";
		return AskToContinue();
	}
	
}

void Shop::AddProduct(const Product& product)     // этот метод добавляет продукты в  админ это делает
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
void Shop::ShowBuyProducts()
{
	for (int i = 0; i < all_products.size(); i++)
	{
		std::cout << "Номер продукта: " << i+1 << ", Продукт: " << all_products[i].GetName() << ", Цена: " << all_products[i].GetPrice() << "\n";
	}
}
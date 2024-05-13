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
	cout << "У вас осталось денег: " <<  money << "\n\n";
	return money;
}

void Client::AddProductToOrder(const Product& product) {               // добавляем продукт в заказ
	order.AddProductToOrder(product);
}
void Client::ShowOrder() {                                             // показываем итоговый заказ
    cout << "\n\nВот весь ваш заказ: \n\n";
    for (const auto& product : order.order_products) {
		cout << "Продукт: " << product.GetName() << "\n";
		cout << "Цена: " << product.GetPrice() << "\n\n";
    }
}
void Client::ShowTotal() {                                             // показываем общую сумму заказа
    cout << "Общая сумма заказа: " << order.СalculateTotal() << "\n\n";
}
void Client::MakeOrder(Shop& shop)
{
    while (true) {
        int productIndex;
        cout << "\nВведите номер продукта, который вы хотите добавить в заказ, или -1, завершить заказ: \n";
        cin >> productIndex;

        if (productIndex == -1) {
            break;
        }

        productIndex--;

        if (productIndex >= 0 && productIndex < shop.all_products.size())     // Добавляем выбранный продукт в заказ
        {
            order.AddProductToOrder(shop.all_products[productIndex]);
            cout << "\nПродукт добавлен в заказ! Продолжим!!\n";
        }
        else
        {
            cout << "Неверный номер продукта. Пожалуйста, попробуйте снова.\n\nИли введите -1 для возврата в предыдущее меню.\n\n";
        }
    }
}
bool Client::CanAffordOrder() {
    // Получаем общую стоимость заказа
    float totalOrderCost = order.СalculateTotal();

    // Если у клиента достаточно денег для оплаты заказа, возвращаем true
    if (money >= totalOrderCost) {
        return true;
    }
    // В противном случае возвращаем false
    else {
        return false;
    }
}
void Client::CompletePurchase() {
    // Проверяем, может ли клиент оплатить заказ
    if (CanAffordOrder()) {
        // Если да, вычитаем стоимость заказа из баланса клиента
        money -= order.СalculateTotal();
        cout << "Покупка успешно совершена!\n\n";
    }
    else {
        // Если нет, выводим сообщение об ошибке
        cout << "У вас недостаточно средств для оплаты этого заказа.\n\n";
    }
}

void Client::SavePurchaseHistory() {
    ofstream file("purchase_history.txt", ios::app);  // Создаем файловый поток для записи

    time_t now = std::time(0);
    char dt[26];
    ctime_s(dt, sizeof dt, &now);

    if (!file) {  // Если файл не удалось открыть, выводим сообщение об ошибке
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    file << "Время покупки: " << dt << "\n\n";
    // Записываем историю покупок в файл
    for (const auto& product : order.order_products) { 
        file << "Продукт: " << product.GetName() << "\n";
        file << "Цена: " << product.GetPrice() << "\n\n";
    }

    file << "Сумма покупки: " << order.GetTotal() << "\n\n\n";
    file.close();  // Закрываем файл
    cout << "История покупок успешно сохранена в файл.\n";
}
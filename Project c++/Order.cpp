#include "Order.h"
void Order::AddProductToOrder(const Product& product) {              // администратор добавляет продукт в список продуктов
    order_products.push_back(product);
}
float Order::СalculateTotal()
{
    float total = 0.0;
    for (const auto& product : order_products) {
        total += product.GetPrice();
    }
    return total;
}
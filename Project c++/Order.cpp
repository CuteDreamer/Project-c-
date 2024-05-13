#include "Order.h"
void Order::AddProductToOrder(const Product& product) {              // ������������� ��������� ������� � ������ ���������
    order_products.push_back(product);
}
float Order::�alculateTotal()
{
    float total = 0.0;
    for (const auto& product : order_products) {
        total += product.GetPrice();
    }
    return total;
}
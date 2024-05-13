#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Order
{
	float sum;

   
public:
    vector<Product> order_products;                          // cоздали список продуктов

    void AddProductToOrder(const Product& product);
    float СalculateTotal();
    double GetTotal() const;

    ~Order() { cout << "Заказ выполнен!\n\n"; cout << "СЛЕДУЮЩИИИИИИЙ!!!! (деструктор) \n\n\n\n\n\n\n";}; 
};

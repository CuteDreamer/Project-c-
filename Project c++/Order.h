#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Order
{
	float sum;

   
public:
    vector<Product> order_products;                          // c������ ������ ���������

    void AddProductToOrder(const Product& product);
    float �alculateTotal();
    

    ~Order() { cout << "����� ��������!\n\n"; cout << "��������������!!!! (����������) \n\n\n\n\n\n\n";};
};




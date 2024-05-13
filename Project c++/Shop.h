#pragma once
#include <fstream> 
#include <iostream>
#include "Product.h"
#include "Order.h"
using namespace std;
class Shop
{

public:
	vector<Product> all_products;                     // создали список продуктов

	void Welcome();
	bool AskToContinue();
	void AddProduct(const Product& product);
	void ShowProducts();
	void ShowVegetables();
	void ShowBuyProducts();
	
};


#pragma once
#include <fstream> 
#include <iostream>
#include "Product.h"


class Shop
{

public:
	vector<Product> all_products;                     // ������� ������ ���������

	void Welcome();
	bool AskToContinue();
	void AddProduct(const Product& product);
	void ShowProducts();
	void ShowVegetables();
	void ShowBuyProducts();
	
};


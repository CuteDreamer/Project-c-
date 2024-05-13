#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Product
{
	string name;
	float price;

public:
	Product() 
	{
		name = "";
		price = 0.0;
	}

	Product(string name, float price)
	{
		SetName(name);
		SetPrice(price);

	}
	
	virtual ~Product() {}


public:
	string GetName() const;
	float GetPrice() const;

	void SetName(string name);
	void SetPrice(float price);
};


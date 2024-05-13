#include "Product.h"
void Product::SetName(string name)
{
	this->name = name;
}

void Product::SetPrice(float price)
{
	this->price = price;
}

string Product::GetName() const
{
	return name;
}
float Product::GetPrice() const
{
	return price;
}
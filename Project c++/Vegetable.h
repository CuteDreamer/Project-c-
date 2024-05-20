#pragma once
#include "Product.h"
class Vegetable : public Product
{
    string type;

public:
    Vegetable(string name, float price, string type);

    string GetVegetableType() const;
};

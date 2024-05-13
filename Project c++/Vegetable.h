#pragma once
#include "Product.h"
class Vegetable : public Product
{
    string type;

public:
    Vegetable(string name, float price, string type)                // наследование от продукта
        : Product(name, price), type(type) {}

    string GetVegetableType() const { return type; }
};

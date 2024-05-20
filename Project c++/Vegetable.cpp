#include "Vegetable.h"
Vegetable::Vegetable(string name, float price, string type)
    : Product(name, price), type(type) {}

string Vegetable::GetVegetableType() const { return type; }
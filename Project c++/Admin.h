#pragma once
#include <iostream>
#include "Shop.h"
using namespace std;

class Admin
{
	string password = "admin";

public:
    bool Authenticate();

    void AddProduct(Shop& shop);

    void EditProduct(Shop& shop);

    void DeleteProduct(Shop& shop);
    void ManageShop(Shop& shop);
};


#pragma once
#include <iostream>
#include "Shop.h"
using namespace std;
class Application
{
    int money;
    string password = "admin";
public:
    
    int GetMoney();
    void Login(Shop& shop);
    void AskMoney();
};
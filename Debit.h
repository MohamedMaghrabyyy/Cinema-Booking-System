#ifndef DEBIT_H
#define DEBIT_H
#include <iostream>
#include "BankPayment.h"
#include "Authorization.h"

class Debit : public BankPayment 
{
  public:
    Debit(std::string securityCode, Authorization *authType);
    std::string processPayment() override;
};

#endif
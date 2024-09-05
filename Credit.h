#ifndef CREDIT_H
#define CREDIT_H
#include <iostream>
#include "BankPayment.h"
#include "Authorization.h"

class Credit : public BankPayment 
{
  public:
    Credit(std::string securityCode, Authorization *authType);
    std::string processPayment() override;
};

#endif
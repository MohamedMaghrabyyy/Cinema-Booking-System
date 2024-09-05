#ifndef PAYPAL_H
#define PAYPAL_H
#include <iostream>
#include "OnlinePayment.h"

class Paypal : public OnlinePayment 
{
  public:
    Paypal(std::string email, OnlineAuth* authType);
    std::string processPayment() override;

};

#endif
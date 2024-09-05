#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
class Payment
{
  public:
    virtual std::string processPayment() = 0; 
};

#endif
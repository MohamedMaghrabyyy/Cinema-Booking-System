#ifndef BANKPAYMENT_H
#define BANKPAYMENT_H
#include <iostream>
#include "Payment.h"
#include "Authorization.h"
class BankPayment : public Payment
{
  protected:
    std::string securityCode;
    Authorization *authType;

  public:
    BankPayment(std::string securityCode, Authorization *authType): securityCode(securityCode), authType(authType){}
    virtual std::string processPayment() = 0;
    void authorize()
    {
      authType->authorize();
    }
  
};

#endif
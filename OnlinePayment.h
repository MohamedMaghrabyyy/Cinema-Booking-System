#ifndef ONLNEPAYMENT_H
#define ONELINEPAYMENT_H
#include <iostream>
#include "Payment.h"
#include "OnlineAuth.h"
#include "Authorization.h"

class OnlinePayment : public Payment
{
  protected:
    std::string email;
    OnlineAuth *authType;
  public:
    OnlinePayment(std::string email, OnlineAuth *authType): email(email), authType(authType){}
    virtual std::string processPayment() = 0;
    void authorize()
    {
      authType->authorize();
    } 
};

#endif
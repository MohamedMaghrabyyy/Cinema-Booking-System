#ifndef SMS_H
#define SMS_H
#include <iostream>
#include "Authorization.h"

class SMS : public Authorization 
{
  private:
    std::string mobileNumber;
  public:
    SMS(std::string mobileNumber) : mobileNumber(mobileNumber){}
    void authorize() override;
    std::string getMobileNumber();
};

#endif
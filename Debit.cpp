#include "Debit.h"

Debit::Debit(std::string securityCode, Authorization *authType) 
    : BankPayment(securityCode, authType) 
{}
std::string Debit::processPayment() 
{
  authorize();
  return "Processing debit payment type ---- Verifying security code: {" + securityCode + "}\n\n";
}




#include "Credit.h"

Credit::Credit(std::string securityCode, Authorization *authType) 
    : BankPayment(securityCode, authType) 
{}

std::string Credit::processPayment() {
  authorize();
  return "Processing credit payment type ---- Verifying security code: {" + securityCode + "}\n\n";
}




#include "Paypal.h"

Paypal::Paypal(std::string email, OnlineAuth* authType)
    : OnlinePayment(email, authType) {}

std::string Paypal::processPayment() {
    authorize();
    return "Processing Paypal payment type ---- Verifying email: {" + email + "}\n\n";
}




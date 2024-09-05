#include "SMS.h"

std::string SMS::getMobileNumber()
{
  return mobileNumber;
}
void SMS::authorize()
{
  std::cout << "SMS authorization done with mobile number: " << getMobileNumber() << std::endl;
}



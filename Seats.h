#ifndef SEATS_H
#define SEATS_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Common.h"

using namespace std;
class Seats
{
  private:
    map<string, pair<float, bool>> m_seats;
    
  public:
    void initializeSeats();
    void displaySeats() const;
    bool reserveSeat(const string& seatLabel);
    const map<string, pair<float, bool>>& getSeats() const {return m_seats;}
};

#endif

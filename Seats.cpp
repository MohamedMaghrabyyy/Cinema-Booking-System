#include "Seats.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void Seats::initializeSeats() 
{
    vector<vector<string>> seatArrangement = {
        {"1-A", "2-A", "3-A", "4-A", "5-A", "6-A", "7-A", "8-A"},
        {"1-B", "2-B", "3-B", "4-B", "5-B", "6-B", "7-B", "8-B"},
        {"1-C", "2-C", "3-C", "4-C", "5-C", "6-C", "7-C", "8-C"},
        {"1-D", "2-D", "3-D", "4-D", "5-D", "6-D", "7-D", "8-D"}
    };
    
    // Assign categories by rows: First row -> Regular, Second -> Premium, Third and Fourth -> Gold
    for (int row = 0; row < seatArrangement.size(); row++) {
        SeatE category;
        if (row == 0) 
            category = SeatE::REGULAR;
        else if (row == 1)
            category = SeatE::PREMIUM;
        else
            category = SeatE::GOLD;

        for (int col = 0; col < seatArrangement[row].size(); col++) 
        {
            string seatLabel = seatArrangement[row][col];
            m_seats[seatLabel] = {c_SeatPrice.at(category), false};
        }
    }
}

void Seats::displaySeats() const 
{
    for (const auto& [seat, info] : m_seats) 
    {
        cout << seat << ": " << (info.second ? "[RESERVED]" : "[AVAILABLE]") << " ";
        if (seat.find("-D") != string::npos) 
            cout << endl;
    }
}

bool Seats::reserveSeat(const string& seatLabel) 
{
    auto it = m_seats.find(seatLabel);
    if (it != m_seats.end()) 
    {
        if (!it->second.second) 
        { 
            it->second.second = true;
            cout << "Seat " << seatLabel << " has been reserved." << endl;
            return true;
        } 
        else 
        {
            cout << "Seat " << seatLabel << " is already reserved!" << endl;
            return false;
        }
    } 
    else 
    {
        cout << "Seat " << seatLabel << " does not exist." << endl;
        return false;
    }
}

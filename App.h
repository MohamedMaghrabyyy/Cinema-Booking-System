#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <memory>
#include "Hall.h"
#include "Movie.h"
#include "User.h"
#include "Common.h"
#include "ShowTime.h"
#include "Ticket.h"
#include "Payment.h"
#include "Credit.h"
#include "Debit.h"
#include "Paypal.h"
#include "SMS.h"
#include "NotARobot.h"
#include "Cinema.h"

class App {
private:
    CinemaC* cinema;

    void createInitialData();
    bool loginUser(UserC& user);
    void createAccount(UserC& user);
    void bookShowtime(UserC& user);

public:
    App() : cinema(CinemaC::GetCinemaInst()) {}

    void run();
};

#endif // APP_H

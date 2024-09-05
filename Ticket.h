#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "ShowTime.h" // Ensure this includes ShowTime

class Ticket
{
private:
    std::string m_name;
    std::string m_mail;
    ShowTime m_showTime;

public:
    Ticket(const std::string& name, const std::string& mail, const ShowTime& showtime)
        : m_name(name), m_mail(mail), m_showTime(showtime) {}

    std::string formulateTicket();
    void printTicket() { std::cout << formulateTicket(); }
};

#endif

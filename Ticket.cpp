#include "Ticket.h"
#include <iostream> 

std::string Ticket::formulateTicket()
{
    std::string result{};
    result += "Customer name: " + m_name + "\n";
    result += "Customer mail: " + m_mail + "\n";
    result += "Movie name: " + m_showTime.getMovie().GetTitle() + "\n";
    result += "Hall: " + m_showTime.getHall().getName() + "\n";
    result += "Price: " + std::to_string(m_showTime.getPrice()) + "\n";

    return result;
}

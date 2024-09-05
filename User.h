#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Ticket.h" 
#include "Payment.h"

class UserC {
private:
    std::string m_name;
    std::string m_mail;
    std::string m_phoneNum;
    Payment* m_payment; // Use raw pointer
    std::vector<Ticket> m_ticketsHistory;

public:
    UserC(std::string name, const std::string& mail, std::string phoneNum)
        : m_name(std::move(name)), m_mail(mail), m_phoneNum(std::move(phoneNum)), m_payment(nullptr) {}

    void setName(const std::string& name) { m_name = name; }
    const std::string& getName() const { return m_name; }
    void setMail(const std::string& email) { m_mail = email; }
    const std::string& getMail() const { return m_mail; }
    void setPhoneNum(const std::string& phoneNum) { m_phoneNum = phoneNum; }
    const std::string& getPhoneNum() const { return m_phoneNum; }
    void setPaymentMethod(Payment* payment) { m_payment = payment; }
    Payment* getPaymentMethod() const { return m_payment; }
    void addTicket(const Ticket& ticket) { m_ticketsHistory.push_back(ticket); }
    std::vector<Ticket> getTicketHistory() const { return m_ticketsHistory; }
};

#endif

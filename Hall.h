#ifndef HALL_H
#define HALL_H

#include <string>
#include "Common.h"

class Hall {
private:
    std::string m_name;
    HallE m_category;
    float m_price;

public:
    Hall(const std::string& name, HallE category) 
        : m_name(name), m_category(category), m_price(c_HallPrice.at(m_category)) {}

    float getPrice() const { return m_price; }
    std::string getName() const { return m_name; }
    HallE getCategory() const { return m_category; }
};

#endif

#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <string>
#include "Seats.h"
#include "Hall.h" 
#include "Movie.h"
#include "Common.h" 

class ShowTime {
private:
    MovieC m_movie;
    DayE m_movieDay;
    TimeE m_time;
    Hall m_hall;
    Seats m_seats;

public:
    ShowTime(const MovieC& movie, DayE day, TimeE timeSlot, const Hall& hall)
        : m_movie(movie), m_movieDay(day), m_time(timeSlot), m_hall(hall) { m_seats.initializeSeats();}

    float getPrice() const {
        return c_DayPrice.at(m_movieDay) + c_TimePrice.at(m_time) + m_hall.getPrice();
    }

    const MovieC& getMovie() const { return m_movie; }
    DayE getDay() const { return m_movieDay; }
    TimeE getTime() const { return m_time; }
    const Hall& getHall() const { return m_hall; }
    const Seats& getSeats() const { return m_seats; }
};

#endif

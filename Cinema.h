#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "Hall.h"
#include "Movie.h"
#include "User.h"
#include "Common.h"
#include "ShowTime.h"
#include "algorithm"

class CinemaC {
private:
    static std::unique_ptr<CinemaC> m_cinemaInst;
    std::vector<MovieC> m_movies;
    std::vector<UserC> m_users;
    std::vector<Hall> m_halls;
    std::vector<ShowTime> m_showtimes;

public:
    static CinemaC* GetCinemaInst();
    void AddShowTime(ShowTime showTime);
    void AddHall(Hall hall);
    void AddMovie(MovieC movie);
    void AddUser(UserC user);
    const std::vector<MovieC>& getMovies() const;
    const std::vector<UserC>& getUsers() const;
    const std::vector<ShowTime>& getShowTimes() const;
    const std::vector<Hall>& getHalls() const;
    std::vector<ShowTime> viewShowtimes(const std::string& movieTitle);
    std::vector<ShowTime> viewShowtimes(const std::vector<MovieGenreE>& genres);
    std::string viewAllShowtimes() const;
    std::string viewMovies() const;
};

#endif // CINEMA_H

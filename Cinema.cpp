#include "Cinema.h"

std::unique_ptr<CinemaC> CinemaC::m_cinemaInst = nullptr;

CinemaC* CinemaC::GetCinemaInst() {
    if (!m_cinemaInst) {
        m_cinemaInst = std::make_unique<CinemaC>();
    }
    return m_cinemaInst.get();
}

void CinemaC::AddShowTime(ShowTime showTime) {
    m_showtimes.emplace_back(showTime);
}

void CinemaC::AddHall(Hall hall) {
    m_halls.emplace_back(hall);
}

void CinemaC::AddMovie(MovieC movie) {
    m_movies.emplace_back(movie);
}

void CinemaC::AddUser(UserC user) {
    m_users.emplace_back(user);
}

const std::vector<MovieC>& CinemaC::getMovies() const {
    return m_movies;
}

const std::vector<UserC>& CinemaC::getUsers() const {
    return m_users;
}

const std::vector<ShowTime>& CinemaC::getShowTimes() const {
    return m_showtimes;
}

const std::vector<Hall>& CinemaC::getHalls() const {
    return m_halls;
}

std::vector<ShowTime> CinemaC::viewShowtimes(const std::string& movieTitle) {
    std::vector<ShowTime> result;
    for (const auto& showtime : m_showtimes) {
        if (showtime.getMovie().GetTitle() == movieTitle) {
            result.emplace_back(showtime);
        }
    }
    return result;
}

std::vector<ShowTime> CinemaC::viewShowtimes(const std::vector<MovieGenreE>& genres) {
    std::vector<ShowTime> result;
    for (const auto& showtime : m_showtimes) {
        const auto& movieGenres = showtime.getMovie().GetGenreVec();
        for (const auto& genre : genres) {
            if (std::find(movieGenres.begin(), movieGenres.end(), genre) != movieGenres.end()) {
                result.emplace_back(showtime);
                break;
            }
        }
    }
    return result;
}

std::string CinemaC::viewAllShowtimes() const {
    std::string result;
    for (const auto& showtime : m_showtimes) {
        result += "" + showtime.getMovie().GetTitle()
                + ", " + m_dayStr.at(showtime.getDay())
                + ", " + m_timeStr.at(showtime.getTime())
                + ", " + showtime.getHall().getName() + "\n";
    }
    return result;
}

std::string CinemaC::viewMovies() const {
    std::string result;
    for (const auto& movie : m_movies) {
        result += "Title: " + movie.GetTitle()
                + ", Rating: " + std::to_string(movie.GetRating()) + "\n";
    }
    return result;
}

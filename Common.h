#ifndef COMMON_HPP
#define COMMON_HPP

#include <array>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

enum class DayE {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

enum class TimeE {
    NINE_AM,
    TWELVE_PM,
    THREE_PM,
    SIX_PM,
    NINE_PM,
    TWELVE_AM
};

enum class MovieGenreE {
    ACTION,
    COMEDY,
    DRAMA,
    THRILLER,
    HORROR,
    SCIENCE_FICTION,
    ROMANCE
};

enum class HallE {
    STANDARD,
    IMAX,
    PREMIUM
};

enum class SeatE {
    REGULAR,
    PREMIUM,
    GOLD
};

const map<SeatE, float> c_SeatPrice = {
    {SeatE::REGULAR, 5},
    {SeatE::PREMIUM, 10},
    {SeatE::GOLD, 20}
};

const map<HallE, float> c_HallPrice = {
    {HallE::STANDARD, 20},
    {HallE::IMAX, 40},
    {HallE::PREMIUM, 50}
};

const map<DayE, float> c_DayPrice = {
    {DayE::THURSDAY, 70},
    {DayE::FRIDAY, 70},
    {DayE::SATURDAY, 64},
    {DayE::SUNDAY, 40},
    {DayE::MONDAY, 20},
    {DayE::TUESDAY, 15},
    {DayE::WEDNESDAY, 30}
};

const map<TimeE, float> c_TimePrice = {
    {TimeE::NINE_AM, 5},
    {TimeE::TWELVE_PM, 8},
    {TimeE::THREE_PM, 2},
    {TimeE::SIX_PM, 15},
    {TimeE::NINE_PM, 25},
    {TimeE::TWELVE_AM, 30}
};

const unordered_map<MovieGenreE, string> m_genreStr = {
    { MovieGenreE::ACTION, "Action" },
    { MovieGenreE::COMEDY, "Comedy" },
    { MovieGenreE::DRAMA, "Drama" },
    { MovieGenreE::THRILLER, "Thriller" },
    { MovieGenreE::HORROR, "Horror" },
    { MovieGenreE::SCIENCE_FICTION, "Science fiction" },
    { MovieGenreE::ROMANCE, "Romance" }
};

const unordered_map<DayE, string> m_dayStr = {
    { DayE::SATURDAY, "Saturday" },
    { DayE::SUNDAY, "Sunday" },
    { DayE::MONDAY, "Monday" },
    { DayE::TUESDAY, "Tuesday" },
    { DayE::WEDNESDAY, "Wednesday" },
    { DayE::THURSDAY, "Thursday" },
    { DayE::FRIDAY, "Friday" }
};

const unordered_map<TimeE, string> m_timeStr = {
    { TimeE::NINE_AM, "nine am" },
    { TimeE::TWELVE_PM, "twelve pm" },
    { TimeE::THREE_PM, "three pm" },
    { TimeE::SIX_PM, "six pm" },
    { TimeE::NINE_PM, "nine pm" },
    { TimeE::TWELVE_AM, "twelve am" }
};

#endif

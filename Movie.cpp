#include "Movie.h"

std::string MovieC::GetGenreStr() const {
    std::string genreStr = "";
    for (const auto& genre : m_genre) {
        genreStr += (m_genreStr.at(genre) + ", ");
    }
    if (!genreStr.empty()) {
        genreStr.pop_back();
        genreStr.pop_back();
    }
    return genreStr;
}

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Common.h"

using namespace std;

class MovieC {
private:
    string m_title;
    vector<MovieGenreE> m_genre;
    float m_rating;

public:
    MovieC(const string& title, const vector<MovieGenreE>& genre, float rating) 
        : m_title(title), m_genre(genre), m_rating(rating) {}

    void SetTitle(const string& title) { m_title = title; }
    const string& GetTitle() const { return m_title; }
    void SetGenre(const vector<MovieGenreE>& genre) { m_genre = genre; }
    void AddGenre(MovieGenreE genre) { m_genre.emplace_back(genre); }
    const vector<MovieGenreE>& GetGenreVec() const { return m_genre; }
    void SetRating(float rating) { m_rating = rating; }
    const float& GetRating() const { return m_rating; }
    string GetGenreStr() const;
};

#endif

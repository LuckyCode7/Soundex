#pragma once
#include <string>
#include <map>

class Soundex
{
private:
    std::string inputWord;
    std::string badLetters;
    std::map<char, char> keyMap;

    void setFirstLetter();
    void mapLetters();
    void removeLetters();
    void addZero();
    void removeDuplicate();
    void toLower();
public:
    Soundex() = delete;
    ~Soundex() = default;
    Soundex(const Soundex&) = delete;
    Soundex& operator=(const Soundex&) = delete;
    Soundex(Soundex&&) = delete;
    Soundex& operator=(Soundex&&) = delete;

    Soundex(std::string inputWord_);
    std::string encrypt();
};

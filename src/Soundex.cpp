#include "Soundex.hpp"
#include <iostream>

Soundex::Soundex(std::string inputWord_)
    : inputWord(inputWord_),
      badLetters("aeiouyhw")
{
    keyMap.insert(std::make_pair('b', '1'));
    keyMap.insert(std::make_pair('f', '1'));
    keyMap.insert(std::make_pair('p', '1'));
    keyMap.insert(std::make_pair('v', '1'));

    keyMap.insert(std::make_pair('c', '2'));
    keyMap.insert(std::make_pair('g', '2'));
    keyMap.insert(std::make_pair('j', '2'));
    keyMap.insert(std::make_pair('k', '2'));
    keyMap.insert(std::make_pair('q', '2'));
    keyMap.insert(std::make_pair('s', '2'));
    keyMap.insert(std::make_pair('x', '2'));
    keyMap.insert(std::make_pair('z', '2'));

    keyMap.insert(std::make_pair('d', '3'));
    keyMap.insert(std::make_pair('t', '3'));

    keyMap.insert(std::make_pair('l', '4'));

    keyMap.insert(std::make_pair('m', '5'));
    keyMap.insert(std::make_pair('n', '5'));

    keyMap.insert(std::make_pair('r', '6'));
}

std::string Soundex::encrypt()
{
    toLower();
    removeDuplicate();
    removeLetters();
    mapLetters();
    setFirstLetter();
    addZero();
    return inputWord.substr(0, 4);
}

void Soundex::setFirstLetter()
{
    inputWord[0] = toupper(inputWord[0]);
}

void Soundex::mapLetters()
{
    for(unsigned int i = 1; i < inputWord.size(); i++)
    {
        inputWord[i] = keyMap[inputWord[i]];
    }
}

void Soundex::removeLetters()
{
    for(auto& x : badLetters)
    {
        auto iter = inputWord.find(x);
        if((inputWord[iter] == 'h' || inputWord[iter] == 'w') &&
          (keyMap[inputWord[iter-1]] == keyMap[inputWord[iter+1]]))
        {
            inputWord.erase(iter, 2);
            continue;
        }
        for(unsigned int i=1; i<inputWord.size(); i++)
        {
            if(inputWord[i] == x)
                inputWord.erase(i, 1);
        }
    }
}

void Soundex::addZero()
{
    while(inputWord.size() < 4)
        inputWord.append(1, '0');
}

void Soundex::removeDuplicate()
{
    for(unsigned int i = 0; i < inputWord.size(); i++)
    {
        if(keyMap[inputWord[i]] == keyMap[inputWord[i+1]])
            inputWord.erase(i+1, 1);
    }
}

void Soundex::toLower()
{
    for(auto& x : inputWord)
        x = tolower(x);
}

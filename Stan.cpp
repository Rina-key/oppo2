#include"pch.h"
#include"stan.h"
#include<string>
#include<iostream>
#include <stdexcept>

std::string Stan::getStreet()
{
    return street;
};
int Stan::getHome()
{
    return home;
};
void Stan::setStreet(std::string str)
{
    street = str;
};
void Stan::setHome(int h)
{
    home = h;
};
void Stan::readStan(std::istream & file)
{
    std::string str;
    int h;
    file >> str;
    file >> h;
    correctStreet(str);
    correctHome(h);
    street = str;
    home = h;
};
void Stan::printStan(std::ostream & out)
{
        
    out << street << " " << home << "\n";
};

void correctHome(int h)
{
    if (h <= 0) throw std::runtime_error("Адрес введен неверно! Проверьте корректность входных данных");
};


void correctStreet(std::string str)
{
    if (!(str[2] == '.' && str[1] == 't' && str[0] == 's')) throw std::runtime_error("Oshibka!");
};
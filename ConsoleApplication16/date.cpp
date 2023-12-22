#include"pch.h"
#include "date.h"
#include<string>
#include<iostream>
#include <stdexcept>

void DateStruct::readDate(std::string& dateStr) {
    if (dateStr[2] == '.' && dateStr[5] == '.') {
        int d = stoi(dateStr.substr(0, 2));
        int m = stoi(dateStr.substr(3, 5));
        int y = stoi(dateStr.substr(6, 8));

        dd = d;
        mm = m;
        yy = y;
    }
    else throw std::runtime_error("Неверный разделитель! Проверьте корректность вводимых данных.");
}


void DateStruct::printDate(std::ostream& out) {
    out << "Дата: " << dd << '.' << mm << '.' << yy;
}


int DateStruct::getDD() {
    return dd;
}

int DateStruct::getMM() {
    return mm;
}

int DateStruct::getYY() {
    return yy;
}

void DateStruct::setDD(int value) {
    Correct(value, 12, 12);
    dd = value;
}

void DateStruct::setMM(int value) {
    Correct(12, value, 12);
    mm = value;
}

void DateStruct::setYY(int value) {
    Correct(12, 12, value);
    yy = value;
}


bool DateStruct::isLeapYear(int year) {
    if (year < 0) throw std::runtime_error("Год не может быть отрицательным!");
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


void DateStruct::Correct(int day, int month, int year) {
    int maxDaysInMonth = 31;
    if (month == 2) {
        maxDaysInMonth = isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDaysInMonth = 30;
    }

    if (day < 1 || !(day <= maxDaysInMonth)) throw std::runtime_error("День ввёден неверно! Проверьте корректность входных данных");
    if (month < 1 || month > 12) throw std::runtime_error("Месяц ввёден неверно! Проверьте корректность входных данных");
    if (year < 0 || year > 99) throw std::runtime_error("Год ввёден неверно! Проверьте корректность входных данных");
}

void DateStruct::CorrectDate(std::string& dateStr) {
    if ((dateStr.length() > 8 || dateStr.length() <= 7) || !(dateStr[2] == '.' && dateStr[5] == '.')) throw std::runtime_error("Дата введена неверно! Проверьте корректность входных данных");
    int d = stoi(dateStr.substr(0, 2));
    int m = stoi(dateStr.substr(3, 5));
    int y = stoi(dateStr.substr(6, 8));

    Correct(d, m, y);
}
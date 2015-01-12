//
//  Excursion.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "Excursion.h"
Excursion::Excursion() : _name("None")
{
    _cost = 0.0;
    _maxTourists = 10;
    _soldSeats = 0;
    
    time_t t = time(NULL);
    time_t* p_t = &t;
    //time_t* p_t = time(NULL);
    //*p_t = time(NULL);
    _dateStart = *localtime(p_t);
    //_dateStart.tm_year += 1900;
}

Excursion::Excursion(const string &name,
                     const float  &cost,
                     const unsigned int &year,
                     const unsigned int &month,
                     const unsigned int &day,
                     const unsigned int &hour,
                     const unsigned int &min,
                     const unsigned int &maxTourists,
                     const unsigned int &soldSeats) : _name(name), _cost(cost), _maxTourists(maxTourists), _soldSeats(soldSeats)
{
    setDateStart(year, month, day, hour, min);
}

Excursion::~Excursion()
{
}

void Excursion::setName(const string &name)
{
    _name = name;
}

void Excursion::setName(std::istream &is)
{
    is >> _name;
}

string Excursion::getName() const
{
    return _name;
}

void Excursion::setDateStart(const unsigned int &year,
                             const unsigned int &month,
                             const unsigned int &day,
                             const unsigned int &hour,
                             const unsigned int &min)
{
    _dateStart.tm_year = year - 1900;
    _dateStart.tm_mon  = month;
    _dateStart.tm_mday = day;
    _dateStart.tm_hour = hour;
    _dateStart.tm_min  = min;
}

tm Excursion::getDateStart() const
{
    return _dateStart;
}

void Excursion::setCost(const float &cost)
{
    _cost = cost;
}

float Excursion::getCost() const
{
    return _cost;
}

void Excursion::setMaxTourists(const unsigned int &maxTourists)
{
    _maxTourists = maxTourists;
}

void Excursion::setSoldSeats(const unsigned int &soldSeats)
{
    _soldSeats = soldSeats;
}

unsigned int Excursion::getMaxTourists() const
{
    return _maxTourists;
}

unsigned int Excursion::getSoldSeats() const
{
    return _soldSeats;
}


std::ostream &Excursion::show(std::ostream &os) const
{
    os << "excursion name: " << _name << std::endl;
    os << "date start excursion: " << _dateStart.tm_mday << "."
    << _dateStart.tm_mon << "."
    << _dateStart.tm_year + 1900 << " "
    << _dateStart.tm_hour << "h"
    << _dateStart.tm_min << "m" << std::endl;
    os << "cost: " << _cost << std::endl;
    os << "maximum tourists: " << _maxTourists << std::endl;
    os << "sold seats: " << _soldSeats << std::endl;
    
    return os;
}

void Excursion::sellSeats(const unsigned int &sellSeats)
{
    _soldSeats += sellSeats;
}

void  Excursion::freeSeats(const unsigned int &freeSeats)
{
    _soldSeats -= freeSeats;
}

std::istream &Excursion::get(std::istream &is)
{
    
    std::cout << "enter excursion name: ";
    is >> _name;
    std::cout << "enter excursion date start" << std::endl;
    std::cout << "enter day: ";
    is >> _dateStart.tm_mday;
    std::cout << "enter month: ";
    is >> _dateStart.tm_mon;
    std::cout << "enter year: ";
    int year = 0;
    is >> year;
    _dateStart.tm_year = year - 1900;
    std::cout << "enter hour: ";
    is >> _dateStart.tm_hour;
    std::cout << "enter min: ";
    is >> _dateStart.tm_min;
    std::cout << "enter excursion cost: ";
    is >> _cost;
    std::cout << "enter maximum tourists: ";
    is >> _maxTourists;
    std::cout << "enter sold seats: ";
    is >> _soldSeats;
    
    return is;
}

std::ostream &operator<<(std::ostream &os, const Excursion &excursion)
{
    return excursion.show(os);
}


std::istream &operator>>(std::istream &is, Excursion &excursion)
{
    return excursion.get(is);
}


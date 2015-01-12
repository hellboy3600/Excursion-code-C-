//
//  multiday_excursion.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "multiday_excursion.h"
MultidayExcursion::MultidayExcursion()
{
    _amountDays = 2;
    _routes = new Route[_amountDays];
}

MultidayExcursion::MultidayExcursion(const unsigned int &amountDays)
{
    _amountDays = amountDays;
    _routes = new Route[_amountDays];
}

MultidayExcursion::MultidayExcursion(const unsigned int &amountDays, Route* routes)
{
    int i = 0;
    
    _amountDays = amountDays;
    _routes = new Route[_amountDays];
    for (i = 0; i < _amountDays; i++)
        _routes[i] = routes[i];
}

MultidayExcursion::MultidayExcursion(const MultidayExcursion &multidayExcursion) : Excursion(multidayExcursion)
{
    int i = 0;
    
    _amountDays = multidayExcursion._amountDays;
    _routes = new Route[_amountDays];
    for (i = 0; i < _amountDays; i++)
        _routes[i] = multidayExcursion._routes[i];
}

MultidayExcursion::~MultidayExcursion()
{
    delete[] _routes;
}


std::ostream &MultidayExcursion::show(std::ostream &os) const
{
    int i = 0;
    
    os << "==== multiday excursion ====" << std::endl;
    os << std::endl;
    
    Excursion::show(os);
    
    os << std::endl;
    os << "excursion routes:" << std::endl;
    for (i = 0; i < _amountDays; i++)
    {
        os << "----------------------------" << std::endl;
        os << i+1 << " route" << std::endl;
        os << _routes[i] << std::endl;
        os << "----------------------------" << std::endl;
    }
    
    return os;
}


std::ostream &operator<<(std::ostream &os, MultidayExcursion &multidayExcursion)
{
    return multidayExcursion.show(os);
}

unsigned int MultidayExcursion::getAmountDays() const
{
    return _amountDays;
}



MultidayExcursion::MultidayExcursion(const unsigned int &amountDays,
                                     const string &name,
                                     const float  &cost,
                                     const unsigned int &year,
                                     const unsigned int &month,
                                     const unsigned int &day,
                                     const unsigned int &hour,
                                     const unsigned int &min,
                                     const unsigned int &maxTourists,
                                     const unsigned int &soldSeats) : Excursion (name, cost, year, month, day, hour, min, maxTourists, soldSeats)
{
    _amountDays = amountDays;
    _routes = new Route[_amountDays];
}

MultidayExcursion::MultidayExcursion(const unsigned int &amountDays,
                                     const string &name,
                                     const float  &cost,
                                     const unsigned int &year,
                                     const unsigned int &month,
                                     const unsigned int &day,
                                     const unsigned int &hour,
                                     const unsigned int &min,
                                     const unsigned int &maxTourists,
                                     const unsigned int &soldSeats,
                                     Route* routes) : Excursion (name, cost, year, month, day, hour, min, maxTourists, soldSeats)
{
    int i = 0;
    
    _amountDays = amountDays;
    _routes = new Route[_amountDays];
    for (i = 0; i < _amountDays; i++)
        _routes[i] = routes[i];
}

MultidayExcursion &MultidayExcursion::operator=(const MultidayExcursion &multidayExcursion)
{
    int i = 0;
    
    if (this == &multidayExcursion)
        return *this;
    
    _amountDays = multidayExcursion._amountDays;
    delete[] _routes;
    _routes = new Route[_amountDays];
    
    for (i = 0; i < _amountDays; i++)
        _routes[i] = multidayExcursion._routes[i];
    
    return *this;
}

Route &MultidayExcursion::getRoute(const unsigned int &n)
{
    return _routes[n];
}

Route* MultidayExcursion::getRoutes()
{
    return _routes;
}

void MultidayExcursion::setRoute(const unsigned int &n, const Route &route)
{
    _routes[n] = route;
}

void MultidayExcursion::setRoutes(const unsigned int &amountDays, Route* routes)
{
    int i = 0;
    
    if (amountDays == _amountDays)
        for (i = 0; i < amountDays; i++)
            _routes[i] = routes[i];
    
    else
        std::cout << "oops!" << std::endl;
}


void MultidayExcursion::setAmountDays(const unsigned int &amountDays)
{
    _amountDays = amountDays;
    *this = MultidayExcursion(_amountDays);
}

void MultidayExcursion::setAmountDays(std::istream &is)
{
    is >> _amountDays;
    *this = MultidayExcursion(_amountDays);
}



std::istream &MultidayExcursion::get(std::istream &is)
{
    int i = 0;
    
    
    std::cout << "==== enter multiday excursion ====" << std::endl;
    
    
    Excursion::get(is);
    
    
    std::cout << "enter amount days: ";
    setAmountDays(is);
    
    
    std::cout << "enter routes" << std::endl;
    for (i = 0; i < _amountDays; i++)
    {
        std::cout << "enter route " << i+1 << " day" << std::endl;
        is >> _routes[i];
    }
    
    return is;
}

std::istream &operator>>(std::istream &is, MultidayExcursion &multidayExcursion)
{
    return multidayExcursion.get(is);
}
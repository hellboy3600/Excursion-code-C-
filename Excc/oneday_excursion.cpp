//
//  oneday_excursion.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "oneday_excursion.h"
OnedayExcursion::OnedayExcursion() : _route()
{
}

OnedayExcursion::OnedayExcursion(const string &name,
                                 const float  &cost,
                                 const unsigned int &year,
                                 const unsigned int &month,
                                 const unsigned int &day,
                                 const unsigned int &hour,
                                 const unsigned int &min,
                                 const unsigned int &maxTourists,
                                 const unsigned int &soldSeats) : Excursion(name, cost, year, month, day, hour, min, maxTourists, soldSeats), _route()
{
}

OnedayExcursion::OnedayExcursion(const string &name,
                                 const float  &cost,
                                 const unsigned int &year,
                                 const unsigned int &month,
                                 const unsigned int &day,
                                 const unsigned int &hour,
                                 const unsigned int &min,
                                 const unsigned int &maxTourists,
                                 const unsigned int &soldSeats,
                                 const Route &route) : Excursion(name, cost, year, month, day, hour, min, maxTourists, soldSeats), _route(route)
{
}

OnedayExcursion::~OnedayExcursion()
{
}

Route &OnedayExcursion::getRoute()
{
    return _route;
}

void OnedayExcursion::setRoute(const Route &route)
{
    _route = route;
}


std::ostream &OnedayExcursion::show(std::ostream &os) const
{
    os << "==== oneday excursion ====" << std::endl;
    os << std::endl;
    
    Excursion::show(os);
    
    os << std::endl;
    os << "excursion route:" << std::endl;
    os << "----------------------------" << std::endl;
    os << _route << std::endl;
    os << "----------------------------" << std::endl;
    
    return os;
}


std::ostream &operator<<(std::ostream &os, const OnedayExcursion &onedayExcursion)
{
    return onedayExcursion.show(os);
}

std::istream &OnedayExcursion::get(std::istream &is)
{
    std::cout << "==== enter oneday excursion ====" << std::endl;
    
    Excursion::get(is);
    
    is >> _route;
    
    return is;
}

std::istream &operator>>(std::istream &is, OnedayExcursion &onedayExcursion)
{
    return onedayExcursion.get(is);
}
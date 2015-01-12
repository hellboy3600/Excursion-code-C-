//
//  item.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "item.h"
#include <iostream>

Item::Item() : _namePlace("None"), _nameItem("None")
{
    _duration = 1;
    
    time_t t;
    time_t* p_t = &t;
    *p_t = time(NULL);
    _timeStart = *localtime(p_t);
}

Item::Item(const string &namePlace,
           const string &nameItem,
           const unsigned int &hour,
           const unsigned int &min,
           const unsigned int &duration) : _namePlace(namePlace), _nameItem(nameItem)
{
    _duration = duration;
    setTimeStart(hour,min);
}

Item::~Item()
{
}

void Item::setNamePlace(const string &namePlace)
{
    _namePlace = namePlace;
}

string Item::getNamePlace() const
{
    return _namePlace;
}

void Item::setNameItem(const string &nameItem)
{
    _nameItem = nameItem;
}

string Item::getNameItem() const
{
    return _nameItem;
}

void Item::setTimeStart(const unsigned int &hour, const unsigned int &min)
{
    _timeStart.tm_hour = hour;
    _timeStart.tm_min  = min;
}

tm Item::getTimeStart() const
{
    return _timeStart;
}

void Item::setDuration(const unsigned int &duration)
{
    _duration = duration;
}

int Item::getDuration() const
{
    return _duration;
}

std::ostream &operator<<(std::ostream &os, const Item &item)
{
    os << "name place: " << item.getNamePlace() << std::endl;
    os << "name item: " << item.getNameItem() << std::endl;
    os << "time start item: " << (item.getTimeStart()).tm_hour << "h" << (item.getTimeStart()).tm_min << "m" << std::endl;
    os << "duration item: " << item.getDuration();
    
    return os;
}

std::istream &operator>>(std::istream &is, Item &item)
{
    std::cout << "==== enter item ====" << std::endl;
    std::cout << "enter item name place: ";
    item.setNamePlace(is);
    std::cout << "enter name item: ";
    item.setNameItem(is);
    std::cout << "enter item time start" << std::endl;
    item.setTimeStart(is);
    std::cout << "enter item duration: ";
    item.setDuration(is);
    
    return is;
}

void Item::setNamePlace(std::istream &is)
{
    is >> _namePlace;
}

void Item::setNameItem(std::istream &is)
{
    is >> _nameItem;
}

void Item::setTimeStart(std::istream &is)
{
    std::cout << "enter hour: ";
    is >> _timeStart.tm_hour;
    std::cout << "enter minutes: ";
    is >> _timeStart.tm_min;
}

void Item::setDuration(std::istream &is)
{
    is >> _duration;
}

/*
 std::istream &Item::print(std::istream &is)
 {
	std::cout << "test" << std::endl;
 
	return is;
 }
 */
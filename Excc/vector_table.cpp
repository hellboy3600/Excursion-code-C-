//
//  vector_table.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "vector_table.h"
#include "oneday_excursion.h"
#include "multiday_excursion.h"
#include <algorithm>


VectorTable::VectorTable()
{
}

VectorTable::~VectorTable()
{
    auto i = _table.begin();
    
    for (i = _table.begin(); i != _table.end(); i++)
    {
        delete i->excursion;
        i->excursion = nullptr;
    }
}

void VectorTable::addRecord(const unsigned int &code, Excursion &excursion)
{
    Record record;
    record.code = code;
    record.excursion = &excursion;
    
    _table.push_back(record);
}

void VectorTable::addRecord(Record &record)
{
    _table.push_back(record);
}

std::ostream &operator<<(std::ostream &os, const VectorTable &vectorTable)
{
    
    //os << vectorTable._table[0].code;
    //os << *vectorTable._table[0].excursion;
    
    auto i = vectorTable._table.begin();
    
    for (i = vectorTable._table.begin(); i != vectorTable._table.end(); i++)
    {
        os << "-------------------------------------" << std::endl;
        os << *i;
        os << "-------------------------------------" << std::endl;
    }
    
    return os;
}


std::vector<Record>::iterator VectorTable::find(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    auto i = _table.begin();
    
    for (i = _table.begin(); i != _table.end(); i++)
        if ((code == (*i).code) &&
            (year == (*i).excursion->getDateStart().tm_year + 1900) &&
            (month == (*i).excursion->getDateStart().tm_mon) &&
            (day == (*i).excursion->getDateStart().tm_mday))
        {
            //std::cout << *i;
            return i;
        }
    
    return _table.end();
}

bool VectorTable::erase(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    auto i = find(code,year,month,day);
    
    if (i != _table.end())
        _table.erase(i,i+1);
    
    return true;
}


void VectorTable::addRecord(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    auto i = _table.begin();
    
    for (i = _table.begin(); i != _table.end(); i++)
        if (code == (*i).code)
        {
            _table.push_back(*i);
            (*(_table.end()-1)).excursion->setDateStart(year,month,day,0,0);
            return;
        }
}

void VectorTable::AllFind(const unsigned int &code)
{
    auto i = _table.begin();
    
    for (i = _table.begin(); i != _table.end(); i++)
        if (code == i->code)
            std::cout << *i << std::endl;
    
}


void VectorTable::GetAllDate(const unsigned int &code)
{
    auto i = _table.begin();
    int j = 1;
    
    for (i = _table.begin(); i != _table.end(); i++)
        if (code == i->code)
        {
            std::cout << "date start " << j << " excursion ";
            std::cout << (i->excursion->getDateStart()).tm_year + 1900 << ".";
            std::cout << (i->excursion->getDateStart()).tm_mon << ".";
            std::cout << (i->excursion->getDateStart()).tm_mday << std::endl;
            j++;
        }
    
}

int VectorTable::SoldSeats(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    int seats = 0;
    
    auto i = find(code,year,month,day);
    
    seats = (*i).excursion->getSoldSeats();
    
    return seats;
}



tm VectorTable::GetData(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    tm data;
    
    auto i = find(code,year,month,day);
    
    data = (*i).excursion->getDateStart();
    
    return data;
}

void VectorTable::SetData(std::vector<Record>::iterator &i, const unsigned int &year, const unsigned int &month, const unsigned int &day, const unsigned int &hour, const unsigned int &min)
{
    i->excursion->setDateStart(year, month, day, hour, min);
    
}

std::vector<Record>::iterator VectorTable::findClosest(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day)
{
    auto i = _table.begin();
    auto positionRecord = _table.begin();
    
    time_t desiredDate, currentDate;
    tm temp_data = {0};
    
    auto d = 1000000000;
    double differenceDates = 0;
    
    tm desiredDateStruct = {0};
    
    desiredDateStruct.tm_year = year - 1900;
    desiredDateStruct.tm_mon  = month;
    desiredDateStruct.tm_mday = day;
    
    desiredDate = mktime(&desiredDateStruct);
    
    
    for (i = _table.begin(); i != _table.end(); i++)
    {
        temp_data = i->excursion->getDateStart();
        currentDate = mktime(&temp_data);
        differenceDates = abs(difftime(desiredDate,currentDate));
        
        if ((code == i->code) && (differenceDates<d))
        {
            d = differenceDates;
            positionRecord = i;
        }
    }
    
    return positionRecord;
}

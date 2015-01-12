//
//  record.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__record__
#define __Excc__record__

#include <stdio.h>
#include "excursion.h"

struct Record
{
    unsigned int code;
    Excursion* excursion;
    
    Record() : code(0), excursion(NULL) {} //! конструктор структуры, состоящей из кода экскурсии и указателя на экскурсию
    
public:
    Record(const Record &record);
};

std::ostream &operator<<(std::ostream &os, const Record &record); //! перегруженный оператор вывода
std::istream &operator>>(std::istream &is, Record &record);//! перегруженный оператор ввода

#endif /* defined(__Excc__record__) */

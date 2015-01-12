//
//  record.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include "record.h"
#include "oneday_excursion.h"
#include "multiday_excursion.h"

//TEST

Record::Record(const Record &record)
{
    code = record.code;
    excursion = record.excursion->clone();
}




std::ostream &operator<<(std::ostream &os, const Record &record)
{
    os << "record code: ";
    os << record.code << std::endl;
    os << "record excursion" << std::endl;
    os << *record.excursion;
    
    return os;
}

std::istream &operator>>(std::istream &is, Record &record)
{
    int type = 0;
    
    std::cout << "what type of excursion enter?" << std::endl;
    std::cout << "oneday excursion: 1" << std::endl;
    std::cout << "multiday excursion: 2" << std::endl;
    std::cout << "type is: ";
    is >> type;
    
    std::cout << "enter code record: ";
    is >> record.code;
    
    switch (type)
    {
        case 1:
        {
            OnedayExcursion onedayExcursion;
            is >> onedayExcursion;
            record.excursion = new OnedayExcursion(onedayExcursion);
            break;
        }
        case 2:
        {
            MultidayExcursion multidayExcursion;
            is >> multidayExcursion;
            record.excursion = new MultidayExcursion(multidayExcursion);
            break;
        }
    }
    
    return is;
}
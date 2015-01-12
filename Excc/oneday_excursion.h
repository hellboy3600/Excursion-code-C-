//
//  oneday_excursion.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__oneday_excursion__
#define __Excc__oneday_excursion__

#include <stdio.h>
#include "Excursion.h"

class OnedayExcursion : public Excursion
{
public:
    OnedayExcursion();//! конструктор однодневной экскурсии по умолчанию
    OnedayExcursion(const string &name,
                    const float  &cost,
                    const unsigned int &year,
                    const unsigned int &month,
                    const unsigned int &day,
                    const unsigned int &hour,
                    const unsigned int &min,
                    const unsigned int &maxTourists,
                    const unsigned int &soldSeats);//!конструктор однодневной экскурсии
    OnedayExcursion(const string &name,
                    const float  &cost,
                    const unsigned int &year,
                    const unsigned int &month,
                    const unsigned int &day,
                    const unsigned int &hour,
                    const unsigned int &min,
                    const unsigned int &maxTourists,
                    const unsigned int &soldSeats,
                    const Route &route);//! конструктор однодневной экскурсии
    ~OnedayExcursion();//! деструктор однодневной экскурсии
    
    virtual OnedayExcursion* clone() const { return new OnedayExcursion(*this); } //!метод клонирующий эксукрсию
    
    void  setRoute(const Route &route);//! ввод маршрута
    Route &getRoute(); //! вывод маршрута
    
    friend std::ostream &operator<<(std::ostream &os, const OnedayExcursion &onedayExcursion);//! перегруженный оператор вывода
    friend std::istream &operator>>(std::istream &is, OnedayExcursion &onedayExcursion);//! перегруженный оператор ввода
    
protected:
    virtual std::ostream &show(std::ostream &os) const;//! вывод информации об однодневной экскурсии
    virtual std::istream &get(std::istream &is);//! получение данных об однодневной экскурсии
private:
    Route _route;
};
#endif /* defined(__Excc__oneday_excursion__) */

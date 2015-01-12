//
//  multiday_excursion.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__multiday_excursion__
#define __Excc__multiday_excursion__

#include <stdio.h>
#include "Excursion.h"

class MultidayExcursion : public Excursion
{
public:
    MultidayExcursion();//! конструктор многодневной экскурсии по умолчанию
    MultidayExcursion(const unsigned int &amountDays);//! конструктор многодневной экскурсии по количеству дней
    MultidayExcursion(const unsigned int &amountDays, Route* routes);//! конструктор многодневной экскурсии по маршрута и количеству дней
    MultidayExcursion(const MultidayExcursion &multidayExcursion);//!копирующий конструктор
    MultidayExcursion(const unsigned int &amountDays,
                      const string &name,
                      const float  &cost,
                      const unsigned int &year,
                      const unsigned int &month,
                      const unsigned int &day,
                      const unsigned int &hour,
                      const unsigned int &min,
                      const unsigned int &maxTourists,
                      const unsigned int &soldSeats);//! конструктор многодневаной экскурсии
    MultidayExcursion(const unsigned int &amountDays,
                      const string &name,
                      const float  &cost,
                      const unsigned int &year,
                      const unsigned int &month,
                      const unsigned int &day,
                      const unsigned int &hour,
                      const unsigned int &min,
                      const unsigned int &maxTourists,
                      const unsigned int &soldSeats,
                      Route* routes);//! конструктор многодневной экскурсии
    ~MultidayExcursion();//! диструктор
    
    MultidayExcursion &operator=(const MultidayExcursion &multidayExcursion);//! перегруженный оператор присваивания
    friend std::ostream &operator<<(std::ostream &os, MultidayExcursion &multidayExcursion);//! перегруженный оператор вывода
    friend std::istream &operator>>(std::istream &is, MultidayExcursion &multidayExcursion);//! перегруженный оператор ввода
    
    virtual MultidayExcursion* clone() const { return new MultidayExcursion(*this); }//!метод клонирующий многодневную экскурсию
    
    void   setAmountDays(const unsigned int &amountDays);//! ввод количества дней
    void   setAmountDays(std::istream &is);//! ввод количества дней в поток
    void   setRoutes(const unsigned int &anountDays, Route* routes);//! ввод маршрутов
    void   setRoute(const unsigned int &n, const Route &route);//! ввод одного маршрута
    Route  &getRoute(const unsigned int &n);//! вывод маршрута
    Route* getRoutes();//! вывод всех маршрутов
    unsigned int getAmountDays() const;//! вывод количества дней
    
protected:	
    virtual std::ostream &show(std::ostream &os) const;//! вывод информации о многодневной экскурсии
    virtual std::istream &get(std::istream &is);//! вывод информации о многодневной экскурсии
    
private:
    unsigned int _amountDays;
    Route*       _routes;
};
#endif /* defined(__Excc__multiday_excursion__) */

//
//  route.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__route__
#define __Excc__route__

#include <stdio.h>
#include "item.h"

class Route
{
public:
    Route(); //! конструктор маршрута по умолчанию
    Route(const unsigned int &amountItems);//! контруктор маршрута по количеству экскурсиооных объектов
    Route(const Item &item);//! конструктор маршрута по экскурсиооному объекту
    Route(const unsigned int &amountItems, Item* items);//! конструктор маршрута по экскурсионному объекту и их количеству
    Route(const Route &route);//! копирующий конструктор маршрута
    ~Route();//!деструктор маршрута
    
    void setAmountItems(const unsigned int &amountItems);//! ввод количества экскурсионных объектов
    void setAmountItems(std::istream &is);//! ввод количества экскурсионных объектов в поток
    void setItem(const unsigned int &n, const Item &item);//! ввод данных экскурсионного объекта
    Item &getItem(const unsigned int &n); //! вывод данных экскурсиооного объекта
    tm   getTimeStart() const;//! вывод времени начала экскурсиооного объекта
    unsigned int getAmountItems() const; //! вывод количества экскурсиооных объектов
    unsigned int getDuration() const; //! вывод продолжительности экскурсии
    
    Route &operator=(const Route &route);//! перегруженный оператор присваивания
    
    friend std::ostream &operator<<(std::ostream &os, const Route &route);//! перегруженный оператор вывода
    friend std::istream &operator>>(std::istream &is, Route &route);//! перегруженный оператор ввода
    
private:
    unsigned int _amountItems;
    Item*        _items;
};
#endif /* defined(__Excc__route__) */

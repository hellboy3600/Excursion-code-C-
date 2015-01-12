//
//  item.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__item__
#define __Excc__item__

#include <stdio.h>
#include <string>
#include <time.h>
#include <iostream>

using std::string;

class Item
{
public:
    
    Item(); //! конструктор пункта по умолчанию (название населенного пункта - None, название экскурсионного объекта - None, дата и время - текущее время
    Item(const string &namePlace, //! конструктор пункта
         const string &nameItem,
         const unsigned int &hour,
         const unsigned int &min,
         const unsigned int &duration);
    ~Item(); //! диструктор пункта
    
    void   setNamePlace(const string &namePlace); //! ввод названия населенного пункта
    void   setNamePlace(std::istream &is);//! ввод названия населенного пункта в поток
    string getNamePlace() const; //! вывод название населенного пунска
    void   setNameItem(const string &nameItem);//! ввод названия экскурсионного объекта
    void   setNameItem(std::istream &is);//! ввод названия экскурсиооного объекта в поток
    string getNameItem() const;//! вывод названия экскурсиооного объекта
    void   setTimeStart(const unsigned int &hour, const unsigned int &min); //! ввод времени начала экскурсии
    void   setTimeStart(std::istream &is); //! ввод времени начала экскурсии в поток
    tm     getTimeStart() const; //! вывод времени начала экскурсии
    void   setDuration(const unsigned int &duration); //! ввод продолжительности экскурсии
    void   setDuration(std::istream &is); //! ввод продолжительности экскурсии в поток
    int    getDuration() const; //! вывод продолжительности экскурсии
    
    friend std::ostream &operator<<(std::ostream &os, const Item &item);//! перегруженный оператор вывда
    friend std::istream &operator>>(std::istream &is, Item &item);//! перегруженный оператор ввода
    
private:
    string       _namePlace;
    string       _nameItem;
    tm	         _timeStart;
    unsigned int _duration;
};
#endif /* defined(__Excc__item__) */

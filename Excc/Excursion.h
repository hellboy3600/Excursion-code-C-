//
//  Excursion.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__Excursion__
#define __Excc__Excursion__

#include <stdio.h>
#include "route.h"

class Excursion
{
public:
    Excursion();
    Excursion(const string &name,
              const float  &cost,
              const unsigned int &year,
              const unsigned int &month,
              const unsigned int &day,
              const unsigned int &hour,
              const unsigned int &min,
              const unsigned int &maxTourists,
              const unsigned int &soldSeats);
    virtual ~Excursion();
    
    virtual Excursion* clone() const = 0;
    
    friend std::ostream &operator<<(std::ostream &os, const Excursion &excursion);
    friend std::istream &operator>>(std::istream &is, Excursion &excursion);
    
    virtual void   setName(const string &name);
    virtual void   setName(std::istream &is);
    virtual string getName() const;
    virtual void   setDateStart(const unsigned int &year,
                                const unsigned int &month,
                                const unsigned int &day,
                                const unsigned int &hour,
                                const unsigned int &min);
    virtual tm    getDateStart() const;
    virtual void  setCost(const float &cost);
    virtual float getCost() const;
    virtual void  setMaxTourists(const unsigned int &maxTourists);
    virtual void  setSoldSeats(const unsigned int &soldSeats);
    virtual void  sellSeats(const unsigned int &sellSeats);
    virtual void  freeSeats(const unsigned int &freeSeats);
    virtual unsigned int getSoldSeats() const;
    virtual unsigned int getMaxTourists() const;
    
    std::string eGetNamePlace ();
    
protected:
    virtual std::ostream &show(std::ostream &os) const = 0;
    virtual std::istream &get(std::istream &is) = 0;
    
private:
    string _name;
    tm     _dateStart;
    float  _cost;
    unsigned int _maxTourists;
    unsigned int _soldSeats;
};
#endif /* defined(__Excc__Excursion__) */

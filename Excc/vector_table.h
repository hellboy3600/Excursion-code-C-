//
//  vector_table.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__vector_table__
#define __Excc__vector_table__

#include <stdio.h>
#include "record.h"
#include <vector>

class VectorTable
{
public:
    VectorTable();
    ~VectorTable();
    
    void addRecord(const unsigned int &code, Excursion &excursion);
    void addRecord(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    void addRecord(Record &record);
    
    //void find(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    std::vector<Record>::iterator find(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    tm GetData(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    
    std::string GetNamePlace(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    bool erase(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    
    friend std::ostream &operator<<(std::ostream &os, const VectorTable &vectorTable);
    int SoldSeats(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    
    void SetData(std::vector<Record>::iterator &i, const unsigned int &year, const unsigned int &month, const unsigned int &day, const unsigned int &hour, const unsigned int &min);
    
    void GetAllDate(const unsigned int &code);
    
    std::vector<Record>::iterator findClosest(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    void Replace(const unsigned int &code, const unsigned int &year, const unsigned int &month, const unsigned int &day);
    void AllFind(const unsigned int &code);
private:
    std::vector <Record> _table;
};
#endif /* defined(__Excc__vector_table__) */

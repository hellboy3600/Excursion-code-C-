//
//  table_iterator.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__table_iterator__
#define __Excc__table_iterator__

#include <stdio.h>
#include "record.h"

class TableIterator
{
public:
    TableIterator() : _curentRecord(NULL){}
    TableIterator(Record* currentRecord) : _curentRecord(currentRecord){}
    ~TableIterator();
    
    Record &operator*();
    TableIterator &operator++();
    TableIterator operator++(int);
    int operator !=(const TableIterator &tableItarator) const;
    int operator ==(const TableIterator &tableTterator) const;
    
private:
    Record* _curentRecord;
};
#endif /* defined(__Excc__table_iterator__) */

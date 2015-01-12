//
//  main.cpp
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#include <iostream>

#include "oneday_excursion.h"
#include "multiday_excursion.h"
//#include "record.h"
//#include <vector>
#include "vector_table.h"

using namespace std;

//const int M = 5;



int SetTableExcursion(VectorTable &vt);
int GetTableExcursion(VectorTable &vt);
int DelTableExcursion(VectorTable &vt);
int FindTableExcursion(VectorTable &vt);
int AddRecord(VectorTable &vt);
int GetExcursion(VectorTable &vt);
int GetSeats(VectorTable &vt);
int GetData(VectorTable &vt);
int SetData(VectorTable &vt);
int FindClosest(VectorTable &vt);
int BuyTicket(VectorTable &vt);
int Replace (VectorTable &vt);
int PassTicket(VectorTable &vt);


int Exit(VectorTable &vt);

int main()
{
    
    VectorTable vt;
    int i;
    int exit = 0;
    int ch = 0;
    
    
    char *msgs[] = {  "- Set table excursion\n", "- Get table excursion\n","- Del Table excursion\n", "- Find Table excursion\n", "- Add Record\n", "- Get excursion\n","- Get seats\n","- Get data\n", "- Set data\n", "- Find closest\n", "- Buy ticket\n", "- Pass ticket\n","- Replace\n", "- Exit\n" };
    const int amount = sizeof(msgs) / sizeof(msgs[0]);
    
    for (i = 0; i<amount; ++i)
    {
        std::cout << i << " " << msgs[i];
    }
    
    int(*func[amount])(VectorTable &v) = { SetTableExcursion, GetTableExcursion, DelTableExcursion, FindTableExcursion, AddRecord, GetExcursion, GetSeats,GetData, SetData, FindClosest, BuyTicket, PassTicket,Replace, Exit };
    
    while (!exit)
    {
        std::cout << "\n GOGOGO  ";
        std::cin >> ch;
        
        if ((ch > -1) && (ch < amount))
        {
            exit = (*func[ch])(vt);
        }
    }
    
    return 0;
}

int SetTableExcursion(VectorTable &vt)
{
    int n = 0;
    int i = 0;
    Record r;
    std::cout << "enter amount excurions" << endl;
    std::cin >> n;
    
    for (i = 0; i < n; i++)
    {
        cout << "enter " << i + 1 << " record" << endl;
        
        std::cin >> r;
        
        vt.addRecord(r);
    }
    return 0;
}

int GetTableExcursion(VectorTable &vt)
{
    std::cout << vt;
    
    return 0;
}

int DelTableExcursion(VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    vt.erase(code, year, month, day);
    
    return 0;
}

int FindTableExcursion(VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    std::cout << *vt.find(code, year, month, day);
    
    return 0;
}

int AddRecord(VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    vt.addRecord(code, year, month, day);
    std::cout << vt;
    
    return 0;
}

int GetExcursion(VectorTable &vt)
{
    int code = 0;
    std::cout << "enter code" << std::endl;
    std::cin >>code;
    
    vt.AllFind(code);
    
    return 0;
}

int GetSeats(VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    int seats = 0;
    
    seats = vt.SoldSeats(code, year, month, day);
    std::cout << "Sold seats - " << seats << std::endl;
    
    return 0;
}

int GetData(VectorTable &vt)
{
    int code;
    std::cout << "enter code" << endl;
    std::cin >> code;
    
    vt.GetAllDate(code);
    
    return 0;
}

int SetData(VectorTable &vt)
{
    int code, day, month, year,hour, min;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    auto i = vt.find(code, year, month, day);
    
    std::cout << "enter new year" << std::endl;
    std::cin >> year;
    std::cout << "enter new month" << std::endl;
    std::cin >> month;
    std::cout << "enter new day" << std::endl;
    std::cin >> day;
    std::cout << "enter new hour" << std::endl;
    std::cin >> hour;
    std::cout << "enter new min" << std::endl;
    std::cin >> min;
    
    vt.SetData(i, year, month, day, hour, min);
    
    return 0;
}

int FindClosest(VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    
    std::cout << *vt.findClosest(code, year, month, day);
    
    return 0;
}

int BuyTicket(VectorTable &vt)
{
    int code, day, month, year, amountTicket;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    std::cout << "enter amout Ticket" << std::endl;
    std::cin >> amountTicket;
    
    vt.find(code,year,month,day)->excursion->sellSeats(amountTicket);
    return 0;
}


int PassTicket(VectorTable &vt)
{
    int code, day, month, year, amountTicket;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    std::cout << "enter amout Ticket" << std::endl;
    std::cin >> amountTicket;
    
    vt.find(code,year,month,day)->excursion->freeSeats(amountTicket);
    return 0;
}

int Replace (VectorTable &vt)
{
    int code, day, month, year;
    std::cout << "enter code" << endl;
    std::cin >> code;
    std::cout << "enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "enter day" << std::endl;
    std::cin >> day;
    vt.erase(code, year, month, day);
    
    Record r;
    std::cout << "enter new excursion" << std::endl;
    std::cin >> r;
    vt.addRecord(r);
    
    return 0;
}

int Exit(VectorTable &vt)
{
    return 1;
}



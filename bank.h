#ifndef BANK_H
#define BANK_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct bank
{
    float purchase;
    float sale;
    char name[MAX_STRING_SIZE];
    char address[MAX_STRING_SIZE];
    date start;
    date finish;
    char title[MAX_STRING_SIZE];
};

#endif
#ifndef BANK_H
#define BANK_H

#include "constants.h"

struct bank
{
    float purchase;
    float sale;
    char name[MAX_STRING_SIZE];
    char address[MAX_STRING_SIZE];
    char title[MAX_STRING_SIZE];
};

#endif
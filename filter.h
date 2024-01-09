#ifndef FILTER_H
#define FILTER_H

#include "bank.h"

bank** filter(bank* array[], int size, bool (*check)(bank* element), int& result_size);


bool check_belarus_bank_prices(bank* element);


bool check_bank_sale(bank* element);

#endif

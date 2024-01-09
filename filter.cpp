#include "filter.h"
#include <cstring>
#include <iostream>

bank** filter(bank* array[], int size, bool (*check)(bank* element), int& result_size)
{
	bank** result = new bank * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_belarus_bank_prices(bank* element)
{
	return element->name == "Беларусбанк";
}

bool check_bank_sale(bank* element)
{
	return element->sale < 2.5;
}

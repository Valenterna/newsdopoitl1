// Название банка
// Покупка 
// Продажа
// Адрес

#ifndef BANK_H
#define BANK_H

struct bank
{
	float purchase;
	float sale;
	char address[MAX_STRING_SIZE];
	char name[MAX_STRING_SIZE];
};

#endif
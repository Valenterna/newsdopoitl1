//В соответствии с заданием своего варианта 
//(см. ниже) необходимо разработать консольное приложение по
//обработке некоторых данных, хранящихся в текстовых файлах. 
//Шаги по реализации данного приложения необходимо сохранять в публичном репозитории одного из открытых ресурсов, 
//поддерживающих систему контроля версий GIT. 
//Шаги должны быть аналогичны описанным в примере ниже. При обработке текстовых файлов считать, что:
//отдельные поля в строке разделяются ровно одним пробелом; вся информация в файле корректна; 
//количество строк в файле не превосходит 100; длина одной строки в файле не превосходит 200 символов.

#include <iostream>

using namespace std;

#include "bank.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"


void output(bank* bank)
{
    cout << bank->name << '\n';
    cout << bank->address << '\n';
    cout << bank->sale << '\n';
    cout << bank->purchase << '\n';
    cout << bank->title << '\n';
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №1. GIT\n";
    cout << "Вариант №4. Курсы валюты\n";
    cout << "Автор: Рыжакова Валентина\n\n";
    cout << "Группа: 23ПИнж1З";
    bank* bank[MAX_FILE_ROWS_COUNT];
    int size = 0;
    try
    {
        read("data.txt", bank, size);
        for (int i = 0; i < size; i++)
        {
            //output(bank[i]);
        }
		bool (*check_function)(bank*) = NULL;
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_bank_sale; //       
			break;
		case 2:
			check_function = check_belarus_bank_prices; //       
			break;
		default:
			throw "  ";
		}
		if (check_function)
		{
			int new_size;
			bank** filtered = filter(bank, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}


        for (int i = 0; i < size; i++)
        {
            delete bank[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}
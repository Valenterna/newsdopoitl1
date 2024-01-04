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

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №1. GIT\n";
    cout << "Вариант №4. Курсы валюты\n";
    cout << "Автор: Рыжакова Валентина\n\n";
    bank* bank[MAX_FILE_ROWS_COUNT];
    int size = 0;
    try
    {
        read("data.txt", bank, size);
        for (int i = 0; i < size; i++)
        {
            cout << bank[i]->name << '\n';
            cout << bank[i]->address << '\n';
            cout << bank[i]->sale << '\n';
            cout << bank[i]->purchase << '\n';
            cout << bank[i]->finish.day << ' ';
            cout << bank[i]->finish.month << ' ';
            cout << bank[i]->finish.year << '\n';
            cout << bank[i]->start.day << ' ';
            cout << bank[i]->start.month << ' ';
            cout << bank[i]->start.year << '\n';
            cout << bank[i]->title << '\n';
            cout << '\n';
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
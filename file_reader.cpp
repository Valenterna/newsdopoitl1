#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>
#include <string>


void read(const char* file_name, bank* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            bank* item = new bank;
            file >> item->name;
            file >> item->purchase;
            file >> item->sale;
            file >> item->address;
            file >> tmp_buffer;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->title, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
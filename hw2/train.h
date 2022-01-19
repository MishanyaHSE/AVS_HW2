#pragma once
#ifndef __train__
#define __train__

//------------------------------------------------------------------------------
// train.h - содержит описание поезда и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

# include "random.h"
#include "transport.h"
#include <stdio.h>
// Поезд
class Train : public Transport {
private:
    int wagons_number;
public:
// Ввод параметров поезда из файла
    void In(FILE *file);

// Случайный ввод параметров поезда
    void InRnd();

// Вывод параметров поезда в файл
    void Out(FILE *file);
};
#endif //__train__

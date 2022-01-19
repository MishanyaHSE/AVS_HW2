#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

#include "random.h"
#include "transport.h"
#include <stdio.h>

// Корабль
class Ship: public Transport {
    // Вывод типа корабля в форматируемый поток
    void printType(FILE *file);

public:
    virtual ~Ship() {}
    // Ввод параметров корабля из файла
    virtual void In(FILE *file);
    // Случайный ввод параметров корабля
    virtual void InRnd();
    // Вывод параметров корабля в форматируемый поток
    virtual void Out(FILE *file);
private:
    int displacement; // водоизмещение
    enum ship_type {
        LINEAR = 1, TUGBOAT, TANKER //типы корабля
    };
    ship_type type;
};

#endif //__ship__

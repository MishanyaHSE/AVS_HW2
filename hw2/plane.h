#ifndef __Plane__
#define __Plane__

//------------------------------------------------------------------------------
// plane.h - содержит описание самолета
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "random.h"
#include "transport.h"
#include <stdio.h>
//------------------------------------------------------------------------------
// Самолет
class Plane: public Transport {
private:
    int range; // расстояние
    int lifting_capacity; // грузоподъемность
public:
    ~Plane() {}
    // Ввод параметров самолета из файла
    void In(FILE *file);
    // Случайный ввод параметров самолета
    void InRnd();
    // Вывод параметров самолета в форматируемый файл
    void Out(FILE *file);
};

#endif //__Plane__

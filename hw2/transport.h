#ifndef __transport__
#define __transport__

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщающего транспорта,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "random.h"

//------------------------------------------------------------------------------
// Класс, обобщающий все типы транспорта
class Transport {
protected:
    static Random rnd;
public:
    int speed; // скорость
    double distance; // дистанция

    virtual ~Transport() {};
    // Ввод обобщенного транспорта
    static Transport *StaticIn(FILE *file);
    // Ввод обобщенного транспорта
    virtual void In(FILE *file) = 0;
    // Случайный ввод обобщенного транспорта
    static Transport *StaticInRnd();
    // Виртуальный метод ввода случайного транспорта
    virtual void InRnd() = 0;
    // Вывод обобщенного транспорта
    virtual void Out(FILE *file) = 0;
    // Вычисление идеального времени прохождения пути
    double GetPerfectTime();
};


#endif

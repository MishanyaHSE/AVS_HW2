//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенного транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include "ship.h"
#include "plane.h"
#include "train.h"

//------------------------------------------------------------------------------
Random Transport::rnd(0, 100000);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного транспорта из файла
Transport *Transport::StaticIn(FILE *file) {
    int transport_type, speed;
    double distance;

    if (fscanf(file, "%d", &transport_type) == EOF) {
        return nullptr;
    }
    fscanf(file, "%d", &speed);
    fscanf(file, "%lf", &distance);
    Transport *entered_transport = nullptr;
    // Определение типа транспорта
    switch (transport_type) {
        case 1:
            entered_transport = new Plane;
            entered_transport->speed = speed;
            entered_transport->distance = distance;
            break;
        case 2:
            entered_transport = new Train;
            entered_transport->speed = speed;
            entered_transport->distance = distance;
            break;
        case 3:
            entered_transport = new Ship;
            entered_transport->speed = speed;
            entered_transport->distance = distance;
            break;
    }
    entered_transport->In(file);
    return entered_transport;

}

// Случайный ввод обобщенного транспорта
Transport *Transport::StaticInRnd() {
    auto transport_type = Random::Rand(3) + 1;
    int speed;
    double distance;
    Transport *generated_transport = nullptr;
    switch (transport_type) {
        case 1:
            generated_transport = new Plane;
            speed = rnd.Rand(1000) + 500;
            distance = (double)(rnd.Rand(100000)) / RAND_MAX * 1000 + 1;
            generated_transport->speed = speed;
            generated_transport->distance = distance;
            break;
        case 2:
            generated_transport = new Train;
            speed = rnd.Rand(300) + 100;
            distance = (double)(rnd.Rand(100000)) / RAND_MAX * 1000 + 1;
            generated_transport->speed = speed;
            generated_transport->distance = distance;
            break;
        case 3:
            generated_transport = new Ship;
            speed = rnd.Rand(200) + 50;
            distance = (double)(rnd.Rand(100000)) / RAND_MAX * 1000 + 1;
            generated_transport->speed = speed;
            generated_transport->distance = distance;
            break;
    }
    generated_transport->InRnd();
    return generated_transport;
}

double Transport::GetPerfectTime() {
    return this->distance / (double)this->speed;
}

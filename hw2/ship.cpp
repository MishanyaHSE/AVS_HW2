//------------------------------------------------------------------------------
// ship.cpp - содержит методы корабля
//------------------------------------------------------------------------------

#include "ship.h"
#include <stdio.h>
//------------------------------------------------------------------------------
// Ввод параметров корабля из файла
void Ship::In(FILE *file) {
    int key;
    fscanf(file, "%d,", &displacement);
    fscanf(file, "%d,", &key);
    switch (key) {
        case 1:
            this->type = Ship::LINEAR;
            break;
        case 2:
            this->type = Ship::TUGBOAT;
            break;
        case 3:
            this->type = Ship::TANKER;
            break;
        default: ;
    }

}

// Случайный ввод корабля
void Ship::InRnd() {
    displacement = Random::Rand(3000) + 500;
    int key = Random::Rand(3) + 1;
    switch (key) {
        case 1:
            this->type = Ship::LINEAR;
            break;
        case 2:
            this->type = Ship::TUGBOAT;
            break;
        case 3:
            this->type = Ship::TANKER;
            break;
        default: ;
    }
}

// Вывод типа корабля в форматируемый поток
void Ship::printType(FILE *file) {
    switch (this->type) {
        case 1:
            fprintf(file, "It's type : LINEAR");
            break;
        case 2:
            fprintf(file, "It's type : TUGBOAT");
            break;
        case 3:
            fprintf(file, "It's type : TANKER");
            break;
        default:;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров корабля в форматируемый поток
void Ship::Out(FILE *file) {
    fprintf(file, "It is a Ship: displacement = %d \n", displacement );
    printType(file);
    fprintf(file, ". Perfect time = %f\n",GetPerfectTime());
}


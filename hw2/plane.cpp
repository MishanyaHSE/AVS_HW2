//------------------------------------------------------------------------------
// plane.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------
#include <math.h>
#include "plane.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Ввод параметров самолета из файла
void Plane::In(FILE *file) {
    fscanf(file,"%d", &range);
    fscanf(file,"%d", &lifting_capacity);
}

// Случайный ввод параметров самолета
void Plane::InRnd() {
    range = Random::Rand(101) + 10;
    lifting_capacity = Random::Rand(101) + 5;
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в файл
void Plane::Out(FILE *file) {
    fprintf(file, "It is a Plane: range = ");
    fprintf(file,"%d, lifting capacity = %d\n", range, lifting_capacity);
    fprintf(file,"Perfect time = %f\n", GetPerfectTime());
}


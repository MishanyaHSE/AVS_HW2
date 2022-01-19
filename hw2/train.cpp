
#include "train.h"
#include "random.h"
//------------------------------------------------------------------------------
// Ввод параметров поезда из файла
void Train::In(FILE *file) {
    fscanf(file, "%d", &wagons_number);
}

// Случайный ввод параметров поезда
void Train::InRnd() {
    wagons_number = Random::Rand(91) + 10;
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в форматируемый поток
void Train::Out(FILE *file) {
    fprintf(file, "It is a Train: wagons number = %d, \n", wagons_number);
    fprintf(file, "Perfect time = %f \n", GetPerfectTime());
}


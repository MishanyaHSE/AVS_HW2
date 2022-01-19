//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <cstdlib> // для функций rand() и srand()
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start");
    printf("\n");
    Container c;


    if(!strcmp(argv[1], "-f")) {
        FILE *file;
        file = fopen(argv[2], "r");
        c.In(file);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect number of figures");
            printf(". Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(nullptr)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *output1;
    output1 = fopen(argv[3],"w");
    fprintf(output1,"Filled container:\n");
    c.Out(output1);

    // Вторая часть задания
    FILE *output2;
    output2 = fopen(argv[4], "w");
    double avg = c.MoveToTheEnd();

    fprintf(output2, "Sorted container:\n");
    c.Out(output2);
    fprintf(output2, "Average perfect time = %f\n", avg);

    printf("Stop\n");
    return 0;
}

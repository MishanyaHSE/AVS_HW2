//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *file) {
    int number_type;
    try {
        while (max_len > len && (storage[len] = Transport::StaticIn(file)) != nullptr) {
            len++;
        }
        // исключение переполнения
        if (max_len <= len && Transport::StaticIn(file) != nullptr) {
            fprintf(file, "Слишком много элементов, оставшиеся элементы не будут считаны");
        }
    } catch (std::exception Ex) { }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        // check EOF (and in StaticInRnd() method) - same for In()
        if ((storage[len] = Transport::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file,"%d: ", i);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Перемещение транспорта с большим идеальным временем, чем среднее для всех транспортов
double Container::MoveToTheEnd() {
    double average = 0.0;
    for(int i = 0; i < this->len; i++) {
        average += storage[i]->GetPerfectTime();
    }
    average = average / (double)this->len;
    Transport* container_for_sort[max_len];
    int index = 0;
    for (int i = 0; i < this->len; i++) {
        if (storage[i]->GetPerfectTime() <= average) {
            container_for_sort[index] = this->storage[i];
            ++index;
        }
    }
    for (int i = 0; i < this->len; i++) {
        if (storage[i]->GetPerfectTime() > average) {
            container_for_sort[index] = this->storage[i];
            ++index;
        }
    }
    for (int i = 0; i < this->len; i++) {
        storage[i] = container_for_sort[i];
    }

    return average;
}



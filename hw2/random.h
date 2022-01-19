#ifndef __Random__
#define __Random__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// Random.h - содержит генератор случайных чисел
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
    }
    // Генерация случайного числа в заданном диапазоне
    static int Rand(int n){
        return rand() % n;
    }

private:
    int first;
    int last;
};

#endif //__Random__

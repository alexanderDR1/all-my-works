#ifndef DOGSVSCATS_CAT_H
#define DOGSVSCATS_CAT_H

#include "Animal.h"

class Cat : Animal {
public:
    ~Cat();
    int getTotalAnimals() const override ;

private:
};


#endif //DOGSVSCATS_CAT_H

//
// Created by Lotus on 17/08/2020.
//

#ifndef DOGSVSCATS_DOG_H
#define DOGSVSCATS_DOG_H

#include "Animal.h"

class Dog : Animal {
public:
    ~Dog();
    int getTotalAnimals() const override;

private:
};


#endif //DOGSVSCATS_DOG_H

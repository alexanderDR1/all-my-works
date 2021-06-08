//
// Created by Lotus on 17/08/2020.
//

#include "Cat.h"
#include <iostream>


Cat::~Cat() {
    std::cout << "Cat " << this->id << " died :(" << std::endl;
    Cat::total--;
}

int Cat::getTotalAnimals() const {
    return Cat::total;
}

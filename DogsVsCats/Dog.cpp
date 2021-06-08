//
// Created by Lotus on 17/08/2020.
//

#include "Dog.h"
#include <iostream>

Dog::~Dog() {
    std::cout << "Dog " << this->id << " died" << std::endl;
    Dog::total--;
}

int Dog::getTotalAnimals() const {
    return Dog::total;
}

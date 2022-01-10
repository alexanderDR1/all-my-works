#include "Cat.h"
#include <iostream>


Cat::~Cat() {
    std::cout << "Cat " << this->id << " died :(" << std::endl;
    Cat::total--;
}

int Cat::getTotalAnimals() const {
    return Cat::total;
}

//
// Created by Lotus on 17/08/2020.
//

#include "Animal.h"

// Animal constructor
Animal::Animal() {
    this->is_full = false;
}

void Animal::feedMe() {
    this->is_full = !this->is_full; // Because if full and eating then throw up
}
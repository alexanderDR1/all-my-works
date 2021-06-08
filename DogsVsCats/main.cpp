#include <iostream>
#include <vector>
#include "Cat.h"
#include "Dog.h"

int main() {
    /* Vector explanation:
    int *arr = new int[10]; // Dynamic memory
    int other[5]; // Cannot delete

    // Expand dynamic array by one
    int *new_arr = new int[11];
    for(int i = 0; i < 10; i++) {
        new_arr[i] = arr[i];
    }
    delete arr; // Delete memory in previous pointer
    arr = new_arr; // Switch pointer to new address
     */
    std::vector<Dog> dogs = {};
    std::vector<Cat> cats = {};
    int cats_to_create;
    int dogs_to_create;

    std::cout << "Cats to create: ";
    std::cin >> cats_to_create;
    std::cout << "Dogs to create: ";
    std::cin >> dogs_to_create;

    for(int i = 0; i < cats_to_create; i++) cats.push_back(Cat());
    for(int i = 0; i < dogs_to_create; i++) dogs.push_back(Dog());

    // Inline IF
    // Syntax: condition ? if_true : else;
    // condition: has a true or false value (boolean)
    // if_true or else: can have any value and will be returned by condition
    int min = cats_to_create > dogs_to_create ? dogs_to_create : cats_to_create;

    for(int i = 0; i < min; i++) {
        dogs.erase(dogs.begin());
        cats.erase(cats.begin());
    }

    return 0;
}

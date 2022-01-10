#ifndef DOGSVSCATS_ANIMAL_H
#define DOGSVSCATS_ANIMAL_H


class Animal {
public:
    Animal();
    void feedMe(); // Mutator
    virtual int getTotalAnimals() const = 0; // Spectator

protected:
    static unsigned int total;
    unsigned int id;
    bool is_full;
};


#endif //DOGSVSCATS_ANIMAL_H

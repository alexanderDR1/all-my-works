#include <iostream>

using namespace std;

typedef struct {
    int* arr;
    int length;
} AwesomeArray;

void addElements(AwesomeArray & arr, int * valuesToAdd, int numberOfValuesToAdd) {
    // Allocate new memory
    int * newarr = new int[arr.length + numberOfValuesToAdd];

    // Copy previous array values to new array
    for(int i = 0; i < arr.length; i++){
        newarr[i] = arr.arr[i];
    }

    // add new elements to new array
    for(int i = 0; i < numberOfValuesToAdd; i++){
        newarr[arr.length + i] = valuesToAdd[i];
    }

    delete arr.arr;
    arr.arr = newarr;
    arr.length += numberOfValuesToAdd;
}

void addElement(AwesomeArray & arr, int valueToAdd) {
    addElements(arr, { valueToAdd }, 1);
}

void deleteElement(AwesomeArray & arr, int indexToDelete) {

}

int main()
{

}

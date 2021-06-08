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
    int newarr[1] = {valueToAdd};
    addElements(arr,  newarr , 1);
}

void deleteElement(AwesomeArray & arr, int indexToDelete) {
    for(int i = indexToDelete; i < arr.length; i++){
        arr.arr[i] = arr.arr[i + 1];
    }
    arr.length--;

}

int Find(AwesomeArray & arr , int FindValue){
    for(int i = 0; i < arr.length; i++) {
        if (arr.arr[i] == FindValue) return i;
    }
    return -1;
}

AwesomeArray findAll(AwesomeArray & arr, int value) {
    AwesomeArray result;
    result.arr = new int[0];
    result.length = 0;

    for(int i = 0; i < arr.length; i++) {
        if (arr.arr[i] == value) addElement(result, i);
    }

    return result;
}

void deleteByValue(AwesomeArray & arr, int valueToDelete) {
    int indexTodelete = Find(arr, valueToDelete);
    while(indexTodelete != -1) {
        deleteElement(arr, indexTodelete);
        indexTodelete = Find(arr, valueToDelete);
    }
}

int main()
{
    AwesomeArray arr;
    cout << "Enter the size of array: ";
    cin >> arr.length;
    arr.arr = new int[arr.length];

    for(int i = 0; i < arr.length; i++){
        cout << "Enter number" << i + 1  << ": ";
        cin >> arr.arr[i];
    }
    cout << "thats all the numbers in the array: " << endl;

    for(int i = 0; i < arr.length; i++){
        cout << arr.arr[i] ;
        if(i == arr.length - 1) {
            cout << "." << endl;
        }
        else cout << ",";

    }

    while(true){
        int command;

        cout << "enter command that you want(0 - add values, 1 - add one value , 2 - delete element, 3 - find index of value , 4 -  print, 5 - Find all, 6 - exit): ";
        cin >> command;

        if (command == 6) break;

        if(command > 6){
            cout << "worng command . try again: " << endl;
            continue;
        }

        if(command == 0) {
                int numberOfValues = 0;
                cout << "Enter number of values to add: ";
                cin >> numberOfValues;
                int valuesToAdd[numberOfValues];

                for(int i = 0; i < numberOfValues; i++) {
                    cout << "Enter number: ";
                    cin >> valuesToAdd[i];
                }

                addElements(arr, valuesToAdd,numberOfValues);
        }
        else if(command == 1) {
                int valueToAdd;
                cout << "Enter value: ";
                cin >> valueToAdd;
                addElement(arr, valueToAdd);
        }
        else if(command == 2) {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                deleteElement(arr, index);
        }
        else if(command == 3){
            int toFind;
            cout << "Enter number to find: ";
            cin >> toFind;
            cout << "Value at " << Find(arr, toFind);
        }
        else if(command == 4){
            for( int i = 0; i < arr.length; i++){
                cout << arr.arr[i] << " ";
            }
            cout << endl;
        }
        else if (command == 5) {
            int tofind;
            cout << "enter number that you want to find: ";
            cin >> tofind;

            AwesomeArray indicies = findAll(arr, tofind);

            if(indicies.length == 0) {
                cout << "Not found";
                continue;
            }

            cout << "Indicies of values: ";
            for(int i = 0; i < indicies.length; i++) {
                cout << indicies.arr[i] << " ";
            }
            cout << endl;
        }
    }
}

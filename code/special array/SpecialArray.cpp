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
     arr.arr[1] = {valueToAdd};
    addElements(arr,  valueToAdd , 1);
}

void deleteElement(AwesomeArray & arr, int indexToDelete) {

    for(int i = indexToDelete; i < arr.length - 1 ; i++){
        int temp = arr.arr[i];
        arr.arr[i] = arr.arr[i +1];
        arr.arr[i +1] = temp;
    }
    arr.length--;

}

void  Find(AwesomeArray & arr , int FindIndex ){
    int n = sizeof(arr.arr)/sizeof(arr.arr[0]);
    int i = 0;
	while (i < n)
	{
		if (arr.arr[i] == FindIndex) {
			break;
		}
		i++;
	}

	if ( i < n) {
		cout << "Element " << FindIndex << " is present at index " << i
			 << " in the given array";
	}
	else {
		cout << "Element is not present in the given array";
	}
}

int main()
{
    int arr_size;
    cout << "enter the size of array: ";
    cin >> arr_size;

    int arr[arr_size];

    for(int i = 0; i < arr_size; i++){
        cout << "enter number" << i + 1  << ": "<< endl;
        cin >> arr[i];
    }
    cout << "that all numbers in array: " << endl;

    for(int i = 0; i < arr_size; i++){
        cout << arr[i] ;
        if(i == arr_size) {
            cout << ".";
        }
        else cout << ",";

    }


    while(true){


    int command;

        cout << "enter command : ";
        cin >> command;
        if (command == 4) break;
        if(command > 4){
            cout << "worng command . try again: " << endl;
        continue;
        }
        cout << "enter command that you want(0 - add values, 1 - add one value , 2 - delete element, 3 - find index of value , 4 -  exit )";

        switch(command){
        case 0:
            addElements(arr , arr[arr_size] ,arr_size);
            break;
        case 1:
            addElement(arr.arr , arr_size);
            break;
        case 2:
            deleteElement(arr, arr_size);
            break;
        case 3:
            Find(arr, arr_size);
            break;




            }
        }
   }

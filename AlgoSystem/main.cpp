#include <iostream>

using namespace std;

typedef struct {
    int* arr;
    int length;
    bool is_sorted = true;
} AwesomeArray;

void BubbleSort(AwesomeArray* arr) {
    for(int i = 0; i < arr->length - 1; i++) {
        for(int j = 0; j < arr->length - i - 1; j++) {
            if(arr->arr[j] > arr->arr[j + 1]) {
                int temp = arr->arr[j];
                arr->arr[j] = arr->arr[j + 1];
                arr->arr[j + 1] = temp;
            }
        }
    }

    arr->is_sorted = true;
}

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
        if(arr.is_sorted && arr.length + i != 0 && newarr[arr.length + i] < newarr[arr.length + i - 1]) arr.is_sorted = false;
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
    if(!arr.is_sorted) {
        std::cout << "Using Linear Search" << std::endl;
        for(int i = 0; i < arr.length; i++) {
            if (arr.arr[i] == FindValue) return i;
        }
        return -1;
    } else {
        std::cout << "Using Binary Search" << std::endl;
        int start = 0;
        int end = arr.length - 1;
        int middle = (start + end) / 2;
        while(arr.arr[middle] != FindValue) {
            if(arr.arr[middle] > FindValue) {
                end = middle;
                middle = (start + end) / 2;
            } else {
                start = middle;
                middle = (start + end) / 2;
            }

            if(start - end == 1) {
                if(arr.arr[end] == FindValue) return end;
                return -1;
            }
        }
        return middle;
    }
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


typedef struct Node
{
    int data;
    Node* next;
};

void push(struct Node ** head, int new_data) {
    struct Node* new_node = new struct Node;

    struct Node *last = *head;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void  sortLinkedList(Node* head)
{
    if (head != 0)
    {
        Node* current = head;
        Node* prev = 0;
        Node* tempNode = 0;
        bool changeFlag = true;
        while(changeFlag)
        {
            prev = 0;
            current = head;
            changeFlag = false;

            while (current->next != 0)
            {
                tempNode = current->next;

                if (current->data > tempNode->data)
                {
                    changeFlag = true;
                    swap(current->data, tempNode->data);
                }
                else
                {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }
}

void printLinkedList(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout << current->data << ", ";
        current = current->next;
    }
}

// remove an element from the linked list
void removeElement(Node* head ,int remValue) {
    Node* prev = head; // empty header
    Node* current = head->next; // the first valid node
    while(current != NULL) {
        if(current->data == remValue) {
            break;
        }
        else {
            prev = current;
            current = current->next; // go to next value
        }
    }
    if(current == NULL) { // if we reached end of list or the list is empty
        cout << "Can't remove value: no match found.\n";
    }else {
        cout << "Deleting: " << current << "\n";
        prev->next = current->next; // unlink the node you remove
        delete current; // delete the node
    }
}

int main()
{
    int choice;
    cout << "enter 1  if you want  use array. enter 2 if you want use linked list" << endl ;
    cin >> choice;
    if (choice == 1){
        AwesomeArray arr;
        cout << "Enter the size of array: ";
        cin >> arr.length;
        arr.arr = new int[arr.length];

        for(int i = 0; i < arr.length; i++){
            cout << "Enter number" << i + 1  << ": ";
            cin >> arr.arr[i];
            if(i != 0 && arr.is_sorted && arr.arr[i] < arr.arr[i - 1]) arr.is_sorted = false;
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

            cout << "enter command that you want(0 - add values, 1 - add one value , 2 - delete element, 3 - find index of value , 4 -  print, 5 - Find all, bubble sort - 6, 7 - exit): ";
            cin >> command;

            if (command == 7) break;

            if(command > 7){
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
                cout << "Value index at " << Find(arr, toFind) << endl;
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
            else if(command == 6){
                BubbleSort(&arr);
            }
        }
    }
    else if(choice == 2){
        Node* head = nullptr;
        int length;
        int value;
        cout << " print number of values that you want: " << endl;
        cin >> length;

        for(int i = 0; i < length ; i++){
            cout << "print values :" << i << endl;
            cin >> value;
            push(&head, value);
        }

        while(true){
            int command;

            cout << "enter command that you want(0 - add value, 1 - remove value , 2 - sort, 3 - exit ): ";
            cin >> command;

            if (command == 4) break;

            if(command > 4){
                cout << "worng command . try again: " << endl;
                continue;
            }

            if(command == 0){
                int numValues;
                cout << "enter number of values that you wont to add:" ;
                cin  >> numValues ;
                cout << endl;
                push(&head, numValues);
            }

            else if(command == 1){
                int removeValue;
                cout << "enter number that you wont delete: ";
                cin >> removeValue;
                removeElement(head,removeValue);
            }

            else if(command == 2){
                sortLinkedList(head);
            }

            else if(command == 3){
                break;
            }

            printLinkedList(head);
            cout << endl;
        }
    }
}


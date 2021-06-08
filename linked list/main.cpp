#include <iostream>
#include "LinkedList.h"


using namespace std;

int main()
{
        int choice;
        count << "enter your choice if you want use linked list put 1 or if you want use array put 2"
        cin >> choice;
        if(choice == 1){

       Node* head = nullptr;
       int length;
       int value;
     cout << " print number of values that you want: " << endl;
     cin >> length;

     for(int i = 0; i < length ; i++){
          cout << "print values :" << i << endl;
          cin >> value;
           head->push(&head, value);
     }

     head->printLinkedList();
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
          head->push(&head, numValues);
        }

          else if(command == 1){
          int removeValue;
          cout << "enter number that you wont delete: ";
          cin >> removeValue;
          head->removeElement(removeValue);
        }
             else if(command == 2){
          head->sortLinkedList();
     }

         else if(command == 3){
          break;
        }
              head->printLinkedList();
               cout << endl;
          }
     }
}





#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class Node
{
     public:


          int data;
          Node* next;

          void push(Node ** head, int new_data);
          void  sortLinkedList();
          void printLinkedList();
          void removeElement(int remValue) ;

     private:
};



#endif // LINKEDLIST_H

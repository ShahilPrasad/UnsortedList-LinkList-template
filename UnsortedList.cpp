


#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    head = nullptr; //null pointer (null must be store in the beginning)
    length = 0; //length
    currPos = nullptr; //current position
}

template<class T>
UnsortedList<T>::~UnsortedList() {
    MakeEmpty();

}


template<class T>
void UnsortedList<T>::MakeEmpty() {

    while(head != nullptr){
        Node* tmp = head;
        head = head-> next;
        delete tmp; //this is everything for deconstructor
    }
    length =0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try{
        Node* tmp = new Node; //trying this code, if it fails it catch
        delete tmp;
    }
    Catch(){
        return true;
    }
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* currNode = head;

    while(currNode->next != nullptr){ //if the list is empty it will return false, else it would do what's in the loop
        if(currNode->value == someItem){
            return true;
        }
        currNode = currNode -> next; //move to next
    }
    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) { //adds new node at the start (not including head)
   if (IsFull())
       return;

    Node* nodeToAdd = new Node; //creates the node
    nodeToAdd -> value = item; //makes the value for the nodes and set the item value (item/address)
    nodeToAdd -> next = head; //points at the next node
    head = nodeToAdd; //makes the head point at this node
    length++; //increments the length
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currNode = head;
    Node* prevNode = nullptr;

    while(currNode->next != nullptr){ //if the list is empty it will return false, else it would do what's in the loop
        if(currNode->value == item){
            prevNode -> next = currNode -> next; //skips the node we want to delete
            delete currNode; //delete the node
            length--;
            return; //it's saying stop running the loop right here
        }
        prevNode = currNode;
        currNode = currNode -> next; //move to next
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;


}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T itemToReturn = currPos -> value;
    currPos = currPos -> next;
    return itemToReturn;
}


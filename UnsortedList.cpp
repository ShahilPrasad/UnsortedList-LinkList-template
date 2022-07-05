//4 steps to create a node
//1 Create Node
//2 Init Node (point at the next node, and give it value store inside)
//3 Set Head (since this is starting from the start, the head will point at it)
//4 book keeping

//Steps to Deleting unsorted List (works in deleting nth and last nodes)
//1 Find Item
//2 prevNode needs to point to currNode-> next; (in other words the previous node is linked to the next node (the node after current node, current node is in the middle right now)
//3 Delete Current Node
//4 Book Keeping
//Regarding Deleting head node
// Steps 1 nd 2 are the same
// 3: does an if statement to check if(head == currNode)
// 4: Deletes current node
// 5: Book Keeping


#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    head = nullptr; //null pointer (null must be store in the beginning)
    length = 0; //length
    currPos = nullptr; //current position, currpos used for iterator
}

template<class T>
UnsortedList<T>::~UnsortedList() {
    MakeEmpty(); //all the work is done in the function

}


template<class T>
void UnsortedList<T>::MakeEmpty() {

    while(head != nullptr){
        Node* tmp = head; //makes a temp pointer
        head = head-> next; //pointing at the next node to be head
        delete tmp; //this is everything for deconstructor, it deletes the node temp is on
    }
    length =0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try{
        Node* tmp = new Node; //try to create a node
        delete tmp;
    }
    catch(...){
        return true; //if it fails it'll come here and we return true
    }
    return length;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* currNode = head; //points the current node at the head
//nullptr is the end of the list, this loop will go until it reaches null
    while(currNode->next != nullptr) { //This loops through the entire list, (in more detail this is saying loop until the next item is null)else it would do what's in the loop
        if(currNode->value == someItem){ //check if the current node contains that items
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

    Node* nodeToAdd = new Node; //creates the node (immediately set up the value and pointer (next 2 lines)
    nodeToAdd -> value = item; //makes the value for the nodes and set the item value (item/address)
    nodeToAdd -> next = head; //new node points at the next node
    head = nodeToAdd; //makes the head point at this node
    length++; //increments the length
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currNode = head;
    Node* prevNode = nullptr;

    while(currNode->next != nullptr){ //if the list is empty it will return false, else it would do what's in the loop
        if(currNode->value == item){  //check if the current node contains that item
            if(head == currNode){//if head head has this item do this
                head = currNode -> next; //if the item is stored in head, the next item in the list will be the new head
            }
            else{//the if statement nested in this already found it, so if it's not in the head it's in the other nodes
                prevNode -> next = currNode -> next; //skips the node we want to delete
            }

            delete currNode; //delete the node
            length--;
            return; //it's saying stop running the loop right here
        }
        prevNode = currNode; //works the same as curnode, helps paint better pic
        currNode = currNode -> next; //move to next (always 1 ahead of prevNode)
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


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:
#include <initializer_list>
using std::initializer_list;
template<typename T>
class LinkedList{

private:
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    LinkedList() :head(nullptr),tail(nullptr),count(0) {

    }

    LinkedList(initializer_list<T> x):head(nullptr),tail(nullptr),count(0){
        for (T item:x){
            push_back(item);
        }
    }

    void push_front(const T& data){
        Node<T> *newNode= new Node<T>(data);
        if (count==0){
            head=newNode;
            tail=newNode;
        }else{
            newNode->next = head;
            head->previous = newNode;
            head=newNode;
        }
        ++count;
    }

    const T& front()const{
        return head->data;
    }

    void push_back(const T& data){
        Node<T> *newNode = new Node<T>(data);
        if(count==0){
            tail= newNode;
            head=newNode;
        }else
        {
            newNode->previous=tail;
            tail->next=newNode;
            tail=newNode;
        }
        ++count;
    }

    const T& back(){
        return tail->data;
    }

    int size(){
        return count;
    }

    NodeIterator<T> begin(){
        if(head== nullptr){
            return nullptr;
        }
        return  NodeIterator<T>(head);
    }

    NodeIterator<T> end(){
        if(tail== nullptr){
            return nullptr;
        }
        return  NodeIterator<T>(tail->next);
    }

    ~LinkedList(){
   Node<T> * tempNode=head;
     while (tempNode!=nullptr){
         Node<T>* aNode = tempNode->next;
         delete tempNode;
         tempNode=aNode;

     }


    }

    void reverse(){

        Node<T> *tempNode;
        Node<T> *oldNextNode;
        Node<T> *oldPrevNode;
        Node<T> *oldHead=head;
        Node<T> *oldTail=tail;

        tempNode = head;
        while (tempNode!=nullptr) {
            oldNextNode = tempNode->next;
            oldPrevNode = tempNode->previous;
            tempNode->previous = oldNextNode;
            tempNode->next = oldPrevNode;
            tempNode = oldNextNode;
        }

        tail = oldHead;
        head = oldTail;

   }

   NodeIterator<T> insert(NodeIterator<T> positionToInsert, T element){
        if(size()==0){
            push_front(element);
            ++count;
            return begin();
        }
       if(positionToInsert.getCurrent()==head){
           push_front(element);
           NodeIterator<T> anIterator = begin();
           ++count;
           return anIterator;
       }
       if(positionToInsert.getCurrent()==tail){
           push_back(element);
           NodeIterator<T> anIterator = end();
           ++count;
           return anIterator;
       }

       Node<T>* aNode = new Node<T>(element);
       Node<T>* previousToChange = positionToInsert.getCurrent()->previous;
       Node<T>* nextToChange = positionToInsert.getCurrent();

       previousToChange->next =aNode;
       nextToChange->previous = aNode;
       aNode->previous = previousToChange;
       aNode->next = nextToChange;
       ++count;
       return NodeIterator<T>(aNode);
    }

    NodeIterator<T> erase(NodeIterator<T> positionToErase){
        Node<T>* nodeToDelete = positionToErase.getCurrent();
        if(positionToErase.getCurrent()==head){
            head = nodeToDelete->next;
            head->previous=nullptr;
            delete nodeToDelete;
            return head;
        }
        if(positionToErase.getCurrent()==tail){
            tail = nodeToDelete->previous;
            tail->next= nullptr;
            delete nodeToDelete;;
            return tail;
        }
        Node<T>* previous = positionToErase.getCurrent()->previous;
        Node<T>* next = positionToErase.getCurrent()->next;

        previous->next=next;
        next->previous=previous;


        delete nodeToDelete;
        --count;
        return next;

    }
};



//do not edit below this line

#endif








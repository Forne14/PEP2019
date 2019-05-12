#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode {
public:
    T data;
    unique_ptr<TreeNode<T>> leftChild;
    unique_ptr<TreeNode<T>> rightChild;
    TreeNode<T> *parent;

    TreeNode(const T &someData) : data(someData), parent(nullptr) {

    }

    void setLeftChild(TreeNode<T> *child) {

            leftChild = (unique_ptr<TreeNode>) child;
            leftChild->parent = this;

    }

    void setRightChild(TreeNode<T> *child) {

            rightChild = (unique_ptr<TreeNode>) child;
            rightChild->parent = this;

    }

    ostream &write(ostream &o) const {

        if (leftChild != nullptr) {

            leftChild->write(o);
        }

        o << " " << data << " ";
        if (rightChild != nullptr) {
            rightChild->write(o);
        }
        return o;

    }

    ostream &preOrderWrite(ostream &o) const {

        o << " " << data << " "<<balanceFactor();

        if (leftChild != nullptr) {

            leftChild->preOrderWrite(o);
        }
        if (rightChild != nullptr) {
            rightChild->preOrderWrite(o);
        }

        return o;

    }

    int balanceFactor() {
        int balance=0;
        balance = rightChild->maxDepth()-leftChild->maxDepth();
       // cout<<data<<": "<<balance<<endl;
        return balance;
    }

    int maxDepth() {

        int rightDepth =0;
        int leftDepth=0;
        if (!this) {
            return 0;
        }

        if (leftChild) {
            leftDepth = leftChild.get()->maxDepth();
        }
        if (rightChild) {
            rightDepth = rightChild.get()->maxDepth();
        }

       if (rightDepth>leftDepth){
           return rightDepth+1;
       }else {
           return leftDepth+1;
       }

    }


};

template<typename T>
class TreeNodeIterator {
public:
    TreeNode<T>* current;

    TreeNodeIterator( TreeNode<T>* inCurrent) : current(inCurrent) {}

    T & operator*() {
        return current->data;
    }

   bool operator==(const TreeNodeIterator<T> &other) {
        return current == other.current;
    }

   bool operator!=(const TreeNodeIterator<T> &other) {
        return current != other.current;
    }

   void const operator++() {


         if(current->rightChild) {
             current = current->rightChild.get();
             while(current->leftChild){
                 current = current->leftChild.get();
             }

         }else{
             T dataVal = current->data;
             current = current->parent;
             if(current){
             while(dataVal>current->data && current->parent){
                 current=current->parent;
             }
             if (current->data < dataVal){
                 current= nullptr;
             }
         }
         }




    }

};


// do not edit below this line

#endif

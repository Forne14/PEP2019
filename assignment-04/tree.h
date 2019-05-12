#ifndef TREE_H
#define TREE_H

#include "treenode.h"
#include <iostream>
using std::cout;
using std::endl;


// TODO your code goes here:
template<typename T>
class BinarySearchTree {
private:
    unique_ptr<TreeNode<T>> root;


public:
    BinarySearchTree() {

    }

    BinarySearchTree(const BinarySearchTree<T> &other) {
        if (root == nullptr) {
            root = unique_ptr<TreeNode<T>>(new TreeNode<T>(other.root.get()->data));
        }
        TreeNode<T> *oldTreeNode = other.root.get();
        TreeNode<T> *currentTreeNode = root.get();
        buildPreOrder(oldTreeNode, currentTreeNode);

    }

    void write(ostream &o) const {

        if (root) {
            root.get()->write(o);
        }

    }


    void buildPreOrder(TreeNode<T> *oldChild, TreeNode<T> *newChild) const {
        if (oldChild->leftChild) {
            newChild->setLeftChild(new TreeNode<T>(oldChild->leftChild->data));
            buildPreOrder(oldChild->leftChild.get(), newChild->leftChild.get());
        }
        if (oldChild->rightChild) {
            newChild->setRightChild(new TreeNode<T>(oldChild->rightChild->data));
            buildPreOrder(oldChild->rightChild.get(), newChild->rightChild.get());
        }


    }
    int maxDepth() {

        return root.get()->maxDepth();


    }
    //Function checking the balance of the tree.


    TreeNode<T> *insert(T someData){
        if (root == nullptr) {
            root = unique_ptr<TreeNode<T>>(new TreeNode<T>(someData));

           // cout<<root->balanceFactor();
            return root.get();
        }
        bool found = 0;
        TreeNode<T> *aPointerToCheck = root.get();
        while (found == 0) {
            if (!(aPointerToCheck->data < someData) && !(someData < aPointerToCheck->data)) {
                return aPointerToCheck;
            }
            if (someData < aPointerToCheck->data) {
                if (aPointerToCheck->leftChild) {
                    aPointerToCheck = aPointerToCheck->leftChild.get();
                } else {
                    aPointerToCheck->setLeftChild(new TreeNode<T>(someData));
                    TreeNode<T>* insertedNodePointer = aPointerToCheck->leftChild.get();
                    leftRotate(insertedNodePointer);
                    return aPointerToCheck->leftChild.get();
                }
            } else if (aPointerToCheck->data < someData) {
                if (aPointerToCheck->rightChild) {
                    aPointerToCheck = aPointerToCheck->rightChild.get();
                } else {
                    aPointerToCheck->setRightChild(new TreeNode<T>(someData));
                    TreeNode<T>* insertedNodePointer = aPointerToCheck->rightChild.get();
                    rightRotate(insertedNodePointer);
                    return aPointerToCheck->rightChild.get();
                }
            }

        }
        return nullptr;
    }

    TreeNode<T> * rightRotate(TreeNode<T>* insertedNodePointer) {
        while(insertedNodePointer->parent){
            if(insertedNodePointer->parent->balanceFactor()==2) {
                    TreeNode<T>*nodeToMove= insertedNodePointer->parent;
                    TreeNode<T>* newSubTreeRoot =  insertedNodePointer;

                    //rea
                    if(!newSubTreeRoot->parent->parent){
                        newSubTreeRoot->parent= nullptr;
                        unique_ptr<TreeNode<T>>newRoot= unique_ptr<TreeNode<T>>(newSubTreeRoot);
                        root.release();
                        root=std::move(newRoot);
                    }else{
                        TreeNode<T>* newSubTreeRootParent =newSubTreeRoot->parent->parent;
                        newSubTreeRoot->parent=newSubTreeRootParent;

                        unique_ptr<TreeNode<T>>newSubTreeRootUP= unique_ptr<TreeNode<T>>(newSubTreeRoot);
                        newSubTreeRootParent->rightChild.release();
                        newSubTreeRootParent->rightChild=std::move(newSubTreeRootUP);

                    }
                    nodeToMove->parent= nullptr;
                    nodeToMove->rightChild.release();
                    nodeToMove->rightChild = nullptr;
                    bool found = 0;
                    TreeNode<T>*tempNodePointer = root.get();
                    while (found == 0) {
                        found=1;
                        if (nodeToMove->data < tempNodePointer->data) {
                            if (tempNodePointer->leftChild) {
                                tempNodePointer = tempNodePointer->leftChild.get();
                                found=0;
                            } else {
                                tempNodePointer->setLeftChild(nodeToMove);
                                tempNodePointer = tempNodePointer->leftChild.get();
                                while(tempNodePointer->parent){
                                    if(tempNodePointer->parent->balanceFactor()==2){
                                        rightRotate(tempNodePointer);
                                    }
                                    else if(tempNodePointer->parent->balanceFactor()==-2){
                                        leftRotate(tempNodePointer);
                                        //return insertedNodePointer;
                                    }
                                    else{
                                        tempNodePointer=tempNodePointer->parent;
                                    }
                                }
                                return insertedNodePointer;
                            }
                        } else {
                            if (tempNodePointer->rightChild) {
                                tempNodePointer = tempNodePointer->rightChild.get();
                                found=0;
                            }else {
                                tempNodePointer->setRightChild(nodeToMove);
                                tempNodePointer = tempNodePointer->rightChild.get();
                                while(tempNodePointer->parent){
                                    if(tempNodePointer->parent->balanceFactor()==2){
                                        rightRotate(tempNodePointer);
                                    }
                                    else if(tempNodePointer->parent->balanceFactor()==-2){
                                        leftRotate(tempNodePointer);
                                    }
                                    else{
                                        tempNodePointer=tempNodePointer->parent;
                                    }
                                }
                                return insertedNodePointer;
                            }
                        }
                           //found=1;
                    }

            }else if (insertedNodePointer->parent->balanceFactor()==-2){
                leftRotate(insertedNodePointer);
            }else {
                insertedNodePointer = insertedNodePointer->parent;
            }
        }
    }

    TreeNode<T> * leftRotate(TreeNode<T>* insertedNodePointer) {
        while(insertedNodePointer->parent){
            if(insertedNodePointer->parent->balanceFactor()==-2) {
                TreeNode<T>*nodeToMove= insertedNodePointer->parent;
                TreeNode<T>* newSubTreeRoot =  insertedNodePointer;

                //rea
                if(!newSubTreeRoot->parent->parent){
                    newSubTreeRoot->parent= nullptr;
                    unique_ptr<TreeNode<T>>newRoot= unique_ptr<TreeNode<T>>(newSubTreeRoot);
                    root.release();
                    root=std::move(newRoot);
                }else{
                    TreeNode<T>* newSubTreeRootParent =newSubTreeRoot->parent->parent;
                    newSubTreeRoot->parent=newSubTreeRootParent;

                    unique_ptr<TreeNode<T>>newSubTreeRootUP= unique_ptr<TreeNode<T>>(newSubTreeRoot);
                    newSubTreeRootParent->leftChild.release();
                    newSubTreeRootParent->leftChild=std::move(newSubTreeRootUP);

                }
                nodeToMove->parent= nullptr;
                nodeToMove->leftChild.release();
                nodeToMove->leftChild = nullptr;
                bool found = 0;
                TreeNode<T>*tempNodePointer = root.get();
                while (found == 0) {
                    found=1;
                    if (nodeToMove->data < tempNodePointer->data) {
                        if (tempNodePointer->leftChild) {
                            tempNodePointer = tempNodePointer->leftChild.get();
                            found=0;
                        } else {
                            tempNodePointer->setLeftChild(nodeToMove);
                            tempNodePointer = tempNodePointer->leftChild.get();
                            while(tempNodePointer->parent){
                                if(tempNodePointer->parent->balanceFactor()==2){
                                    rightRotate(tempNodePointer);
                                }
                                else if(tempNodePointer->parent->balanceFactor()==-2){
                                    leftRotate(tempNodePointer);
                                }
                                else{
                                    tempNodePointer=tempNodePointer->parent;
                                }
                            }
                            return insertedNodePointer;
                        }
                    } else {
                        if (tempNodePointer->rightChild) {
                            tempNodePointer = tempNodePointer->rightChild.get();
                            found=0;
                        }else {
                            tempNodePointer->setRightChild(nodeToMove);
                            tempNodePointer = tempNodePointer->rightChild.get();
                            while(tempNodePointer->parent){
                                if(tempNodePointer->parent->balanceFactor()==2){
                                    rightRotate(tempNodePointer);
                                }
                                else if(tempNodePointer->parent->balanceFactor()==-2){
                                    leftRotate(tempNodePointer);
                                }
                                else{
                                    tempNodePointer=tempNodePointer->parent;
                                }
                            }
                            return insertedNodePointer;
                        }
                    }
                    //found =1;
                }

            }else if (insertedNodePointer->parent->balanceFactor()==2){
                rightRotate(insertedNodePointer);
            }else {
                insertedNodePointer = insertedNodePointer->parent;
            }
        }
    }


  TreeNode<T> *find(T someData) const {
        TreeNode<T> *temp = root.get();
        if (!(temp->data < someData) && !(someData < temp->data)) {
            return temp;
        }

        while (temp != nullptr) {
            if (!(temp->data < someData) && !(someData < temp->data)) {
                return temp;
            } else if (someData < temp->data) {
                temp = temp->leftChild.get();
            } else if (temp->data < someData) {
                temp = temp->rightChild.get();
            }
        }
        return nullptr;
    }


    void operator=(const BinarySearchTree<T> &other) {

        root = unique_ptr<TreeNode<T>>(new TreeNode<T>(other.root.get()->data));
        TreeNode<T> *oldTreeNode = other.root.get();
        TreeNode<T> *currentTreeNode = root.get();
        buildPreOrder(oldTreeNode, currentTreeNode);
    }

    TreeNodeIterator<T> begin() {
        TreeNode<T> *temp = root.get();
        if(!temp){
            return nullptr;
        }
        while (temp->leftChild) {
            temp = temp->leftChild.get();
        }
        return TreeNodeIterator<T>(temp);
    }

   TreeNodeIterator<T> end() {
        return nullptr;
    }

    void getBalanceOfEachNode(){
        TreeNode<T>* y = root.get();
        getBalanceOfEachnode(y);
    }
    void getBalanceOfEachnode(TreeNode<T>* x){
        cout<<x->balanceFactor()<<" ";
        if(x->leftChild){
            getBalanceOfEachnode(x->leftChild.get());
        }
        if(x->rightChild){
            getBalanceOfEachnode(x->rightChild.get());
        }
    }

};




// do not edit below this line

#endif

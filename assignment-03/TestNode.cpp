#include "node.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    
    int retval = 0;
    
    {
        Node<int> * nodeA = new Node<int>(10);
        
        if (nodeA->data == 10) {
            cout << "1) Pass: a node initialised with '10' contains 10 as its data\n";
        } else {
            cout << "1) Fail: a node initialised with '10' should contain 10 as its data but contains " << nodeA->data << "\n";
            ++retval;
        }
        
        delete nodeA;
    }        
    
    {
        Node<int> * nodeA = new Node<int>(10);
        Node<int> * nodeB = new Node<int>(20);
        
        
        nodeA->next = nodeB;
        nodeB->previous = nodeA;
        
        NodeIterator<int> itr(nodeA);
        
        if (*itr == 10) {
            cout << "2) Pass: an iterator pointing to a node containing 10 returns 10 when writing *itr\n";
        } else {
            cout << "2) Fail: an iterator pointing to a node containing 10 returns " << *itr << " when writing *itr, but should be 10\n";
            ++retval;
        }

        
        NodeIterator<int> itrTwo(nodeA);
        
        if (itr == itrTwo) {
            cout << "2) Pass: two iterators pointing to the same node should be equal\n";            
        } else {
            cout << "2) Fail: two iterators pointing to the same node were not equal\n";
        }
        
        ++itr;
        
        if (*itr == 20) {
            cout << "3) Pass: incrementing an iterator causes it to point to the next node\n";
        } else {
            cout << "3) Fail: incrementing an iterator does not cause it to point to the next node\n";
            ++retval;
        }
                
        if (itr != itrTwo) {
            cout << "4) Pass: two iterators pointing to different nodes were not equal\n";            
        } else {
            cout << "4) Fail: two iterators pointing to different nodes were equal\n";
        }
        
        
        delete nodeA;
        delete nodeB;
    }        
    
    
    return retval;
    
}


#include "linkedlist.h"

#include <iostream>
using std::cout;
using std::endl;



#include <vector>
using std::vector;

int main() {

    int retval = 0;
    
    {
        
        LinkedList<int> aList{2,4,6,8};

        vector<int> numbersOut;
        
        for (auto & n : aList) { // uses begin() and end() to loop over aList
            numbersOut.push_back(n);
        }
        
        vector<int> shouldBe{2,4,6,8};
        
        if (numbersOut == shouldBe) {
            cout << "1) Pass: making a list for {2,4,6,8} using an initializer list, then looping over it, gets these values\n";
        } else {
            ++retval;
            cout << "1) Fail: making a list for {2,4,6,8} using an initializer list, then looping over it, gets the values: {";
            for (auto & n : numbersOut) {
                cout << " " << n;
            }
            cout << " }\n";
        }
    }

    {
        
        LinkedList<int> aList{2,4,6,8};

        auto itr = aList.begin();
        ++itr;
        
        itr = aList.erase(itr);
        
        if (*itr == 6) {
            cout << "2) Pass: making a list for {2,4,6,8} using an initializer list, then erasing 4, returns an iterator pointing to 6\n";
        } else {
            ++retval;
            cout << "2) Fail: making a list for {2,4,6,8} using an initializer list, then erasing 4, should return an iterator pointing to 6, but instead it got " << *itr << endl;
        }
    }
    
    {
        
        LinkedList<int> aList{2,4,6,8};

        auto itr = aList.begin();
        ++itr;
        
        itr = aList.insert(itr, 3);
        
        if (*itr == 3) {
            cout << "3) Pass: making a list for {2,4,6,8} using an initializer list, then inserting 3 before 4, returns an iterator pointing to 3\n";
        } else {
            ++retval;
            cout << "3) Fail: making a list for {2,4,6,8} using an initializer list, then inserting 3 before 4, should return an iterator pointing to 3, but instead it got " << *itr << endl;
        }
        
        vector<int> numbersOut;
        
        for (auto & n : aList) { // uses begin() and end() to loop over aList
            numbersOut.push_back(n);
        }
        
        vector<int> shouldBe{2,3,4,6,8};
        
        if (numbersOut == shouldBe) {
            cout << "4) Pass: making a list for {2,4,6,8} using an initializer list, then inserting 3 before 4, gives the list {2,3,4,6,8}\n";
        } else {
            ++retval;
            cout << "4) Fail: making a list for {2,4,6,8} using an initializer list, then inserting 3 before 4, should give the list {2,3,4,6,8} but instead produced the list: {";
            
            for (auto & n : numbersOut) {
                cout << " " << n;
            }
            cout << " }\n";
        }
    }
        
    return retval;
    
        
}


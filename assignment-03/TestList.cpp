#include "linkedlist.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;


int main() {
    int retval = 0;
    
    {

        // these tests need push_front and front
        
        LinkedList<int> aList;
    
        aList.push_front(3);
        aList.push_front(4);
    
        if (aList.front() == 4) {
            cout << "1) Pass: pushing 3 then 4 onto the front of a list gives a list with 4 at the front\n";
        } else {
            ++retval;
            cout << "1) Fail: pushing 3 then 4 onto the front of a list should give a list with 4 at the front, but it actually has " << aList.front() << " at the front\n";
        }             
    }
    
    {
        
        // these tests need push_back, back and size
        
        LinkedList<int> aList;
    
        aList.push_back(3);
        aList.push_back(4);
    
        if (aList.back() == 4) {
            cout << "2) Pass: pushing 3 then 4 onto the back of a list gives a list with 4 at the back\n";
        } else {
            ++retval;
            cout << "2) Fail: pushing 3 then 4 onto the back of a list should give a list with 4 at the back, but it actually has " << aList.back() << " at the back\n";
        }             
        
        if (aList.size() == 2) {
            cout << "3) Pass: pushing two things onto a list makes a list of size 2\n";
        } else {
            ++retval;
            cout << "3) Fail: pushing two things onto a list has made a list of size " << aList.size() << endl;
        }
                
    }
    
    {
        // these tests need push_front and begin
        
        LinkedList<int> aList;
        
        aList.push_front(3);
        aList.push_front(4);
        
        if (*(aList.begin()) == 4) {
            cout << "4) Pass: pushing 3 then 4 onto the front of a list gives a list where begin() points to 4\n";
        } else {
            ++retval;
            cout << "4) Fail: pushing 3 then 4 onto the front of a list should give a list where begin() points to 4, but it actually points to " << *(aList.begin()) << endl;
        }
    }
    
    
    
    {
        // these tests need push_front and begin
        
        LinkedList<int> aList;
        
        aList.push_front(3);
        aList.push_front(4);
    
        auto itr = aList.begin();
        ++itr;
        
        if (*itr == 3) {
            cout << "5) Pass: pushing 3 then 4 onto the front of a list gives a list where ++ on begin() then points to 3\n";
        } else {
            ++retval;
            cout << "5) Fail: pushing 3 then 4 onto the front of a list should give a list where ++ on begin() then points to 3, but it actually points to " << *itr << endl;
        }
    }
    
    {
        // this test needs push_back(), begin() and end()
        
        LinkedList<int> aList;
        
        vector<int> numbersIn{2,4,6,8};
        
        for (auto & n : numbersIn) {
            aList.push_back(n);
        }
        
        vector<int> numbersOut;
        
        for (auto & n : aList) { // uses begin() and end() to loop over aList
            numbersOut.push_back(n);
        }
        
        if (numbersIn == numbersOut) {
            cout << "6) Pass: pushing {2,4,6,8} onto the back of the list, then looping over it, gets these values\n";
        } else {
            ++retval;
            cout << "6) Fail: pushing {2,4,6,8} onto the back of the list, then looping over it, gets the values: {";
            for (auto & n : numbersOut) {
                cout << " " << n;
            }
            cout << " }\n";
        }
    }

    {
        // this test needs push_back(), begin(), end() and reverse()
        
        LinkedList<int> aList;
        
        vector<int> numbersIn{2,4,6,8};
        
        for (auto & n : numbersIn) {
            aList.push_back(n);
        }

        aList.reverse();
        
        vector<int> numbersOut;
        
        for (auto & n : aList) { // uses begin() and end() to loop over aList
            numbersOut.push_back(n);
        }
        
        vector<int> numbersOutShouldBe{8,6,4,2};
        
        
        if (numbersOutShouldBe == numbersOut) {
            cout << "6) Pass: pushing {2,4,6,8} onto the back of the list, reversing it, then looping over it, gets the values {8,6,4,2}\n";
        } else {
            ++retval;
            cout << "6) Fail: pushing {2,4,6,8} onto the back of the list, reversing it, then looping over it, gets the values: {";
            for (auto & n : numbersOut) {
                cout << " " << n;
            }
            cout << " } -- should be { 8 6 4 2 }\n";
        }
    }

    
    
    return retval;
    
}


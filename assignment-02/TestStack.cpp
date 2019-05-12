#include "Stack.h"

#include <algorithm>
#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

int main() {

    int retval = 0;
    
    {        
        list<double> pushThese{3.0, 7.0};
        
        Stack s;
        for (const double d : pushThese) {
            s.push(d);
        }
        
        if (s.empty()) {
            cout << "0) Fail: stack is empty after pushing things onto it\n";
            ++retval;
        } else {
            cout << "0) Pass: stack is not empty after pushing things onto it\n";
        }
        
        list<double> popped;
        
        while (!s.empty()) {
            popped.push_front(s.pop());
        }
        
        if (popped == pushThese) {
            cout << "1) Pass: pushed {3.0, 7.0}, popped {7.0, 3.0}\n";
        } else {
            cout << "1) Fail: pushed {3.0, 7.0}, popped {";
            
            
            for (bool comma = false; !popped.empty(); comma = true) {
                if (comma) {
                    cout << ", ";
                }
                cout << popped.back();
                popped.pop_back();
            }
            cout << "}\n";
            ++retval;
        }
                        
    }
    
    {
        double answer = evaluate("3.0 4.0 +");
        if (answer == 7.0) {
            cout << "2) Pass: evaluated '3.0 4.0 +', got 7.0\n";
        } else {
            cout << "2) Fail: evaluated '3.0 4.0 +' expecting 7.0, but got " << answer << std::endl;
            ++retval;
        }
    }
    
    {
        double answer = evaluate("3.0 4.0 - 4.0 +");
        if (answer == 3.0) {
            cout << "3) Pass: evaluated '3.0 4.0 - 4.0 +', got 3.0\n";
        } else {
            cout << "3) Fail: evaluated '3.0 4.0 - 4.0 +' expecting 3.0, but got " << answer << std::endl;
            ++retval;
        }
    }
    
    {
        double answer = evaluate("3.0 4.0 - 2.0 *");
        if (answer == -2.0) {
            cout << "4) Pass: evaluated '3.0 4.0 - 2.0 *', got -2.0\n";
        } else {
            cout << "4) Fail: evaluated '3.0 4.0 - 2.0 *' expecting -2.0, but got " << answer << std::endl;
            ++retval;
        }
    }
        
    return retval;
}

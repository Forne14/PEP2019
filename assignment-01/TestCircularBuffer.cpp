#include "CircularBuffer.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main() {
    
    int retval = 0;
    
    CircularBuffer buf(10); // circular buffer of size 10
    
    if (buf.count() == 0) {
        cout << "0 - Pass: Buffer correctly has 0 elements in it when created\n";
    } else {
        cout << "0 - Fail: Buffer has non-zero number of elements in it when created\n";
        ++retval;
    }
    
    string hello = "hello";
    
    for (char c : hello) {
        buf.add(c);
    }
    
    if (buf.count() == (int) hello.size()) {
        cout << "1 - Pass: Buffer correctly has 5 elements in it after adding hello\n";
    } else {
        cout << "1 - Fail: Buffer has " << buf.count () << " elements it it after adding hello, should be 5\n";
        ++retval;        
    }
    
    char taken = buf.remove();
    
    if (taken == 'h') {
        cout << "2 - Pass: h was removed from buffer\n";
    } else {
        cout << "2 - Fail: tried to remove first character, should have been 'h', but got '" << taken << "'\n";
        ++retval;
    }
    
    string world = "world";
    
    bool allAdded = true;
    for (char c : world) {
        if (buf.full()) {
            allAdded = false;
        } else {
            buf.add(c);
        }
    }
    
    if (allAdded) {
        cout << "3 - Pass: world was added\n";
    } else {
        cout << "3 - Fail: tried to add world, but the buffer said it was full\n";
        ++retval;
    }
    
    string shouldMatch = "elloworld";
    string itwas;
    
    while (buf.count() > 0 && itwas.size() < 9) {
        itwas.push_back(buf.remove());
    }
    
    if (itwas == shouldMatch) {
        cout << "4 - Pass: elloworld was removed\n";
    } else {
        cout << "4 - Fail: tried to remove elloworld, got " << itwas << endl;
        ++retval;
    } 

    
    
    return retval;
}

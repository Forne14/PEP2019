#include "NearlySorted.h"


#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<vector<int> > inputs{
        {1,4,3,2,5},     // example one from the README
        {1,2,6,5,4,3,7}, // example two from the README
        {1,3,2,4,6,5,7}, // example three from the README
        {1,2,3}          // an already-sorted list
    };
    
    vector<HowToSort> outputs{
        HowToSort(1,3,true),
        HowToSort(2,5,false),
        HowToSort(),
        HowToSort(0,0,true)
    };
    
    for (size_t i = 0; i < inputs.size(); ++i) {        
        cout << "Test case " << i << ": using vector {";
        for (int elem : inputs[i]) {
            cout << " " << elem;
        }
        cout << " }\n";
        
        cout << "Expecting answer        : HowToSort(" << outputs[i].getFirstElement() << ", " << outputs[i].getSecondElement();
        if (outputs[i].isASwap()) {
            cout << ", true)\n";
        } else {
            cout << ", false)\n";
        }
        
        HowToSort how = nearlySorted(inputs[i]);
        
        cout << "Called function, and got: HowToSort(" << how.getFirstElement() << ", " << how.getSecondElement();
        if (how.isASwap()) {
            cout << ", true)\n";
        } else {
            cout << ", false)\n";
        }
        
        if (   how.getFirstElement()  == outputs[i].getFirstElement()
            && how.getSecondElement() == outputs[i].getSecondElement()
            && how.isASwap()          == outputs[i].isASwap()           ) {
         
            cout << " -- passed, function returned correct output\n\n";
        } else {
            cout << " -- failed, function returned incorrect output\n\n";
        }
    }
    
    return 0;
}

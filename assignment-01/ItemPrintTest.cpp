#include "Item.h"

#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;

int main() {
    
    int retval = 0;
    
    
    {
        Item strand(51.5115, -0.1160, "StrandCampus", 600);
        Item londonEye(51.5033, -0.1195, "LondonEye", 700);
        
        ostringstream str;
        str << strand << londonEye;
        
        string s = str.str();
        
        if (s == "{51.5115, -0.116, \"StrandCampus\", 600}{51.5033, -0.1195, \"LondonEye\", 700}") {
            cout << "0: Pass - operator<< gives the correct output\n";
        } else {
            cout << "0: Fail - operator<< gives incorrect output\n";
            ++retval;
        }
    }
    
    return retval;
}

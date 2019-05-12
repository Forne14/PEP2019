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
    
    {
        Item strand(51.5115, -0.1160, "StrandCampus", 600);
        Item londonEye(51.5033, -0.1195, "LondonEye", 700);
        
        double distance = strand.distanceTo(londonEye);
        
        if (distance > 940.0 && distance < 945.0) {
            cout << "1: Pass - distance from the Strand to the London Eye is correct\n";
        } else {
            cout << "1: Fail - distance of " << distance << " returned, should be around 943.7\n";
            ++retval;
        }
        
    }
    
    
    
    return retval;
}

#include "StringConstruction.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

struct Testcase {
    string target;
    int appendCost;
    int cloneCost;
    int bestCost;
    
    string notes;
};

ostream & operator<<(ostream & o, const Testcase & t) {
    o << "Target string: " << t.target << "\n";
    o << "Cost of appending an arbitrary character: " << t.appendCost << "\n";
    o << "Cost of cloning a substring, and appending: " << t.cloneCost << "\n";
    o << "Cheapest way to make the string should be: " << t.bestCost << "\n";
    
    return o;
}

int main() {

    int retval = 0;
    
    vector<Testcase> testcases{
        
        {"aa",1,2,2,"    Append 'a' (cost 1), append 'a' (cost 1)"},
        {"aaaa",2,3,7,"    Append 'a' (cost 2), append 'a' (cost 2), clone 'aa' (cost 3)"},        
        {"xzxpzxzxpq", 10, 11, 71, "    Append 'x' (cost 10), Append 'z' (cost 10), Append 'x' (cost 10), Append 'p' (cost 10), Append 'z' (cost 10),\n    Clone 'xzxp' (cost 11), Append 'q' (cost 10)"}
        
    };
    
    
    for (size_t i = 0; i < testcases.size(); ++i) {        
        
        cout << "Testcase " << i << "\n";
        cout << testcases[i];
        cout << "\nRunning your function\n";
        
        int costWas = stringConstruction(testcases[i].target, testcases[i].appendCost, testcases[i].cloneCost);
        
        if (costWas == testcases[i].bestCost) {
            cout << " -- Test passed, correct cost was returned\n\n\n";
        } else {
            cout << " -- Test failed, incorrect cost of " << costWas << " was returned\n";
            cout << "    To help your debugging, the cheapest way to make the string should be:\n";
            cout << testcases[i].notes << "\n\n\n";
            
            ++retval;
        }
        
        
        
    }

    string bigString = "abcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifpblgmbtmblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifpblgmbtmblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcqaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifpblgmbtmblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjoirmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifpblgmbtmblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifpblgmbtmblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcqaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaip";
    string doubleIt = bigString + bigString;

    cout << "Big target string testcase, using a " << doubleIt.size() << " character test string.  An excellent solution will complete in around a hundredth of a second.\n";
    cout << "(Note -- if the program freezes at this point, Ctrl+C will stop it from running)\n";

    int result = stringConstruction(doubleIt, 1234, 1235);

    if (result == 59249) {
        cout << "-- Correct cost of 59249 returned\n";
    } else {
        cout << "-- Incorrect cost of " << result << " returned, rather than 59249\n";
    }
        
    return retval;
}



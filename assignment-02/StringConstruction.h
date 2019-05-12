#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
using std::string;

#include <iostream>
using std:: cout;
using std:: endl;
#include <vector>
using std :: vector;

#include <math.h>



// TODO: your code goes here:

int stringConstruction(const string& word,const int& apendCost,const int& cloneCost);
int canBeCloned(string substr,string targetWord, int diff);
int testForLongerClone(string growingString, string temp, int position, string target);


int stringConstruction(const string& word,const int& apendCost,const int& cloneCost) {
    double val = (double)cloneCost/(double)apendCost;
    double min = ceil(val);

    string emptyString = "";
    string potentialString = "";
    const int POTENTIAL_CLONE = 0;
    const int CLONED = 1;
    int cost = 0;
    bool isCloned = 0;
    vector<string> substringStorage = {"", ""};
    for (int i = 0; i < word.length(); ++i) {
        string tempString = "";
        bool aSwitch = 1;
        bool canBeClone = 1;
        char x = word.at(i);
        if (emptyString == "") {
            emptyString += x;
            cost = apendCost;
        } else {
            tempString += x;
        }
        if (i != 0) {
            int j = i;
            bool fLoop =1;
            while (aSwitch) {
                while (fLoop) {
                    if ((emptyString.find(tempString) != std::string::npos)
                        && (tempString.length() <= emptyString.length())
                        && (j < word.length())) {
                        ++j;
                        if (j < word.length() && tempString.length() < emptyString.length()) {
                            tempString += word.at(j);
                            canBeClone = 0;
                        }else{
                            fLoop=0;
                        }


                    }
                    if (emptyString.find(tempString) == std::string::npos && j > i) {
                        tempString = tempString.substr(0, tempString.length() - 1);
                        fLoop=0;
                    }else if(j==i && emptyString.find(tempString) == std::string::npos){
                        fLoop=0;
                    }

                }
                    if (j == i || tempString.length() < min) {
                        emptyString += tempString;
                        cost += apendCost;
                        aSwitch = 0;
                    } else {

                        bool isOverlap = 1;
                        bool charactersStillToCheck = 1;
                        int k = i + 1;
                        int nextCharAlong = k;
                        string orgininalTemp = tempString;
                        string bestClonableString = tempString;
                        string potentialClone = tempString;
                        while (charactersStillToCheck) {
                            potentialClone = potentialClone.substr(1, 1);

                            while (isOverlap) {
                                if ((emptyString.find(potentialClone) != std::string::npos)
                                    && (potentialClone.length() <= emptyString.length())
                                    && (nextCharAlong < word.length())) {
                                    ++nextCharAlong;
                                    if (nextCharAlong < word.length()) {
                                        potentialClone += word.at(nextCharAlong);
                                        canBeClone = 0;
                                    } else {
                                        isOverlap = 0;
                                    }
                                }
                                if(emptyString.find(potentialClone) == std::string::npos && nextCharAlong>k){
                                    potentialClone = potentialClone.substr(0,potentialClone.length()-1);
                                    isOverlap=0;
                                }else if(potentialClone ==""){
                                    isOverlap= 0;
                                }

                            }

                            ++k;
                            nextCharAlong = k;
                            if (potentialClone.length() > bestClonableString.length()) {
                                bestClonableString = potentialClone;
                                potentialClone ="";
                            }

                            if(potentialClone =="") {
                                if (bestClonableString.length() > tempString.length()) {
                                    emptyString += word.at(i);
                                    cost += apendCost;
                                    charactersStillToCheck = 0;
                                    aSwitch = 0;
                                } else {
                                    emptyString += bestClonableString;
                                    i += (bestClonableString.length() - 1);
                                    cost += cloneCost;
                                    charactersStillToCheck = 0;
                                    aSwitch = 0;
                                }
                            }
                        }

                    }
                }

            }
        }
    return cost;
    }

// do not write or edit anything below this line

#endif

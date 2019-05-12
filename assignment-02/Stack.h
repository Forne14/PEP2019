#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

#include <iostream>
using std ::cout;
using std ::endl;

#include <string>
using std::string;

#include <sstream>
using std :: istringstream;

// TODO: Your code goes here


class Stack{
private:
    vector <double> myStack;
    int size;
    int top;

public:
    Stack()
    :size(0),top(-1),myStack(1)
    {

    }

    bool empty()const {
        return size==0;
    }

    double pop(){
        if (empty())
        {
            return 0;
        }
        double element = myStack[top];
        --size;
        --top;
        return element;
    }

    void push(const double& element){
        if (size==myStack.size()){
            myStack.resize(myStack.size()*2);
        }
        ++top;
        myStack[top]= element;
        ++size;
    }
};

double evaluate(const string& word);
double evaluate(const string& word){
    istringstream x(word);
    Stack aStack;
    double firstTerm=0;
    double secondTerm =0;
    double result=0;
   while (x){
        string subs;
        x>>subs;

        if (subs == "+" ){
            secondTerm = aStack.pop();
            firstTerm = aStack.pop();
            result = firstTerm + secondTerm;
            aStack.push(result);
        }
        else if( subs =="-"){
            secondTerm = aStack.pop();
            firstTerm = aStack.pop();
            result = firstTerm - secondTerm;
            aStack.push(result);
        }
        else if (subs =="*"){
            secondTerm = aStack.pop();
            firstTerm = aStack.pop();
            result = firstTerm * secondTerm;
            aStack.push(result);
        }
        else if (subs =="/"){
            secondTerm = aStack.pop();
            firstTerm = aStack.pop();
            result = firstTerm / secondTerm;
            aStack.push(result);
        }
        else{
            double aValue= atof(subs.c_str());
            aStack.push(aValue);
        }
    }
    return result;
}

// Do not write anything below this line

#endif

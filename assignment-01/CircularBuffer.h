#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>
using std:: cout;
using std:: endl;

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {
private:
    SimpleVector<char> circBuff;
    int addCounter;
    int removeCounter;
public:
    CircularBuffer(int size)
    :circBuff(size){
        clear();
        addCounter=0;
        removeCounter=0;
    }

    //count the number of elements in buffer
   int count() const{
        int count=0;
        for (int i=0; i<circBuff.size();++i){
            if(circBuff[i]!=0){
                count++;
            }

        }

        return count;
    }

    bool full() const{
        return count()==circBuff.size();
    }

    void add(const char& c){
        if (!full()) {
            circBuff[addCounter] = c;
            addCounter = (addCounter + 1) % (circBuff.size());
        }
        else
        {
            remove();
            add(c);
        }
    }

    char remove(){
        if(count()==0){
            return 0;
        }
        else {
            char x = circBuff[removeCounter];
            circBuff[removeCounter] = 0;
            removeCounter = (removeCounter + 1) % (circBuff.size());
            return x;
        }
    }

    void clear(){
        for(int i=0;i<circBuff.size();++i){
            circBuff[i]=0;
        }
    }

};

// don't write any code below this line

#endif

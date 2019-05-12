#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H


// NB Do not change this given code -- all your work for this part of the assignment should be in CircularBuffer.h

/** @brief A simple vector class
 * 
 * This is a stripped-down version of the vector class.
 * 
 * - You can construct it to have a fixed size
 * - You can call size() to find what that size is
 * - You can access elements using []
 */
template<class T>
class SimpleVector {
private:
    T * elements;
    int numberOfElements;
public:
    SimpleVector(const int sizeIn)
        : elements(new T[sizeIn]), numberOfElements(sizeIn) {
    }
    
    ~SimpleVector() {
        delete [] elements;
    }

    SimpleVector(const SimpleVector & b) = delete;
    SimpleVector(SimpleVector && b) = delete;        
    SimpleVector & operator=(const SimpleVector & b) = delete;
    SimpleVector & operator=(SimpleVector && b) = delete;
    
    int size() const {
        return numberOfElements;
    }
    
    T & operator[](const int i) {
        return elements[i];
    }
    
    const T & operator[](const int i) const {
        return elements[i];
    }
};

#endif

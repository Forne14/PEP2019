#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H


#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;



/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort {
protected:
    
    /** @brief The index of the first element to use */
    int firstElement;
    
    /** @brief The index of the second element to use */
    int secondElement;
    
    /** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
    bool swapThem;
    
public:
    
    /** @brief Default constructor.
     * 
     * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
     * to have an index -1.
     */
    HowToSort() 
      : firstElement(-1),
        secondElement(-1),
        swapThem(false) {
    }
    
    /** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
     * 
     * @param firstElementIn   The first element to use
     * @param secondElementIn  The second element to use
     * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
     */
    HowToSort(const int firstElementIn, const int secondElementIn,
              const bool swapThemIn)
      : firstElement(firstElementIn),
        secondElement(secondElementIn),
        swapThem(swapThemIn) {
    }
    
    /** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
    bool canBeMadeSorted() const {
        return (firstElement != -1);
    }
    
    /** @brief Accessor function -- get the first element to use */
    int getFirstElement() const {
        return firstElement;
    }

    /** @brief Accessor function -- get the second element to use */
    int getSecondElement() const {
        return secondElement;
    }

    /** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
    bool isASwap() const {
        return swapThem;
    }
    
};

// TODO your code goes here:

HowToSort nearlySorted(const vector<int> &x);
bool isSorted(vector<int> x, int& start, int& end);

HowToSort nearlySorted(const vector<int> &x)
{
    int start=-1;
    int tempDescendingCounter=0;
    int descendingCounter=0;
    int end =-1;
    int numOfProcesses=0;
    int j=0;

    for(int i=0; i<x.size()-1;++i){
        ++j;
            if (x[i]>x[j]){
                if(start==-1){
                    start=i;
                }else
                    {
                        end = j;
                    }
                 ++tempDescendingCounter;
            }
            else if  (tempDescendingCounter!=2 && start != -1 ){
                descendingCounter+=tempDescendingCounter;
                tempDescendingCounter=0;
                end=i;
                numOfProcesses++;
            }
    }

    if(start!=-1){
    if (start!=-1 && end!=-1 && isSorted(x,start,end)){
        HowToSort v(start,end,1);
        return v;
    }
    }
    if(tempDescendingCounter>2 || numOfProcesses==1){
        HowToSort v(start,end,0);
        return v;
    }
    else if (numOfProcesses>1 && start !=-1){
        HowToSort v(-1,-1,0);
        return v;
    }else if(start==-1 || end==-1){
        HowToSort v(0,0, 1);
        return v;
    }

}


bool isSorted(vector<int> x, int& start, int& end){
    int j=0;
    int temp = x[start];
    x[start] = x[end];
    x[end] = temp;

    for (int i=0; i<x.size();++i){
        ++j;
        if (x.size()!=j) {
            if (x[i]>x[j]){
                return 0;
            }
        }
    }
    return 1;
}


// Don't write any code below this line

#endif

#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Searchable.h"

#include <memory>
using std::unique_ptr;

#include <deque>
using std::deque;

class BreadthFirstSearch {

protected:

    /** A queue of incomplete solutions: initially, the board we start with */
    deque<unique_ptr<Searchable> > Q;
    
    /** How many nodes (boards) we made successors for, in order to solve the problem */    
    int nodes = 0;
public:

    /** Constructor: move the pointer out of startFrom into the queue, Q */
    BreadthFirstSearch(std::unique_ptr<Searchable> && startFrom) {
        Q.push_back(std::move(startFrom));
    }

    int getNodesExpanded() const {
        return nodes;
    }

    /** Solve the problem.  If a solution found, return a pointer to it.  Otherwise, return nullptr */
    Searchable * solve() {
        
        // If there are still incomplete solutions on the queue
        while (!Q.empty()) {
            
            // If the solution on the front of the queue is a solution 
            if (Q.front()->isSolution()) {
                return Q.front().get(); // return the pointer 
            }
                  
            ++nodes; // we've now looked at one more node, increment our counter
            
            // Steal the pointer to the board at the front of the queue, by moving it into a unique_ptr here
            // After this, the pointer on the front of the queue is `nullptr`...
            unique_ptr<Searchable> current(std::move(Q.front()));
            
            // ...which can then be popped off the front of the queue
            Q.pop_front();
            
            // Get the successors...
            vector<unique_ptr<Searchable>> successors = current->successors();
            
            for (auto & successor : successors) {
                // and push each one onto the back of queue.
                Q.push_back(std::move(successor));
            }
        }
        
        // If we get to here, we never found a solution and returned it higher up
        return nullptr;
    }
};

//Better search with a heuristic

//Open up BreadthFirstSearch.h. It defines a search strategy known as breadth-first search. It has a queue of incomplete solutions (initially, the starting configuration of the board. Then, it repeatedly takes a board off the queue, and if it's not a solution, gets its successors, and puts them on the queue.
//The queue used follows a first in, first out (FIFO) strategy: the next board is always taken off the front of the queue; and new boards are always put on the back of the queue.
//Breadth-first search can be improved by using a heuristic: an estimate of how close a board is to being finished. The Searchable class defines a heuristicValue() function that calculates an estimate of this.
//Add a heuristicValue() function to your Sudoku class, that returns the number of squares on the board whose sets are of size greater than 1. On paper this corresponds to the number of squares we haven't written a number into yet; and the fewer the squares, the closer it looks like that board is to being a solution.
//Complete the BestFirstSearch class provided, so that instead of using a first-in first-out queue (as in breadth-first search) it uses a priority queue, sorted in ascending order of heuristic value. That is, when we get the successors to a board, these are inserted into the queue so that the board with the smallest heuristic value is always at the front.

#endif

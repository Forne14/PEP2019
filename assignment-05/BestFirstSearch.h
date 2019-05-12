#ifndef BEST_FIRST_SEARCH_H
#define BEST_FIRST_SEARCH_H

#include "Searchable.h"

#include <memory>
using std::unique_ptr;

#include <queue>
#include <vector>
using std:: priority_queue;
using std:: vector;

struct Comp{
    bool operator()(const unique_ptr<Searchable> & a, const unique_ptr<Searchable> &b){
        return (a->heuristicValue()>b->heuristicValue());
    }
};

class BestFirstSearch {

protected:

    priority_queue<unique_ptr<Searchable> ,vector<unique_ptr<Searchable>>, Comp> Q;

    /// Make sure you increment this every time you 'expand' a node, by getting it successors and putting them on the queue        
    int nodes = 0;
    
    
public:

    BestFirstSearch(std::unique_ptr<Searchable> && startFrom) {
        // TODO Put startFrom onto the queue:
        Q.push(std::move(startFrom));
    }
    
    int getNodesExpanded() const {
        return nodes;
    }
    
    Searchable * solve() {
            
        // TODO Implement search, returning a pointer to the solution (if one is found)
        while (!Q.empty()) {

            // If the solution on the front of the queue is a solution
            if (Q.top()->isSolution()) {
                return Q.top().get(); // return the pointer
            }

            ++nodes; // we've now looked at one more node, increment our counter

            // Steal the pointer to the board at the front of the queue, by moving it into a unique_ptr here
            // After this, the pointer on the front of the queue is `nullptr`...
            unique_ptr<Searchable> current(std::move(const_cast<std::unique_ptr<Searchable> &>(Q.top())));

            // ...which can then be popped off the front of the queue
            Q.pop();

            // Get the successors...
            vector<unique_ptr<Searchable>> successors = current->successors();

            for (auto & successor : successors) {
                // and push each one onto the back of queue.
                Q.push(std::move(successor));
            }
        }

        // If we get to here, we never found a solution and returned it higher up
        return nullptr;
    }
};


// Do not edit below this line

#endif

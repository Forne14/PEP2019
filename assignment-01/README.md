# Basic building blocks of C++

For this assignment you will code using some of the basic building blocks of C++: vectors, functions, and classes.

Where you are to write functions, ensure you use constness and references where appropriate, to avoid needlessly copying objects, and to help ensure you have written correct code.

Note this coursework has a split deadline: an earlier deadline for "treasure hunt" and "circular buffer"; and a later deadline for "nearly sorted".  See KEATS for details.

# Main [6 marks]

## Treasure hunt [3 marks]

For this part of the coursework, you will write code to work with data about items that are placed at different places on a map, each of which is available at a certain time.

Items are described by four properties:

- Their latitude (a number in degrees, e.g. 51.75087595155126)
- Their longitude (a number in degrees, e.g. -0.33483137537806396)
- A string ID
- The time at which they become available: an integral number of seconds past the hour

In `Item.h`, make a class Item that contains these as private member variables.

Give the class an appropriate constructor that initialises these four variables to the arguments passed to the constructor (passed in the above order).

To compile your code, `BasicItemTest.cpp` provides a main function that makes two `Item` objects.  You can compile this as follows:

`g++ -std=c++11 -o BasicItemTest BasicItemTest.cpp`  

...and if it compiles then run:

`./BasicItemTest`

The code will not produce any output, as it's just constructing objects but doing nothing with them.  Let's work on that.

In `Item.h`, implement an `operator<<` function for printing out Item objects, so that the following code will work:

`Item strand(51.5115, -0.116, "StrandCampus", 600);`  
`cout << strand << endl;`  

...and will produce output of the form:

`{latitude, longitude, "ID", time}`

...in this case:

`{51.5115, -0.116, "StrandCampus", 600}`  

To compile your code, `ItemPrintTest.cpp` provides a main function that makes two `Item` objects, prints them out, and checks the output is correct.  You can compile this as follows:

`g++ -std=c++11 -o ItemPrintTest ItemPrintTest.cpp`  

...and if it compiles then run:

`./ItemPrintTest`

All working well?  One last thing -- let's actually do something interesting with the items.  Create a class function `distanceTo` in Item, that will take another Item, and return the distance to it in metres.  To compute this distance, use the [Haversine Formula](http://andrew.hedges.name/experiments/haversine/), which can be implemented using the following pseudo-code:

`dlon = lon2 - lon1`  
`dlat = lat2 - lat1`  
`a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2)`  
`c = 2 * atan2( sqrt(a), sqrt(1-a) )`  
`distance = R * c (where R is the radius of the Earth)`  

Note that this pseudo-code assumes the latitude and longitude are in *radians*, whereas your class stores them in degrees, so you will need to convert them to radians first.  `cos`, `sin` and the other trignometric functions can be obtained by putting `#include <cmath>` at the top of Item.h.  You should assume `R`, the radius of the earth in metres, is 6373000.

To test your code, you can use ItemDistanceTest.cpp.  To compile to an executable `ItemDistanceTest`, run:

`g++ -std=c++11 -o ItemDistanceTest ItemDistanceTest.cpp`  

Note that this will only work once you have implemented the constructor and functions discussed above.


## Circular buffer [3 marks]

### What is a circular buffer?

Circular buffers use a fixed-size block of memory to temporary buffer data.  For instance, keypresses on the keyboard put characters in the buffer; and when the operating system is ready to process them, it reads characters from the buffer.

The buffer starts as being empty.  For instance, if we had a buffer of size 5 it would look like:

`[   |   |   |   |   ]`  


If we then write 'a' and 'b' into the buffer it would look like:

`[ a | b |   |   |   ]`  


...and then removing the next item in the buffer would give:

`[   | b |   |   |   ]`  


If we continue to write elements into the buffer, e.g. 'c', 'd', 'e', 'f' then when the end is reached, elements start being written into any spare space at the start:

`[ f | b | c | d | e ]`  


At this point the buffer is full.  We can't write any more data to it -- in the case of keyboard buffers, the computer would start beeping.  We can though remove an element, which always removes the *oldest*, i.e. the letter 'b', which would leave the buffer:

`[ f |   | c | d | e ]`  

We could then remove the next element (c), or as there is now a space again, write another character into the buffer.

### Given Code -- SimpleVector

Your implementation in this part of the coursework should be based on a `SimpleVector` of characters. A `SimpleVector` is a simplified version of `vector`, that has reduced functionality that you don't need here.  But, it can still do the operations you'd expect to be able to do with an array in Java: to create a `SimpleVector` of some size; to ask for its size; and to access elements.  For instance:

`SimpleVector<int> someNumbers(10);  // a simple vector of 10 numbers`  
`cout << someNumbers.size() << "\n"; // will print out 10`  
`someNumbers[3] = 42;                // set element 3 to 42`  
`cout << someNumbers[3] << "\n";     // will print out element 3, i.e. 42`  

### Implement a circular buffer

In the file`CircularBuffer.h` complete the definition of the CircularBuffer class.  In `CircularBuffer.h`, the constructor of the class should take the capacity of the buffer as an argument.  It should have a `SimpleVector<char>` as a member variable, to store the characters in the buffer.  There should be no default constructor.

It needs to have the functions:  
1. `count()` which returns how many things are in the buffer  
2. `full()` which returns true *iff* the buffer is full  
3. `add()` which takes a character and adds it to the buffer (you can assume the buffer is not full -- you do not need to implement error handling)  
4. `remove()` which removes and returns the next character from the buffer (you can assume the buffer is not empty -- you do not need to implement error handling)  
 
Once you have provided the constructor and functions, you can test your code using `TestCircularBuffer.cpp`.  To compile this, run:

`g++ -std=c++11 -o TestCircularBuffer TestCircularBuffer.cpp`  

If it compiles, you can then run:

`./TestCircularBuffer`  

As well as being confident your solution behaves correctly, and that you have used const appropriately, ensure you use the initialisation syntax with your constructor to appropriately initialise the vector to be the right size -- `SimpleVector` does not have a default constructor, so this is the only way to give it its size.

Note: do not change the code in `SimpleVector.h` and do not add any extra `#include` statements to `CircularBuffer.h`.

# Advanced [3 marks]

Note this is the advanced part of the assignment.  It has a later deadline than the main part.

## Nearly Sorted [3 marks]

Your next task is to do with vectors of integers that are *nearly* sorted, in ascending order.  For our purposes, the vector is nearly sorted if either:

- There is a pair of elements i and j, such that if these two elements are swapped, the vector becomes sorted; or,
- There is a pair of elements i and j, such that if the range of elements from i and j (inclusive) is reversed, the vector becomes sorted.

For instance, if our vector is:

`vector<int> numbers{1,4,3,2,5};`  

...then it is nearly sorted as swapping the elements with index 1 and 3 gives a sorted vector.  Or, if the vector is:

`vector<int> moreNumbers{1,2,6,5,4,3,7};`  

...then it is nearly sorted as reversing the elements from index 2 to index 5 gives a sorted vector.  The vector:

`vector<int> ohDear{1,3,2,4,6,5,7};`  

...is not nearly sorted, though, as multiple swaps would be needed to make it sorted.

In the file NearlySorted.h, implement a function `nearlySorted` that takes a vector of integers, and returns a `HowToSort` object that describes how to sort the vector.  `HowToSort` is a small class that has been written for you -- you should not change this.  For the examples above, the HowToSort objects that would be returned are:

`return HowToSort(1,3,true); // index 1 and 3, true because it's a swap`  
`return HowToSort(2,5,false); // index 2 and 5, false because it's a range reversal`  
`return HowToSort();  // default constructor: it can't be sorted`  

Assumptions you can make:
* The input vector will not be empty
* The input vector will not have any duplicate numbers.
* If it's possible to use a swap or a reverse, use a swap.
* If the vector is already sorted, return `HowToSort(0,0,true)`

To perform some basic testing on your code, once you have implemented the function (or at least declared it, and given it a return statement) `TestNearlySorted.cpp` defines a simple test harness.  To compile this, run:

`g++ -std=c++11 -o TestNS TestNearlySorted.cpp`  

If it compiles, you can then run:

`./TestNS`  

If you push your code to your GitHub repository, it will be ran against some additional test cases, and you'll be sent the results of these as a GitHub issue.

When your work is marked, a wider range of test cases will be used, including input vectors that contain up to 10,000 numbers -- your code should be able to handle these with modest resources (10 seconds of CPU on a desktop machine, and 0.5GB of RAM).




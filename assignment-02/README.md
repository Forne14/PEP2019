# Further C++ practice

For this assignment you will get more practice working with the basic building blocks of C++: vectors, functions, and classes; and additionally, in the advanced part, pointers.

Where you are to write functions, ensure you use constness and references where appropriate, to avoid needlessly copying objects, and to help ensure you have written correct code.

Note this coursework has a split deadline: an earlier deadline for 'stacks' and 'string construction'; and a later deadline for 'treasure hunt, continued'.

# Main part [6 marks]

## Using stacks [3 marks]

In `Stack.h`, implement a class `Stack` that is a Stack of `double`s.  You should implement this using the `vector` class: Stack.h already contains the necessary `include` and `using` lines for this.

Your `Stack` class needs to provide three functions:

- `empty()` that returns true if the stack is empty
- `pop()` that removes and returns the top element off the stack
- `push()` that takes a double and pushes it onto the stack

Once you have written a Stack class, after it -- but still in `Stack.h` -- implement a function `evaluate` that takes a `string` containing a mathematical expression written in [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation), and returns the result of evaluating the expression, as a `double`.

In reverse polish notation (RPN), operators are written *after* rather than between what they act upon.  For instance:

`3.0 4.0 +`

...is the same as the usual (infix) notation `(3.0 + 4.0)`.  Or:

`3.0 4.0 + 2.0 *`

...is the same as `(3.0 + 4.0) * 2`.  The advantage of RPN is that there is no need to worry about brackets and order of precedence.

To implement the `evaluate` function, use your Stack class.  RPN expressions can be evaluated by splitting the input string by spaces into tokens, and working through it one token at a time:
 
 * If the token is a `+`, pop two numbers a and b off the stack, and push (b + a) onto the stack
 * If the token is a `-`, pop two numbers a and b off the stack, and push (b - a) onto the stack
 * If the token is a `*`, pop two numbers a and b off the stack, and push (b * a) onto the stack
 * If the token is a `/`, pop two numbers a and b off the stack, and push (b / a) onto the stack
 * Otherwise, the token is a number: push it onto the stack
 
 After going through all the tokens, the answer is then on the top of the stack: return it.
 
 To test your code, compile and run `TestStack.cpp`.  This will to evaluate three expressions, and check they give the right answer.  As a reminder, to compile using g++ at the command line, with debugging turned on (`-g`):
 
 `g++ -std=c++11 -g -o TestStack TestStack.cpp`  
 
 ...then run `./TestStack`
 
Notes:

- `std::stod(s)` will convert the string `s` into a double, and return its value

## String construction [3 marks]

This part of the assignment considers a string construction problem defined as follows:

- You are given as input a target string
- Starting with an empty string, you add characters to it, until your new string is same as the target.  You have two options to add characters to a string:
  - You can append an arbitrary character to your new string, with cost x
  - You can clone any substring of your new string so far, and append it to the end of your new string, with cost y
- For a given target, append cost x, and clone cost y, we want to know what the *cheapest cost* is of building the target string

For some simple examples:

- Target "aa", append cost 1, clone cost 2: the cheapest cost is 2:
  - Start with an empty string, ""
  - Append 'a' (cost 1), giving the string "a"
  - Append 'a' (cost 1), giving the string "aa"

- Target "aaaa", append cost 2, clone cost 3: the cheapest cost is 7:
  - Start with an empty string, ""
  - Append 'a' (cost 2), giving the string "a"
  - Append 'a' (cost 2), giving the string "aa"
  - Clone "aa" (cost 3), giving the string "aaaa"

- Target "xzxpzxzxpq", append cost 10, clone cost 11: the cheapest cost is 71:
  - Start with an empty string, ""
  - Append 'x' (cost 10): "x"
  - Append 'z' (cost 10): "xz" 
  - Append 'x' (cost 10): "xzx"
  - Append 'p' (cost 10): "xzxp"
  - Append 'z' (cost 10): "xzxpz"
  - Clone "xzxp" (cost 11): "xzxpzxzxp"
  - Append 'q' (cost 10) : "xzxpzxzxpq"

In the file `StringConstruction.h` write a function `stringConstruction` that takes the target string, the append cost, and the clone cost (in that order), and returns the cheapest way of making the target string.  It doesn't need to return *how* to do it, just the cost.

To test your code, TestStringCons.cpp contains some test cases.  To compile and run at the command line:

`g++ -std=c++11 -o TestSC TestStringCons.cpp`  
`./TestSC`

Note: when your work is marked, it will be tested with target strings of a range of sizes.  To get full marks, it will need to work for the largest of these target strings, which is 30,000 characters.  Your code will be ran on a modest desktop PC, and allowed 2 seconds.


# Advanced - Treasure hunt, continued [3 marks]

This is the advanced part of this assignment -- note it has a later deadline than the earlier parts.

*For this part, first, copy across your Item.h file from assignment 1, over the (basically empty) file provided.  *

## A map of items

In MapOfItems.h, make a class `MapOfItems`. It needs to have:

- a private member variable that stores a vector of `Item`s
- a public function 'addItem' for adding an item to the end of this vector
- a public function 'size()' for returning the size of this vector
- a public function 'getItems' that returns a const reference to the vector of Items


## Taking a tour of the Map

For this part of the assignment, you will implement a greedy algorithm that finds an order in which to visit the Items, allowing for a walking speed between them, and during the times at which they are available (i.e. from a given number of seconds past the hour, until 15 minutes after).

It should be in a class function called `getTour`, implemented within the MapOfItems class.  It should take a walking speed as an argument.  The tour should take no longer than 3600 seconds; that is, the last item you visit, must be visited before 3600.  It should return the tour as a `vector` of `Item*`s -- each of these Item pointers should point to some item in the vector of Items inside the MapOfItems class.

The algorithm specification is as follows:

- The tour must finish before time 3600.
- The tour must start at the Item that is available first, at the time it becomes available.  For instance, if there are five items on the map, available from times 3,10,14,16,18, the item at time 3 would be visited first, at time 3.  (That is, the current time is 3.)
- Then, repeatedly:
  - For each Item *I* that hasn't been visited yet, 
    - Calculate the time that it would take to walk from the previous Item visited, to *I* (using the distance between them, and the walking speed).  This time, plus the current time, is the time that *I* would be visited -- if we went there next.  This time is denoted *visit(I)*.
    - If *visit(I)* is too late (more than fifteen minutes after the item appears), we can't visit that Item
    - If it's too early (before the time at which the item appears), we would need to wait at *I* until it appeared.  This is okay. but we would set *visit(I)* to the time at which *I* appears.
  - The next item to visit is then the one with the smallest *visit(I)*: append a pointer to this Item to the tour, and set the current time to *visit(I)*..
  - Or, if we are too late for all the remaining Items, the tour has finished.  (Yes, it might not be able to visit all the items.)
- The function then returns the tour


To test your implementation, use MapOfItemsTest.cpp.

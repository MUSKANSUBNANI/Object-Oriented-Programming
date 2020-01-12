/*
 * Template class that will be used to hold pointers to things
 * Sorted array list, depends on operator< existing for the type being held
 */

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

// Any necessary includes

// It's a template class
class List {
public:
    // Default Constructor
    // Constructor that takes first item of list
    // Copy Constructor
    // Move Constructor
    // Destructor
    // Copy assignment operator overload
    // Move assignment operator overload
    // function size; does not throw exceptions
    // function capacity; does not throw exceptions
    // function insert; does not throw exceptions
    // function erase; throws underflow_error if empty, range_error if item doesn't exist
    // function at; throws out_of_range exception; returns a const value
    // function at; throws out_of_range exception; returns l-value
    // function search; throws domain error if item doesn't exist
private:
    // variable that gives us our dynamic array
    unsigned int _size;
    unsigned int _capacity;
};


// LIST CLASS FUNCTION IMPLEMENTATIONS



#endif
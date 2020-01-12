#ifndef PFASTRING_HPP
#define PFASTRING_HPP
#include <string>

class PFAString
{
public:
    PFAString();     //Default constructor
    PFAString(unsigned int size, std::string val="");// Constructor that sets capacity and initializes all elements to a specific string
    PFAString(PFAString &&rhs);//Move constructor
    PFAString(const PFAString &rhs);//Copy Constructor
    ~PFAString();//destructor
    unsigned int capacity()const;//capacity function
    unsigned int size()const;//size function
    void push_back(const std::string& value);// function push_back Places a string at the back of the array
    void pop_back();// function pop_back    Sets final active element to null string, behaves as if destroyed
    void resize(unsigned int size,std::string val="");// function resize  Grows or shrinks array accordingly, must behave like vector resize() function (C++98 version)
    void empty_array();// Sets the size to zero
    std::string& operator[]( unsigned int index);//overload operator []  works as l-value
    std::string& operator[](const unsigned int index)  const;       // const overload  []
    PFAString& operator=(const PFAString& other);//copy assignment operator
    PFAString& operator=(PFAString&& other);//move assignment operator
    friend bool operator == (const PFAString& left, const PFAString& right);//== operator overload
    friend bool operator !=(const PFAString& left,const PFAString& right);//!= operator overload
    friend bool operator <(const PFAString& left, const PFAString& right);//< operator overload
    friend bool operator <=(const PFAString& left, const PFAString& right);//<=operator overload
    friend bool operator >(const PFAString& left, const PFAString& right);//>operator overload
    friend bool operator >=(const PFAString& left, const PFAString& right);//>= operator overload
private:
    std::string *arr;
    unsigned int _size;
    unsigned int _capacity;               // Capacity and size are two different things

};

#endif

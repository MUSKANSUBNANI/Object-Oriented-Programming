
#include <string>
#include"PFAString.hpp"

    PFAString::PFAString():_size(0),_capacity(0)//Default constructor
    {
        arr=nullptr;

    }
    PFAString::PFAString(unsigned int size, std::string val)// Constructor that sets capacity and initializes all elements to a specific string
    {
        _size=size;
        _capacity=size;
        arr=new std::string[_size];
        for(unsigned int i=0;i<size;i++)
        {
            *(arr+i)=val;
        }
    }
    PFAString::PFAString(PFAString &&rhs)  //Move Constructor
    {
        _size=rhs._size;

        _capacity=rhs._capacity;
        arr=rhs.arr;
        rhs.arr=nullptr;
        rhs._size=0;

    }
    PFAString::PFAString(const PFAString &rhs)//Copy Constructor
    {
        _size=rhs._size;
        _capacity=rhs._size;
        arr=new std::string[_size];
        for(unsigned int i=0;i<_size;i++)
        {
            *(arr+i)=*(rhs.arr+i);
        }
    }

    PFAString::~PFAString()//destructor
    {
        _size=0;
        _capacity=0;
        delete [] arr;
        arr=nullptr;
    }
    unsigned int PFAString::capacity()const//capacity function
    {
        return _capacity ;
    }
    unsigned int PFAString:: size()const//size function
    {
        return _size;
    }
    void PFAString::push_back(const std::string& value)
    {
        if(_capacity==0)
        {
            _size++;
            _capacity=_size;
            arr=new std::string[_size];
            *arr=value;//<=operator overload
        }
        else if(_size<_capacity)
        {
            _size++;
            *(arr+(_size-1))=value;
        }
        else
        {
            std::string *temp=new std::string[_size*2];
             for(unsigned int i=0;i<_size;i++){
                 temp[i]=*(arr+i);
             }
             temp[_size]=value;
            delete [] arr;
            _capacity=_size*2;
            _size=_size+1;
            arr=temp;
        }
    }
    void PFAString:: pop_back()
    {
        if(_size>0)
        {
         PFAString temp ;
         temp._size=_size-1;
         temp._capacity=_size-1;
         temp.arr=new std::string[temp._size];
         for(unsigned int i=0;i<temp._size;i++)
         {
             *(temp.arr+i)=*(arr+i);
         }
         delete[] arr;
         _size=temp._size;
         _capacity=temp._size;
         arr=new std::string[_size];
         for(unsigned int i=0;i<_size;i++)
         {
             *(arr+i)=*(temp.arr+i);
         }
        }
        else
        {

        }

    }
    void PFAString::resize(unsigned int size,std::string val)
    {
        if(size<=_size)
        {
            _size=size;
        }
        else if((size>_size)&&(size<_capacity))
        {
            _size=size;
                for(unsigned int i=_size;i<size;i++)
                {
                    *(arr+i)=val;
                }
        }
        else
        {
            std::string *temp=new std::string[size];

            for(unsigned int i=0;i<_size;i++)
            {
                temp[i]=*(arr+i);
            }
            for(unsigned int i=_size;i<size;i++)
            {
                temp[i]=val;
            }
            delete[] arr;
            _size=size;
            _capacity=size;
            arr=temp;
        }

    }
    void PFAString::empty_array()
    {
            _size = 0;
    }
    std::string& PFAString::operator[](unsigned int index)
    {
        return *(arr+index);
    }// Needs to work as l-value
    std::string& PFAString::operator[](const unsigned int index)  const
    {
        return *(arr+index);
    }       // const overload (Refer to vector overload on cplusplus.com for both of these)
    PFAString& PFAString::operator=(const PFAString& other)  //copy assignment operator
  {
     if (this != &other)
     {
        // Free the existing resource.
        delete[] arr;
        _size = other._size;
        _capacity=other._size;
        arr=new std::string[_size];
        for(unsigned int i=0;i<_size;i++)
        {
            *(arr+i)=*(other.arr+i);
        }
     }
     return *this;
  }
    //overload operator []
PFAString& PFAString::operator=(PFAString&& other)  //move assignment operator
{
   if (this != &other)
   {
      // Free the existing resource.
     if(arr!=nullptr)
     {
      delete[] arr;
    }  
      _size = other._size;
      _capacity=other._capacity;          // Copy the data pointer and its length from the    // source object.
      arr=other.arr;
      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other.arr = nullptr;
      other._size= 0;
   }
   return *this;
}

bool operator ==(const PFAString& lhs, const PFAString& rhs)
{
    if(lhs._size!=rhs._size)
    {
        return false;
    }
    else
    {   bool flag=true;
        unsigned int i=0;
        while((i<rhs._size) &&flag)
        {
            if(*(lhs.arr+i)!= *(rhs.arr+i))
            {
                flag=false;
            }
            i++;
        }
        return flag;
    }




}
 bool operator !=(const PFAString& lhs,const PFAString& rhs)
{ if(lhs==rhs)
    return false;
    else
    return true;
}
bool operator <(const PFAString& lhs, const PFAString& rhs)
{
if(lhs._size<rhs._size)
{
    return true;
}
else
{   bool flag=true;
    unsigned int i=0;
    while((i<rhs._size) &&flag)
    {
        if(*(lhs.arr+i)>= *(rhs.arr+i))
        {
            flag=false;
        }
        i++;
    }
    return flag;
}
}
bool operator <=(const PFAString& lhs, const PFAString& rhs)
 {  if((lhs<rhs)||(lhs==rhs))
    return true;
    else
    return false;

 }
bool operator >(const PFAString& lhs, const PFAString& rhs)
{
    if(lhs._size>rhs._size)
    {
        return true;
    }
    else
    {   bool flag=true;
        unsigned int i=0;
        while((i<lhs._size) &&flag)
        {
            if(*(lhs.arr+i)<= *(rhs.arr+i))
            {
                flag=false;
            }
            i++;
        }
        return flag;
    }
}
 bool operator >=(const PFAString& lhs, const PFAString& rhs)
 {  if((lhs>rhs)||(lhs==rhs))
        return true;
        else
        return false;
 }

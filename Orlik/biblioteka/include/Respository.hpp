

#ifndef RESPOSITORY_HPP
#define RESPOSITORY_HPP

#include <vector>
#include <string>
#include <sstream>


template <class T>
class Respository {
public:
    virtual bool add(T)=0;
    virtual bool remove(T)=0;
    virtual std::string report()=0;
};


#endif

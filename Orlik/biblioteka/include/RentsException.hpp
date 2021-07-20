

#ifndef RENTSEXCEPTION_HPP
#define RENTSEXCEPTION_HPP

#include <iostream>

class RentsException : public std::logic_error{
public:
    RentsException(std::string s);
};


#endif

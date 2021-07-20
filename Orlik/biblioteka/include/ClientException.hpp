

#ifndef CLIENTEXCEPTION_HPP
#define CLIENTEXCEPTION_HPP

#include <iostream>

class ClientException : public std::logic_error{
public:
    ClientException(std::string s);

};


#endif

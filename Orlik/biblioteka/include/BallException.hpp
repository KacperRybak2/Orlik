

#ifndef BALLEXCEPTION_HPP
#define BALLEXCEPTION_HPP

#include <iostream>

class BallException :  public std::logic_error{
public:
    BallException(std::string s);

};

#endif

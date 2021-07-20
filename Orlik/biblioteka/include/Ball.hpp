

#ifndef BALL_HPP
#define BALL_HPP

#include "BallException.hpp"
#include <memory>
#include <string>
#include <sstream>

class Ball {
protected:
    double airPressure;
    double radius;

public:
    Ball(double airPressure, double radius);
    virtual ~Ball();

    virtual double getAirPressure() const;
    virtual double getRadius() const;

    virtual std::string ballInfo();

};
typedef std::shared_ptr<Ball> ball_ptr;

#endif

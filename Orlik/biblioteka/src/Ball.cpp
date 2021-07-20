

#include "../include/Ball.hpp"

Ball::Ball(double airPressure, double radius) : airPressure(airPressure), radius(radius) {

    if(airPressure<=0){
        throw("air pressure in the ball is less than or equal to 0!");
    }
    else if(radius<=0){
        throw("ball radius is less than or equal to 0!");
    }
}

Ball::~Ball() {

}

double Ball::getAirPressure() const {
    return airPressure;
}

double Ball::getRadius() const {
    return radius;
}



std::string Ball::ballInfo() {

    std::stringstream sout;


    sout<<"Cisnienie pilki: "<<getAirPressure()<<std::endl<<"Promien pilki: "<<getRadius();

    return sout.str();
}

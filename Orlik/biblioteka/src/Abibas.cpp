

#include "../include/Abibas.hpp"

Abibas::Abibas(double airPressure, double radius, std::string logo) : Ball(airPressure, radius), logo(logo) {

    if(airPressure<=0){
        throw("air pressure in the ball is less than or equal to 0!");
    }
    else if(radius<=0){
        throw("ball radius is less than or equal to 0!");
    }
    else if(logo==""){
        throw("logo doesn't exist!");
    }
}

Abibas::~Abibas() {

}

std::string Abibas::getLogo() const {
    return logo;
}

double Abibas::getAirPressure() const {
    return Ball::getAirPressure();
}

double Abibas::getRadius() const {
    return Ball::getRadius();
}

std::string Abibas::ballInfo() {

    std::stringstream sout;


    sout << Ball::ballInfo() << std::endl << "Logo pilki: " << getLogo() << std::endl;

    return sout.str();
}

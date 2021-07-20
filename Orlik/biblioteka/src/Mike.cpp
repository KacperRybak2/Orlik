

#include "../include/Mike.hpp"

Mike::Mike(double airPressure, double radius, const std::string &logoNapis) : Ball(airPressure, radius),
                                                                              logoNapis(logoNapis) {

    if (airPressure <= 0) {
        throw("air pressure in the ball is less than or equal to 0!");
    }
    else if (radius <= 0) {
        throw("ball radius is less than or equal to 0!");
    }
    else if (logo == "") {
        throw("logo doesn't exist!");
    }
}

Mike::~Mike() {

}

const std::string &Mike::getLogoNapis() const {
    return logoNapis;
}

double Mike::getAirPressure() const {
    return Ball::getAirPressure();
}

double Mike::getRadius() const {
    return Ball::getRadius();
}

std::string Mike::ballInfo() {

    std::stringstream sout;

    sout << Ball::ballInfo() << std::endl << "Napis logo: " << getLogoNapis() << std::endl;

    return sout.str();
}

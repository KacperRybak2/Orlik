

#ifndef ABIBAS_HPP
#define ABIBAS_HPP

#include "Ball.hpp"

class Abibas : public Ball {
private:
    std::string logo;

public:
    Abibas(double airPressure, double radius, std::string logo);
    virtual ~Abibas();

    std::string getLogo() const;
    virtual double getAirPressure() const;
    virtual double getRadius() const;

    virtual std::string ballInfo();
};

typedef std::shared_ptr<Abibas> abibas_ptr;


#endif

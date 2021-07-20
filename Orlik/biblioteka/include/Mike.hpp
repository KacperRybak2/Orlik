

#ifndef MIKE_HPP
#define MIKE_HPP


#include "Ball.hpp"

class Mike : public Ball {
private:
    std::string logoNapis;

public:
    Mike(double airPressure, double radius, const std::string &logoNapis);
    virtual ~Mike();

    const std::string &getLogoNapis() const;
    virtual double getAirPressure() const;
    virtual double getRadius() const;

    virtual std::string ballInfo();
};
typedef std::shared_ptr<Mike> mike_ptr;


#endif

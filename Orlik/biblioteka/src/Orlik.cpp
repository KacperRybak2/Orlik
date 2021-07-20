

#include "../include/Orlik.hpp"

Orlik::Orlik(const int &openHour, const int &closeHour) : openHour(openHour), closeHour(closeHour) {}

Orlik::~Orlik() {

}

const int &Orlik::getOpenHour() const {
    return openHour;
}


void Orlik::setOpenHour(int openHour) {
    this->openHour = openHour;
}

const int &Orlik::getCloseHour() const {
    return closeHour;
}


void Orlik::setCloseHour(int closeHour) {
    this->closeHour = closeHour;
}

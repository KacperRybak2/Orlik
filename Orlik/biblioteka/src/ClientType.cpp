

#include "../include/ClientType.hpp"

ClientType::ClientType(int maxRents) : maxRents(maxRents) {}

ClientType::~ClientType() {

}

int ClientType::getMaxRents() const {
    return maxRents;
}

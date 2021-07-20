

#include "../include/RegularClient.hpp"

RegularClient::RegularClient(int maxRents) : ClientType(10) {}

RegularClient::~RegularClient() {

}

int RegularClient::getMaxRents() const {
    return ClientType::getMaxRents();
}

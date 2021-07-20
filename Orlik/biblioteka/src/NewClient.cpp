

#include "../include/NewClient.hpp"

NewClient::NewClient(int maxRents) : ClientType(1) {}

NewClient::~NewClient() {

}

int NewClient::getMaxRents() const {
    return ClientType::getMaxRents();
}



#include "../include/NormalClient.hpp"

NormalClient::NormalClient(int maxRents) : ClientType(5) {}

NormalClient::~NormalClient() {

}

int NormalClient::getMaxRents() const {
    return ClientType::getMaxRents();
}

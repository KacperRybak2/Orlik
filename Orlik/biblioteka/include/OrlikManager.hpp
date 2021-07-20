

#ifndef ORLIKMANAGER_HPP
#define ORLIKMANAGER_HPP

#include "Orlik.hpp"
#include "ClientRespository.hpp"
#include "RentsRespository.hpp"
#include <memory>

class OrlikManager {
private:
    RentsRespository rentRespository;
    ClientRespository clientRespository;
    orlik_ptr orlik;

public:
    OrlikManager(const orlik_ptr &orlik);
    virtual ~OrlikManager();

    bool createRent(rent_ptr rent);
    void removeRent(rent_ptr rent);
    int getAllArchivalClientRents(client_ptr client);
    int getAllCurrentClientRents(client_ptr client);
    void changeOrlikOpenHour(const int &openHour);
    void changeOrlikCloseHour(const int &closeHour);
    std::string informacja();

};
typedef std::shared_ptr<OrlikManager> orlikmanager_ptr;

#endif

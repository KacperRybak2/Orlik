

#include <NewClient.hpp>
#include <NormalClient.hpp>
#include <RegularClient.hpp>
#include "../include/OrlikManager.hpp"



OrlikManager::OrlikManager(const orlik_ptr &orlik) : orlik(orlik) {}

OrlikManager::~OrlikManager() {

}

bool OrlikManager::createRent(rent_ptr rent) {
    if(getAllArchivalClientRents(rent->getClient())>10) {
        rent->getClient()->setClientType(regularclient_ptr (new RegularClient(10)));
    }
    else if(getAllArchivalClientRents(rent->getClient())>5) {
        rent->getClient()->setClientType(normalclient_ptr (new NormalClient(5)));
    }
    else if(getAllArchivalClientRents(rent->getClient())==0) {
        rent->getClient()->setClientType(newclient_ptr (new NewClient(1)));
    }
    if(this->orlik->getOpenHour()>rent->getStartDate() || this->orlik->getCloseHour()<rent->getEndDate()){
        return false;
    }
    if(rent->getClient()->getClientType()->getMaxRents()<=getAllCurrentClientRents(rent->getClient())){
        return false;
    }

    rentRespository.add(rent);

    bool newClient = true;
    for(auto it : clientRespository.getClients()){
        if(it==rent->getClient()){
            newClient = false;
        }
    }

    if(newClient){
        clientRespository.add(rent->getClient());
    }

    return true;
}

void OrlikManager::removeRent(rent_ptr rent){
    rentRespository.remove(rent);
}


int OrlikManager::getAllCurrentClientRents(client_ptr client) {

    int count = 0;

    std::vector<rent_ptr> zbior;

    zbior = rentRespository.getCurrentRents();

    for (auto it : zbior) {
        if (it->getClient() == client) {
            count++;
        }
    }

    return count;
}


int OrlikManager::getAllArchivalClientRents(client_ptr client) {

    int count = 0;

    std::vector<rent_ptr> zbior;

    zbior = rentRespository.getArchivalRents();//

    for(auto it : zbior) {
        if(it->getClient() == client){
            count++;
        }
    }

    return count;
}



void OrlikManager::changeOrlikOpenHour(const int &openHour) {

    orlik->setOpenHour(openHour);
}

void OrlikManager::changeOrlikCloseHour(const int &closeHour) {

    orlik->setCloseHour(closeHour);
}


std::string OrlikManager::informacja() {

    std::stringstream sout;

    sout<<"Klienci: "<<std::endl;

    sout<<this->clientRespository.report()<<std::endl<<std::endl;
    sout<<this->rentRespository.report()<<std::endl;

    return sout.str();
}







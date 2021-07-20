

#include "../include/ClientRespository.hpp"

bool ClientRespository::add(client_ptr client) {

    clients.push_back(client);
    return true;
}


bool ClientRespository::remove(client_ptr client) {

    std::vector<client_ptr> :: iterator it;
    for(it=clients.begin(); it!=clients.end(); it++){
        if(*it==client){
            clients.erase(it);
            return true;
        }
    }

    return false;
}

std::string ClientRespository::report(){

    std::stringstream sout;

    for(auto it : clients){
        sout << it->clientInfo() << std::endl;
    }

   return sout.str();
}

const std::vector<client_ptr> &ClientRespository::getClients() const {
    return clients;
}


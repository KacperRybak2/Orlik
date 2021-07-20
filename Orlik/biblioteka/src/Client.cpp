

#include "../include/Client.hpp"

Client::Client(const std::string &id, const std::string &firstName, const std::string &lastName) : id(id),
                                                                                                   firstName(firstName),
                                                                                                   lastName(lastName) {
    if(id==""){
        throw("id is empty");
    }
    else if(firstName==""){
        throw("first name is empty");
    }
    else if(lastName==""){
        throw("last name is empty");
    }

}

Client::~Client() {

}

const std::string &Client::getId() const {
    return id;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const clientType_ptr &Client::getClientType() const {
    return clientType;
}

void Client::setClientType(clientType_ptr clientType){
    Client::clientType = clientType;
}

const std::vector<rent_ptr> &Client::getRents() const {
    return rents;
}

std::string Client::clientInfo() const {

    std::stringstream sout;

    sout<<"Imie Klienta: "<<getFirstName()<<std::endl<<"Nazwisko Klienta: "<<getLastName()<<std::endl
    <<"Id Klienta: "<<getId()<<std::endl;


    return sout.str();
}

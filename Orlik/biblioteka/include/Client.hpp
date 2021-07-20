

#ifndef CLIENT_HPP
#define CLIENT_HPP


#include <string>
#include <memory>
#include "ClientType.hpp"
#include "Rents.hpp"
#include "ClientException.hpp"
#include <vector>

class Rents;
typedef std::shared_ptr<Rents> rent_ptr;

class Client {
private:
    std::string id;
    std::string firstName;
    std::string lastName;
    clientType_ptr clientType;
    std::vector<rent_ptr> rents;


public:
    Client(const std::string &id, const std::string &firstName, const std::string &lastName);
    virtual ~Client();

    const std::string &getId() const;
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const clientType_ptr &getClientType() const;
    const std::vector<rent_ptr> &getRents() const;
    void setClientType(clientType_ptr clientType);

    std::string clientInfo() const;
};
typedef std::shared_ptr<Client> client_ptr;

#endif

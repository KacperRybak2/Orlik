

#ifndef CLIENTRESPOSITORY_HPP
#define CLIENTRESPOSITORY_HPP


#include "Respository.hpp"
#include "Client.hpp"

class ClientRespository : Respository<client_ptr> {
private:
 std::vector<client_ptr> clients;
public:

    bool add(client_ptr client);
    bool remove(client_ptr client);
    const std::vector<client_ptr> &getClients() const;
    std::string report();
};
typedef std::shared_ptr<ClientRespository> clientrespository_ptr;

#endif

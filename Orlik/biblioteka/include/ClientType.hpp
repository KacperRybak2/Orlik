

#ifndef CLIENTTYPE_HPP
#define CLIENTTYPE_HPP

#include <memory>
class Client;


class ClientType {
protected:
    int maxRents;

public:
    ClientType(int maxRents);
    virtual ~ClientType();

    virtual int getMaxRents() const;

};
typedef std::shared_ptr<ClientType> clientType_ptr;

#endif

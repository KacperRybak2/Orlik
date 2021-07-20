

#ifndef NORMALCLIENT_HPP
#define NORMALCLIENT_HPP

#include "ClientType.hpp"

class NormalClient : public ClientType {
public:
    NormalClient(int maxRents);
    virtual ~NormalClient();

    virtual int getMaxRents() const;

};
typedef std::shared_ptr<NormalClient> normalclient_ptr;


#endif

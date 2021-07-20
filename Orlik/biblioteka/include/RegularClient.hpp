

#ifndef REGULARCLIENT_HPP
#define REGULARCLIENT_HPP

#include "ClientType.hpp"

class RegularClient : public ClientType {
public:
    RegularClient(int maxRents);
    virtual ~RegularClient();

    virtual int getMaxRents() const;
};
typedef std::shared_ptr<RegularClient> regularclient_ptr;

#endif

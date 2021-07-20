

#ifndef NEWCLIENT_HPP
#define NEWCLIENT_HPP

#include "ClientType.hpp"

class NewClient : public ClientType {
public:
    NewClient(int maxRents);
    virtual ~NewClient();

    virtual int getMaxRents() const;

};
typedef std::shared_ptr<NewClient> newclient_ptr;


#endif

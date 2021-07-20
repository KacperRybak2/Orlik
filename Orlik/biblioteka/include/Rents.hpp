

#ifndef RENTS_HPP
#define RENTS_HPP


#include "Ball.hpp"
#include "Orlik.hpp"
#include "Client.hpp"
#include "RentsException.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time/local_time/local_time.hpp>


class Client;


typedef std::shared_ptr<Client> client_ptr;
typedef boost::uuids::uuid uuid;


class Rents {
private:
    int startDate;
    int endDate;
    int rentalTime;
    uuid id;
    client_ptr client;
    ball_ptr ball;

public:
    Rents(const int &startDate, const int &endDate, const client_ptr &client, const ball_ptr &ball);
    virtual ~Rents();

    const int &getStartDate() const;
    const int &getEndDate() const;
    const int &getRentalTime() const;
    const uuid &getId() const;
    const client_ptr &getClient() const;
    const ball_ptr &getBall() const;

    std::string rentInfo() const;
};
typedef std::shared_ptr<Rents> rent_ptr;

#endif

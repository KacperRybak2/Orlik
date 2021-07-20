

#include "../include/Rents.hpp"

Rents::Rents(const int &startDate, const int &endDate, const client_ptr &client, const ball_ptr &ball)
        : startDate(startDate), endDate(endDate), client(client), ball(ball) {

if(startDate>endDate){
    throw("start Date is after the end Date");
}
else if(client==nullptr){
    throw("Client doesn't exist");
}
else if(ball==nullptr){
    throw("Ball doesn't exist");
}

    id = boost::uuids::random_generator()();
    rentalTime=endDate-startDate;
}

Rents::~Rents() {

}

const int &Rents::getStartDate() const {
    return startDate;
}

const int &Rents::getEndDate() const {
    return endDate;
}

const int &Rents::getRentalTime() const {
    return rentalTime;
}

const uuid &Rents::getId() const {
    return id;
}

const client_ptr &Rents::getClient() const {
    return client;
}

const ball_ptr &Rents::getBall() const {
    return ball;
}

std::string Rents::rentInfo() const {

    std::stringstream sout;


    sout << "Id klienta: " << client->getId() << std::endl << "Godzina rozpoczecia rezerwacji: " << getStartDate() << std::endl << "Godzina zakonczenia rezerwacji: " << getEndDate() << std::endl
         << "Id wypozyczenia: " << getId() << std::endl << "Informacje o pilce: " << ball->ballInfo() << std::endl;

    return sout.str();

}

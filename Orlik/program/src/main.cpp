

#include <iostream>
#include "Rents.hpp"
#include "Client.hpp"
#include "OrlikManager.hpp"
#include "Orlik.hpp"
#include "Ball.hpp"
#include "Abibas.hpp"




int main(){
    orlik_ptr orlik(new Orlik(6,22));
    orlikmanager_ptr manager(new OrlikManager(orlik));

    client_ptr client1(new Client("1","ja","aj"));


    client_ptr client2(new Client("2","ja2","aj2"));


    ball_ptr ball1(new Abibas(2,36,"x"));


    rent_ptr rent1(new Rents(7,10,client1,ball1));


    rent_ptr rent2(new Rents(6,10,client2,ball1));


    manager->createRent(rent1);
    manager->createRent(rent2);
    manager->removeRent(rent2);
    std::cout<<std::endl<<manager->informacja();

    return 0;
};

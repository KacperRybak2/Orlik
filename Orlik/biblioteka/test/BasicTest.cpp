#include <boost/test/unit_test.hpp>

#include "Client.hpp"
#include "Rents.hpp"
#include "ClientType.hpp"
#include "Ball.hpp"
#include "Abibas.hpp"
#include "Mike.hpp"
#include "RegularClient.hpp"
#include "NewClient.hpp"
#include "NormalClient.hpp"
#include "Respository.hpp"
#include "ClientRespository.hpp"
#include "RentsRespository.hpp"
#include <memory>
#include <OrlikManager.hpp>

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)



BOOST_AUTO_TEST_CASE(ClientTest){

      client_ptr Adam(new Client("5555","Adam", "Nowak"));

      BOOST_CHECK_EQUAL(Adam->getId(), "5555");
      BOOST_CHECK_EQUAL(Adam->getFirstName(), "Adam");
      BOOST_CHECK_EQUAL(Adam->getLastName(), "Nowak");
      BOOST_CHECK_EQUAL(Adam->getClientType(), nullptr);

      clientType_ptr normaltype(new NormalClient(5));
      Adam->setClientType(normaltype);
      BOOST_CHECK_EQUAL(Adam->getClientType(), normaltype);
    }


    BOOST_AUTO_TEST_CASE(BallTest){

        abibas_ptr Jabulani(new Abibas(50,20,'A'));


        BOOST_CHECK_EQUAL(Jabulani->getAirPressure(), 50);
        BOOST_CHECK_EQUAL(Jabulani->getRadius(), 20);
        BOOST_CHECK_EQUAL(Jabulani->getLogo(), "A");

        mike_ptr mike(new Mike(2,40,"logo"));
        BOOST_CHECK_EQUAL(mike->getLogoNapis(), "logo");

    }



    BOOST_AUTO_TEST_CASE(RentsTest) {
        client_ptr Adam(new Client("5555","Adam", "Nowak"));
        abibas_ptr Jabulani(new Abibas(50,20,"A"));
        rent_ptr rent(new Rents(10,12,Adam,Jabulani));

        BOOST_CHECK_EQUAL(rent->getStartDate(),10);
        BOOST_CHECK_EQUAL(rent->getEndDate(),12);
        BOOST_CHECK_EQUAL(rent->getRentalTime(),2);
        BOOST_CHECK_EQUAL(rent->getClient(),Adam);
        BOOST_CHECK_EQUAL(rent->getBall(),Jabulani);
    }

    BOOST_AUTO_TEST_CASE(CreatingRentTest){
        orlik_ptr orlik(new Orlik(6,22));
        orlikmanager_ptr manager(new OrlikManager(orlik));
        client_ptr Adam(new Client("5555","Adam", "Nowak"));
        abibas_ptr Jabulani(new Abibas(50,20,"A"));
        rent_ptr rent(new Rents(10,12,Adam,Jabulani));
        rent_ptr rent2(new Rents(5,12,Adam,Jabulani));

        BOOST_CHECK_EQUAL(manager->createRent(rent),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent2),false);

    }
    BOOST_AUTO_TEST_CASE(OrlikTest){
        orlik_ptr orlik(new Orlik(6,22));

        BOOST_CHECK_EQUAL(orlik->getOpenHour(),6);
        BOOST_CHECK_EQUAL(orlik->getCloseHour(),22);
        orlik->setOpenHour(2);
        BOOST_CHECK_EQUAL(orlik->getOpenHour(),2);
        orlik->setCloseHour(23);
        BOOST_CHECK_EQUAL(orlik->getCloseHour(),23);

}
    BOOST_AUTO_TEST_CASE(OrlikManagerTest){
        orlik_ptr orlik(new Orlik(6,22));
        orlikmanager_ptr manager(new OrlikManager(orlik));
        client_ptr Adam(new Client("5555","Adam", "Nowak"));
        abibas_ptr Jabulani(new Abibas(50,20,"A"));
        rent_ptr rent(new Rents(10,12,Adam,Jabulani));

        BOOST_CHECK_EQUAL(manager->createRent(rent),true);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(Adam),0);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(Adam),1);
        manager->removeRent(rent);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(Adam),1);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(Adam),0);
}


BOOST_AUTO_TEST_SUITE_END()

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

BOOST_AUTO_TEST_SUITE(SymulationTestSuite)


BOOST_AUTO_TEST_CASE(SymulationTest){
        orlik_ptr orlik(new Orlik(6,22));
        orlikmanager_ptr manager(new OrlikManager(orlik));
        client_ptr client1(new Client("1","ja","aj"));
        client_ptr client2(new Client("2","ja2","aj2"));
        ball_ptr ball1(new Abibas(2,36,"x"));
        rent_ptr rent1(new Rents(7,10,client1,ball1));
        rent_ptr rent2(new Rents(6,10,client2,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent1),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent2),true);
        manager->removeRent(rent2);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),0);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),1);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client2),1);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client2),0);
        rent_ptr rent3(new Rents(4,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent3),false);
        rent_ptr rent4(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent4),false);
        manager->removeRent(rent1);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),1);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent5(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent5),true);
        manager->removeRent(rent5);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),2);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent6(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent6),true);
        manager->removeRent(rent6);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),3);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent7(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent7),true);
        manager->removeRent(rent7);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),4);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent8(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent8),true);
        manager->removeRent(rent8);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),5);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent9(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent9),true);
        manager->removeRent(rent9);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),6);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);
        rent_ptr rent10(new Rents(8,10,client1,ball1));
        rent_ptr rent11(new Rents(8,10,client1,ball1));
        rent_ptr rent12(new Rents(8,10,client1,ball1));
        rent_ptr rent13(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent10),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent11),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent12),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent13),true);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),6);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),4);
        rent_ptr rent14(new Rents(8,10,client1,ball1));
        rent_ptr rent15(new Rents(8,10,client1,ball1));
        BOOST_CHECK_EQUAL(manager->createRent(rent14),true);
        BOOST_CHECK_EQUAL(manager->createRent(rent15),false);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),6);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),5);
        manager->removeRent(rent10);
        manager->removeRent(rent11);
        manager->removeRent(rent12);
        manager->removeRent(rent13);
        manager->removeRent(rent14);
        BOOST_CHECK_EQUAL(manager->getAllArchivalClientRents(client1),11);
        BOOST_CHECK_EQUAL(manager->getAllCurrentClientRents(client1),0);

}


BOOST_AUTO_TEST_SUITE_END()

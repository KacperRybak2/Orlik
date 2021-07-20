

#include "../include/RentsRespository.hpp"
bool RentsRespository::add(rent_ptr rent) {
    currentRents.push_back(rent);
    return true;
}



bool RentsRespository::remove(rent_ptr rent) {

    for(int i=0;i<currentRents.size();i++){
        if(rent==currentRents[i]){
            archivalRents.push_back(rent);
            currentRents.erase(currentRents.begin()+i);
            return true;
        }
    }

    return false;
}


const std::vector<rent_ptr> &RentsRespository::getCurrentRents() const {
    return currentRents;
}

const std::vector<rent_ptr> &RentsRespository::getArchivalRents() const {
    return archivalRents;
}



std::string RentsRespository::report(){

    std::stringstream sout;


    sout<<"Aktualne wypozyczenia: "<<std::endl;
    for(int i=0; i<currentRents.size(); i++){
        sout << "wypozyczenie: " << currentRents[i]->rentInfo() << std::endl;
    }



    sout<<"Archiwalne wypozyczenia: "<<std::endl;
    for(int i=0; i<archivalRents.size(); i++){
        sout << "wypozyczenie: " << archivalRents[i]->rentInfo() << std::endl;
    }

    return sout.str();
}






#ifndef RENTSRESPOSITORY_HPP
#define RENTSRESPOSITORY_HPP


#include "Respository.hpp"
#include "Rents.hpp"

class RentsRespository : Respository<rent_ptr> {
private:
    std::vector<rent_ptr> currentRents;
    std::vector<rent_ptr> archivalRents;

public:

    bool add(rent_ptr rent);
    bool remove(rent_ptr rent);
    std::string report();

    const std::vector<rent_ptr> &getCurrentRents() const;
    const std::vector<rent_ptr> &getArchivalRents() const;

};
typedef std::shared_ptr<RentsRespository> rentrespository_ptr;


#endif

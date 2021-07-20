

#ifndef ORLIK_HPP
#define ORLIK_HPP
#include <memory>

class Orlik {
private:
    int openHour;
    int closeHour;

public:
    Orlik(const int &openHour, const int &closeHour);
    virtual ~Orlik();

    const int &getOpenHour() const;
    void setOpenHour(int openHour);
    const int &getCloseHour() const;
    void setCloseHour(int closeHour);
};
typedef std::shared_ptr<Orlik> orlik_ptr;


#endif

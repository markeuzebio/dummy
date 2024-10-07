#ifndef HOTEL_H
#define HOTEL_H


#include "src/guest.h"

class Hotel{
public:
    static Hotel* createHotel();
    virtual Guest* createGuest(std::string name, std::string cpf, std::string email, std::string phone)=0;
    virtual ~Hotel(){};
};

#endif // HOTEL_H

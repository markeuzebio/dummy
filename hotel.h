#ifndef HOTEL_H
#define HOTEL_H


#include "src/guest.h"

class Hotel{
public:
    static Hotel* createHotel();
    virtual Guest* createGuest(std::string name, unsigned long int cpf, std::string email, unsigned long int phone)=0;
    virtual ~Hotel(){};
};

#endif // HOTEL_H

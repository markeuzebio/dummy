#ifndef HOTELIMPL_H
#define HOTELIMPL_H

#include "hotel.h"
#include "src/guestimpl.h"
#include <string>
class HotelImpl: public Hotel{
private:
    static HotelImpl *_instance;
public:
    HotelImpl(){};
    virtual ~HotelImpl(){};
    static Hotel* instance();
    Guest* createGuest(std::string name, unsigned long int cpf, std::string email, unsigned long int phone);
};

#endif // HOTELIMPL_H

#ifndef HOTELIMPL_H
#define HOTELIMPL_H

#include "hotel.h"
#include "guestimpl.h"
#include <string>
class HotelImpl: public Hotel{
private:
    HotelImpl();
    static HotelImpl *_instance;
public:
    virtual ~HotelImpl(){};
    static Hotel* instance();
    Guest* createGuest(std::string name, unsigned long int cpf, std::string email, unsigned long int phone);
};

#endif // HOTELIMPL_H

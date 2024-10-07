#ifndef HOTELIMPL_H
#define HOTELIMPL_H

#include "hotel.h"
#include "src/guestimpl.h"
#include <string>
class HotelImpl: public Hotel{
private:
    std::string name;
    std::string cpf;
    std::string email;
    std::string phone;
    static HotelImpl *_instance;
public:
    HotelImpl(){};
    virtual ~HotelImpl(){};
    static Hotel* instance();
    Guest* createGuest(std::string name, std::string cpf, std::string email, std::string phone);
};

#endif // HOTELIMPL_H

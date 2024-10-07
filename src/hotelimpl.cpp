#include "hotelimpl.h"

Hotel* HotelImpl::instance(){
    if(_instance == 0){
        _instance = new HotelImpl();
    }
    return _instance;
}

Guest* HotelImpl::createGuest(std::string name, unsigned long cpf, std::string email, unsigned long phone){
    Guest *g = new GuestImpl(name,cpf,email,phone);
    return g;
}

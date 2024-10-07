#include "hotelImpl.h"

Hotel* HotelImpl::instance(){
    if(_instance == 0){
        _instance = new HotelImpl();
    }
    return _instance;
}

Guest* HotelImpl::createGuest(std::string name, std::string cpf, std::string email, std::string phone){
    Guest *g = new GuestImpl(name,cpf,email,phone);
    return g;
}

#include "hotel.h"
#include "hotelimpl.h"
HotelImpl* HotelImpl::_instance = nullptr;
Hotel* Hotel::createHotel(){
    return HotelImpl::instance();
}

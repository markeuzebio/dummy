#include "hotel.h"
#include "hotelImpl.h"
HotelImpl* HotelImpl::_instance = nullptr;
Hotel* Hotel::createHotel(){
    return HotelImpl::instance();
}

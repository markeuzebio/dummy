#include "GuestImpl.h"
GuestImpl::GuestImpl()
{

}
GuestImpl::GuestImpl(std::string name, unsigned long int cpf, std::string email, unsigned long int phone){
    this->name = name;
    this->cpf = cpf;
    this->email = email;
    this->phone = phone;
}
unsigned long int GuestImpl::getCpf()  {return cpf;}
std::string GuestImpl::getEmail()  {return email;}
std::string GuestImpl::getName()  {return name;}
unsigned long int GuestImpl::getPhone() {return phone;}

void GuestImpl::setCpf(unsigned long int cpf){
    this->cpf = cpf;
}

void GuestImpl::setEmail(std::string email){
    this->email = email;
}

void GuestImpl::setName(std::string name){
    this->name=name;
}

void GuestImpl::setPhone(unsigned long int phone){
    this->phone=phone;
}
GuestImpl& GuestImpl::operator =(const GuestImpl &guest){
    if(this == &guest) return *this;
    name = guest.name;
    email = guest.email;
    cpf = guest.cpf;
    phone = guest.phone;
    return *this;

}
GuestImpl::GuestImpl(const GuestImpl& guest){
    name = guest.name;
    email = guest.email;
    cpf = guest.cpf;
    phone = guest.phone;
}


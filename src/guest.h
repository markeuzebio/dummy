#ifndef GUEST_H
#define GUEST_H
#include <string>

class Guest{
public:
    virtual void setName(std::string)=0;
    virtual void setCpf(unsigned long int)=0;
    virtual void setPhone(unsigned long int)=0;
    virtual void setEmail(std::string)=0;

    virtual std::string getName()=0;
    virtual std::string getEmail()=0;
    virtual unsigned long int getCpf()=0;
    virtual unsigned long int getPhone()=0;

    ~Guest(){};
};

#endif // GUEST_H

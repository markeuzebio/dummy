#ifndef GUEST_H
#define GUEST_H
#include <string>

class Guest{
public:
    virtual void setName(std::string)=0;
    virtual void setCpf(std::string)=0;
    virtual void setPhone(std::string)=0;
    virtual void setEmail(std::string)=0;

    virtual std::string getName()=0;
    virtual std::string getEmail()=0;
    virtual std::string getCpf()=0;
    virtual std::string getPhone()=0;

    ~Guest(){};
};

#endif // GUEST_H

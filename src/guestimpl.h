#ifndef GUESTIMPL_H
#define GUESTIMPL_H
#include <string>
#include "guest.h"
class GuestImpl : public Guest
{
private:
    /**
     * @brief guest's name
     */
    std::string name;
    /**
     * @brief guest's cpf
     */
    unsigned long int cpf;
    /**
     * @brief guest's email
     */
    std::string email;
    /**
     * @brief guest's phone
     */
    unsigned long int phone;

public:
    /**
     * @brief GuestImpl base constructor
     */
    GuestImpl();

    virtual ~GuestImpl(){};
    /**
     * @brief GuestImpl with all parameters constructor
     * @param name
     * @param cpf
     * @param email
     * @param phone
     */
    GuestImpl(std::string name,unsigned long int cpf,std::string email,unsigned long int phone);

    /**
     * @brief set a Name for the guest
     * @param name
     */
    void setName(std::string name);

    /**
     * @brief set a Cpf for the guest
     * @param cpf
     */
    void setCpf(unsigned long int cpf);

    /**
     * @brief set a Phone for the guest
     * @param phone
     */
    void setPhone(unsigned long int phone);

    /**
     * @brief set a Email for the guest
     * @param email
     */
    void setEmail(std::string email);

    /**
     * @brief get the guest Name
     * @return
     */
    std::string getName() ;

    /**
     * @brief get the guest Email
     * @return
     */
    std::string getEmail()  ;
    /**
     * @brief get the guest Cpf
     * @return
     */
    unsigned long int getCpf() ;

    /**
     * @brief get the guest Phone
     * @return
     */
    unsigned long getPhone();

    /**
     * @brief GuestImpl constructor by copy
     * @param GuestImpl adress
     */
    GuestImpl(const GuestImpl &guest);

    /**
     * @brief overload for the = operator
     * @param guest
     * @return guestImpl adress
     */
    GuestImpl& operator=(const GuestImpl& guest);
};

#endif // GUESTIMPL_H

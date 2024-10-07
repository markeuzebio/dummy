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
    std::string cpf;
    /**
     * @brief guest's email
     */
    std::string email;
    /**
     * @brief guest's phone
     */
    std::string phone;

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
    GuestImpl(std::string name,std::string cpf,std::string email,std::string phone);

    /**
     * @brief set a Name for the guest
     * @param name
     */
    void setName(std::string name);

    /**
     * @brief set a Cpf for the guest
     * @param cpf
     */
    void setCpf(std::string cpf);

    /**
     * @brief set a Phone for the guest
     * @param phone
     */
    void setPhone(std::string phone);

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
    std::string getCpf() ;

    /**
     * @brief get the guest Phone
     * @return
     */
    std::string getPhone();

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

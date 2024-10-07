#ifndef __CONN_MODULE_HPP__
#define __CONN_MODULE_HPP__

#include <string>
#include <mariadb/conncpp.hpp>

class ConnModule {
private:
    ConnModule();
    ConnModule(ConnModule&);
    virtual ~ConnModule();
    ConnModule& operator=(ConnModule&);
public:
    static std::unique_ptr<sql::Connection> createConnection(std::string username, std::string password, std::string url);

    static int createGuest(std::unique_ptr<sql::Connection> &conn, std::string guest_name, unsigned long int guest_cpf, unsigned long int guest_telephone, std::string guest_email);
};

#endif
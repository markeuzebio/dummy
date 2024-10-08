#ifndef __CONN_MODULE_HPP__
#define __CONN_MODULE_HPP__

#include <string>
#include <mariadb/conncpp.hpp>
#include "guest.h"

class ConnModule {
private:
    ConnModule();
    ConnModule(ConnModule&);
    virtual ~ConnModule();
    ConnModule& operator=(ConnModule&);
public:
    static std::unique_ptr<sql::Connection> createConnection(std::string username, std::string password, std::string url);

    static int createGuest(Guest *guest);
};

#endif
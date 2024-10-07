#include <iostream>
#include "connmodule.h"

std::unique_ptr<sql::Connection> ConnModule::createConnection(std::string username_param, std::string password_param, std::string url_param) {
    // Instantiate the driver
    sql::Driver *driver = sql::mariadb::get_driver_instance();

    // Configure Connection
    sql::SQLString url(url_param);
    sql::Properties properties({{"user", username_param}, {"password", password_param}});

    // Establish connection
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));

    return conn;
}

int ConnModule::createGuest(std::unique_ptr<sql::Connection> &conn, std::string guest_name, unsigned long int guest_cpf, unsigned long int guest_telephone, std::string guest_email) {
    try {
        // Create "INSERT INTO" statement
        std::unique_ptr<sql::PreparedStatement> insert_statement(conn->prepareStatement("INSERT INTO hospedes (nome, cpf, telefone, email) VALUES (?, ?, ?, ?)"));

        // Binding C++ varibles into INSERT statement
        insert_statement->setBigInt(1, guest_name);
        insert_statement->setBigInt(2, std::to_string(guest_cpf));
        insert_statement->setBigInt(3, std::to_string(guest_telephone));
        insert_statement->setString(4, guest_email);

        // Execute query
        return insert_statement->execute();
    } catch(sql::SQLException &e) {
        std::cerr << "Error creating guest: " << e.what() << "\n";
    }

    return 1;
}

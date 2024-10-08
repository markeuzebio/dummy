#include <iostream>
#include "connmodule.h"

#define DB_USERNAME   "admin"
#define DB_PASSWORD   "teste"
#define DB_URL        "jdbc:mariadb://localhost:3306/teste"

typedef std::unique_ptr<sql::Connection> Connection;
typedef std::unique_ptr<sql::Statement> Statement;
typedef std::unique_ptr<sql::PreparedStatement> PreparedStatement;

Connection ConnModule::createConnection(std::string username_param, std::string password_param, std::string url_param) {
    try {
        // Instantiate the driver
        sql::Driver *driver = sql::mariadb::get_driver_instance();

        // Configure Connection
        sql::SQLString url(url_param);
        sql::Properties properties({{"user", username_param}, {"password", password_param}});

        // Establish connection
        Connection conn(driver->connect(url, properties));

        return conn;
    } catch(sql::SQLException &e) {
        throw;
    }

    return nullptr;
}

int ConnModule::createGuest(Guest *guest) {
    try {
        Connection conn = createConnection(DB_USERNAME, DB_PASSWORD, DB_URL);

        // Create "INSERT INTO" statement
        PreparedStatement insert_statement(conn->prepareStatement("INSERT INTO hospedes (nome, cpf, telefone, email) VALUES (?, ?, ?, ?)"));

        // Binding C++ varibles into INSERT statement
        insert_statement->setBigInt(1, guest->getName());
        insert_statement->setBigInt(2, std::to_string(guest->getCpf()));
        insert_statement->setBigInt(3, std::to_string(guest->getPhone()));
        insert_statement->setString(4, guest->getEmail());

        // Execute query
        insert_statement->execute();

        // Close the connection
        conn->close();
    } catch(sql::SQLException &e) {
        std::cerr << "Error creating guest: " << e.what() << "\n";
        std::cerr << e.getErrorCode() << "\n";
        throw;
        return 0;
    }

    return 1;
}

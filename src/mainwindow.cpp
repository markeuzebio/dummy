#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hotel.h"
#include "connmodule.h"

#define PK_ERROR_CODE   1062
#define CONN_ERROR_CODE 1045

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cadastrar_clicked()
{
    Hotel *hotel = Hotel::createHotel();
    Guest *guest;

    // UI fields values
    string guest_name;
    unsigned long int guest_cpf;
    string guest_email;
    unsigned long int guest_phone;

    guest_name = ui->txt_nome->text().toStdString();
    guest_cpf = ui->txt_cpf->text().toULong();
    guest_email = ui->txt_email->text().toStdString();
    guest_phone = ui->txt_telefone->text().toULong();

    guest = hotel->createGuest(guest_name, guest_cpf, guest_email, guest_phone);

    try {
        ConnModule::createGuest(guest);
    } catch(sql::SQLException &e) {
        std::cerr << "Error creating guest: " << e.what() << "\n";
    }
}


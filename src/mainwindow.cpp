#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <cctype>
#include <QMessageBox>
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

bool NumberValidation(string &str){
    for(auto c : str){
        if(!std::isdigit(c)){
            return false;
        }

    }
    return true;
}

void setLabelErr(Ui::MainWindow *ui, QString message) {
    ui->lb_erro->setText(message);
    ui->lb_erro->setStyleSheet("QLabel { color : red; }");
}

void MainWindow::on_btn_cadastrar_clicked()
{
    Hotel *hotel = Hotel::createHotel();
    Guest *guest;

    // UI fields values
    string txt_guest_name;
    string txt_guest_cpf;
    string txt_guest_email;
    string txt_guest_phone;

    if(ui->txt_nome->text().isEmpty()  ||
       ui->txt_cpf->text().isEmpty()   ||
       ui->txt_email->text().isEmpty() ||
       ui->txt_telefone->text().isEmpty()) {
        setLabelErr(ui, "Preencha todos os campos para confirmar o cadastro");
        return;
    }

    txt_guest_name = ui->txt_nome->text().toStdString();
    txt_guest_cpf = ui->txt_cpf->text().toStdString();
    txt_guest_email = ui->txt_email->text().toStdString();
    txt_guest_phone = ui->txt_telefone->text().toStdString();

    if(NumberValidation(txt_guest_cpf) == false){
        setLabelErr(ui, "Preencha CPF com valores numéricos");
        return;
    }

    if(NumberValidation(txt_guest_phone) == false){
        setLabelErr(ui, "Preencha Telefone com valores numéricos");
        return;
    }

    try {
        QString empty_msg = "";

        string guest_name             = txt_guest_name;
        string guest_email            = txt_guest_email;
        unsigned long int guest_cpf   = ui->txt_cpf->text().toULong();
        unsigned long int guest_phone = ui->txt_telefone->text().toULong();

        guest = hotel->createGuest(guest_name, guest_cpf, guest_email, guest_phone);
        ConnModule::createGuest(guest);

        setLabelErr(ui, empty_msg);

        QMessageBox::information(this,
                                 "Confirmação de cadastro",
                                 "O cadastro do Hospede:\nNome:" + QString::fromStdString(txt_guest_name) + ", CPF:" +
                                     QString::fromStdString(txt_guest_cpf) + ", Email:" +
                                     QString::fromStdString(txt_guest_email) + ", Telefone:" +
                                     QString::fromStdString(txt_guest_phone) + "\nfoi realizado.");
    } catch(sql::SQLException &e) {
        QString err_msg;

        if(e.getErrorCode() == CONN_ERROR_CODE)
            err_msg = "Erro de conexão com o Banco de Dados!";
        else if(e.getErrorCode() == PK_ERROR_CODE)
            err_msg = "Usuário com o CPF informado já cadastrado!";
        else
            err_msg = e.getMessage();

        setLabelErr(ui, err_msg);

        return;
    }
}

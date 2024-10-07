#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <cctype>
#include <QMessageBox>
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

void MainWindow::on_btn_cadastrar_clicked()
{
    string nome;
    string cpf;
    string email;
    string telefone;

    nome = ui->txt_nome->text().toStdString();
    cpf = ui->txt_cpf->text().toStdString();
    email = ui->txt_email->text().toStdString();
    telefone = ui->txt_telefone->text().toStdString();

    if(ui->txt_nome->text().isEmpty()){
        ui->lb_erro->setText("Preencha todos os campos para confirmar o cadastro");
        ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(ui->txt_cpf->text().isEmpty()){
        ui->lb_erro->setText("Preencha todos os campos para confirmar o cadastro");
        ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(ui->txt_email->text().isEmpty()){
        ui->lb_erro->setText("Preencha todos os campos para confirmar o cadastro");
        ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(ui->txt_telefone->text().isEmpty()){
        ui->lb_erro->setText("Preencha todos os campos para confirmar o cadastro");
        ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(!NumberValidation(cpf)){
        ui->lb_erro->setText("Preencha CPF com valores numéricos");
        ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(!NumberValidation(telefone)){
        ui->lb_erro->setText("Preencha Telefone com valores numéricos");
            ui->lb_erro->setStyleSheet("QLabel { color : red; }");
        return;
    }

    QMessageBox::information(this,
                              "Confirmação de cadastro",
                              "O cadastro do Hospede:\nNome:" + QString::fromStdString(nome) + ", CPF:" +
                                  QString::fromStdString(cpf) + ", Email:" +
                                  QString::fromStdString(email) + ", Telefone:" +
                                  QString::fromStdString(telefone) + "\nfoi realizado.");


}




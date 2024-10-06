#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    string nome;
    string cpf;
    string email;
    string telefone;

    nome = ui->txt_nome->text().toStdString();
    cpf = ui->txt_cpf->text().toStdString();
    email = ui->txt_email->text().toStdString();
    telefone = ui->txt_telefone->text().toStdString();

    cout << nome << "\n";
    cout << cpf << "\n";
    cout << email << "\n";
    cout << telefone << "\n";
}


#include "mainwindow.h"

#include <QApplication>
#include "hotelimpl.h"
#include "guest.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hotel *h = HotelImpl::createHotel();
    Guest *g = h->createGuest("a",1,"c",2);
    cout<< g->getName() << g->getEmail() << g->getPhone() << g->getCpf();
    w.show();

    return a.exec();
}

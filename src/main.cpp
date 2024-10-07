#include "mainwindow.h"

#include <QApplication>
#include "hotelImpl.h"
#include "guest.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hotel *h = HotelImpl::createHotel();
    Guest *g = h->createGuest("a","b","c","d");
    cout<< g->getName() + g->getEmail() + g->getPhone() + g->getCpf();
    w.show();

    return a.exec();
}
